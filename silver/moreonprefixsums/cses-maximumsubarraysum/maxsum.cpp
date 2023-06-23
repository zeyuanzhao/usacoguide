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
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        int num; cin >> num; prefix += num;
        ans = max(ans, prefix-small);
        small = min(small, prefix);
    }
    cout << ans;
}
