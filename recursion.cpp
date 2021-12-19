#include<iostream>
using namespace std;

/*int fibo(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }

    return fibo(n-1) + fibo(n-2);
}*/

/*int fact(int n)
{
    if(n == 0)
    {
        return 1;
    }
    return n*fact(n-1);
}*/

/*int power(int a,int b)
{
    if(b == 0)
    {
        return 1;
    }
    return a*power(a,b-1);
}*/

/*void PrintNumbers(int n)
{
  if(n == 0)
  {
      return;
  }
  PrintNumbers(n-1); 
  cout<<n<<endl; 
}*/

/*int countD(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return 1+countD(n/10);
}*/

/*bool isSorted(int arr[],int size)
{
    if(size == 0 || size == 1)
    {
        return true;
    }

    if(arr[0] > arr[1])
    {
        return false;
    }
     return isSorted(arr+1,size-1);
}*/

/*int ArraySum(int a[],int size)
{
    //int sum;
    if(size == 0)
    {
       return 0;
    }
    
    return a[0] + ArraySum(a+1,size-1);
}*/

/*bool checkForX(int a[],int size,int x)
{
    if(size == 0)
    {
        return false;
    }
    if(a[0] == x)
    {
        return true;
    }

    return checkForX(a+1,size-1,x);
}*/

/*int FirstIndex(int a[],int size,int x)
{
    static int c;
    if(size == 0)
    {
        return -1;
    }
    if(a[0] == x)
    {
        return c;
    }
    c++;
    return FirstIndex(a+1,size-1,x);
}*/
int LastIndex(int a[],int size,int x)
{
    if(size == 0)
    {
        return -1;
    }
    if(a[size-1] == x)
    {
        return size-1;
    }
    return LastIndex(a,size-1,x);
}

int main()
{
    //PrintNumbers(5);
    //int result = fibo(17);
    //cout<<result<<endl;
    int a[] = {1,2,3,4,3};
    /*if(isSorted(a,5))
    {
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }*/
    int result = LastIndex(a,5,3);
    cout<<result<<endl;
    return 0;
}