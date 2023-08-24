#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
        m += cows[i].first;
    }
    sort(cows.begin(), cows.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
    
    int ans = 0;
    int a = 0, b = n-1;
    for (int i = 0; i < m/2; i++) {
        int time = cows[a].second + cows[b].second;
        if (--cows[a].first == 0) {
            a++;
        }
        if (--cows[b].first == 0) {
            b--;
        }
        ans = max(ans, time);
    }
    cout << ans << endl;
}
