
#include <bits/stdc++.h>
using namespace std;
#define flush fflush(stdout);
#define no cout << "NO";
#define yes cout << "YES";
#define line cout << '\n';
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
  bool ISWin(string x)
  {
    bool IsFull=(count(all(x),'X')+ count(all(x),'O')==9);
    bool rows=(x[0]!='.'&&x[0]==x[1]&&x[1]==x[2])||(x[3]!='.'&&x[3]==x[4]&&x[4]==x[5])||(x[6]!='.'&&x[6]==x[7]&&x[7]==x[8]);
    bool coloumns=(x[0]!='.'&&x[0]==x[3]&&x[3]==x[6])||(x[1]!='.'&&x[1]==x[4]&&x[4]==x[7])||(x[2]!='.'&&x[2]==x[5]&&x[5]==x[8]);
    bool diagonals=(x[0]!='.'&&x[0]==x[4]&&x[4]==x[8])||(x[2]!='.'&&x[2]==x[4]&&x[4]==x[6]);
return rows||coloumns||diagonals||IsFull;
  }
void solve(string grid) {
    string start=".........", curr;
    queue<pair<string,bool>>qu;
    bool curr_player,valid=false;
    qu.push({start,1});
    while(!qu.empty()) {
        curr = qu.front().first;
        curr_player = qu.front().second;
        qu.pop();
        if (curr == grid&& ISWin(curr)) {
       valid=true;
            break;
        }
        if (ISWin(curr)) continue;
        lp(i, 9)if (curr[i] == '.') {
                curr[i] = curr_player ? 'X' : 'O';
                if (curr[i] == grid[i])
                    qu.push({curr, !curr_player});
                curr[i] = '.';
            }
    }
    if(valid)
        cout<<"valid"<<endl;
    else
        cout<<"invalid"<<endl;

}
int main () { IO
string x;
   //  int t; cin>>t;
     while (cin>>x&&x!="end")
    solve(x);
    return 0;
}
