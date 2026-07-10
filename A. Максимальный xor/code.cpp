#include <bits/stdc++.h>
using namespace std;
 
struct Trie {
    vector<array<int,2>> ch;
    Trie() { ch.push_back({-1, -1}); }
 
    void insert(int x) {
        int cur = 0;
        for (int b = 26; b >= 0; b--) {
            int bit = (x >> b) & 1;
            if (ch[cur][bit] == -1) {
                ch.push_back({-1, -1});
                ch[cur][bit] = (int)ch.size() - 1;
            }
            cur = ch[cur][bit];
        }
    }
 
    int queryMax(int x) {
        int cur = 0, res = 0;
        for (int b = 26; b >= 0; b--) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (ch[cur][want] != -1) {
                res |= (1 << b);
                cur = ch[cur][want];
            } else {
                cur = ch[cur][bit];
            }
        }
        return res;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
 
    int n1 = n / 2;
    int n2 = n - n1;
 
    vector<int> A(n1), B(n2);
    for (int i = 0; i < n1; i++) A[i] = a[i];
    for (int i = 0; i < n2; i++) B[i] = a[n1 + i];
 
    int sizeA = 1 << n1;
    vector<int> xorA(sizeA, 0);
    for (int s = 1; s < sizeA; s++) {
        int low = s & (-s);
        int idx = __builtin_ctz(low);
        xorA[s] = xorA[s ^ low] ^ A[idx];
    }
 
    int sizeB = 1 << n2;
    vector<int> xorB(sizeB, 0);
    for (int t = 1; t < sizeB; t++) {
        int low = t & (-t);
        int idx = __builtin_ctz(low);
        xorB[t] = xorB[t ^ low] ^ B[idx];
    }
 
    vector<Trie> tries(n1 + 1);
    for (int s = 0; s < sizeA; s++) {
        int cnt = __builtin_popcount(s);
        tries[cnt].insert(xorA[s]);
    }
 
    int ans = 0;
    for (int t = 0; t < sizeB; t++) {
        int cnt2 = __builtin_popcount(t);
        int need = k - cnt2;
        if (need < 0 || need > n1) continue;
        int cand = tries[need].queryMax(xorB[t]);
        ans = max(ans, cand);
    }
 
    cout << ans << "\n";
    return 0;
}
