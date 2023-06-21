#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("sums.in", "r", stdin);

    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> sums;
    int prefix = 0;
    int ans = 0;
    sums[0] = 1;
    for (int i = 1; i <= n; i++) {
        prefix += arr[i];
        ans += sums[prefix-x];
        sums[prefix]++;
    }
    cout << ans;
}
