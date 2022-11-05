#include <bits/stdc++.h>
using namespace std;
#define flush fflush(stdout);
#define no cout << "NO";
#define yes cout << "YES";
#define line cout << endl;
#define here cout << "here!";
#define read_in freopen ("Manga.txt","r",stdin);
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
char grid[31][31];
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
bool sortbysec(pair<int,int>a,pair<int,int>b)
{
    return (a.second<b.second);
}
vec<pair<int,int>>waste;
int GetNumberOfWastes(int a,int b) {
    int cnt = 0;
    lp(i, waste.size()) {
        if (waste[i].first > a || waste[i].second > b)
            break;
        cnt++;
        if(waste[i].first==a&&waste[i].second==b)
        cnt=-1;
    }
    return cnt;
}
vec<vec<pair<int,int>>>KeyBoard(26);
vec<pair<int,int>>Shift;
vi couldwritten(26,0);
bool CouldWrittenUpperCase(int i,int j,int x,int n,int m)
{
   for(auto it:Shift)
       if((it.first-i)*(it.first-i)+(it.second-j)*(it.second-j)<=x*x)
           return true;
   return false;
}
void solve() {
  read_in;
    int n, m, x,cnt=0;
    cin>>n>>m>>x;
char c;
lp(i,n)
lp(j,m) {
    cin >> c;
    if (c == 'S')
        Shift.push_back(MP(i, j));
    else {
        grid[i][j] = c;
        KeyBoard[c - 'a'].push_back(MP(i, j));
    }
}
if(Shift.size())
    lp(i,n)
        lp(j,m)
if(CouldWrittenUpperCase( i, j,x,n,m))
couldwritten[grid[i][j]-'a']=1;
string s;int z;
cin>>z>>s;
lp(i,s.size())
{
    if(islower(s[i]))
        if (!KeyBoard[s[i] - 'a'].size()) {
            cout << -1;
            return;
        }
   if(isupper(s[i])) {
            if (!Shift.size()) {
                cout << -1;
                return;
            }
            else if(!couldwritten[tolower(s[i])-'a'])
                cnt++;
        }
}
cout<<cnt;
}
int main () {
    IO;
     int t; t=1;//cin>>t;
     while (t--)
    solve();
    return 0;
}
