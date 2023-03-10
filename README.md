  # grafos-implementations
  
  
  Aluno: Rafael Ribeiro Lima Carleial
  
  Professor: Rian Gabriel Pinheiro
  
  
  Foram implementados os seguintes algoritmos:

  - Dijkstra
  - Floyd Warshall
  - Prim
  - Bellman-Ford

  Como existem várias implementações que se encaixam melhor dependendo da situação, eu resolvi implementar as que eu achei mais conveniente.

  O algoritmo de Dijkstra foi implementado para grafos não direcionados mas pode ser facilmente mudado para grafos direcionados apenas apagando a linha comentada. Também pode ser encontrado na pasta uma entrada de grafo sem pesos.

  O algoritmo de Bellman-Ford foi implementado para grafos direcionados, tendo na própria pasta um arquivo de entradas com pesos negativos.

  O de Floyd_Warshall foi implementado para grafos não direcionados mas pode ser facilmente mudado para grafos direcionados apenas apagando a linha comentada.

  Como executar os códigos:

  Os algoritmos de Dijkstra, Bellman-Ford e Prim possuem funcionamento semelhante ao do exemplo da lista.
  
  
<br>

```
cd (pasta do algoritmo)
```

<br>

### Ex Dijkstra:


  Isso vai printar a distância mínima do vértice 1 até o 3:
  
```
make
```
```
./dijkstra -i 1 -l 3 < entrada.dat
```

  ou então para obter todas as distâncias iniciando do vértice 1:
  
```
./dijkstra -i 1 < entrada.dat
```


### Ex Floyd-warshall:


  Printa matriz com as distâncias:
```
make
```
```
./floyd_warshall < entrada.dat
```


### Ex Bellman-Ford:


```
make
```
  Isso vai printar a distancia minima do vértice 1 até o 3:
  
```
./bellman_ford -i 1 -l 3 < entrada.dat
```
  


  ou então para obter todas as distancias iniciando do vértice 1:

```
./bellman_ford -i 1 < entrada.dat
```



### Ex prim:


  Para obter a mst:

```
make
```
```
./prim -i 1 < entrada1.dat
```
  


  Para obter o custo da mst iniciando do vértice 1 :
```
./prim -s -i 1 < entrada1.dat
```

