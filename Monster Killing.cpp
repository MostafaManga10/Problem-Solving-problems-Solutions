#include "bits/stdc++.h"

using namespace std;
#define flush fflush(stdout);
#define no cout << "NO";
#define yes cout << "YES";
#define line cout << '\n';
#define read_in freopen ("Manga.txt","r",stdin);
#define gen_out freopen ("output.txt","w",stdout);
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define X first
#define Y second
#define vec vector
#define vi vec<int>
#define vll vec<ll>
#define MP make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pb push_back
#define sz(v) ((int)((v).size()))
#define clr(v, d) memset(v,d,sizeof(v))
#define all(v) ((v).begin()),((v).end())
#define rep(i, v) for(int i=0; i<sz(v); ++i)
#define rep1(i, v) for(int i=1; i<=sz(v); ++i)
#define lp(i, n) for(int i=0; i<(int)n; ++i)
#define lp1(i, n) for(int i=1; i<=(int)n; ++i)
typedef double dl;
typedef long long ll;
typedef unsigned long long ull;

/*
int x, y;
int oo = 1e7;
int const N = 1e3 + 2;
int mem[N][N][3]; //memo in 3 dim   for coloumn and width and last
int n, m;
int grid[N];
 */
const int N = 1e4 + 2;
int Items[2][N];
ll DP[2][N];
const int M = 1e4 + 2;
pii dp[N];
/*ll solve(int r, int c, int n) {
    if (c >= n)
        return 0;
    if (DP[r][c] != -1)
        return DP[r][c];
    ll res = 0;
    if (r == 0)
        res = Items[r][c] + max(solve(1, c + 1, n), solve(1, c + 2, n));
    else res = Items[r][c] + max(solve(0, c + 1, n), solve(0, c + 2, n));
    return DP[r][c] = res;
}
*/
void Assignment() {
    multiset<int> res;
    int n, x;
    cin >> n;
    vec<pii > Assignments(n + 1);
    lp1(i, n) {
        cin >> x;
        Assignments[i] = {x, 0};
    }
    ll penalty = 0;
    lp1(i, n) {
        cin >> x;
        penalty += x;
        Assignments[i].second = x;
    }
    sort(Assignments.begin() + 1, Assignments.end());
    int per = 1;
    lp1(i, n) {
        if (Assignments[i].first < per) {
            if (Assignments[i].second > *res.begin()) {
                res.erase(res.begin());
                res.insert(Assignments[i].second);
            }
            continue;
        }
        res.insert(Assignments[i].second);
        per++;
    }
    ll cnt = 0;
    for (auto it: res)
        cnt += it;
    cout << penalty - cnt;
}

int Weapons[N];
int WeaponsDP[M][N];

/* int MonsterKilling(int i, int Health, int N) {
    if (Health == 0 || i == N)
        return 0;
    int res1=-646484154;
    if(Health>=Weapons[i])
    res1 = 1 + MonsterKilling(i, Health - Weapons[i], N);
    int res2 = MonsterKilling(i + 1, Health, N);
    return max(res1, res2);
}
 */
/*int MonsterKilling(int i, int Health, int m, int sum, int &mx, vi arr, vi &res) {
    if (sum == Health) {
        if (sum > mx) {
            mx = sum;
            res = arr;
        }
        return 0;
    }
    if (i == m) {
        if (sum <= Health) {
            if (sum > mx) {
                mx = sum;
                res = arr;
            }
            return 0;
        }
        return -135131358;
    }
    if (sum > Health)
        return -1656156;
    if (WeaponsDP[Weapons[i]][sum] != -1)
        return WeaponsDP[Weapons[i]][sum];
    arr.pb(Weapons[i]);
    int res1 = Weapons[i] + MonsterKilling(i, Health, m, sum + Weapons[i], mx, arr, res);
    arr.pop_back();
    int res2 = MonsterKilling(i + 1, Health, m, sum, mx, arr, res);
    return WeaponsDP[Weapons[i]][sum] = max(res1, res2);
}
*/
pii solve( int h, int m) {
    if (h == 0)
        return {0, 0};
    if (dp[h].first != -1)
        return {dp[h].first, dp[h].second};
    int health = h;
    int count = INT_MAX;
    for (int i = 0; i < m; i++) {
        if (h >= Weapons[i]) {
            pii res = solve( h - Weapons[i], m);
            if (res.first < health) {
                health = res.first;
                count = 1 + res.second;
            } else if (health == res.first) {
                count = min(count, 1 + res.second);
            }
        }
    }
    if (health == h) {
        dp[h].first = h;
        dp[h].second = 0;
    } else {
        dp[h].first = health;
        dp[h].second = count;
    }
    return {dp[h].first, dp[h].second};
}
void MonsterKillingBU() {
    int n, m, x, mx = INT_MIN;
    cin >> n;
    vi arr(n);
    lp(i, n)cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    vec<pii > Health(1e4 + 2);
    cin >> m;
    vi weapons(m);
    int cnt = 0;
    lp(i, m) {
        cin >> weapons[i];
        mx = max(mx, weapons[i]);
    }
    int k = 0;
    for (int i = mx; i < 1e4 + 1; i++) {
        k = i;
        cnt = 0;
        lp(j, weapons.size())
            if (k >= weapons[j]) {
                cnt += k / weapons[j];
                k %= weapons[j];
            }
        Health[i].first = k;
        Health[i].second = cnt;
    }
    lp(i, n) {
        cout << Health[arr[i]].first << " " << Health[arr[i]].second << "\n";
    }
}

int main() {
    /*  cin >> n;
      clr(DP,-1);
      lp(i, n)cin >> Items[0][i];
      lp(i, n)cin >> Items[1][i];
      cout << max(solve(1, 0, n), solve(0, 0, n));
      */
    int n, m;
    cin >> n;
    vi Health(n);
    lp(i, n)cin >> Health[i];
    cin >> m;
    lp(i, m)cin >> Weapons[i];
    clr(dp, -1);
    lp(i, n) {
        pii res = solve(Health[i], m);
        cout << res.first << " " << res.second << "\n";
    }
}
