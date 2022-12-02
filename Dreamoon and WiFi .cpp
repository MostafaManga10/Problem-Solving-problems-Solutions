
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
#define clr(v, d) memset(v,d,sizeof(v))
#define all(v) ((v).begin()),((v).end())
#define rall(v) ((v).rbegin()),((v).rend())
#define rep(i, v) for(int i=0; i<sz(v); ++i)
#define rep1(i, v) for(int i=1; i<=sz(v); ++i)
#define lp(i, n) for(int i=0; i<(int)n; ++i)
#define lp1(i, n) for(int i=1; i<=(int)n; ++i)
#define lpi(i, j, n) for(int i=j; i<(int)n; ++i)
#define lpd(i, j, n) for(int i=j; i>=(int)n; --i)

typedef double dl;
typedef long long ll;
typedef unsigned int ui;
typedef long long int lli;
typedef unsigned long long ull;
vec<vi > adjlist;

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

vi BFSShortestPath2(int s, int d) {
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
    while (d != -1) {
        Path.push_back(Parents[d]);
        d = Parents[d];
    }
    reverse(all(Path));
    return Path;
}

bool kicked[101];
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int combinatorics[11][11];

void solve() {
    string commands;
    string received;
    cin >> commands >> received;
    int difference;
    int countplus = count(commands.begin(), commands.end(), '+');
    int countplusreceived = count(received.begin(), received.end(), '+');
    int unrecognized = count(received.begin(), received.end(), '?');
    difference = countplus - countplusreceived;
    if (difference < 0 || unrecognized < difference) {
cout.precision(15);
        cout << fixed<<0;
    }
    else {
//you wanna determine differenceCunrecognized
        combinatorics[0][0] = 1;
        combinatorics[1][0] = 1;
        combinatorics[1][1] = 1;
        lpi(i, 2, 11)lp(j, 10)combinatorics[i][j] = combinatorics[i - 1][j] + combinatorics[i - 1][j - 1];
        double res=double (combinatorics[unrecognized][difference]) / double(pow(2, unrecognized));
        cout.precision(15);
        cout << fixed<<res;
    }
}

int main() {
    IO
    solve();
}
