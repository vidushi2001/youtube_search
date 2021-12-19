#include<iostream>
#include<climits>
using namespace std;

int findMinVertex(int* weight,int* Parent,int n,bool* visited)
{
    int minVertex = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
 return minVertex;
}

void Prims(int** edges,int n)
{
    int* Parent = new int[n];
    int* weight = new int[n];
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    Parent[0] = -1;

    for(int i=0;i<n;i++)
    {
        int minVertex = findMinVertex(weight,Parent,n,visited);
        visited[minVertex] = true;
        for(int j=0;j<n;j++)
       {
         if(edges[minVertex][j] > 0 && !visited[j])

          {
            if(edges[minVertex][j]< weight[j])
            {
                weight[j] = edges[minVertex][j];
                Parent[j] = minVertex;
            }
          }
       }
    }

    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<Parent[i]<<" "<<weight[i]<<endl;
    }

    delete [] Parent;
    delete [] weight;
    delete [] visited;
}

int main()
{
    int n;
    int e;
    cin>>n>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    Prims(edges,n);
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}