#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010],b[100010];
signed main(){
    //cin.tie(0);
    //cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> a[i];
        }
        for(int i = 1;i<=n;i++){
            cin >> b[i];
        }
        vector<pair<vector<int>,vector<int>>>cur;
        vector<int>a1,b1;
        for(int i = 1;i<=n;i++){
            a1.push_back(a[i]);
            b1.push_back(b[i]);
            
        }
        cur.push_back({a1,b1});
        int ans = 0;
        for(int i1 = 29;i1>=0;i1--){
            //cout << i1 << ' ' << cur.size() << '\n';
            bool flag = true;
            for(pair<vector<int>,vector<int>>i:cur){
                int cnta = 0;
                int cntb = 0;
                for(int j:i.first){
                    if((j>>i1)&1){
                        cnta++;
                    }
                }
                
                for(int j:i.second){
                    if((j>>i1)&1){
                        cntb++;
                    }
                }
                if(cnta+cntb != i.first.size())flag = false;
            }
            if(flag){
                ans |= (1<<i1);
                vector<pair<vector<int>,vector<int>>>curn;
                for(pair<vector<int>,vector<int>>i:cur){
                    //cout << cur.size() << '\n';
                    vector<int>ahas,ahasnt,bhas,bhasnt;
                    for(int j:i.first){
                        if((j>>i1)&1)ahas.push_back(j);
                        else ahasnt.push_back(j);
                    }
                    
                    for(int j:i.second){
                        if((j>>i1)&1)bhas.push_back(j);
                        else bhasnt.push_back(j);
                    }
                    
                    if(!ahas.empty())curn.push_back({ahas,bhasnt});
                    if(!bhas.empty())curn.push_back({ahasnt,bhas});
                }
                cur.clear();
                for(pair<vector<int>,vector<int>>i:curn)cur.push_back(i);
            }
        }
        cout << ans << '\n';
    }
}
