#include <bits/stdc++.h>
using namespace std;
int a[200010];
set<int>adj[200010];
int dis[200010];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int x,y;
        cin >> x >> y;
        for(int i = 1;i<=n;i++){
            adj[i].clear();
            a[i] = 0;
        }
        for(int i = 1;i<=k;i++){
            int cur;
            cin >> cur;
            a[cur] = 1;
        }
        for(int i = 1;i<=n-1;i++){
            int u,v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        queue<int>q;
        for(int i =1;i<=n;i++){
            if(adj[i].size()==1 && i!=x && i!=y && !a[i]){
                q.push(i);
            }
        }
        int cnt = n;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur==x || cur==y || a[cur])continue;
            cnt--;
            for(int child:adj[cur]){
                adj[child].erase(cur);
                if(adj[child].size()==1)q.push(child);
            }
        }
        q.push(x);
        for(int i = 1;i<=n;i++)dis[i] = INT_MAX;
        dis[x] = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int child:adj[cur]){
                if(dis[cur]+1<dis[child]){
                    dis[child] = dis[cur]+1;
                    q.push(child);
                }
            }
        }
        cout <<2*(cnt-1)-dis[y] << '\n';
    }
}
