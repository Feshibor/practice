#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
 
        int pair = min(2 * a, b);
        int pairs = n / 2;
        int rest = n % 2;
 
        int total = pairs * pair + rest * a;
 
        printf("%d\n", total);
    }
    return 0;
}
