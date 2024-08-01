#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        map<int,int>cnt;
        cnt.clear();
        for(int i = 1;i<=n;i++){
            int a;
            cin >> a;
            cnt[a]++;
        }
        deque<int>v;
        for(auto i:cnt){
            if(i.second>=k){
                v.push_back(i.first);
            }
        }
        if(v.empty()){
            cout << "-1\n";
            continue;
        }
        sort(v.begin(),v.end());
        int ans = -1;
        int lft,rit;
        while(!v.empty()){
            int cur = v.front();
            v.pop_front();
            int r = cur;
            while(!v.empty() && v.front()==r+1){
                r = r+1;
                v.pop_front();
            }
            if(r-cur>ans){
                ans = r-cur;
                lft = cur;
                rit = r;
            }
        }
        cout << lft << ' ' << rit << '\n';
    }
}
