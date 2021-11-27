#include<stack>
#include<iostream>
#include<list>
#include<queue>
#include <typeinfo>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int v){
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
        void printAdjList(){
            for(int i=0;i<V;i++)
            {
                cout<<i<<"--->";
                for(auto node:l[i])
                {
                    cout<<node<<" ";
                }
                cout<<endl;
                
            }
            // cout<<typeid(l[2][1]).name()<<endl;
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
        void DFS(int source )
        {
            stack<int> s;
            bool visited[V]{0};
          
            s.push(source);
            visited[source] = true;
            while(!s.empty())
            {
                int f = s.top();
                cout<<f<<" ";
                s.pop();
                for(auto nbr : l[f])
                {
                    if(!visited[nbr])
                    {
                        s.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
        }
};

int main(){
    // cout<<"Hello World";
    // Graph g(6);
    // g.addEdge(0,1);   
    // g.addEdge(0,4);
    // g.addEdge(2,1);
    // g.addEdge(3,4);
    // g.addEdge(4,5);
    // g.addEdge(2,3);
    // g.addEdge(3,5);
    // g.printAdjList();
    Graph g2(7);
    g2.addEdge(0,1);   
    g2.addEdge(0,4);
    g2.addEdge(2,1);
    g2.addEdge(3,4);
    g2.addEdge(4,5);
    g2.addEdge(2,3);
    g2.addEdge(3,5);
    g2.addEdge(6,5);
    g2.bfs(1,6);
   
   
}