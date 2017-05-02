Atividade 9
======
1. Responda:

- a) Quando se pode aplicar a otimização de eliminação de sub-expressão comum?

É possível aplicar tal otimização quando for identificadas expressões comuns em várias partes do código e que suas variáveis não se modifiquem.
Se tivermos um caso como o exemplo abaixo:

```python
x = y + z;
...
...
w = y + z;
```

 É possível substituir o resultado da expressão `y + z` por uma variável temporária e utilizá-la durante o programa, caso y e z se mantenham, ou até mesmo
 substituir por `x` na segunda atribuição da expressão. Mas para isso, é necessário garantir que estaas variáveis não sejam modificadas no escopo em que
 foram utilizadas, o que pode ser mais complicado com arrays e ponteiros, mas o algoritmo **Directed Acyclic Graph (DAG)** pode ser utilizado para gerar o
 código otimizado.

- b) Qual o efeito que a quantidade de registradores tem no código gerado e por quê?

A quantidade de resgistradores está diretamente ligado ao código intermediário gerado pelo compilador. Uma forma de geração de código intermediário é o chamado
*Código de 3 endereços*. Com essa abordagem, qualquer operação é reduzida à instrução mais básica: `x = y op z`. A expressão a seguir:

```python
2*a+(b-3)
```

é modificada para:

```python
t1=2*a
t2=b-3
t3=t1+t2
```

Isso mostra que muitas variáveis temporárias podem ser criadas na geração do código intermediário e essas variáveis podem ficar em memória ou em registradores.
É sabido que o registrador é bem mais veloz que a memória principal e, se as variáveis temporárias forem armazenados neles, o código pode ser bem mais otimizado.
Portanto, quanto mais registradores disponíveis, melhor.


 2. Mostre como o código intermediário a seguir pode ser otimizado. Justifique as otimizações. 
 
- a)

Código intermediário:

```assembly
    1 MOV a 0
    2 JGT a 10 5
    3 MOV x a
    4 JMP 6
    5 MOV x b
    6 RTN 
```


Como `a` está recebendo um valor constante que nunca será maior que `10`, a condição nunca será satisfeita e o desvio não será realizado.
Não podemos deixar de atribuir 0 à variável `a`, pois ela pode estar sendo utilizada em outra parte do programa.

Código intermediário otimizado:

```assembly
    1 MOV a 0
    2 MOV x a
    3 RTN 
```

- b)

Código intermediário:

```assembly
    1 MOV x 0
    2 JGT x 10 7
    3 MULT t1 y A
    4 ADD t2 x t1
    5 MOV x t2
    6 JMP 2
    7 RTN  
```


Novamente, `x` está recebendo uma constante. A expressão avaliada tem o seu resultado atribuído à variável `x`, portanto ela pode receber o temporário
depois, já que *0* não influencia na soma.

Código intermediário otimizado:

```assembly
    1 MOV t1 y A
    2 MOV x t1
    3 RTN  
```

- c)

Código intermediário:

```assembly
    1 MOV a 0
    2 MOV a p
    3 JGT 0 a 17
    4 DIV t1 a p
    5 JGT t1 0.5 9
    6 DIV t2 a p
    7 ADD t3 f t2
    8 MOV f t3
    9 DIV t4 a p
    10 JGT 0.5 t4 14
    11 DIV t5 a p
    12 SUB t6 f t5
    13 MOV f t6
    14 SUB t7 a 1
    15 MOV a t7
    16 JMP 3
    17 MOV p f 
```

A primeira linha pode ser retirada devido à sobrescrita de `p` em `a`. Como as variáveis `a` e `p` são iguais, a divisão delas é sempre 1.
É possível ver dentro do loop que as duas variáveis são decrementadas no mesmo fator. Podemos então eliminar as variáveis temporárias e reaproveitar
as mesmas variáveis para realizar o decremento em 1. A condição da linha *5* nunca será satisfeita, pois o valor de `t1` sempre será 1.

Código intermediário otimizado:

```assembly
    1 MOV a p
    2 JGT 0 a 17
    3 MOV t5 1 
    4 SUB f f t5
    5 SUB a a 1 
    6 JMP 3
    7 MOV p f 
```
3.  Indique qual o numero de registradores necessários para calcular as expressões a seguir. Lembrando que você precisa passar as instruções 
abaixo para a codificação de três endereços. (utilizem quantos registradores forem necessários)

- a) (a+b)*(c-d)

É possível calcular as expressões com **2** registradores auxiliares.

```assembly 
    ADD t1 a b
    SUB t2 c d
    MUL t1 t1 t2
```

- b) (a+(b-c))*((e-f)+(g-h)) 

É possível calcular as expressões com **3** registradores auxiliares.

```assembly 
    SUB t1 b c
    ADD t2 a t1
    SUB t1 e f
    SUB t3 g h
    ADD t1 t1 t3
    MUL t1 t2 t1
```

- c) ((a-b)\*(c-d)+(e-f)\*(g-h)) 

É possível calcular as expressões com **3** registradores auxiliares.

```assembly 
    SUB t1 a b
    SUB t2 c d
    MUL t1 t1 t2
    SUB t2 e f
    SUB t3 g h
    MUL t2 t2 t3
    ADD t1 t1 t2 
```

4. Refaça a questão anterior utilizando o menor número possível de registradores que você conseguir.


- a) (a+b)*(c-d)

*Não consegui utilizar menos que **2** registradores sem sobrescrever as variáveis*


- b) (a+(b-c))*((e-f)+(g-h)) 

É possível calcular as expressões com  apenas **2** registradores auxiliares, pois a soma e subtração são operações comutativas.

```assembly 
    SUB t1 b c
    ADD t1 a t1
    SUB t2 e f
    ADD t2 t2 g
    SUB t2 t2 h
    MUL t1 t2 t1
```


- c) ((a-b)\*(c-d)+(e-f)\*(g-h)) 

*Não consegui utilizar menos que **3** registradores sem sobrescrever as variáveis*
