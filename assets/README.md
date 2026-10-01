# Assets

Esta pasta reúne os recursos visuais utilizados no repositório do **Sistema de Gestão de Comissões — Hitek Informática**.

O objetivo é centralizar imagens auxiliares utilizadas na apresentação e documentação do projeto.

---

## Uso da pasta

Esta pasta poderá armazenar elementos como:

- logotipo da Hitek Informática;
- imagens utilizadas no README principal;
- elementos gráficos de apresentação;
- capturas de tela relevantes;
- recursos visuais utilizados na documentação.

---

## O que não deve ficar aqui

Os diagramas técnicos do sistema possuem uma pasta própria e não devem ser duplicados nesta seção.

Eles ficam em:

```text
docs/03-diagramas/
```

Nessa pasta estão ou estarão:

```text
casos-de-uso.png
atividade.png
estendido.png
sistema-comissoes.asta
```

Da mesma forma, o DER deverá permanecer na documentação de Banco de Dados:

```text
docs/04-banco-de-dados/
```

E o futuro diagrama de rede deverá permanecer em:

```text
docs/06-redes/
```

---

## Organização prevista

A pasta poderá evoluir para uma estrutura semelhante a:

```text
assets/
├── README.md
├── logo/
├── screenshots/
└── imagens/
```

Essas subpastas somente deverão ser criadas quando houver arquivos reais para armazenar.

---

## Padronização dos arquivos

Para manter a organização do repositório, os arquivos deverão utilizar nomes simples e descritivos.

Preferir:

```text
logo-hitek.png
tela-login.png
tela-vendas.png
fluxo-apresentacao.png
```

Evitar nomes como:

```text
imagem1.png
foto-final-final.png
captura(2).png
novo.png
```

---

## Formatos recomendados

Quando possível:

```text
PNG  → diagramas, interfaces e imagens com texto
JPG  → fotografias
SVG  → elementos vetoriais, quando aplicável
```

---

## Cuidados

Antes de adicionar um recurso visual ao repositório, deverá ser verificado se:

- o arquivo realmente será utilizado;
- a imagem possui qualidade adequada;
- o nome do arquivo está padronizado;
- não existe uma cópia desnecessária;
- o conteúdo não possui informações sensíveis;
- o recurso está armazenado na pasta mais adequada.

---

## Relação com o README principal

Os arquivos desta pasta poderão ser utilizados no `README.md` principal para melhorar a apresentação visual do projeto.

Exemplo:

```markdown
![Logo do projeto](assets/logo-hitek.png)
```

O recurso somente deverá ser referenciado quando o arquivo correspondente realmente existir.

---

[← Voltar ao README principal](../README.md)
