#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#define endl "\n"
#define int long long
#define range(a) a.begin(),a.end()
#define inputarr(a) for(int i = 0;i<n;i++) cin>>a[i]

using umii  = unordered_map<int,int>;
using vpii = vector<pair<int,int>>;
using pii = pair<int,int>;
using vi = vector<int>;
const int MOD = 1e9 + 7;

void solve()
{
   int n;
   cin>>n;
   vi a(n);
   inputarr(a);
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        int sum = 0;
        int init = 0;
        int target = a[i];
        bool valid = false;
        for(int j = 0;j<i;j++)
        {
            sum+=a[j];
            while(sum>target && init<j)
            {
                sum-=a[init++];
            }
            if(sum == target && j-init+1>1)
            {
                count++;
                valid = true;
                break;
            }
        }
        if(valid)
        continue;

        int last = i+1;
        sum = 0;
        for(int j = i+1; j<n;j++)
        {
            sum+=a[j];
            while(sum>target && last<j)
            {
                sum-=a[last++];
            }
            if(sum == target && j-last+1>1)
            {
                count++;
                break;
            }
        }
    }
    cout<<count<<endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
       solve();
    }
    return 0;
}
