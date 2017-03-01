#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int b, w;
	edge(int _b, int _w)
	{
		b = _b;
		w = _w;	
	}
	
	bool operator< (const edge& x) const
	{
		return w > x.w;
	}	
};

vector <edge> graph[100];
int dist[100], visited[100], par[100];
int nodes, edges;

void dijkstra(int src)
{
	priority_queue <edge> q;
	int u, v, weight;
	
	q.push(edge(src, 0));
	
	while(!q.empty())
	{
		u = q.top().b;
		q.pop();
		visited[u] = 1;
		
		for(int i=0; i<graph[u].size(); i++)
		{
			v = graph[u][i].b;
			weight = graph[u][i].w;
			
			if(dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				par[v] = u;
			}
				
			if(!visited[v])
				q.push(edge(v, dist[v]));
		}
	}
}

void printPath(int dest)
{
	stack <int> s; int i;
	i = dest;
	s.push(i);
	while(par[i] != 0)
	{
		s.push(par[i]);
		i = par[i];
	}
				
	while(!s.empty())
	{
		cout<<s.top();
		if(s.size() != 1)
			cout<<"->";
		s.pop();
	}		
	cout<<endl;
}

int main()
{
	int src;
	nodes = 5;
	edges = 10;
	
	graph[1].push_back(edge(2, 10));
	graph[1].push_back(edge(5, 5));
	
	graph[2].push_back(edge(3, 1));
	graph[2].push_back(edge(5, 2));
	
	graph[3].push_back(edge(4, 4));
	
	graph[4].push_back(edge(3, 7));
	graph[4].push_back(edge(1, 7));
	
	graph[5].push_back(edge(2, 3));
	graph[5].push_back(edge(3, 9));
	graph[5].push_back(edge(4, 2));

	memset(visited, 0, sizeof(visited));
		
	cout<<"Enter source: ";
	cin>>src; cout<<endl;
		
	for(int i=1; i<=nodes; i++)
	{
		dist[i] = 1000;
		par[i] = 0;
	}
	
	dist[src] = 0;
			
	dijkstra(src);
	
	for(int i=1; i<=nodes; i++)
		cout<<dist[i]<<" ";

	cout<<endl;
	
	for(int i=1; i<=nodes; i++)
		cout<<par[i]<<" ";
		
	cout<<endl;	
	
	printPath(2);
		
	return 0;
}
