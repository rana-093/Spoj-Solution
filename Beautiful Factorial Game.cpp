#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
#define db(x) cout<<#x<<" -> "<<x<<endl
 
const int mx = (int) 1e5+5;
map<int,bool>mp;
vector<int>prime;
vector<pair<int,int> > vec;
 
void seive()
{
    for(int i=2; i*i<=mx; i++)
    {
        if(!mp[i])
        {
            for(int j=(2*i); j<=mx; j+=i)
            {
                mp[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(int i=3; i<=mx; i+=2)
    {
        if(!mp[i])
        {
            prime.push_back(i);
        }
    }
    return ;
}
 
 
void fact(int  n)
{
    for(int i=0; prime[i]*prime[i]<=n; i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }
            vec.push_back(make_pair(prime[i],cnt));
        }
    }
    if(n>1)
    {
        vec.push_back(make_pair(n,1));
    }
}
 
int po(int a,int n)
{
    int f  = 1;
    for(int i=1; i<=n; i++)
    {
        f*=a;
    }
    return f;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    seive();
    int t;
    cin>>t;
    int tc =0;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k;
        vec.clear();
        fact(k);
        int  mn = 1000000000LL;
        for(int i=0; i<vec.size(); i++)
        {
            int sum = 0;
            int f = vec[i].first;
            int s = vec[i].second;
            for(int j=1; ; j++)
            {
                int tot = po(f,j);
                if(tot>n)
                {
                    break;
                }
                sum+=(int) (n/(po(f,j)));
            }
            mn = min(mn,sum/s);
        }
        printf("Case %d: %d\n",++tc,mn);
    }
    return 0;
} 

