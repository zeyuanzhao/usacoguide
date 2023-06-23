#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);

    int n; cin >> n;
    int prefix = 0;
    int small = 0;
    int large = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num; prefix += num;
        small = min(small, prefix);
        large = max(large, prefix);
    }
    cout << large - small;
}
