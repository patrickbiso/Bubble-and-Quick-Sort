# Bubble-and-Quick-Sort
Implementação dos algoritmos de ordenação Bubble Sort e Quick Sort com intuito de comparação entre eles

Relatório:

Para pode realizar a comparacao dos dois metodos, foi implementado a biblioteca time.h, utilizando marcadores de termpo
antes e depois da execucao de cada algoritmo. Como o Bubble sorte compara cada elemento com todos os outros, e os ordena no array pratos,
para conjuntos de dados tipo esse com 300.000 linhas, leva muito tempo, de exemplo na minha execucao levou cerca de 927 segundos, (15 minutos),
considerando que meu algoritmo salva um arquivo ordenado e que meu notebook nao é dos mais atuais para execuçoes longas assim (ate implementei "marcadores"
linhas dizendo quando o codigo le o arquivo e inicia cada metodo de ordenacao para saber se esta em execuçao). Entretanto, ja o Quick Sort, levando em conta todo
os mesmos parametros do Bubble como a geraçao do arquivo, leva incriveis 0.15 segundos, mostrando sua eficiencia para casos assim com seu metodo dividir para conquistar.

Consideracoes sobre os metodos:


Bubble Sort
É um método de ordenação simples, mas ineficiente para grandes volumes de dados.
Sua complexidade no pior caso é O(n^2), pois envolve comparar repetidamente elementos vizinhos e trocá-los até que estejam na ordem desejada.
O tempo de execução aumentou consideravelmente com o número de elementos no conjunto de dados.
Recomendado apenas para conjuntos pequenos ou para fins educacionais.

Quicksort:

Um dos algoritmos de ordenação mais rápidos em média, com complexidade 
𝑂(𝑛log𝑛) no melhor e caso médio.
Utiliza a estratégia de "dividir para conquistar", particionando o array em duas partes em torno de um pivô.
Comparado ao Bubble Sort, o Quicksort foi significativamente mais eficiente em termos de tempo, mesmo para conjuntos maiores.
No entanto, no pior caso (quando o pivô escolhido é o maior ou o menor elemento em cada iteração), sua complexidade é O(n^2)

Pivô

Para essa implementacao utilizei a mais comum e simples, que seria o pivo como ultimo elemento, pois seu pior caso seria para dados ordenados ou quase ordenados,
o que nao é o caso desse exercicio.

Funcionamento

O último elemento do array (ou subarray) é escolhido como o pivô.

Durante o particionamento, os elementos são comparados ao pivô:
Elementos menores ou iguais ao pivô são movidos para a esquerda.
Elementos maiores são mantidos à direita.

Após o particionamento, o pivô é colocado na sua posição correta, dividindo o array em duas partes.
O processo é então recursivamente aplicado às subpartes à esquerda e à direita do pivô.

Vantagens
Simples implementaçao e eficiente, a escolha do último elemento como pivô elimina a necessidade de cálculos ou decisões adicionais.
Requer pouca adaptação ao algoritmo básico.
Quando os dados são distribuídos de forma aleatória, essa abordagem pode funcionar bem e evitar o pior caso em muitas situações.

Outras formas de pivo seriam:

Pivô como elemento do meio:

Reduz a probabilidade de ocorrer o pior caso.
É uma escolha comum para minimizar a degradação do desempenho.

Pivô aleatório:

Escolhe um elemento aleatório como pivô.
Garante que o algoritmo funcione de forma eficiente na maioria das vezes, mesmo com dados já ordenados.

Mediana de três elementos:

Utiliza a mediana do primeiro, do último e do elemento central como pivô.
Geralmente resulta em um desempenho próximo ao ideal, evitando o pior caso.
