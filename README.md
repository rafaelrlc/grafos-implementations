# grafos-implementations

Foram implementados os seguintes algoritmos:

- Dijkstra
- Floyd Warshall
- Prim
- Bellman-Ford

Como existem várias implementações que se encaixam melhor dependendo da situação, eu resolvi implementar as que eu achei mais conveniente.

O algoritmo de Dijkstra foi implementado para grafos não direcionados mas pode ser facilmente mudado para grafos direcionados apenas apagando a linha comentada. Também pode ser encontrado na pasta a entrada do grafo sem pesos.

O algoritmo de Bellman-Ford foi implementado para grafos direcionados, tendo na própria pasta do arquivo entradas com pesos negativos.

O de Floyd_Warshall foi implementado para grafos não direcionados mas pode ser facilmente mudado para grafos direcionados apenas apagando a linha comentada.

Como executar os códigos:

Os algoritmos de Dijkstra, Bellman-Ford e Prim possuem funcionamento semelhante ao do exemplo da lista.

Ex dijkstra:



make dijkstra ou apenas 'make'
./dijkstra -i 1 -l 3 < entrada.dat

Isso vai printar a distância mínima do vértice 1 até o 3.



ou então para obter todas as distâncias:

make dijkstra ou apenas 'make'

./dijkstra -i 1 < entrada.dat



Ex floyd-warshall:

make floyd_warshall ou apenas 'make'

./floyd_warshall < entrada.dat



Ex bellman-ford:

make bellman_ford ou apenas 'make'

./bellman_ford -i 1 -l 3 < entrada.dat

Isso vai printar a distancia minima do vértice 1 até o 3.



ou então para obter todas as distancias:

make bellman_ford (ou apenas 'make')

./bellman_ford -i 1 < entrada.dat




Ex prim:

Para obter a mst:

make prim ou apenas (ou apenas 'make')

./prim -s -i 1 < entrada1.dat



Para obter o custo da mst:

./prim -s -i 1 < entrada1.dat
