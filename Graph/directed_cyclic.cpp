#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph
{
    int V;
    list<int>* l;
public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int source, int destination)
    {
        l[source].push_back(destination);
    }
    bool dfs(int node, vector<bool>& visited, vector<bool>& stack)
    {
        visited[node] = true;
        stack[node] = true;
        for (auto nbr : l[node])
        {
            if (stack[nbr] == true)
                return true;
            else if (visited[nbr] == false)
            {
                bool cycleAtChild = dfs(nbr, visited, stack);
                if (cycleAtChild)
                    return true;
            }
        }

        stack[node] = false;
        return false;
    }
    bool check_cycle()
    {
        vector<bool> visited(V, false);
        vector<bool> stack(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, stack))
                    return true;
            }
        }
        return false;
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " --> ";
            for (auto x : l[i])
                cout << x << " ";
            cout << endl;
        }

    }
};
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(0, 5);
    g.addEdge(5, 4);
    cout << "Answer is " << g.check_cycle()<<endl;
    g.printAdjList();
}