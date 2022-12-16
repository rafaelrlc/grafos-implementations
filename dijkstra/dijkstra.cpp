#include <queue>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <ostream>
using namespace std;
const int INFINITO = 1e5;

vector<int> distancia;
vector<int> instrucoes(4, -1);

void dijkstra(vector<vector<pair<int,int> > > adj, int inicial, int num_v)
{

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > prio_queue;
	vector<string> pre(num_v, "-1");
	
	distancia.assign(num_v, INFINITO); // -1 representa o infinito neste caso.
	distancia[inicial] = 0; // setar a distancia para ele mesmo

	pair<int, int> v_adj;
	prio_queue.push(pair<int, int>(distancia[inicial], inicial));
	
	while(!prio_queue.empty())
	{
		int vert = prio_queue.top().second; 
		prio_queue.pop();

		//cout << "Valor de V:" << vert << endl;
		if (pre[vert] != "1") //se não foi visitado
		{
			pre[vert] = "1";
			for (int i = 0; i < adj[vert].size(); i++)
			{
				v_adj = adj[vert][i];
				int vert_adj = v_adj.first;
				int vert_adj_w = v_adj.second;

				if (distancia[vert_adj] > distancia[vert] + vert_adj_w)
				{
					distancia[vert_adj] = distancia[vert] + vert_adj_w;
					prio_queue.push(pair<int, int>(distancia[vert_adj], vert_adj));
				}
			}
		}
	}
}

void printDist(int end_v){

	if (end_v == -1) // mostrar todas as distancias
	{
		for (int i = 1; i <= distancia.size() - 1; i++) {
			cout << i << ":" << distancia[i] << " " << endl;
		}
	}
	else // mostrar distância específica
	{
		cout << distancia[end_v] << "\n";
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

	instrucoes = instructions(argc, argv);

	if (instrucoes[0] == -1)
	{
		cout << "é necessário a entrada -i (vertice inicial)" << endl;
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
		adj[v2].push_back(pair<int,int>(v1, weight)); //apagando esta linha o grafo se torna direcionado
	}
	
	dijkstra(adj, instrucoes[0], num_v);
	printDist(instrucoes[1]);

	return 0;
}
