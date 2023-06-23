#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("subarrays.in", "r", stdin);
    // freopen("subarrays.out", "w", stdout);

    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        string input; cin >> input;
        int prefix = 0;
        unordered_map<int, int> diff;
        for (int i = 0; i < n; i++) {
            prefix += input.at(i) - '0';
            diff[prefix-i-1]++;
        }
        diff[0]++;
        int ans = 0;
        for (auto i : diff) {
            ans += i.second * (i.second-1) / 2;
        }
        cout << ans << endl;
    }
}

