# 📡 Redes de Computadores e Infraestrutura de Comunicação

Este documento detalha a arquitetura de redes, topologia, protocolos e requisitos de infraestrutura que suportam o **Sistema de Gestão de Comissões da Hitek Informática**, elaborado no âmbito do Projeto Integrado Multidisciplinar (PIM II - UNIP).

---

## 1. Visão Geral da Arquitetura de Rede

O Sistema de Gestão de Comissões adota o **modelo Cliente-Servidor**, no qual os terminais de atendimento (Vendedores, Financeiro e Administrador) executam a aplicação cliente desenvolvida em C e comunicam-se de forma centralizada com o banco de dados **MySQL**.


---

## 2. Mapeamento no Modelo de Referência TCP/IP e OSI

A comunicação do sistema engloba todas as camadas do modelo de referência, garantindo integridade, segurança e baixo tempo de resposta (< 2 segundos, conforme **RNF03**):

| Camada OSI | Camada TCP/IP | Tecnologias / Protocolos Utilizados | Função no Sistema de Comissões |
|---|---|---|---|
| **7. Aplicação** | **Aplicação** | MySQL Native Protocol, SSH, HTTP/HTTPS | Interface de aplicação C, consultas SQL e administração remota. |
| **6. Apresentação** | **Aplicação** | UTF-8, SSL/TLS | Codificação de dados e criptografia da conexão com o banco de dados. |
| **5. Sessão** | **Aplicação** | Sockets TCP / C MySQL API | Manutenção de sessão ativa entre o cliente C e o MySQL. |
| **4. Transporte** | **Transporte** | **TCP** (Porta 3306) | Transporte confiável orientado à conexão para transações financeiras e de vendas. |
| **3. Rede** | **Internet** | **IPv4**, ICMP, ARP | Endereçamento IP interno e roteamento entre sub-redes/VLANs. |
| **2. Enlace** | **Acesso à Rede**| Ethernet (IEEE 802.3), Wi-Fi (IEEE 802.11ax) | Enquadramento e controle de acesso ao meio físico. |
| **1. Física** | **Acesso à Rede**| Cabo UTP Cat6, Switch Gigabit Ethernet | Meio físico de transmissão dos dados na Hitek Informática. |

---

## 3. Topologia e Meio Físico

### 3.1 Topologia Física e Lógica
* **Topologia Física:** **Estrela (Star)**, onde todas as estações de trabalho e o servidor central estão conectados a um **Switch Gigabit Ethernet (1000 Mbps)** central.
* **Topologia Lógica:** Barramento sobre Ethernet com controle de colisão CSMA/CD.

### 3.2 Especificações do Cabeamento e Conectividade
* **Cabeamento:** Par trançado não blindado (**UTP Cat6**), permitindo taxas de transferência de até **1 Gbps** a 250 MHz, eliminando gargalos de rede e garantindo a regra de desempenho **RNF03**.
* **Conectores:** RJ-45 padrão EIA/TIA 568B.
* **Rede Sem Fio (Opcional para Terminais Móveis):** Wi-Fi 6 (IEEE 802.11ax) com autenticação **WPA3-Enterprise**.

---

## 4. Serviços de Rede e Protocolos de Suporte

### 4.1 Endereçamento IP e DHCP
* **Servidor de Banco de Dados:** Endereçamento IP **Estático (Fixo)** para evitar perda de rota da aplicação cliente (Exemplo: `192.168.10.10/24`).
* **Estações de Trabalho (Clientes):** Atribuição dinâmica via **DHCP (Dynamic Host Configuration Protocol)** com *lease time* de 8 horas e reserva de IP via endereço MAC quando necessário.

### 4.2 Resolução de Nomes (DNS)
* Servidor DNS local ou arquivo hosts mapeando a entrada `db.hitek.local` para o IP do servidor de banco de dados, facilitando migrações futuras sem alteração no código-fonte em C.

---

## 5. Segurança da Rede e Controle de Acesso (RNF01 & Cap. 20)

Para atender ao requisito de segurança (**RNF01**), a infraestrutura de rede aplica as seguintes diretivas:

1. **Segmentação de Rede via VLANs (IEEE 802.1Q):**
   * **VLAN 10 (Operacional / Vendedores):** Acesso limitado à porta `3306` do servidor MySQL.
   * **VLAN 20 (Financeiro & Gestão):** Acesso restrito para baixa de comissões e relatórios.
   * **VLAN 30 (Servidores & Gerência):** Contém o servidor MySQL e acessos de administração.

2. **Regras de Firewall (Filtragem de Pacotes):**
   * Bloqueio por padrão de todo o tráfego de entrada na porta `3306` vindo de fora da rede local.
   * Liberação estrita da porta `3306/TCP` para o bloco de IPs das VLANs internas corporativas.

3. **Criptografia em Trânsito:**
   * Conexão entre o cliente em C e o MySQL configurada com **TLS/SSL**, impedindo a interceptação de senhas e dados de vendas (*Sniffing*).

---

## 6. Disponibilidade, Desempenho e Escalabilidade (RNF03, RNF04, RNF05)

* **Desempenho (RNF03):** Com latência de rede interna inferior a **2 ms** via cabeamento Cat6 Gigabit, a execução das consultas SQL (`INSERT`, `UPDATE`, `SELECT`) ocorre bem abaixo do limite tolerável de 2 segundos.
* **Disponibilidade e Redundância (RNF04):**
  * Servidor de banco de dados equipado com **RAID 1** (Espelhamento de discos).
  * Rotinas de **Backup diário** automatizado via rede para storage secundário/nuvem.
  * *No-Break* (Nobreak de 1500VA) acoplado ao servidor e ao switch principal para evitar interrupções de energia.
* **Escalabilidade (RNF05):** A estrutura de endereçamento `/24` (suporte a até 254 hosts) e a arquitetura modular da aplicação em C suportam a expansão no número de colaboradores e vendas sem necessidade de restruturação física.