#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
 
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
void dfs(int u, vector<vi>& adj, vector<bool>& vis) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) dfs(v, adj, vis);
    }
}
 
int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<bool> vis(n + 1, false);
    vi bridges;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            bridges.pb(i);
            dfs(i, adj, vis);
        }
    }
    cout << bridges.size() - 1 << "\n";
    for(size_t i = 0; i < bridges.size() - 1; i++) {
        cout << bridges[i] << " " << bridges[i+1] << "\n";
    }
    return 0;
}
