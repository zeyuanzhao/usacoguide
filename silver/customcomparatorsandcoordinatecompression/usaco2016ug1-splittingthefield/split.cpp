#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("split.in", "r", stdin);
    // freopen("split.out", "w", stdout);

    int n; cin >> n;
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int twoarea = INT_MAX;
    int ylen;
    for (int i = 0; i < n; i++) {

        int xlen1 = cows[i-1].first - cows[0].first;
        int xlen2 = cows[n-1].first - cows[i].first;

        int h = INT_MIN;
        int l = INT_MAX;
        for (int j = 0; j < i; j++) {
            h = max(h, cows[j].second);
            l = min(l, cows[j].second);
        }
        int ylen1 = h - l;

        h = INT_MIN;
        l = INT_MAX;
        for (int j = i; j <= n-1; j++) {
            h = max(h, cows[j].second);
            l = min(l, cows[j].second);
        }
        int ylen2 = h - l;

        twoarea = min(twoarea, xlen1*ylen1 + xlen2*ylen2);

        if (i == 0) {
            ylen = ylen2;
        }
    }
    int onearea = (cows[n-1].first-cows[0].first) * ylen;
    int areadiff = onearea - twoarea;
    cout << areadiff;
}
