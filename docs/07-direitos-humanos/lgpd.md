# Uso Responsável da Tecnologia e Proteção de Dados (LGPD)

Este documento descreve as diretrizes de governança da informação, privacidade e conformidade com a Lei Geral de Proteção de Dados Pessoais (Lei nº 13.709/2018 - LGPD) aplicadas ao **Sistema de Gestão de Comissões — Hitek Informática**.

## 1. Contexto e Aplicação da LGPD

O sistema manipula dados pessoais e financeiros de colaboradores (cadastros de vendedores, CPF, e-mail, telefone, registros de vendas e valores de comissões). 

A conformidade com a LGPD assegura a proteção dos direitos fundamentais de liberdade, privacidade e o livre desenvolvimento da pessoa natural no ambiente corporativo.

## 2. Princípios da LGPD Incorporados ao Sistema

### 2.1. Finalidade e Adequação (Artigo 6º, I e II)
O tratamento de dados pessoais no software restringe-se estritamente ao propósito de operacionalizar o cálculo de comissões, registro de Ordens de Serviço (OS) e quitação financeira. Nenhum dado é compartilhado com terceiros ou utilizado para fins diversos dos estipulados no contrato de trabalho.

### 2.2. Minimização dos Dados (Artigo 6º, III)
Apenas as informações estritamente necessárias para a gestão de vendas e pagamentos são coletadas e armazenadas no banco de dados MySQL:
- **Colaboradores:** Nome completo, CPF, e-mail corporativo, telefone, cargo, login de acesso, perfil de permissão e status.
- **Vendas e Atendimentos:** Número da Ordem de Serviço (OS), valores operacionais, margem e percentuais de comissão.

### 2.3. Segurança e Prevenção (Artigo 6º, VII e VIII)
Implementação de medidas técnicas e administrativas para proteger os dados pessoais contra acessos não autorizados, vazamentos, alterações desautorizadas ou destruição acidental.

## 3. Mecanismos Técnicos de Segurança da Informação

1. **Autenticação e Sanitização de Credenciais:**
   * Tratamento das entradas de dados com sanitização estrita via `mysql_real_escape_string()` para prevenção de vulnerabilidades *SQL Injection*.
   * *Nota de Implementação do Protótipo (PIM II):* No âmbito do protótipo desenvolvido em C, a autenticação de colaboradores utiliza sanitização de entradas contra *SQL Injection*. Para ambientes de produção de larga escala, recomenda-se a evolução do algoritmo de autenticação para o armazenamento de *hashes* criptográficos de palavras-passe utilizando `SHA-256` ou `bcrypt`.

2. **Controle de Acesso Baseado em Perfis (RBAC):**
   * O acesso às tabelas e rotinas é restrito pelo perfil do usuário (`ADMINISTRADOR`, `FINANCEIRO`, `VENDEDOR`). Vendedores possuem visibilidade restrita aos seus próprios registros de vendas e comissões.

3. **Auditoria e Rastreabilidade:**
   * Transações financeiras, alterações de status e reajustes de percentual registram o identificador do operador responsável (`id_administrador`/`id_colaborador`) e o carimbo de data/hora (`data_alteracao`/`data_registro`).

4. **Segmentação de Rede e Firewall:**
   * O banco de dados MySQL é isolado na `VLAN_SERVIDORES`, sem exposição direta para a internet ou redes externas não autorizadas.

## 4. Garantia dos Direitos dos Titulares (Artigo 18)

O sistema foi modelado para permitir que a administração da empresa atenda com agilidade às requisições dos titulares dos dados:

- **Direito de Acesso e Confirmação:** O colaborador pode solicitar a visualização de todos os seus dados cadastrais e histórico financeiro mantidos no sistema.
- **Direito de Correção:** Permite a atualização de dados incompletos, inexatos ou desatualizados (ex.: alteração de e-mail, telefone ou cargo via funcionalidade de atualização de colaboradores).
- **Eliminação / Anonimização pós-desligamento:** Dados de ex-colaboradores têm seus acessos revogados imediatamente (`status = INATIVO`) e os dados pessoais são mantidos estritamente conforme os prazos legais de guarda fiscal e trabalhista.

## Documentação Relacionada

- [Acessibilidade e Usabilidade](acessibilidade.md)
- [Inclusão Social e Digital](inclusao.md)
- [README da Seção de Direitos Humanos](README.md)
- [Visão Geral do Projeto](../../docs/01-visao-geral/README.md)
