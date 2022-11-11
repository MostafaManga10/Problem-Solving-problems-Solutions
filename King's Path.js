
#include <bits/stdc++.h>
using namespace std;
#define flush fflush(stdout);
#define no cout << "NO";
#define yes cout << "YES";
#define line cout << '\n';
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
vec<vi>adjlist;

//Practice on BFS Is a Shortest path Algorithm
vi BFSShortestPath1(int s) {
    queue<int> q;
    vi length(adjlist.size(), INT_MAX);
    length[s] = 1;
    int dep = 0, cur = s, size;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            cur = q.front();
            q.pop();
            for (auto i: adjlist[cur])
                if (length[i] == INT_MAX) {
                    length[i] = dep + 1;
                    q.push(i);
                }
        }
        dep++;
    }
    return length;
}
  vi  BFSShortestPath2(int s,int d) {
      queue<int> q;
      vi Length(adjlist.size(), INT_MAX);
      vi Parents(adjlist.size(), -1);
      Length[s] = 0;
      bool found = false;
      q.push(s);
      int dep = 0, cur = s, size;
      while (!q.empty() && !found) {
          size = q.size();
          while (size-- && !found) {
              cur = q.front();
              q.pop();
              for (auto i: adjlist[cur]) {
                  if (i == d) {
                      Parents[i] = cur;
                      found = true;
                      break;
                  }
                  if (Length[i] == INT_MAX) {
                      q.push(i);
                      Length[i] = dep + 1;
                      Parents[i] = cur;
                  }
              }
          }
          dep++;
      }
      vi Path;
      while(d!=-1)
      {
          Path.push_back(Parents[d]);
          d=Parents[d];
      }
      reverse(all(Path));
      return Path;
  }
  int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={0,1,-1,0,1,-1,1,-1};
bool isallowed(int r,int c)
{
    if(r<0||c<0||r> pow(10,9)||c> pow(10,9))
        return false;
}
int solve() {
int sr,sc,dr,dc,n,a,b,c,curr_r,curr_c;
cin>>sr>>sc>>dr>>dc>>n;
map<pair<int,int>,bool>grid;
lp(i,n)
{
cin>>a>>b>>c;
for(int i=b;i<=c;i++)
    grid[{a,i}]=0;
}
queue<pair<int,int>>q;
q.push(MP(sr,sc));
int dep=0,size;
while(!q.empty())
{
    dep++;
size=q.size();
while(size--)
{
curr_r=q.front().first;
curr_c=q.front().second;
q.pop();
if(curr_r==dr&&curr_c==dc)
{
    return dep-1;
}
lp(k,8)
{
int r=dx[k]+curr_r;
int c=dy[k]+curr_c;
if(grid.find({r,c})!=grid.end()&&grid[{r,c}]==0)
{
   q.push(MP(r,c));
   grid[{r,c}]=1;
}
}
}
}
return -1;
}
int main () {
      IO
   //  int t; cin>>t;
    // while ()
   //  {
        cout<< solve();
    // }
    return 0;
}
