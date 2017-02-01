Atividade 1
======
1. Criar um assembly equivalente ao programa abaixo:
---
  ```c
  x = 3;
  y = 1;

  if (x==y)
  {
  	z = 0
  } else {
  	z=x+y*5-2;
  }
  ```

  O assembly `nasm x86 Assembly` foi utilizado para traduzir o código acima e está demonstrado a seguir:

  ```assembly

  global  _start

  section .bss
  z: resw 1       ;variável z a ser inicializada durante o programa

  section .text
  _start:
   xor     edi, edi
   xor     ebx, ebx
   xor     eax, eax
   mov     eax, dword 3    ;eax == x
   mov     edi, dword 1    ;edi == y
   cmp     edi, eax        ;comparando o conteúdo dos registradores
   je      zzero           ;se forem iguais, z recebe 0
   jne     zexp            ;se não forem iguais, a expressão é avaliada

   zzero:
   mov     [z], dword 0
   jmp     exit

   zexp:
   mov     esi,5
   imul    esi,edi
   add     esi,eax
   sub     esi,2
   mov     [z], esi
   ;jmp    exit            não é necessário

   exit:
   mov     eax, 1
   mov     ebx, [z]
   int     0x80
  ```

2. Criar instruções em linguagem de máquina (microcode) tendo o assembly acima como base e utilizando uma arquitetura simples e de livre criação
---

Algumas restrições devem ser satisfeitas. São elas:

*  Apenas 3 bits devem ser usados para comandos. Totalizando 8 possíveis comandos.
*  Cada comando deve possuir apenas 1 parâmetro.
*  O apontador de instruções é incrementado automaticamente.

Satisfazendo todas as restrições, foi criada uma arquitetura bastante simples. As operações (de 3 bits) da arquitetura são descritas na tabela:

OPERAÇÃO|CÓDIGO
------|------
LOAD|000
STORE|001
CMP|010
JE|011
SUB|100
ADD|101
MUL|111

Na arquitetura criada, cada espaço de memória pode ocupar 8 bits e todas as constantes podem ocupar os 8 bits. Utilizando 1 bit como flag para diferir endereços de memória de constantes, é possível flexibilizar uma operação, dado exemplo abaixo:

`LOAD TRUE  0000 0010` //Carrega a constante **2** no acumulador

`LOAD FALSE 0000 0010` //Carrega o conteúdo do endereço de memória **0000 0001** no acumulador

Então, a configuração geral de uma operação tem a seguinte forma:
![Representação geral de uma operação](https://github.com/anjoshigor/compilers/blob/master/assignment1/images/represent.png)

**Descrição das operações:**

* **LOAD**: Carrega o conteúdo do endereço ou constante especififcada no acumulador da ULA.
* **STORE**: Armazena o conteúdo do acumulador na endereço de memória especificado.
* **CMP**: Compara o que existe no acumulador com o especificado e armazena o resultado no acumulador. *(0 para igual | 1 para diferente)*
* **JE**: Verifica o valor armazenado no acumulador. Se o valor presente for **0**, o contador de programa aponta para a linha especificado.
* **SUB**: Subtrai o que está no acumulador com o operando e armazena o valor no acumulador.
* **ADD**: Adiciona o que está no acumulador com o operando e armazena o valor no acumulador.
* **MUL**: Multiplica o que está no acumulador com o operando e armazena o valor no acumulador.

As variáveis do programa foram consideradas já inicializadas e estão presentes na memória e ocupam os endereços a seguir:

VARIÁVEL|ENDEREÇO
-----|-----
x|0000 0001
y|0000 0010
z|0000 0011
