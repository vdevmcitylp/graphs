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
int dist[100], visited[100], par[100], heu[100];
int nodes, edges;

void initialize(int src)
{
	for(int i=1; i<=nodes; i++)
	{
		dist[i] = 1000;
		par[i] = 0;
	}
	
	dist[src] = 0;
}

void relax(int u, int v, int weight)
{
	if(dist[v] > dist[u] + weight)
	{
		dist[v] = dist[u] + weight;
		par[v] = u;
	}
}

//The A* Search algorithm

void astar(int src, int dest)
{
	priority_queue <edge> q;
	
	int u, v, weight;
	
	initialize(src);
	
	q.push(edge(src, heu[src]));
	
	while(!q.empty())
	{
		u = q.top().b;
		q.pop();
		visited[u] = 1;
		
		if(u == dest)
			break;
		
		for(int i=0; i<graph[u].size(); i++)
		{
			v = graph[u][i].b;
			weight = graph[u][i].w;
			
			relax(u, v, weight);
				
			if(!visited[v])
				q.push(edge(v, dist[v] + heu[v]));
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
	int src, dest;
	nodes = 8;
	edges = 12;
	
	graph[1].push_back(edge(2, 6));
	graph[1].push_back(edge(3, 2));
	graph[1].push_back(edge(4, 1));
		
	graph[2].push_back(edge(8, 10));
	graph[2].push_back(edge(5, 3));
	
	graph[3].push_back(edge(5, 2));
	graph[3].push_back(edge(6, 6));
	
	graph[4].push_back(edge(3, 3));
	graph[4].push_back(edge(7, 4));
	
	graph[5].push_back(edge(7, 5));
	
	graph[6].push_back(edge(8, 2));
	
	graph[7].push_back(edge(8, 1));

	heu[1] = 6; heu[2] = 8; heu[3] = 6; heu[4] = 5;
	heu[5] = 4; heu[6] = 2; heu[7] = 1; heu[8] = 0;
	
	memset(visited, 0, sizeof(visited));
		
	cout<<"Enter source: ";
	cin>>src;
		
	cout<<"Enter destination: ";
	cin>>dest; 
			
	astar(src, dest);	
	
	cout<<"Cost: "<<dist[dest]<<endl;
	printPath(dest);
		
	return 0;
}
