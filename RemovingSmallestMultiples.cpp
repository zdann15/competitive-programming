#include <bits/stdc++.h>
using namespace std;
#define int long long
char a[1000010];
signed main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1;i<=n;i++){
            cin >> a[i];
            //a[i] = rand()%2;
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(a[i]=='1')continue;
            for(int j = i;j<=n;j+=i){
                if(a[j]=='1')break;
                else {
                    if(a[j]=='0'){
                        ans+=i;
                        a[j] = '2';
                    }
                    
                }
            }
        }
        cout << ans << '\n';
    }
}
