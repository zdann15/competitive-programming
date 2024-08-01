#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>pos;
        pos.push_back(0);
        for(int i = 1;i<=n;i++){
            cin >> a[i];
            if(a[i]==0)pos.push_back(i);
        }
        pos.push_back(n+1);
        int ans = 0;
        int x,y;
        y = -1;
        for(int i = 0;i<pos.size()-1;i++){
            int l = pos[i]+1;
            int r = pos[i+1]-1;
            if(l>r)continue;
            int cnt = 0;
            int cnt2 =0;
            for(int j = l;j<=r;j++){
                if(a[j]<0)cnt++;
                if(abs(a[j])==2)cnt2++;
            }
            if(cnt%2==0){
                if(cnt2>ans){
                    ans = cnt2;
                    x = l;
                    y = r;
                }
            }
            else{
                int tmp = cnt2;
                for(int j = l;j<=r;j++){
                    if(a[j]<0){
                        if(a[j]==-2)tmp--;
                        if(tmp>ans){
                            x = j+1;
                            y = r;
                            ans = tmp;
                        }
                        break;
                    }
                    if(a[j]==2)tmp--;
                }
                tmp = cnt2;
                for(int j = r;j>=l;j--){
                    if(a[j]<0){
                        if(a[j]==-2)tmp--;
                        if(tmp>ans){
                            x = l;
                            y = j-1;
                            ans = tmp;
                            
                        }
                        break;
                    }
                    if(a[j]==2)tmp--;
                }
            }
        }
        if(y!=-1)cout << x-1 << ' ' << n-y << '\n';
        else cout << 0 << ' ' << n << '\n';
    }
}
