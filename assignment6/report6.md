Eliminando recursões à esquerda e ambiguidade
====

As recursões à esquerda foram eliminadas seguindo o modelo abaixo:

>A →  Aα| β 
>
>A → βA'
>
>A'→ αA' | ε

As ambiguidades foream eiminadas seguindo o modelo abaixo:

>A → A | Aα
>
>A → A A_x
>
>A_x→ α | ε



```
programa →
	program id;
	declarações_variáveis
	declarações_de_subprogramas
	comando_composto
	.
```

```
declarações_variáveis →
	var lista_declarações_variáveis | ε
```

```
lista_declarações_variáveis →
	lista_de_identificadores: tipo; lista_declarações_variáveis'

lista_declarações_variáveis' → 
	lista_de_identificadores: tipo; lista_declarações_variáveis'
	| ε
```

```
lista_de_identificadores →
	id lista_de_identificadores'
 
lista_de_identificadores' →
	, id lista_de_identificadores'
	| ε
```

```
tipo →
	integer | real | boolean
```

```
declarações_de_subprogramas →
	declaração_de_subprograma; declarações_de_subprogramas
	| ε
```

```
declaração_de_subprograma →
	procedure id argumentos;
 	declarações_variáveis
 	declarações_de_subprogramas
 	comando_composto
```

```
argumentos →
	(lista_de_parametros)
	| ε
```

```
lista_de_parametros →
	lista_de_identificadores: tipo lista_de_parametros'

lista_de_parametros' →
	; lista_de_identificadores: tipo lista_de_parametros'
	| ε
```
```
comando_composto →
	begin
	comandos_opcionais
	end
```

```
comandos_opcionais →
	lista_de_comandos
	| ε
```

```
lista_de_comandos →
	comando lista_de_comandos'

lista_de_comandos' →
	; comando lista_de_comandos'
	| ε
```

```
comando →
	variável := expressão
	| ativação_de_procedimento
	| comando_composto
	| if expressão then comando parte_else
	| while expressão do comando
```

```
parte_else →
	else comando
 	| ε
```

```
variável →
	id
```

```
ativação_de_procedimento →
	id x
	
ativação_de_procedimento_x →
	(lista_de_expressões) | ε

```

```
lista_de_expressões →
	expressão lista_de_expressões'

lista_de_expressões' →
	, expressão lista_de_expressões'
	| ε
```

```
expressão →
	expressão_simples expressão_x

expressão_x → 
	op_relacional expressão_simples
	| ε
```

```
expressão_simples →
	termo expressão_simples'
	| sinal termo expressão_simples'

expressão_simples' →
	op_aditivo termo expressão_simples'
	| ε
```

```
termo →
	fator termo'

termo' →
	op_multiplicativo fator termo'
	| ε
```

```
fator →
	id fator_x
	| num_int
	| num_real
	| true
	| false
	| (expressão)
	| not fator

fator_x →
	(lista_de_expressões)
	| ε
```

```
sinal →
	+ | -
```

```
op_relacional →
	= | < | > | <= | >= |<>
```

```
op_aditivo →
	+ | - | or
```

```
op_multiplicativo →
	* | / | and
```
