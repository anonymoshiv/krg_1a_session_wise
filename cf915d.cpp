#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int,int>> edges;
vector<vector<int>> adj;

bool has_cycle(int skip_edge) {
    vector<int> indeg(n+1,0);
    vector<vector<int>> g(n+1);

    for(int i=0;i<m;i++){
        if(i==skip_edge) continue;
        int u=edges[i].first;
        int v=edges[i].second;
        g[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;

    for(int i=1;i<=n;i++)
        if(indeg[i]==0)
            q.push(i);

    int cnt=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        cnt++;

        for(int v:g[u]){
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }

    return cnt!=n;
}

int main(){

    cin>>n>>m;

    edges.resize(m);

    for(int i=0;i<m;i++)
        cin>>edges[i].first>>edges[i].second;

    for(int i=0;i<m;i++){
        if(!has_cycle(i)){
            cout<<"YES";
            return 0;
        }
    }

    if(!has_cycle(-1))
        cout<<"YES";
    else
        cout<<"NO";
}
