#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    int n, k, b;
    cin >> n >> k >> b;

    vector<int> signals(b);
    for (int i = 0; i < b; i++) {
        cin >> signals[i];
    }
    sort(signals.begin(), signals.end());
    signals.push_back(n+1);

    vector<int> prefix(n+1, 0);
    int run = 1;
    for (int i = 0; i < b; i++) {
        for (int j = signals[i]; j < signals[i+1]; j++) {
            prefix[j] = run;
        }
        run++;
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n-k+1; i++) {
        int dif = prefix[i+k-1] - prefix[i-1];
        ans = min(ans, dif);
    }
    cout << ans;
}
