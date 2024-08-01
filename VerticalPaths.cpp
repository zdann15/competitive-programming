#include <bits/stdc++.h>
using namespace std;
vector<int>adj[200010];
int depth[200010],nxt[200010];
void dfs(int cur){
    if(adj[cur].empty()){
        nxt[cur] = -1;
        depth[cur] = 1;
        return;
    }
    else{
        for(int child:adj[cur]){
            dfs(child);
            depth[cur] = max(depth[cur],depth[child]+1);
            if(depth[cur]==depth[child]+1)nxt[cur] = child;
        }
    }
}
vector<int>path;
void dfs1(int cur){
    path.push_back(cur);
    if(nxt[cur]==-1)return;
    else{
        dfs1(nxt[cur]);
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
        for(int i = 1;i<=n;i++)adj[i].clear();
        int rt;
        for(int i = 1;i<=n;i++){
            depth[i] = 0;
            int a;
            cin >> a;
            if(a==i)rt = i;
            else{
                adj[a].push_back(i);
            }
        }
        dfs(rt);
        set<pair<int,int>>nodes;
        for(int i = 1;i<=n;i++){
            nodes.insert({-depth[i],i});
        }
        vector<vector<int>>ans;
        while(!nodes.empty()){
            int cur = (*nodes.begin()).second;
            path.clear();
            dfs1(cur);
            for(int i:path)nodes.erase({-depth[i],i});
            ans.push_back(path);
        }
        cout << ans.size() << '\n';
        for(vector<int>i:ans){
            cout << i.size() << "\n";
            for(int j:i)cout << j << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}
