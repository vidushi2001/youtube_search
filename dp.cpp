#include<iostream>
using namespace std;
int fibo2(int n,int* arr) 
{
    if(n == 0 || n ==1)
    {
        return 1;
    }
    if(arr[n] > 0)
    {
        return arr[n];
    }
    int output = fibo2(n-1,arr) + fibo2(n-2,arr);
    arr[n] = output;
    return output;
    }

    int fibo3(int n)
    {
        int* arr = new int[n+1];
        arr[0] = 1;
        arr[1] = 1;
        for(int i=2;i<n+1;i++)
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
        int output = arr[n];
        delete [] arr;
        return output;
    }

    int main()
    {
        int n;
        cout<<"Enter the fiboncci element to be calculated:"<<endl;
        cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++)
        {
            arr[i] = 0;
        }
        int result = fibo2(n,arr);
        cout<<result<<endl;
        return 0;
    }