#include <bits/stdc++.h>
using namespace std;
vector<int>adj[4010];
int cntb[4010],cntw[4010];
string s;
void dfs(int cur){
    //cout << cur << '\n';
        if(s[cur]=='B'){
            cntb[cur]++;
        }
        else cntw[cur]++;
    for(int child:adj[cur]){
        dfs(child);
        cntb[cur] += cntb[child];
        cntw[cur]+=cntw[child];
    }
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            adj[i].clear();
            cntb[i] = cntw[i] = 0;
        }
        for(int i = 2;i<=n;i++){
            int p;
            cin >> p;
            adj[p].push_back(i);
            //cout << p << ' ' << i << '\n';
        }
        
        cin >> s;
        s = '0'+s;
        dfs(1);
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(cntb[i]-cntw[i]==0){
                //cout << i << '\n';
                ans++;
            }
        }
        cout << ans << '\n';
    }
}
