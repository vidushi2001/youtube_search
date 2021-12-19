#include<iostream>
using namespace std;
int getMinSteps(int n,int* memo)
{
	if(n == 1)
	{
		return 0;
	}
	if(memo[n] != -1)
	{
		return memo[n];
	}

	int res = getMinSteps(n-1,memo);

	if(n%2 == 0)
	{
		res = min(res,getMinSteps(n/2,memo));
	}
	if(n%3 == 0)
	{
		res = min(res,getMinSteps(n/3,memo));
	}
	memo[n] = 1+res;
	return memo[n];
}

int main()
{
	int n;
	cout<<"Enter the number for which minimum steps are to selected:"<<endl;
	cin>>n;

	int* memo = new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		memo[n] = -1;
	}

	int result = getMinSteps(n,memo);
	cout<<"Minimum steps for "<<n<<" are: "<<result;
	return 0;
}