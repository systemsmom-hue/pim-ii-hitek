  # Definition of Done

A **Definition of Done** estabelece os critérios que devem ser atendidos para que uma atividade do projeto **Sistema de Gestão de Comissões — Hitek Informática** seja considerada concluída.

O objetivo é evitar que tarefas sejam marcadas como finalizadas antes de terem sido revisadas, documentadas e integradas ao restante do projeto.

---

## Critérios gerais

Uma atividade somente poderá ser considerada concluída quando:

- o objetivo da tarefa tiver sido atendido;
- o conteúdo estiver coerente com os requisitos do projeto;
- não houver contradições com regras de negócio já definidas;
- o material estiver revisado;
- os arquivos estiverem salvos no local correto do repositório;
- os nomes dos arquivos estiverem padronizados;
- os links da documentação estiverem funcionando;
- o conteúdo estiver atualizado no GitHub;
- a atividade estiver coerente com os demais artefatos do projeto.

---

## Documentação

Uma atividade de documentação será considerada concluída quando:

- o texto estiver completo;
- as informações estiverem coerentes com o projeto;
- não houver dados inventados;
- os termos utilizados estiverem padronizados;
- a formatação estiver adequada;
- os links internos estiverem funcionando;
- o arquivo estiver armazenado na pasta correspondente;
- o conteúdo tiver sido revisado antes do commit.

---

## Requisitos

Um requisito será considerado concluído quando:

- possuir identificação;
- possuir descrição clara;
- estiver coerente com o escopo;
- estiver relacionado às funcionalidades reais do sistema;
- não contradizer regras de negócio;
- estiver refletido nos artefatos relacionados quando aplicável.

---

## Casos de Uso

Um caso de uso será considerado concluído quando:

- o ator estiver corretamente definido;
- a funcionalidade estiver coerente com o perfil do usuário;
- o comportamento estiver descrito de forma clara;
- os relacionamentos `<<include>>` e `<<extend>>` estiverem utilizados apenas quando aplicáveis;
- o caso de uso estiver coerente com o Diagrama de Casos de Uso;
- estiver coerente com os requisitos funcionais e regras de negócio.

---

## Diagramas

Um diagrama será considerado concluído quando:

- representar corretamente o processo ou estrutura correspondente;
- estiver coerente com a documentação textual;
- utilizar os elementos e relacionamentos adequados;
- não possuir informações contraditórias;
- estiver legível;
- estiver exportado em formato de imagem;
- estiver armazenado na pasta `docs/03-diagramas/`;
- possuir, quando aplicável, arquivo editável correspondente.

---

## Banco de Dados

Um artefato de banco de dados será considerado concluído quando:

- estiver coerente com os requisitos do sistema;
- representar corretamente as entidades necessárias;
- possuir relacionamentos coerentes;
- possuir chaves primárias e estrangeiras corretamente definidas quando aplicável;
- estiver compatível com as regras de negócio;
- tiver sido revisado quanto à redundância e normalização;
- estiver documentado no repositório.

---

## Programação em C

Uma funcionalidade implementada em C será considerada concluída quando:

- compilar sem erros;
- executar a funcionalidade prevista;
- possuir lógica coerente com o requisito relacionado;
- tratar as situações previstas para a função;
- possuir nomes de variáveis e funções compreensíveis;
- estiver organizada nos arquivos corretos;
- tiver sido testada;
- estiver versionada no repositório.

---

## Scrum

Um item do Scrum será considerado concluído quando:

- estiver registrado no artefato correspondente;
- possuir descrição clara;
- estiver relacionado ao projeto;
- seu status representar a situação real;
- estiver coerente com o Product Backlog e com as atividades realizadas.

---

## Revisão final

Antes de considerar uma entrega concluída, deverá ser verificada a coerência entre:

```text
Problema e solução
        ↓
Objetivos
        ↓
Escopo
        ↓
Requisitos
        ↓
Regras de negócio
        ↓
Casos de uso
        ↓
Diagramas
        ↓
Banco de dados
        ↓
Implementação
        ↓
Documentação final
```

Todos esses elementos devem representar o mesmo sistema e o mesmo fluxo de negócio.

---

## Critério de conclusão

Uma tarefa não deverá ser marcada como **Concluída** apenas porque foi iniciada ou parcialmente desenvolvida.

O status **Concluído** deverá ser utilizado somente quando todos os critérios aplicáveis desta Definition of Done forem atendidos.

---

## Documentação relacionada

- [Product Backlog](product-backlog.md)
- [User Stories](user-stories.md)
- [Engenharia de Software](../docs/02-engenharia-de-software/)
- [Diagramas](../docs/03-diagramas/)
- [Banco de Dados](../docs/04-banco-de-dados/)

---

[← Voltar para Scrum](README.md)
