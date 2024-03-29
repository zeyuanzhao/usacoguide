#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("maxsum.in", "r", stdin);
    // freopen("maxsum.out", "w", stdout);

    int n; cin >> n;
    long long prefix = 0;
    long long small = 0;
    long long ans = LONG_MIN;
    for (int i = 0; i < n; i++) {
        long num; cin >> num; prefix += num;
        ans = max(ans, prefix-small);
        small = min(small, prefix);
    }
    cout << ans;
}
