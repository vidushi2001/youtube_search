/*Question Description --> Given an array,find the largest sum of a contigous sub array*/
//approach - kadane's algorithm

#include<iostream>
using namespace std;
int Kadane(int arr[],int size)
{
    int current_max = 0;
    int best_so_far = 0;
    for(int i=0;i<size;i++)
    {
        current_max+=arr[i];
        if(current_max < 0)
        {
            current_max = 0;
        }
        if(best_so_far < current_max)
        {
            best_so_far = current_max;
        }
    }

    return best_so_far;
}

int main()
{
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    
    int a[n];
    cout<<"Enter the elements of array:"<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
    }

    int result = Kadane(a,n);
    cout<<"Largest sum of contigous sub array is: "<<result<<endl;
    return 0;
}