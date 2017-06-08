#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int b;
	int w;

	edge(int _b, int _w)
	{
		b = _b;
		w = _w;
	}
};

void dfsUtil(int vertex, vector <edge> graph[], int numNodes, int numEdges, int visited[])
{
	cout<<vertex<<" ";

	visited[vertex] = 1;	
	int adjacentLength = graph[vertex].size();

	for(int i=0; i<adjacentLength; i++)
	{
		if(!visited[graph[vertex][i].b])
			dfsUtil(graph[vertex][i].b, graph, numNodes, numEdges, visited);
	}

}

void dfs(vector <edge> graph[], int numNodes, int numEdges, int visited[])
{
	for(int i=0; i<numNodes; i++)
	{
		if(!visited[i])
			dfsUtil(i, graph, numNodes, numEdges, visited);
	}
}

int main()
{
	int numEdges = 6;
	int numNodes = 7;

	vector <edge> graph[numNodes + 1];

	int visited[numNodes];
	memset(visited, 0, sizeof(visited));
	
	graph[1].push_back(edge(2, 1)); graph[1].push_back(edge(3, 1)); 
	graph[2].push_back(edge(4, 1)); graph[2].push_back(edge(6, 1));
	graph[3].push_back(edge(7, 1));
	graph[4].push_back(edge(5, 1));

	dfs(graph, numNodes, numEdges, visited);
	
	return 0;
}
