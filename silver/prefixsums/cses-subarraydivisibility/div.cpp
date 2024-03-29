#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<long> arr (n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    unordered_map<long, int> sums;
    long prefix = 0;
    long ans = 0;
    sums[0] = 1;
    for (int i = 1; i <= n; i++) {
        prefix = ((prefix + arr[i]) % n + n) % n;
        ans += sums[prefix];
        sums[prefix]++;
    }
    cout << ans;
}
