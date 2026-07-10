#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        
        long long best = 0;
        for(int i = 0; i <= 5; i++){
            for(int j = 0; j <= 5 - i; j++){
                int k = 5 - i - j; 
                long long prod = (a + i) * (b + j) * (c + k);
                best = max(best, prod);
            }
        }
        
        printf("%lld\n", best);
    }
    return 0;
}
