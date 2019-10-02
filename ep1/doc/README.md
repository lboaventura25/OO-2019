# EP1 - OO 2019.2 - UnB 

> Aluno: Lucas Ursulino Boaventura
> 
> Matrícula: 18/0114093


# Descrição do Projeto

Este projeto consiste em criar um software para um pequeno comércio utilizando a linguagem C++ e o paradigma de Orientação a objetos.

O projeto tem como objetivo implementar 3 modos para o comércio de Victoria:

- Modo Venda
- Modo Estoque 
- Modo Recomendação
---
- # Modo Venda 

    Primeiro, deve ser digitado o CPF do cliente, e em seguida o programa vai identificar se o cliente já está cadastrado ou não. 
    - Caso esteja cadastrado, os dados do cliente serão imprimidos na tela.
    - Caso não esteja cadastrado, o programa vai abrir uma área de cadastro do cliente e ele será cadastrado.
  
    Após essa parte de identificação, entrará no modo de compra, onde serão identificados os produtos do carrinho do cliente através do código do produto, e também será inserido a quantidade de cada produto.

    - Caso o código do produto não exista aparecerá na tela a mensagem "*** Produto não cadastrado ***" e a inclusão de produtos continuará normalmente.
    - Caso exista, "### Produto incluído no carrinho ###".

    Em seguida aparecerá a nota fiscal da compra e a seguinte mensagem:
    - A compra será cancelada, caso não tenha quantidade suficiente no estoque de algum produto ou não tenha produtos no carrinho.
    - A compra será concluída com sucesso se tiver produtos no carrinho e as respectivas quantidades no estoque.


    Ao fim, será redirecionado ao menu incial.
    - ## O cliente se tornará sócio automaticamente assim que gastar um total de R$20 em compras, e passará a receber desconto de 15% nas próximas compras.

- # Modo Estoque
    
    Ao entrar no modo estoque aparecerá um menu com 3 funcionalidades.

    1) - Cadastrar um novo Produto.
    - Aparecerá uma tela de cadastro do produto, onde deve ser informado o código do produto, nome, quantidade no estoque, preço e categoria. Na hora de acrescentar as categorias aparecerá mensagem de "Categoria não cadastrada", caso ela nã exista no sistema.

    2) - Atualizar a quantidade de algum produto no estoque.
    -  O programa vai pedir o código do produto e em seguida sua nova quantidade no estoque. Caso o código do produto não exista aparecerá a mensagem "Produto não existe".

    3) - Cadastrar uma nova categoria.
    - O programa vai pedir para digitar o nome da nova categoria, a categoria deve possuir um único nome. E em seguida pedirá para digitar os códigos dos produtos que fazem parte dessa nova categoria, caso o produto não exista será emitida a mensagem "Produto não encontrado" e continuará a adição de produtos normalmente.
---
- # Modo Recomendação
  
    Ao entrar no modo recomendação deverá ser inserido o CPF do cliente.
    - Caso o cliente não seja cadastrado, aparecerá a mensagem "Cliente não encontrado.
    - Caso o cliente seja cadastrado aparecerá uma lista de recomendação de 10 produtos.
        - Essa lista será ordenada a partir do grau de recomendação de cada categoria, se houver empate no grau de recomendação, será respeitada a ordem lexicográfica. Caso a categoria mais recomendada não possua 10 produtos, será recomendado produtos da categoria seguinte da lista ordenada.
---
# Instruções para execução do Software

- Execute no terminal o comando:
```
$  git clone https://gitlab.com/lboaventura25/ep1.git
```
- Entre no diretório do projeto com o comando:
```shell
$ cd ep1/
```
- Para compilar o programa execute o comando:
```shell
$ make
```
- Para rodar o programa execute o comando:
```shell
$ make run
```
- Para limpar:
```shell
$ make clean
```