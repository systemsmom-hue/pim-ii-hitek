# Plano de Endereçamento IP e Segmentação de Rede

Este documento apresenta a estrutura de endereçamento IPv4 e a organização das redes locais virtuais (VLANs) para o ambiente operacional do Sistema de Gestão de Comissões da Hitek Informática.

## 1. Diretrizes da Arquitetura IP

A empresa utiliza o bloco de endereços IP privados **192.168.0.0/16** reservado pela RFC 1918. Para fins de organização, isolamento de tráfego e aplicação de políticas de segurança no firewall, a rede foi dividida em sub-redes com máscara `/24` (255.255.255.0), oferecendo até 254 endereços utilizáveis por segmento.

## 2. Tabela de Mapeamento de Sub-redes e VLANs

| VLAN ID | Nome do Segmento | Sub-rede / CIDR | Máscara de Rede | Gateway Padrão | Capacidade de Hosts |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **VLAN 10** | Vendas | 192.168.10.0/24 | 255.255.255.0 | 192.168.10.1 | 254 hosts |
| **VLAN 20** | Financeiro / Admin | 192.168.20.0/24 | 255.255.255.0 | 192.168.20.1 | 254 hosts |
| **VLAN 30** | Servidores / Infra | 192.168.30.0/24 | 255.255.255.0 | 192.168.30.1 | 254 hosts |

## 3. Endereçamento Estático de Ativos Críticos

Equipamentos essenciais da infraestrutura possuem endereços IP estáticos configurados manualmente ou vinculados por endereço MAC para garantir acessibilidade constante pelas rotinas do sistema em Linguagem C.

| Equipamento / Dispositivo | VLAN | Endereço IP | Interface / Descrição |
| :--- | :--- | :--- | :--- |
| **Roteador / Firewall** | Múltiplas | 192.168.30.1 | Gateway principal e roteamento inter-VLAN |
| **Switch Gerenciável Core** | VLAN 30 | 192.168.30.2 | Interface VLAN de Gerenciamento (SVI) |
| **Servidor MySQL Principal** | VLAN 30 | 192.168.30.10 | Servidor de banco de dados (Porta 3306) |
| **Servidor de Backup / Log** | VLAN 30 | 192.168.30.11 | Armazenamento de backups do MySQL |
| **Nobreak Gerenciável SNMP** | VLAN 30 | 192.168.30.20 | Módulo de telemetria elétrica |

## 4. Escopos DHCP para Estações de Trabalho

Os terminais dos vendedores e operadores do financeiro recebem configurações automáticas de IP via DHCP fornecido pelo roteador/firewall.

### 4.1. Escopo VLAN 10 (Setor de Vendas)
* **Faixa Dinâmica:** 192.168.10.100 até 192.168.10.200
* **Gateway:** 192.168.10.1
* **DNS Primário:** 192.168.30.10 (Local) ou 8.8.8.8
* **Tempo de Concessão (Lease Time):** 8 horas

### 4.2. Escopo VLAN 20 (Setor Financeiro)
* **Faixa Dinâmica:** 192.168.20.100 até 192.168.20.150
* **Gateway:** 192.168.20.1
* **DNS Primário:** 192.168.30.10 (Local) ou 8.8.8.8
* **Tempo de Concessão (Lease Time):** 8 horas

## 5. Resolução de Nomes Interna (DNS)

Para simplificar a configuração das strings de conexão na aplicação C (`banco.c`), a rede local conta com entradas DNS internas mapeadas no roteador:

* `db.hitek.local` -> Resolvido para `192.168.30.10`
* `backup.hitek.local` -> Resolvido para `192.168.30.11`

## 📜 Documentação Relacionada

- [Topologia de Rede](topologia.md)
- [Equipamentos e Hardware de Rede](equipamentos.md)
- [Visão Geral do Projeto](../../docs/01-visao-geral/README.md)
