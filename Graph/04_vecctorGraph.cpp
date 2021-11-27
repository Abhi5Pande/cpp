#include<iostream>
#include<vector>
using namespace std;

class Graph{
    public:
    int V;
    vector<vector<int>> vect;
    Graph(int v)
    {
        V = v;
        
    }
    void addEdge(int i , int j , bool undir = true)
    {
        vect[i][j] = 1;
        if(undir)
        {
            vect[j][i] = 1;
        }
    }
    void printGraph()
    {
        for(int i = 0 ; i< v ; i++)
        {
            cout<<i<<"--->";
            for(auto nbr: vect[i])
            {
                cout<<nbr<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(3,1);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.printGraph();
    return 0;
}