  Atividade 5
======
1.  Encontre gramáticas livre de contexto que gerem as linguagens [veja doc](https://github.com/anjoshigor/compilers/blob/master/assignment5/Atividade05.pdf):
    - a) 
    ```
    G = (V,T,P,S)
    V = {S,E}
    T = {a,b,c,d}
    S → aSdd | E 
    E → bc | bEc
    ```
    - b) 
    ```
    G = (V,T,P,S)
    V = {S,E,X}
    T = {a,b}
    S → aEb | X | ε
    E → aEbb | b
    X → aXbb | abb
    ```
     - c) 
    ```
    G = (V,T,P,S)
    V = {S,E}
    T = {0,1}
    S → 0E0 | 1E1
    E → 0E | 1E | ε
    ```
      - d) 
    ```
    G = (V,T,P,S)
    V = {S,E}
    T = {0,1}
    S → 0E | 1E
    E → 0S | 1S | ε
    ```
      - e) 
    ```
    G = (V,T,P,S)
    V = {S}
    T = {0,1}
    S → 0S1 | 1S0 | 0S0 | 1S1 | 0
    ```
2.  Explique porque a gramática abaixo é ambígua [veja doc](https://github.com/anjoshigor/compilers/blob/master/assignment5/Atividade05.pdf):

      - A gramática é ambígua por produzir a mesma cadeia de caracteres com derivações diferentes, veja um exemplo de produção da cadeia **00110011**
      
| # passo | Derivação 1        | Derivação 2 |
|:---:|:------------- |:-------------|
|1| 0A           | 0A          |
|2| 00AA         | 00AA        |
|3| 001S0AA      | 0011S       |
|4| 0011B0AA     | 00110A      |
|5| 001100AA     | 001100AA    |
|6| 0011001A     | 0011001A    |
|7| **00110011** |**00110011** |

3.  Dada a seguinte gramática livre de contexto ambígua, faça o que se pede [veja doc](https://github.com/anjoshigor/compilers/blob/master/assignment5/Atividade05.pdf):

    - a) Encontre uma string *s* gerada pela gramática que tem duas derivações mais à esquerda. Mostre as derivações.
      
| # passo | Derivação 1        | Derivação 2 |
|:---:|:------------- |:-------------|
|1| Ab           | aaB          |
|2| Aab         | **aab**        |
|3| **aab** |-|
