  Atividade 5
======
1.  Encontre gramáticas livre de contexto que gerem as linguagens [veja doc](https://github.com/anjoshigor/compilers/blob/master/assignment5/Atividade05.pdf):
    - a) 
    ```
    G = (V,T,P,S)
    V = {S,E}
    T = {a,b,c,d}
    S → add | aEdd | E 
    E → bEc | ε
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
