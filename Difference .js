
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
void solve(int v,int e,int w) {
    int  x, y, maxcost = 0;
    vec<vi > graph(v+1);
    vi cost(v + 1);
    vi visited(501, 0);
    int i = 1;
    while (i <= v) {
        cin >> x;
        cost[i] = x;
        maxcost += x;
        i++;
    }
    while (e--) {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    int q, node;
    cin >> q;
    cout<<"Case #"<<w<<":"<<"\n";
    while (q--) {
        fill(all(visited),0);
        int maxoverall = maxcost;
        int min=0;
        cin >> node;
        maxoverall -= cost[node];
        visited[node]=1;
        //GetMax
            for (auto it: graph[node]) {
                if(!visited[it]) {
                    maxoverall -= cost[it];
                    visited[it] = 1;
                }
                for (auto j: graph[it])
                    if (!visited[j]) {
                        maxoverall -= cost[j];
                        visited[j] = 1;
                    }
            }
        lp1(i, v) {   //GetMin
            if (find(all(graph[i]), node) != graph[i].end())
                min += cost[i];
            }
        cout << maxoverall - min<<"\n";
    }
}
int main () {
      IO
  //  read_in;
      int v,e,i=0;
      while(cin>>v>>e&&v) {
          solve(v, e, ++i);
          cout << "\n";
      }
   //  int t; cin>>t;
    // while ()
   //  {
    // }
    return 0;
}
