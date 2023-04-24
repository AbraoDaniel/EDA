# Trabalho 2: Implementando BFS com uma Fila

Grafos são estruturas matemáticas utilizadas para modelar problemas em
diversas áreas. Na Ciência da Computação, são aplicados em diversos problemas nas
áreas de redes de computadores, mídias sociais, organização de informação, modelagem
de circuitos, entre outras aplicações.


Grafos são definidos na forma G(V, A), onde V é um conjunto não vazio de
vértices (ou nós) e A é um conjunto de arestas. Uma aresta representa a conexão entre
dois vértices. A figura a seguir apresenta um exemplo de grafo com 8 vértices.

![image](https://user-images.githubusercontent.com/50593898/234118686-d5803c8b-73e4-4abd-aa52-329fb43127fd.png)


O objetivo deste trabalho é implementar o algoritmo BFS (Breadth-first Search)
ou Busca em Largura em um grafo. Ele se inicia em algum vértice arbitrário do grafo e
explora todos os vértices vizinhos (no mesmo nível), antes de se mover para os vértices
no próximo nível de profundidade. Para isso, a implementação desse algoritmo utiliza
uma fila.


O objetivo do algoritmo neste trabalho é implementar a busca no grafo, dados o
vértice inicial A e o vértice final B. O algoritmo começa em A e faz a busca em largura
até encontrar B. Uma aplicação desse tipo de algoritmo é que ele permite encontrar o
menor caminho entre A e B, em termos de número de arestas percorridas. Nesse
sentido, após a aplicação da busca, a saída deve ser a sequência de vértices visitados
entre A e B.


## Implementação


Um grafo pode ser representado por uma matriz de adjacência, na qual cada
linha representa um vértice e cada vértice adjacente a ele (coluna) possui valor 1, ou 0
para os que não são adjacentes (adjacente aqui signica estar conectado). Por exemplo,
considere o grafo a seguir e sua respectiva matriz de adjacência:


![image](https://user-images.githubusercontent.com/50593898/234118816-7f9a111f-5569-4b25-aa72-e803c91898b7.png)


Repare que, para o usuário, os vértices são numerados a partir de 1, enquanto
que na linguagem C, os índices na matriz começam em 0.
As seguintes estruturas são necessárias para o algorirmo:
1. Matriz de adjacência: alocada dinamicamante, conforme entrada do usuário;
2. Vetor de status dos vértices: também alocado dinamicamente; indica se cada vértice
foi visitado (1), ou se ainda não foi (0);
3. Vetor com o antecessor de cada vértice: semelhante ao vetor de status, mas serve
para registrar qual é o antecessor de cada vértice visitado. Serve para determinar o
caminho entre A e B;
4. Fila de inteiros: bilioteca de filas (vetor dinâmico);
5. Pilha de inteiros: bilioteca de pilhas (vetor dinâmico), usada para mostrar o caminho
percorrido (após a busca, é preciso fazer o percurso na ordem invertida).

### O algoritmo é implementado conforme o seguinte pseudocódigo:

![image](https://user-images.githubusercontent.com/50593898/234118957-32ef4720-1506-4d33-a840-3e94ee3386c5.png)
![image](https://user-images.githubusercontent.com/50593898/234119012-b2d8e64f-4310-40c9-b598-629de05c05d3.png)



## Entrada
A primeira linha da entrada contém um inteiro N, que representa o número de
vértices do grafo. A matriz de adjacência terá, portanto, dimensão N. Em seguida, são
lidas cada uma das N linhas da matriz de adjacência. Finalmente, temos como entrada o
vértices A (inicial) e B (final).

## Saída
A lista de vértices visitados, um em cada linha


![image](https://user-images.githubusercontent.com/50593898/234119133-2ccac135-3dd5-4a32-8b5f-71f0acfbc73e.png)
