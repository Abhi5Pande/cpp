#include<iostream>
#include<list>
using namespace std;
struct graph
{
    list<int> l;
};
void addEdge(graph g[],int source,int destination)
{
    g[source].l.push_back(destination);
    g[destination].l.push_back(source)
}
int main()
{
   graph g[6];
   addEdge(g,1,2) 
    
    return 0;
}