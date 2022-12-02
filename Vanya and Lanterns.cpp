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
void solve() {
    int n,l;
    double Max=INT_MIN;
    cin>>n>>l;
    vec<int>coordinates(n);
    lp(i,n)
    cin>>coordinates[i];
    sort(all(coordinates));
    int Max1=coordinates[0];
    int Max2=l-coordinates[n-1];
    lp(i,n-1)
       if((coordinates[i+1]-coordinates[i])>Max)
            Max=coordinates[i+1]-coordinates[i];
double res=max( max(double (Max1),double (Max2)),double (Max/2));
 //   cout.precision(15);
cout<<fixed<<setprecision(15)<<res;
}
int main () {
    IO
    // int t; cin>>t;
    // while (t--)
    solve();
    return 0;
}
