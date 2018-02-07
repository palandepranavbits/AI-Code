#include<iostream>
#include<vector>

using namespace std;
#define NODES 8
vector <int> adj[100];
bool marked[100];

void initialise(){
	for (int i = 0; i < 100; i++)
	{
		/* code */
		marked[i] = false;
	}
}

void dfs(int root){
	marked[root] = true;
	cout<<root<<"  ";
	for (int i = 0; i < adj[root].size(); i++)
	{
		/* code */
		if(!marked[adj[root][i]])
			dfs(adj[root][i]);
	}
}

int main(int argc, char const *argv[])
{
	int x, y, edges;
    //cin >> nodes;       //Number of nodes
    cin >> edges;       //Number of edges
    for(int i = 0;i < edges;i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);        //Insert y in adjacency list of x
    }
    initialise();
    dfs(1);
    cout<<endl;
	return 0;
}