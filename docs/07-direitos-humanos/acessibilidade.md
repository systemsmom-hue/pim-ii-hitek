# Acessibilidade e Usabilidade no Sistema

Este documento descreve as diretrizes de acessibilidade, usabilidade e desenho inclusivo aplicadas ao **Sistema de Gestão de Comissões — Hitek Informática**, desenvolvido em Linguagem C.

## 1. Contexto e Importância da Acessibilidade em Sistemas Corporativos

A acessibilidade em sistemas de informação corporativos garante que todos os colaboradores, independentemente de suas capacidades físicas, sensoriais ou motoras, possam desempenhar suas funções profissionais de maneira autônoma, digna e eficiente.

No ambiente de terminal CLI (*Command Line Interface*) do sistema, a acessibilidade foi tratada como um requisito de qualidade e inclusão desde as etapas iniciais de projeto.

## 2. Diretrizes de Acessibilidade Aplicadas à Interface em Modo Texto

### 2.1. Alto Contraste e Legibilidade
* **Esquema de Cores:** Utilização do contraste padrão do emulador de terminal (texto claro sobre fundo escuro), evitando combinações de cores de baixa visibilidade (ex.: azul escuro sobre fundo preto).
* **Nao Dependencia Exclusiva de Cores:** Nenhuma informação crítica ou validação é transmitida apenas através de cores. Mensagens de sucesso ou erro sempre incluem texto explícito (ex.: "[SUCESSO]", "[ERRO]").

### 2.2. Compatibilidade com Leitores de Tela
* **Estrutura Linear de Texto:** O fluxo de entrada e saída do programa em C é mantido em formato sequencial simples, permitindo que softwares leitores de tela (como NVDA ou Orca) leiam os menus e dados sem sobreposição de caracteres.
* **Caracteres ASCII Padronizados:** Eliminação de molduras complexas compostas por caracteres especiais que geram ruído sonoro indesejado nos sintetizadores de voz.

### 2.3. Navegação por Teclado e Facilidade Motora
* **Entrada por Opções Numéricas:** Menus organizados em escolhas numéricas simples (ex.: 1, 2, 3, 0 para Sair), reduzindo a quantidade de digitação exigida dos operadores.
* **Prevenção de Loops e Bloqueios:** Tratamento de entradas inválidas no buffer da linguagem C (`fflush(stdin)` / substitutos seguros) para impedir travamentos da interface que forcem a reinicialização manual.

## 3. Mensagens de Feedback e Clareza
* **Linguagem Clara e Direta:** Erros e orientações do sistema são apresentados de forma explicativa, indicando como corrigir a ação (ex.: "Valor inválido. Digite um número positivo ex: 150.00").
* **Tempo de Leitura Adequado:** A interface não utiliza fechamentos automáticos ou temporizadores para mensagens de confirmação, respeitando o tempo individual de leitura de cada usuário.

## Documentacao Relacionada

* [Inclusao Social e Digital](inclusao.md)
* [Uso Responsavel da Tecnologia e LGPD](lgpd.md)
* [README da Secao de Direitos Humanos](README.md)
* [Visao Geral do Projeto](../../docs/01-visao-geral/README.md)
