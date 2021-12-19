#include<iostream>
#include<climits>
using namespace std;

int findMinDistance(int* distance,int n,bool* visited)
{
    int minVertex = -1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (minVertex == -1 || distance[i]<distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void Dijkstra(int** edge,int n)
{
    bool* visited = new bool[n];
    int* distance = new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
        distance[i] = INT16_MAX;
    }
    distance[0] = 0;
    for(int i=0;i<n-1;i++)
    {
        int minVertex = findMinDistance(distance,n,visited);
        visited[minVertex] = true;
        for(int j=0;j<n;j++)
        {
            if(edge[minVertex][j] != 0 && !visited[j])
            {
                int curr_dist = distance[minVertex] + edge[minVertex][j];
                if(curr_dist<distance[j])
                {
                    distance[j] = curr_dist;
                }
            }
        }

    }

    //print
    for(int i=0;i<n;i++)
    {
        cout<<"Vertex:"<<i<<" "<<"Distance:"<<distance[i]<<endl;
    }

    delete [] visited;
    delete [] distance;
}

int main()
{
    int n,e;
    cin>>n>>e;
    int** edge = new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i] = new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            edge[i][j] = 0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int s,f,w;
        cin>>s>>f>>w;
        edge[s][f] = w;
        edge[f][s] = w;
    }

    Dijkstra(edge,n);

    //releasing memory
    for(int i=0;i<n;i++)
    {
        delete [] edge[i];

    }
    delete [] edge;
    return 0;
}