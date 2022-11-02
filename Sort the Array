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
vi presum,presumsorted;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char grid[101][101];
string s="";
int n,m;
bool valid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<m);
}
int  PrefixsumRanges(int s,int e,int type)
{
if(type==1)
    return presum[e]-presum[s-1];
else
    return presumsorted[e]-presumsorted[s-1];
}
void solve() {
            int n;
            cin >> n;
            vi arr(n + 1);
            lp1(i, n)cin >> arr[i];
            if (is_sorted(all(arr)))
                cout << "yes" << endl << 1 << " " << 1;
            else {
                int start = 1;
        lp1(i, n - 1)
        if (arr[i + 1] < arr[i]) {
                start = i;
                break;
            }
        int end = n;
        for (int i = start + 1; i <= n - 1; i++)
            if (arr[i + 1] > arr[i]) {
                end = i;
                break;
            }
                sort(arr.begin()+start,arr.begin()+end+1);
        if (is_sorted(all(arr))) {
            cout << "yes" << endl;
            cout << start << " " << end;
        } else
            cout << "no";
    }
}
int main () {
    IO;
     int t; t=1;//cin>>t;
     while (t--)
    solve();
    return 0;
}
