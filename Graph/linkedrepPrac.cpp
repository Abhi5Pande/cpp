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
        l = new list<int>[V];
    }
    void addEdge(int i , int j , bool undir = true)
    {
        l[i].push_back(j);
        if(undir)
        {
            l[j].push_back(i);
        }
    }
    void printAdjList()
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<"--->";
            for(auto node:l[i] )
            {
            cout<<node<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{

}