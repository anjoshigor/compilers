Compilando o analisador léxico
===

* Tenha o Cmake instalado

```
$ cmake --version
```

* Compilando

```
$ cmake .
$ make
```

Testando o analisador léxico
===

* Caminhe até o diretório /bin/
* Rode o seguinte comando

```
$ ./lexer ../test/pascal.pp > ../test/tabela_simbolo.csv
```
A tabela de símbolos estará no arquivo de saída especificado e se houver algum erro léxico, será mostrado no console.
