#include <iostream>
using namespace std;

struct node
{
	int id, weight;
	node* next;
};

void createNode(int a, int b, int w, node* start[], node* end[])
{
	node* temp = new node;
	temp->id = b;
	temp->weight = w;
	temp->next = NULL;

	if(start[a] == NULL)
	{
		start[a] = temp;
		end[a] = temp;
	}
	else
	{
		end[a]->next = temp;
		end[a] = temp;
	}
}

void dfsUtil(int vertex, node* start[], node* end[], int numNodes, int numEdges, int visited[])
{
	cout<<vertex<<" ";
	visited[vertex] = 1;

	node* temp;	
	temp = start[vertex];

	while(temp != NULL)
	{
		if(!visited[temp->id])
			dfsUtil(temp->id, start, end, numNodes, numEdges, visited);
		temp = temp->next;
	}
}

void dfs(node* start[], node* end[], int numNodes, int numEdges, int visited[])
{
	for(int i=1; i<=numNodes; i++)
	{
		if(!visited[i])
			dfsUtil(i, start, end, numNodes, numEdges, visited);
	}
}

int main()
{
	int numNodes, numEdges;

	cin>>numNodes>>numEdges;

	node* start[numNodes + 1];
	node* end[numNodes + 1];

	for(int i=0; i<numNodes+1; i++)
	{
		start[i] = NULL;
		end[i] = NULL;
	}

	int visited[numNodes+1];
	for(int i=0; i<numNodes+1; i++)
		visited[i] = 0;

	int a, b, w;

	for(int i=0; i<numEdges; i++)
	{
		cin>>a>>b>>w;
		createNode(a, b, w, start, end);
	}		

	dfs(start, end, numNodes, numEdges, visited);

	return 0;
}
