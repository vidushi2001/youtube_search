#include<iostream>
using namespace std;
int MaxBST(int n)
{
    int* arr = new int[n+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i = 2;i<n+1;i++)
    {
        arr[i] = 1+ arr[i-1];
    }
    int ans = arr[n];
    delete [] arr;
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number of nodes for which Maximum number of binary trees is to be calculted:"<<endl;
    cin>>n;
    int result = MaxBST(n);
    cout<<"Maximum Number of Binary Search Trees are: "<<result<<endl;
    return 0;
}