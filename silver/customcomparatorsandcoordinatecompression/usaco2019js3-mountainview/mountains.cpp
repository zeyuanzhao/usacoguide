#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int n; cin >> n;
    vector<pair<int, int>> mountains(n);
    for (int i = 0; i < n; i++) {
        cin >> mountains[i].first >> mountains[i].second;
    }

    sort(mountains.begin(), mountains.end(), [](pair<int, int> a, pair<int, int> b) { return a.second > b.second; });

    vector<pair<int, int>> peaks;
    peaks.push_back(mountains[0]);
    for (int i = 1; i < n; i++) {
        bool seeable = true;
        for (int j = 0; j < peaks.size(); j++) {
            int ydiff = mountains[j].second - mountains[i].second;
            int xdiff = abs(mountains[j].first - mountains[i].first);
            if (xdiff <= ydiff) {
                seeable = false;
            }
        }
        if (seeable) {
            peaks.push_back(mountains[i]);
        }
    }
    cout << peaks.size();
}
