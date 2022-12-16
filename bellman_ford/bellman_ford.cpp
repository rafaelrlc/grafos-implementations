#include <queue>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <ostream>
using namespace std;

int INFINITO = 1e5;
vector<int> distancia;
vector<int> instrucoes(4, -1);

void bellman_ford(vector<vector<pair<int,int> > > adj, int inicial, int num_v)
{

	distancia.assign(num_v, INFINITO);
	distancia[inicial] = 0; // setar a distancia para ele mesmo
	bool negative_cycle = false;

	for (int j = 0; j <= num_v-1; j++)
	{
		for (int k = 0; k < adj[j].size(); k++)
		{
			distancia[adj[j][k].first] = min(distancia[adj[j][k].first], distancia[j] + adj[j][k].second);
		}
	}

	for (int i = 0; i < num_v; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			if (distancia[adj[i][j].first] > distancia[i] + adj[i][j].second) {
				negative_cycle = true;
				cout << "Possui um ciclo negativo" << endl;
				return;
			}		
		}
	}

	if (negative_cycle == false) cout << "Não possui um ciclo negativo" << endl;
}

void printPath(int end_v) {
	if (end_v == -1) // mostrar todas as distancias
	{
		for (int i = 1; i <= distancia.size() - 1; i++)
		{
			cout << i << ":" << distancia[i] << " " << endl;
		}
	}
	else // mostrar distância específica
	{
		cout << distancia[end_v] << endl;
	}
}

vector<int> instructions(int argc, char *argv[]){

	string initial_v_ref = "-i";
	string end_v_ref = "-l";

	if (argc != 1)
	{
		for (int i = 0; i < argc; i++)
		{
			if (argv[i] == initial_v_ref) instrucoes[0] = atoi(argv[i+1]);//setar v inicial
			else if (argv[i] == end_v_ref) instrucoes[1] = atoi(argv[i+1]); // setar v final
		}
	}
	//cout << instrucoes[0] << instrucoes[1] << endl;
	return instrucoes;
}

int main(int argc, char *argv[])
{

	instructions(argc,argv);

	if (instrucoes[0] == -1)
	{
		cout << "é necessário a entrada -i (vertice )" << endl;
		return -1;
	}

	int num_v, num_e, k; 
	int v1, v2, weight;

	cin >> num_v >> num_e;
	num_v += 1;

	vector<vector<pair<int,int> > > adj(num_v);
	
	for (int i = 0; i < num_e; i++)
	{
		weight = 1;

		cin >> v1 >> v2;
		k = cin.get();

		if (k == ' ') cin >> weight;
		
		adj[v1].push_back(pair<int,int>(v2, weight));
	}
	
	bellman_ford(adj, instrucoes[0], num_v);
	printPath(instrucoes[1]);
	
	return 0;
}

