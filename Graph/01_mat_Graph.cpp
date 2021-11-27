#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
	int V;
	int * l;
public:
	Graph(int v)
	{
		V = v;
		l = new int[V*V]{0};
	}
	void addEdge(int i, int j, bool undir = true)
	{
		*(l+ V*i + j) = 1;
		if (undir)
		{
			*(l + V*j + i) = 1;
		}
	}
	void printMat()
	{
		cout << " ";
		for (int i = 0; i < V; i++)
			cout << " " << i;
		cout<<endl;
		for (int i = 0; i < V; i++)
		{
			cout << i << " ";
			for (int j = 0; j < V; j++)
			{
				cout << *(l+V*i+j) << " ";
			}
			cout << endl;
		}
	}
	void BFS(int source)
	{
		queue<int> q;
		bool *visited = new bool[V]{0};
		q.push(source);
		visited[source] = 1;
		while(!q.empty())
		{
			int f = q.front();
			cout<<f<<" ";
			q.pop();
			for(int i = 0; i <V ; i++)
			{
				if(*(l + f*V + i) == 1)
				{
					if(!visited[i])
					{
						q.push(i);
						visited[i] = 1;

					}
				}
			}
		}
	}
};

int main()
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	g.printMat();
	g.BFS(1);
}