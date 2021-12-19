#include<iostream>
using namespace std;

//for DFS - proceeds in only one direction
void DFS(int**edges,int n,int sv,bool*visited)
{
	cout<<sv<<endl;
	visited[sv] = true;

	for(int i=0;i<n;i++)
	{
		if(i == sv)
		{
			continue;
		}
		if(edges[sv][i] == 1)
		{
			if(visited[i])
			{
				continue;
			}
			DFS(edges,n,i,visited);

	    }
	}
}

void BFS(int** edges,int n,int sv,bool* visited)
{
	queue<int> pendingNodes;
	pendingNodes.push(sv);
	while(pendingNodes.size() != 0)
	{
		int front = pendingNodes.front();
		cout<<front<<endl;
		visited[front] = true;
		for(int i = 0;i<n;i++)
		{
			if(edges[front][i] == 1)
			{
				if(visited[front])
				{
					continue;
				}
				else
				{
					pendingNodes.push(i);
					visited[i] = true;
				}
			}
		}
	}
}

void discDFS(int** edges,int n)
{
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}

	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			DFS(edges,n,i,visited);
		}
	}

	delete [] visited;
}

void discBFS(int** edges,int n)
{
	bool visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}

	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			BFS(edges,n,i,visited);
		}
	}

	delete [] visited;
}

int main()
{
	int n;//number of vertices
	int e;//number of edges

	//taking input from the user
	cin>>n>>e;

	//creating dynamic matrix
	int** edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j] = 0;
		}
	}

	//taking in the edge input
	for(int i=0;i<e;i++)
	{
		int v1,v2;
		cin>>v1>>v2;
		edges[v1][v2] = 1;
		edges[v2][v1] = 1;
	}

	/*bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}*/

	//DFS(edges,n,0,visited);
	cout<<"DFS"<<endl;
	discDFS(edges,n);

	cout<<"BFS"<<endl;
	discBFS(edges,n);


	//free memory
	//delete [] visited;
	for(int i=0;i<n;i++)
	{
		delete [] edges[i];
	}

	return 0;
}