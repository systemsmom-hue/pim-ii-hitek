# Equipamentos de Rede e Especificações de Hardware

Este documento apresenta o detalhamento técnico dos equipamentos de rede e servidor selecionados para suportar o Sistema de Gestão de Comissões da Hitek Informática.

## 1. Servidor Principal de Banco de Dados e Aplicação

O servidor central hospeda o SGBD MySQL e a aplicação de retaguarda, exigindo alta disponibilidade e redundância para evitar interrupções no processo financeiro.

### Especificações Técnicas:

* **Modelo:** Servidor Rack 1U
* **Processador:** Intel Xeon E-2336 (6 Cores, 12 Threads, 2.9GHz)
* **Memória RAM:** 32 GB DDR4 ECC (Error-Correcting Code)
* **Armazenamento:** 2x SSD 960GB Enterprise SATA em RAID 1 (Espelhamento)
* **Placa de Rede:** Interface Dupla Gigabit Ethernet (2x 10/100/1000 Mbps) com suporte a Link Aggregation (LACP)
* **Fonte de Alimentação:** Fonte Redundante Hot-Plug de 600W
* **Sistema Operacional Base:** Linux Ubuntu Server 22.04 LTS (64-bit)

## 2. Ativos de Rede

### 2.1. Switch Central (Core / Distribution)

Responsável pela comutação de pacotes entre os terminais de vendas, setor financeiro e o servidor.

* **Modelo:** Switch Gerenciável L2+ de 24 Portas Gigabit Ethernet
* **Portas:** 24x 10/100/1000 Mbps RJ-45 + 4x Portas SFP Gigabit Uplink
* **Capacidade de Comutação (Backplane):** 56 Gbps
* **Recursos Lógicos Suportados:**
  * IEEE 802.1Q VLAN (até 4094 VLANs)
  * Spanning Tree Protocol (STP / RSTP)
  * Access Control Lists (ACLs) para filtragem de IP e portas
  * Port Security (Vinculação de endereço MAC)
  * Quality of Service (QoS) IEEE 802.1p

### 2.2. Roteador / Firewall de Borda

Equipamento encarregado de isolar a rede interna, gerenciar as VLANs e controlar a comunicação com a internet.

* **Funções:** Firewall Stateful, Servidor DHCP dedicado por VLAN e Roteamento Inter-VLAN
* **Interfaces:** 5x Portas Gigabit Ethernet (1x WAN, 4x LAN/VLAN Trunk)
* **Segurança:** Suporte a regras de inspeção profunda de pacotes (SPI) e VPN para acesso remoto administrativo seguro

## 3. Infraestrutura de Proteção Elétrica e Cabeamento

### 3.1. Sistema de Energia Ininterrupta (Nobreak / UPS)

Para garantir que instabilidades na rede elétrica não corrompam as transações do banco de dados MySQL durante a gravação de vendas.

* **Capacidade:** Nobreak Senoidal Online Dupla Conversão de 3000VA / 2700W
* **Autonomia:** Aproximadamente 45 minutos sob carga média
* **Gerenciamento:** Placa SNMP acoplada para desligamento automático e seguro do servidor Linux em caso de interrupção prolongada de energia

### 3.2. Meio Físico de Transmissão

* **Cabeamento Horizontal:** Cabo UTP Categoria 6 (Cat6) homologado Anatel
* **Conectores:** RJ-45 Cat6 blindados nos pontos de rede dos servidores
* **Patch Panels:** Patch Panel 24 portas Cat6 montado em Rack de 19 polegadas

## 📜 Documentação Relacionada

* [Topologia de Rede](topologia.md)
* [Plano de Endereçamento IP](enderecamento.md)
* [Visão Geral do Projeto](../../docs/01-visao-geral/README.md)
