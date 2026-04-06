#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long fact[2000005];
long long inv_fact[2000005];

long long power(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void precompute(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[n] = power(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

long long paths(int y1, int x1, int y2, int x2) {
    if (y2 < y1 || x2 < x1) return 0;
    int dy = y2 - y1;
    int dx = x2 - x1;
    return nCr(dy + dx, dy);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    precompute(2 * n);
    
    vector<pair<int, int>> traps(m);
    for (int i = 0; i < m; i++) {
        cin >> traps[i].first >> traps[i].second;
    }
    
    sort(traps.begin(), traps.end());
    
    vector<long long> dp(m);
    
    for (int i = 0; i < m; i++) {
        dp[i] = paths(1, 1, traps[i].first, traps[i].second);
        
        for (int j = 0; j < i; j++) {
            if (traps[j].first <= traps[i].first && traps[j].second <= traps[i].second) {
                dp[i] = (dp[i] - dp[j] * paths(traps[j].first, traps[j].second, traps[i].first, traps[i].second) % MOD + MOD) % MOD;
            }
        }
    }
    
    long long ans = paths(1, 1, n, n);
    
    for (int i = 0; i < m; i++) {
        ans = (ans - dp[i] * paths(traps[i].first, traps[i].second, n, n) % MOD + MOD) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}
