#include<iostream>
#include<list>
#include<vector>
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
      bool dfs(int node, vector<bool> visited , int parent){
          visited[node] = true;
          for(auto nbr: l[node])
          {
              if(!visited[nbr])
              {
                  bool cycleAtNbr = dfs(nbr,visited,node);
                  if(cycleAtNbr)
                  {
                      return true;
                  }
              }
              else if(nbr != parent)
                    return true;       
          }
          return false;
      }
      bool contains_cycle(){
          vector<bool> visited(V,false);
          return dfs(0,visited,-1);
      }
       void printAdjList(){
           for(int i=0;i<V;i++)
           {
               cout<<i<<"--->";
               for(auto node:l[i])
               {
                   cout<<node<<' ';
               }
              cout<<endl;
          }
      }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.printAdjList();
    cout<<g.contains_cycle()<<endl;
}