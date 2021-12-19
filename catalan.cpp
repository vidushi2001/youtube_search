#include<iostream>
using namespace std;

int catalan(int n)
{
	if(n<=1)
	{
		return 1;
	}
	int res = 0;
	for(int i=0;i<n;i++)
	{
		res+=catalan(i)*catalan(n-i-1); 
	}
	return res;
}

int main()
{
	int res = catalan(3);
	cout<<res<<endl;
	return 0;
}