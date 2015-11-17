//solution by Wsl_F
#include <bits/stdc++.h>


using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

string getTrit(int n)
{/*-1 = 'z'*/
    string ans= "";
    while (n>0)
    {
        ans+= ('0'+ n%3);
        n/= 3;
    }

    for (int i= 0; i<ans.size(); i++)
    {
        if (ans[i]<'2') continue;
        if (i+1 == ans.size()) ans+= '0';
        ans[i+1]+= (ans[i]-'0')/3;
        ans[i]= (ans[i]-'0')%3+'0';
        if (ans[i]=='2')
        {
            ans[i]= 'z';
            ans[i+1]++;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    for (int i= 1; i<=10; i++)
        cout<<i<<")  "<<getTrit(i)<<endl;

    return 0;
}
