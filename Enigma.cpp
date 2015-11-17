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

        const int AlphabetSize= 256;
        char code[AlphabetSize];
        map<char,int> mp;
        bool init;

        void generateCode()
        {
            for (int i= 0; i<AlphabetSize; i++)
                code[i]= i;

            srand(time(NULL));
          //  random_shuffle(code,code+AlphabetSize);
            for (int i= 0; i<AlphabetSize; i++)
                mp[code[i]]= i;
        }

        void Enigma()
        {
            if (!init)
            {
                generateCode();
                init= 1;
            }
        }


        string getCode(string text)
        {
            string ans;
            int p= 0;
            for (int i= 0; i<text.size(); i++)
            {
                ans+= code[(text[i]+p)%AlphabetSize];
                p++;
            }
            return ans;
        }

        string decode(string message)
        {
            string text;
            int p= 0;
            for (int i= 0; i<message.size(); i++)
            {
                text+= mp[(message[i]+p)%AlphabetSize];
                p--;
            }
            return text;
        }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
// LL a[110];
// memset(a,0,sizeof(a));

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//cout<<fixed;
//cout<<setprecision(9);

    Enigma();
    string text= "Does it work?";
    string code= getCode(text);
    cout<<code<<endl;
    cout<<decode(code)<<endl;
    return 0;
}
