#include<iostream>
using namespace std;

int getBit(int n,int pos)
{
    return (n & (1<<pos) != 0);
}

int setBit(int n,int pos)
{
    return (n | (1<<pos));
}

int clearBit(int n,int pos)
{
    return (n & ~(1<<pos));
}

int updateBit(int n,int pos,int val)
{
    int m = ~(1<<pos);
    int c = n & m;
    return (c | (val<<pos)); 
}

int main()
{
    int n = 5;
    int pos = 1;

    //cout<<setBit(n,pos);
    //cout<<updateBit(n,pos,1)<<endl;
    cout<<(-2>>1)<<endl;
    return 0;
}