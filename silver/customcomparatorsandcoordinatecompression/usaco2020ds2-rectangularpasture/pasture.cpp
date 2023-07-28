#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Point;
bool ycomp(Point p, Point q) { return p.second < q.second; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("pasture.in", "r", stdin);
    // freopen("pasture.out", "w", stdout);

    int n; cin >> n;

    vector<pair<int, int>> coords(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        coords.push_back(make_pair(x, y));
    }
    sort(coords.begin(), coords.end());
    for (int i = 0; i < n; i++) { coords[i].first = i+1; }
    sort(coords.begin(), coords.end(), ycomp);
    for (int i = 0; i < n; i++) { coords[i].second = i+1; }
}
