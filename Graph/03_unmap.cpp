#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph{
 
   unordered_map<int , list<int>> l;
   public:
       
       void addEdge(int i , int j , bool undir = true)
       {
           l[i].push_back(j);
           if(undir)
           {
               l[j].push_back(i);
           }
      }
       void printAdjList(){
          for(auto x : l)
          {
              cout<<x.first<<"-->";
                for(auto nbr : x.second)
                {
                    cout<<nbr<<", ";
                }
                cout<<endl;
          }
      }
};
using namespace std;
int main(){
    Graph g;
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(100,2);
    g.printAdjList();
    return 0;
}