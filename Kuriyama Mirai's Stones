#include <bits/stdc++.h>
using namespace std;
#define flush fflush(stdout);
#define no cout << "NO";
#define yes cout << "YES";
#define line cout << endl;
#define here cout << "here!";
#define read_in freopen ("input.txt","r",stdin);
#define gen_out freopen ("output.txt","w",stdout);
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
#define vec vector
#define vi vec<int>
#define vvi vec<vi>
#define vll vec<ll>
#define vc vec<char>
#define vb vec<bool>
#define MP make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define sz(v) ((int)((v).size()))
#define clr(v,d) memset(v,d,sizeof(v))
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define rep(i,v) for(int i=0; i<sz(v); ++i)
#define rep1(i,v) for(int i=1; i<=sz(v); ++i)
#define lp(i,n) for(int i=0; i<(int)n; ++i)
#define lp1(i,n) for(int i=1; i<=(int)n; ++i)
#define lpi(i,j,n) for(int i=j; i<(int)n; ++i)
#define lpd(i,j,n) for(int i=j; i>=(int)n; --i)
typedef double dl;
typedef long long ll;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long ull;
vi cost,costsorted;
vll presum,presumsorted;
ll PrefixsumRanges(int s,int e,int type)
{
if(type==1)
    return presum[e]-presum[s-1];
else
    return presumsorted[e]-presumsorted[s-1];
}
void solve() {
    IO;// Simple App On Prefix Sum Topic
int n,q,l,r,type;ll res;
cin>>n;
cost=costsorted=vi(n+1,0);
presum=presumsorted=vll(n+1,0);
lp1(i,n)
cin>>cost[i];//1indexed
    costsorted=cost;
    sort(all(costsorted));
    lp1(i,n)
    {
        presum[i]=presum[i-1]+cost[i];
        presumsorted[i]=presumsorted[i-1]+costsorted[i];
    }
cin>>q;
lp(i,q)
{
    cin>>type>>l>>r;
if(type==1)
    cout<<presum[r]-presum[l-1]<<endl;
else
    cout<<presumsorted[r]-presumsorted[l-1]<<endl;
}
}
int main () {

    // int t; cin>>t;
    // while (t--)
    solve();
    return 0;
}
