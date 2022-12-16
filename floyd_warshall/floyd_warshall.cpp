#include <queue>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <ostream>
using namespace std;
const int INFINITO = 1e5;


void floyd_warshall(vector<vector<int> > &adj, int num_v)
{
  for (int i = 0; i < num_v; i++) 
  {
    for (int j = 0; j < num_v; j++) {
      for (int k = 0; k < num_v; k++) {
        if (adj[j][i] < INFINITO && adj[i][k] < INFINITO) {
          adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
        }
      }
    }
  }
}

void printDist(vector<vector<int> > &adj, int num_v){
  for (int i = 0; i < num_v; i++) 
  {
    for (int j = 0; j < num_v; j++) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int num_v, num_e;
  int v1, v2, weight,k;
  cin >> num_v >> num_e;
  vector<vector<int> > adjMatriz(num_v, vector<int>(num_v, INFINITO));

  for (int i = 0; i < num_e; i++) {
    weight = 1;
    cin >> v1 >> v2;
    v1--;
    v2--;
    k = cin.get();
    if (k == ' ') cin >> weight;

    adjMatriz[v1][v2] = weight;
    adjMatriz[v2][v1] = weight; //apagando esta linha o grafo se torna direcionado
  }

  for (int i = 0; i < num_v; i++) 
  {
    adjMatriz[i][i] = 0; //setar distancia para ele mesmo para 0
  }

  floyd_warshall(adjMatriz, num_v);
  printDist(adjMatriz, num_v);

  return 0;
}