#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    scanf("%d", &n);
 
    vector<vector<long long>> row(n);
    for(int i = 0; i < n; i++){
        row[i].resize(i+1);
        for(int j = 0; j <= i; j++){
            long long x;
            scanf("%lld", &x);
            row[i][j] = x;
        }
    }
 
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            long long best;
            if(j == 0){
                best = row[i-1][0];
            } else if(j == i){
                best = row[i-1][i-1];
            } else {
                best = max(row[i-1][j-1], row[i-1][j]);
            }
            row[i][j] += best;
        }
    }
 
    long long ans = 0;
    for(int j = 0; j < n; j++){
        ans = max(ans, row[n-1][j]);
    }
 
    printf("%lld\n", ans);
    return 0;
}
