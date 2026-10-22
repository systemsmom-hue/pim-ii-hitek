# Direitos Humanos e Inclusão

Esta seção reúne os conteúdos relacionados à disciplina de **Direitos Humanos e Inclusão** aplicados ao projeto **Sistema de Gestão de Comissões — Hitek Informática**.

O objetivo desta parte é registrar os aspectos do projeto relacionados à inclusão, acessibilidade, respeito aos usuários e uso responsável da tecnologia.

---

## Conteúdo da Seção

### 1. [Acessibilidade e Usabilidade](acessibilidade.md)
Diretrizes de legibilidade, alto contraste, suporte a leitores de tela e facilidade de navegação no terminal CLI.

### 2. [Inclusão Social e Digital](inclusao.md)
Mapeamento da valorização do trabalho, equidade nas regras de comissão, transparência remuneratória e baixa curva de aprendizado.

### 3. [Uso Responsável da Tecnologia e LGPD](lgpd.md)
Governança de dados, privilégios por perfil funcional (RBAC), privacidade e conformidade com a Lei Geral de Proteção de Dados (Lei nº 13.709/2018).

---

## Objetivos da Seção

A documentação aborda os seguintes tópicos alinhados à disciplina:

- Acessibilidade no uso do sistema;
- Inclusão digital e redução da curva de aprendizado;
- Respeito à diversidade dos usuários;
- Facilidade de utilização;
- Apresentação clara de informações e mensagens;
- Uso responsável dos dados;
- Tratamento e proteção adequada das informações dos usuários (LGPD).

---

## Relação com o Sistema

O Sistema de Gestão de Comissões oferece uma experiência de uso clara e acessível aos diferentes perfis de usuário.

Entre os aspectos implementados no projeto estão:

- Organização clara das funcionalidades na interface de terminal CLI;
- Boa legibilidade das informações sem dependência exclusiva de cores;
- Navegação simples por escolhas numéricas;
- Separação de acesso por perfil (Vendedor, Financeiro e Administrador);
- Autenticação individualizada de usuários com senhas criptografadas;
- Acesso restrito somente às funcionalidades autorizadas;
- Preocupação com a segurança e utilização adequada das informações armazenadas no banco de dados.

---

## Acessibilidade

A acessibilidade está diretamente associada aos requisitos não funcionais do sistema.

A interface prioriza:

- Textos e opções com alta legibilidade no terminal;
- Identificação clara de campos, mensagens de retorno e erros;
- Organização visual sequencial e sem poluição de caracteres;
- Navegação teclado-dependente simples e intuitiva;
- Apresentação compreensível das mensagens de feedback do sistema.

---

## Inclusão

A solução busca eliminar barreiras de utilização no ambiente de trabalho.

O sistema foi concebido para permitir que colaboradores executem suas tarefas de forma simples, objetiva e autônoma, independentemente do seu nível prévio de familiaridade com softwares corporativos.

---

## Uso Responsável da Tecnologia

O sistema armazena informações sensíveis relacionadas a usuários, colaboradores, vendas, comissões e pagamentos.

Por esse motivo, o acesso às informações respeita estritamente os privilégios definidos para cada perfil:

- **Vendedor:** Consulta restrita de seus próprios lançamentos e extratos de comissão;
- **Financeiro:** Liberação de comissões, registro de pagamentos e relatórios do setor;
- **Administrador:** Gestão global de usuários, colaboradores e parâmetros.

A autenticação RBAC e o controle de acesso garantem a privacidade e limitam o manuseio dos dados às pessoas devidamente autorizadas.

---

## Estrutura de Arquivos

```text
docs/07-direitos-humanos/
├── README.md
├── acessibilidade.md
├── inclusao.md
└── lgpd.md
```

---

## Situação Atual

| Artefato | Arquivo | Status |
|---|---|:---:|
| Análise de acessibilidade | [`acessibilidade.md`](acessibilidade.md) | Concluído |
| Análise de inclusão | [`inclusao.md`](inclusao.md) | Concluído |
| Uso responsável da tecnologia e LGPD | [`lgpd.md`](lgpd.md) | Concluído |

---

## Observação

Os conteúdos desta seção foram desenvolvidos de acordo com as orientações da disciplina e com os requisitos funcionais e não funcionais efetivamente implementados na solução para a Hitek Informática.

---

## Documentação Relacionada

- [Visão Geral do Projeto](../01-visao-geral/README.md)
- [Requisitos Não Funcionais](../02-engenharia-de-software/requisitos-nao-funcionais.md)
- [Arquitetura do Sistema](../02-engenharia-de-software/arquitetura.md)

---

[← Voltar ao README principal](../../README.md)
