#include<iostream>
using namespace std;

int min_cost(int** arr,int m,int n)
{
    int**output = new int*[m];
    for(int i=0;i<m;i++)
    {
        output[i] = new int[n];
    }
    output[m-1][n-1] = arr[m-1][n-1];
    //filling the last column
    for(int i = m-1;i>=0;i--)
    {
        output[i][n-1] = arr[i+1][n-1] + arr[i][n-1];
    }

    //filling the last row
    for(int j = n-1;j>=0;j--)
    {
        output[m-1][j] = arr[m-1][j+1] + arr[m-1][j];
    }

    //filling the rest of the matrix
    for(int i = m-1;i>=0;i--)
    {
        for(int j = n-1;j>=0;j--)
        {
            output[i][j] = arr[i][j] + min(output[i][j+1],min(output[i+1][j],output[i+1][j+1]));
        }
    }

    int ans = output[0][0];
    for(int i=0;i<m;i++)
    {
        delete [] output[i];
    }
    delete [] output;
    return ans;
}

int main()
{
    int** arr = new int*[3];
    for(int i = 0;i<3;i++)
    {
        arr[i] = new int[3];
    }
    arr[0][0] = 4;
    arr[0][1] = 3;
    arr[0][2] = 2;
    arr[1][0] = 1;
    arr[1][1] = 8;
    arr[1][2] = 3;
    arr[2][0] = 1;
    arr[2][1] = 1;
    arr[2][2] = 8;

    delete [] arr[0];
    delete [] arr[1];
    delete [] arr[2];
    delete [] arr;

}