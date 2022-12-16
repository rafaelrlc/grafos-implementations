#include <queue>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <ostream>
using namespace std;

vector<pair<int,int> > minST;
vector<int> instrucoes(4, -1);

void prim(vector<vector<pair<int,int> > >adj, int inicial, int num_v) 
{

	priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > prio_queue;
	vector<string> pre(num_v, "-1");
	

	vector<int> parent(num_v, 0);
	parent[inicial] = -1;

	prio_queue.push(pair<int,int>(0, inicial));

	while(!prio_queue.empty()) 
	{
		int vert = prio_queue.top().second;
		prio_queue.pop();

		if (pre[vert] != "1")
		{
		pre[vert] = "1";


		if (parent[vert] != -1){
			minST.push_back(pair<int, int>(vert, parent[vert]));
		}

		for (int i = 0; i < adj[vert].size(); i++) 
		{
			parent[adj[vert][i].first] = vert;
			prio_queue.push(pair<int, int>(adj[vert][i].second, adj[vert][i].first));
		}
		}
	}
}

void solve(vector<vector<pair<int,int> > >adj, int sol){

	if (sol == 1) // printar arvore
	{
	for (int i = 0; i < minST.size(); i++){
		cout << "("<< minST[i].first << ", " <<  minST[i].second << ") " << endl;
	}
	}
	else // printar custo da MST
	{
		int custo = 0;

		for (int i = 0; i < minST.size(); i++) 
		{
			for (int j = 0; j < adj[minST[i].first].size(); j++) {
				if (minST[i].second == adj[minST[i].first][j].first) {
					custo = custo + adj[minST[i].first][j].second;
				}
			}
		}

		cout << custo << endl;
	}
}

vector<int> instructions(int argc, char *argv[]){

	string solution_ref = "-s";
	string initial_v_ref = "-i";

  if (argc != 1) 
	{
    for(int i = 0; i < argc; i++)
		{
			if (argv[i] == initial_v_ref) instrucoes[0] = stoi(argv[i+1]);
			else if (argv[i] == solution_ref) instrucoes[1] = 1;
    }
  }
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

	for(int i = 0; i < num_e; i++) 
	{
		cin >> v1 >> v2;

		k = cin.get();
		weight = 1;
		if (k == ' ') cin >> weight; 

		adj[v1].push_back(pair<int, int>(v2, weight));
		adj[v2].push_back(pair<int, int>(v1, weight));
	}

	prim(adj, instrucoes[0], num_v);
	solve(adj, instrucoes[1]);

  return 0;
}
