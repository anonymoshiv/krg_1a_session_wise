#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for(int i = 0; i < n; i++)
        cin >> names[i];

    vector<vector<int>> adj(26);
    vector<int> indegree(26,0);

    for(int i = 0; i < n-1; i++) {

        string a = names[i];
        string b = names[i+1];

        int len = min(a.size(), b.size());
        bool found = false;

        for(int j = 0; j < len; j++) {
            if(a[j] != b[j]) {

                int u = a[j] - 'a';
                int v = b[j] - 'a';

                adj[u].push_back(v);
                found = true;
                break;
            }
        }

        if(!found && a.size() > b.size()) {
            cout << "Impossible";
            return 0;
        }
    }

    for(int i = 0; i < 26; i++)
        for(int v : adj[i])
            indegree[v]++;

    queue<int> q;

    for(int i = 0; i < 26; i++)
        if(indegree[i] == 0)
            q.push(i);

    string ans = "";

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        ans += char('a' + u);

        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }

    if(ans.size() < 26)
        cout << "Impossible";
    else
        cout << ans;
}
