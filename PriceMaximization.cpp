#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>mod[1010];
int a[200010];
signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        for(int i = 0;i<k;i++)mod[i].clear();
        for(int i = 1;i<=n;i++){
            cin >> a[i];
            mod[a[i]%k].push_back(a[i]);
        }
        int ans = 0;
        for(int i = 0;i<k;i++)sort(mod[i].rbegin(),mod[i].rend());
        for(int i = 0;i<k;i++){
            for(int res = 0;res<k;res++){
                int sec = (k+res-i)%k;
                if(mod[i].empty())break;
                if(i==sec){
                    while(mod[i].size()>=2){
                        int tmp1 = mod[i].back();
                        mod[i].pop_back();
                        int tmp2 = mod[i].back();
                        mod[i].pop_back();
                        ans += (tmp1+tmp2)/k;
                    }
                    continue;
                }
                while(!mod[i].empty() && !mod[sec].empty()){
                    ans += (mod[i].back()+mod[sec].back())/k;
                    mod[i].pop_back();
                    mod[sec].pop_back();
                }
            }
        }
        cout << ans << '\n';
    }
}
