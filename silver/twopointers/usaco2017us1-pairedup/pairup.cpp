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
    while (a <= b) {
        int time = cows[a].second + cows[b].second;
        int num = min(cows[a].first, cows[b].first);
        if (a == b) {
            num /= 2;
        }
        cows[a].first -= num;
        cows[b].first -= num;
        if (cows[a].first == 0) a++;
        if (cows[b].first == 0) b--;
        ans = max(time, ans);
    }
    cout << ans << endl;
}
