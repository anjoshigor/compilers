Atividade 7
======

1. Realizar o experimento de exemplo do site [JCUP](http://www2.cs.tum.edu/projects/cup/examples.php#calc) de uma calculadora.

Para rodar, digite o seguinte no terminal:

```console
java -jar java-cup-11b.jar -interface -parser Parser calc.cup
javac -cp java-cup-11b-runtime.jar:. *.java
java -cp java-cup-11b-runtime.jar:. Main
```

Depois, insira uma expressão aritmética como a seguinte:

```console
Please type your arithmethic expression:
(15*2)-10+5;       
```

Depois, aperte `Ctrl+D` _em sistemas linux_ para simular o caractere de escape e obtenha o resultado da
avaliação da expressão:

```console
Please type your arithmethic expression:
(15*2)-10+5;       
25
```