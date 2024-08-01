#include <bits/stdc++.h>
using namespace std;
int dp[200010][3];
pair<int,int>pre[200010][3];
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '0'+s;
    for(int i = 1;i<=n;i++){
        if(s[i]=='R'){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]);
            if(dp[i][0]==dp[i-1][1]){
                pre[i][0] = {i-1,1};
            }
            else{
                pre[i][0] = {i-1,2};
            }
            dp[i][1] = min(dp[i-1][0],dp[i-1][2])+1;
            if(dp[i][1] == dp[i-1][0]+1){
                pre[i][1] = {i-1,0};
            }
            else{
                pre[i][1] = {i-1,2};
            }
            dp[i][2] = min(dp[i-1][0],dp[i-1][1])+1;
            if(dp[i][2]==dp[i-1][0]+1){
                pre[i][2] = {i-1,0};
            }
            else{
                pre[i][2] = {i-1,1};
            }
        }
        else if(s[i]=='G'){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2])+1;
            if(dp[i][0]==dp[i-1][1]+1){
                pre[i][0] = {i-1,1};
            }
            else{
                pre[i][0] = {i-1,2};
            }
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]);
            if(dp[i][1]==dp[i-1][0]){
                pre[i][1] = {i-1,0};
            }
            else{
                pre[i][1] = {i-1,2};
            }
            dp[i][2] = min(dp[i-1][0],dp[i-1][1])+1;
            if(dp[i][2]==dp[i-1][0]+1){
                pre[i][2] = {i-1,0};
            }
            else{
                pre[i][2] = {i-1,1};
            }
        }
        else{
            dp[i][0] = min(dp[i-1][1],dp[i-1][2])+1;
            if(dp[i][0]==dp[i-1][1]+1){
                pre[i][0] = {i-1,1};
            }
            else{
                pre[i][0] = {i-1,2};
            }
            dp[i][1] = min(dp[i-1][0],dp[i-1][2])+1;
            if(dp[i][1]==dp[i-1][0]+1){
                pre[i][1] = {i-1,0};
            }
            else{
                pre[i][1] = {i-1,2};
            }
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]);
            if(dp[i][2]==dp[i-1][0]){
                pre[i][2] = {i-1,0};
            }
            else{
                pre[i][2] = {i-1,1};
            }
        }
    }
    pair<int,int>cur;
    if(min({dp[n][0],dp[n][1],dp[n][2]})==dp[n][0]){
        cur = {n,0};
    }
    else if(min({dp[n][0],dp[n][1],dp[n][2]})==dp[n][1]){
        cur = {n,1};
    }
    else{
        cur = {n,2};
    }
    cout << min({dp[n][0],dp[n][1],dp[n][2]}) << '\n';
    string ans;
    while(true){
        if(cur.first==0)break;
        if(cur.second==0)ans.push_back('R');
        else if(cur.second==1)ans.push_back('G');
        else ans.push_back('B');
        cur = pre[cur.first][cur.second];
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
}
