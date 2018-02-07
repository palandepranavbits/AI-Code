#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define NODES 8
vector <int> adj[100];
queue <int> q;

void bfs(int root){
	q.push(root);
	while(!q.empty()){
		cout<<q.front()<<" ";
		for (int i = 0; i < adj[q.front()].size(); i++)
		{
			/* code */
			q.push(adj[q.front()][i]);
		}
		q.pop();
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
    bfs(1);
    cout<<endl;
	return 0;
}