#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007;
 
int main(){
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<bool> danger(n+1, false);
    for(int i=0;i<m;i++){
        int a; scanf("%d", &a);
        danger[a] = true;
    }
    
    vector<long long> dp(n+1, 0), S(n+1, 0);
    dp[0] = 1;
    S[0] = 1;
    
    for(int i=1;i<=n;i++){
        if(danger[i]){
            dp[i] = 0;
        } else {
            long long upper = S[i-1];
            long long lower = (i-1-k >= 0) ? S[i-1-k] : 0;
            dp[i] = ((upper - lower) % MOD + MOD) % MOD;
        }
        S[i] = (S[i-1] + dp[i]) % MOD;
    }
    
    printf("%lld\n", dp[n] % MOD);
    return 0;
}
