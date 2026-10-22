# Topologia de Rede e Infraestrutura de Comunicação

Este documento descreve a topologia e a arquitetura de rede de computadores projetada para suportar o **Sistema de Gestão de Comissões — Hitek Informática**, garantindo conectividade, segurança e baixa latência entre as estações de trabalho e o servidor central de banco de dados MySQL.

## 1. Arquitetura da Rede Local (LAN)

A infraestrutura de rede da empresa adota o modelo **Cliente-Servidor** sobre uma topologia física em **Estrela (Star Topology)**, utilizando o padrão **Ethernet IEEE 802.3ab (1000BASE-T / Gigabit Ethernet)**.

### Características Principais:

* **Velocidade Nominal:** 1 Gbps por porta (Full-Duplex).
* **Meio Físico:** Categoria 6 (UTP Cat6) com blindagem em pontos de interferência eletromagnética.
* **Elemento Central de Comutação:** Switch Gerenciável de 24 Portas Gigabit com suporte a VLANs (IEEE 802.1Q).
* **Conectividade:** Cabeamento estruturado conforme normas ANSI/TIA-568-C.

## 2. Diagrama de Topologia Física e Lógica

```text
                       [ Roteador / Gateway Principal ]
                                     |
                                     | (Uplink Trunk / 1Gbps)
                                     v
                       [ Switch Gerenciável Cat6 ]
                        (VLAN Trunk 10, 20, 30)
                                     |
    +--------------------------------+--------------------------------+
    | (VLAN 30)                      | (VLAN 10)                      | (VLAN 20)
    v                                v                                v
[ Servidor MySQL ]          [ Terminais Vendas ]           [ Terminais Financeiro ]
(IP: 192.168.30.10)         (DHCP 192.168.10.x)            (DHCP 192.168.20.x)
```

## 3. Divisão de VLANs (Redes Locais Virtuais)

Para mitigar domínios de broadcast, isolar o tráfego sensível e reforçar a segurança contra acessos não autorizados, a rede foi segmentada em três **VLANs (Virtual LANs)**:

| VLAN ID | Nome da VLAN | Finalidade / Público | Sub-rede IPv4 | Nível de Acesso ao Servidor |
| :--- | :--- | :--- | :--- | :--- |
| **VLAN 10** | `VLAN_VENDAS` | Estações dos Consultores de Vendas | `192.168.10.0/24` | Acesso restrito às rotinas de inserção de vendas |
| **VLAN 20** | `VLAN_FINANCEIRO` | Estações do Setor Financeiro / Admin | `192.168.20.0/24` | Acesso total às rotinas de liberação e pagamento |
| **VLAN 30** | `VLAN_SERVIDORES` | Servidor Principal MySQL e Backups | `192.168.30.0/24` | Isolado; recebe conexões apenas das VLANs 10 e 20 |

## 4. Política de Firewall e Regras de Roteamento

O roteador/firewall da borda gerencia o tráfego entre as VLANs e a internet, aplicando as seguintes regras:

1. **Acesso ao Banco de Dados (Porta 3306):**
   * Liberado apenas para os endereços IP originados da `VLAN_VENDAS` (10) e `VLAN_FINANCEIRO` (20) em direção à `VLAN_SERVIDORES` (30).
   * Bloqueada qualquer tentativa de acesso direto à porta 3306 via IP público/Internet.

2. **Isolamento entre Vendas e Financeiro:**
   * O tráfego direto de dados entre a `VLAN_VENDAS` e a `VLAN_FINANCEIRO` é bloqueado por padrão para impedir interceptação de tráfego financeiro.

3. **Qualidade de Serviço (QoS):**
   * Priorização de pacotes de dados direcionados à porta `3306` (MySQL) para assegurar tempo de resposta $< 10\text{ ms}$ nas operações do sistema em C.

## Documentação Relacionada

* [Equipamentos e Hardware de Rede](equipamentos.md)
* [Plano de Endereçamento IP](enderecamento.md)
* [README da Seção de Redes](README.md)
* [Visão Geral do Projeto](../../docs/01-visao-geral/README.md)
