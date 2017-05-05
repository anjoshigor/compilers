Atividade 10
----

## Medição do gasto energético de software

O artigo trata do desenvolvimento de métricas genéricas para se calcular o gasto energético de softwares.
Com o uso elevado de energia elétrica, o campo denominado de *Green IT* vem trazendo novos padrões para a
área de tecnologia e desenvolvimento de software. Primeiramente, preocupava-se apenas com hardwares e uma boa
forma de se ter sistemas efientes em termos de energia focado nisso, mas o artigo traz metodologias para medir
o consumo de energia exclusivamente do software.

Atualmente já existem métricas de consumo de energia de softwares como os métodos de *Benchmarking*. Esses
métodos são capazes de medir o sistema como um todo e não apenas o software como uma caixa preta aplicando testes
de bancos de dados, rede ou gráficos. Isso além de ser algo exclusivo para certos grupos de softwares, impede que 
possa ser visto internamente e impossibilita dizer qual parte específica do software rem potencial para economizar
energia. A técnica abordada no artigo baseia-se na instrumentação de código fonte - muito utilizada em ferramentas
de *code profiling*.

O artigo traz uma aplicação do método sugerido com algoritmos de ordenação. No teste, um conjunto de valores é ordenado
utilizando os algoritmos *Bubble Sort* e *Heap Sort*. Como resultado, foi visto que o *Bubble Sort* consumiu um total de **10.800J** 
para ordenar **200.000** itens, enquanto o *Heap Sort* consumiu **7.325J** para ordenar os mesmos **200.000** itens. Isso
mostra que a complexidade de um algortimo está diretamente relacionada com o seu consumo energético.