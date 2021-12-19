#include<iostream>
using namespace std;

int LIS(int* input,int size)
{
    int* output = new int[size];
    output[0] = 1;
    for(int i=1;i<size;i++)
    {
        output[i] = 1;
        for(int j = i-1;j>=0;j--)
        {
            if(input[j] > input[i])
            {
                continue;
            }
            int possibleans = output[j] + 1;
            if(possibleans > output[i])
            {
                output[i] = possibleans;
            }
        }
    }

    int best = 0;
    for(int i=0;i<size;i++)
    {
        if(best < output[i])
        {
            best = output[i];
        }
    }
    delete [] output;
    return best;
}

int main()
{
    int size;
    cout<<"Enter the size of the array:"<<endl;
    cin>>size;
    cout<<"Enter the elements of array:"<<endl;
    int* arr = new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    int result = LIS(arr,size);
    cout<<"The Length of Longest Increasing Subsequence is: "<<result<<endl;
    delete [] arr;
    return 0;
}