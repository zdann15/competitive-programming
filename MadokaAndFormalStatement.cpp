#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010],minm[200010];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool equal = true;
        bool flag = false;
        for(int i = 0;i<=n-1;i++){
            cin >> a[i];
        }
        for(int i = 0;i<=n-1;i++){
            cin >> b[i];
            if(a[i]!=b[i])equal = false;
            if(a[i]>b[i])flag = true;
        }
        if(equal){
            cout << "YES\n";
            continue;
        }
        if(flag){
            cout << "NO\n";
            continue;
        }
        bool ans = true;
        for(int i = 0;i<n;i++){
            if(a[i]==b[i])continue;
            if(b[(i+1)%n]<b[i]-1){
                ans = false;
            }
        }
        if(ans)cout << "YES\n";
        else cout << "NO\n";
    }
}
