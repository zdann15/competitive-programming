#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
int group[100010];
signed main(){
    cin.tie();
    cin.sync_with_stdio(0);
    int t;
    t = 1;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i = 1;i<=n;i++){
            cin >> a[i];
        }
        group[1] = 1;
        for(int i = 2;i<=n;i++){
            if(a[i]==a[i-1]){
                group[i] = group[i-1];
            }
            else group[i] = group[i-1]+1;
        }
        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans += group[i]*i;
            ans -= (n-i+1)*(group[i]-1);
        }
        while(m--){
            int x,y;
            cin >> x >> y;
            if(a[x]==y){
                cout << ans << '\n';
                continue;
            }
            int i = x;
            if(a[x-1]==a[x+1] && a[x-1]==a[x]){
                int tmp = (i+1+n)*(n-i)/2;
                ans += 4*tmp;
                ans -= 2*n*(n-i);
                ans -= 2*(n-i);
                ans += i;
                ans -= (n-i+1);
                cout << ans << '\n';
            }
            else if(a[x-1]==a[x+1] && y==a[x-1]){
                int tmp = (i+1+n)*(n-i)/2;
                ans -= 4*tmp;
                ans += 2*n*(n-i);
                ans += 2*(n-i);
                ans -= i;
                ans += (n-i+1);
                cout << ans << '\n';
            }
            else if(a[x]==a[x-1] && y==a[x+1]){
                ans += i;
                ans -= n-i+1;
                cout << ans << '\n';
            }
            else if(a[x]==a[x-1]){
                int tmp = (i+n)*(n-i+1)/2;
                ans -= n*(n-i+1);
                ans += 2*tmp;
                ans -= (n-i+1);
                cout << ans << '\n';
            }
            else if(a[x]==a[x+1] && y == a[x-1]){
                ans -= i;
                ans += n-i+1;
                cout << ans << '\n';
            }
            else if(a[x]==a[x+1]){
                int tmp = (i+n+1)*(n-i)/2;
                ans -= n*(n-i);
                ans += 2*tmp;
                ans -= n-i;
                cout << ans << '\n';
            }
            else if(a[x]!=a[x-1] && a[x]!=a[x+1] && y==a[x-1]){
                int tmp = (i+n)*(n-i+1)/2;
                ans += n*(n-i+1);
                ans -= 2*tmp;
                ans += (n-i+1);
                cout << ans << '\n';
            }
            else if(a[x]!=a[x-1] && a[x] != a[x+1] && y == a[x+1]){
                int tmp = (i+1+n)*(n-i)/2;
                ans += n*(n-i);
                ans -= 2*tmp;
                ans += n-i;
                cout << ans << '\n';
                //cout << "X";
            }
            
            else cout << ans << '\n';
            a[x] = y;
            
            /*group[1] = 1;
        for(int i = 2;i<=n;i++){
            if(a[i]==a[i-1]){
                group[i] = group[i-1];
            }
            else group[i] = group[i-1]+1;
        }
        int ans1 = 0;
        for(int i = 1;i<=n;i++){
            ans1 += group[i]*i;
            ans1 -= (n-i+1)*(group[i]-1);
        }
        cout << "?" << ans1 << '\n';*/
        }
    }
}
