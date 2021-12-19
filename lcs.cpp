#include<iostream>
#include<string>
using namespace std;

/*int LCS(char* s1,char* s2)
{
    if(s1[0] == '\0' || s2[0] == '\0')
    {
        return 0;
    }

    if(s1[0] == s2[0])
    {
        return 1+LCS(s1+1,s2+1);
    }
    else{
        int option1 = LCS(s1+1,s2);
        int option2 = LCS(s1,s2+1);

        return max(option1,option2);
    }
}*/
int lcs(char* s1,char* s2,int m,int n,char** dp)
{
    if(m == 0 || n == 0)
    {
        return 0;
    }
    if(dp[m][n]>-1)
    {
        return dp[m][n];
    }

    int ans;
    if(s1[0] == s2[0])
    {
        return lcs(s1+1,s2+1,m-1,n-1,dp);
    }
    else {
        int option1 = lcs(s1,s2+1,m,n+1,dp);
        int option2 = lcs(s1+1,s2,m-1,n,dp);
        ans = max(option2,option1);
    }

    dp[m][n] = ans;
    return ans;
}

int LCS(char* s1,char* s2)
{
    int m = strlen(s1);
    int n = strlen(s2);

    char**dp = new char*[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i] = new char[n+1];
        for(int j= 0;j<=n;j++)
        {
            dp[i][j] = -1;
        }
    }

    int ans = lcs(s1,s2,m,n,dp);
    for(int i=0;i<=m;i++)
    {
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main()
{
    char* s1 = new char[10];
    char* s2 = new char[10];
    s1 = "abc";
    s2 = "1a45b9103";
    int result = LCS(s1,s2);
    cout<<"Longest Common SubSequence of "<<s1<<" and "<<s2<<" is: "<<result<<endl;
    delete [] s1;
    delete [] s2;
    return 0;
}