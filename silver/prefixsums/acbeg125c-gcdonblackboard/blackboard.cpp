#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("blackboard.in", "r", stdin);
    // freopen("blackboard.out", "w", stdout);

    int n; cin >> n;
    vector<int> nums(n);
    for (auto &i : nums) {
        cin >> i;
    }

    vector<int> prefix(n+2);
    prefix[0] = nums[0];
    vector<int> suffix(n+2);
    suffix[n+1] = nums[n-1];
    for (int i = 1; i < n; i++) {
        prefix[i] = __gcd(prefix[i-1], nums[i-1]);
    }
    for (int i = n; i > 1; i--) {
        suffix[i] = __gcd(suffix[i+1], nums[i-1]);
    }
    prefix[0] = suffix[2];
    suffix[n+1] = prefix[n-1];
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, __gcd(prefix[i-1], suffix[i+1]));
    }
    cout << ans;
}