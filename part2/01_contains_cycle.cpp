#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
int V;
list<int> *l;
public:
Graph(int v)
{
    V = v;
    l = new list<int>[V];
}
void addEdge(int source , int destination , bool undir = true)
{
    l[source].push_back(destination);
    if(undir)
        l[destination].push_back(source);
}
void dfsHelper(int node , vector<bool> visited)
{
    visited[node] = true;
    cout<<node<<"--->";
    for(auto nbr: l[node])
    {
        if(!visited[nbr])
        {
            return dfsHelper(nbr,visited);
        }
    }
    cout<<endl;
}
void dfs(int start)
{
    vector<bool> visited(V,false);
    dfsHelper(start,visited);
}
 void bfs(int source, int dest = -1)
        {
            queue<int> q;
            bool *visited = new bool[V]{0};
              int *dist = new int[V]{0};
            int *parent = new int[V];
            for(int i = 0 ; i< V ; i++)
                parent[i] = -1;
            q.push(source);
            visited[source] = true;

            while(!q.empty()){
               int f = q.front();
                cout<<f<< " ";
                q.pop();
                for(auto nbr: l[f])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        parent[nbr] = f;
                        dist[nbr] = dist[f]+1;
                        visited[nbr] = true ;
                    }
                  
                }
               
            }
            cout<<endl;
             for(int i = 0; i < V; i++)
                {
                    cout<<i<< " is at the distance of "<<dist[i]<<endl;
                }
            cout<<endl;
            if(dest != -1)
            {
                int temp = dest;
                while(temp != source)
                {
                    cout<<temp<<"---";
                    temp = parent[temp];
                }
                cout<<source;
            }

        }
void printAdjList()
{
    for(int i = 0; i < V; i++)
    {
        cout<<i<<" --> ";
        for(auto nbr: l[i])
        {
            cout<<nbr<<", ";
        }
        cout<<endl;
    }
}
};
int main()
{
    Graph G(5);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(2,3);
    G.addEdge(3,4);
    G.printAdjList();
    G.dfs(0);
    G.dfs(1);
    G.bfs(2);
}
