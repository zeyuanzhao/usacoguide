#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> arr (n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> sums;
    int prefix = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        prefix = (prefix + arr[i]) % n;
        ans += sums[prefix];
        sums[prefix]++;
    }
    cout << ans;
}
