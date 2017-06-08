#include <iostream>
using namespace std;

struct node
{
	int id, weight;
	node* next;
};

void push(int stack[], int data, int* stackTop)
{
	*stackTop = *stackTop + 1;
	stack[*stackTop] = data;
}

int pop(int stack[], int* stackTop)
{
	int res = stack[*stackTop];
	*stackTop = *stackTop - 1;
	return res;
}

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

void topologicalSortUtil(int vertex, node* start[], node* end[], int numNodes, int numEdges, int visited[], int stack[], int* stackTop)
{
	visited[vertex] = 1;

	node* temp;	
	temp = start[vertex];

	while(temp != NULL)
	{
		if(!visited[temp->id])
			topologicalSortUtil(temp->id, start, end, numNodes, numEdges, visited, stack, stackTop);
		temp = temp->next;
	}

	push(stack, vertex, stackTop);
}

void topologicalSort(node* start[], node* end[], int numNodes, int numEdges, int visited[], int stack[], int* stackTop)
{
	for(int i=1; i<=numNodes; i++)
	{
		if(!visited[i])
			topologicalSortUtil(i, start, end, numNodes, numEdges, visited, stack, stackTop);
	}

	while(*stackTop >= 0)
	{
		cout<<pop(stack, stackTop)<<" ";
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

	int stack[100];
	int stackTop = -1;

	topologicalSort(start, end, numNodes, numEdges, visited, stack, &stackTop);

	return 0;
}
