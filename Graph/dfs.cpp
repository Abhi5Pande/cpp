#include<iostream>
#include<list>
using namespace std;

class Graph{
int V;
list<int> *l;
public:
Graph(int v)
{
    V = v;
    l = new list<int>[v];
}
void addEdge(int i , int j , bool undir = true)
{
    l[i].push_back(j);
    if(undir = true)
    {
            l[j].push_back(i);
    }
}
void printGraph(){
    for(int i=0;i<V;i++)
    {
        cout<<i<<"-->";
        for(auto x:l[i])
        {
            cout<<x<<", ";
        }
        cout<<endl;
    }
}
void dfshelper(int source , bool visited[])
{
    if(visited[source] == 0)
    {
        cout<<source;
        visited[source] = true;
        for(auto x:l[source])
        {
            dfshelper(x,visited);
        }
    }
}
void dfs(int source)
{
    bool visited[V]{0};
    dfshelper(source,visited);
}

};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.printGraph();
    g.dfs(0);
    return 0;
}