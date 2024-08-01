#include <bits/stdc++.h>
using namespace std;
int a[200010],p[200010];
int ans[200010];
vector<int>adj[200010];
bool inq[200010];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    vector<int>dis(200010);
    while(t--){
        int n;
        cin >> n;
        int rot;
        for(int i = 1;i<=n;i++){
            adj[i].clear();
            dis[i] = 0;
            inq[i] = false;
        }
        for(int i = 1;i<=n;i++){
            cin >> a[i];
            if(a[i]==i){
                rot = i;
            }
            else adj[a[i]].push_back(i);
        }
        for(int i = 1;i<=n;i++){
            cin >> p[i];
        }
        for(int i = 1;i<=n;i++){
            dis[p[i]] = i-1;
            //cout << i-1 << ' ' << dis[p[i]] << '\n';
        }
        dis[rot] = 0;
        if(p[1]!=rot){
            cout << "-1\n";
            continue;
        }
        ans[rot] = 0;
        inq[rot] = true;
        for(int i:adj[rot])inq[i] = true;
        for(int i = 2;i<=n;i++){
        }
        for(int i = 2;i<=n;i++){
            if(!inq[p[i]]){
                cout << "-1\n";
                goto nxt;
            }
            for(int child:adj[p[i]])inq[child]=true;
            int par = a[p[i]];
            int curdis = dis[p[i]];
            ans[p[i]] = curdis-dis[par];
        }
        for(int i = 1;i<=n;i++){
            cout << ans[i] << ' ';
        }
        cout << '\n';
        nxt:;
    }
    
}
