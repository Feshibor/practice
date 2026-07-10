#include <bits/stdc++.h>
using namespace std;
 
vector<int> buildZ(const string &w) {
    int len = (int)w.size();
    vector<int> z(len, 0);
    int left = 0, right = 0;
    for (int idx = 1; idx < len; idx++) {
        if (idx < right)
            z[idx] = min(right - idx, z[idx - left]);
        while (idx + z[idx] < len && w[z[idx]] == w[idx + z[idx]])
            z[idx]++;
        if (idx + z[idx] > right) {
            left = idx;
            right = idx + z[idx];
        }
    }
    return z;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string realName, dreamName;
    cin >> realName >> dreamName;
 
    int n = (int)realName.size();
    if ((int)dreamName.size() != n) {
        cout << -1 << "\n";
        return 0;
    }
    string glue = dreamName + "#" + realName + realName;
    vector<int> z = buildZ(glue);
 
    int offsetStart = n + 1; 
    int bestShift = -1;
 
    for (int doublePos = 0; doublePos < n; doublePos++) {
        int zi = z[offsetStart + doublePos];
        if (zi >= n) {
            int shift = (n - doublePos) % n;
            if (bestShift == -1 || shift < bestShift)
                bestShift = shift;
        }
    }
 
    cout << bestShift << "\n";
    return 0;
}
