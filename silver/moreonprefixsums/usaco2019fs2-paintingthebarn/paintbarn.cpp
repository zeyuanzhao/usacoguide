#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    int n, k; cin >> n >> k;
    const int SIZE = 1001;
    vector<vector<int>> barn(SIZE, vector<int> (SIZE, 0));

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j < x2; j++) {
            barn[j][y1]++;
            barn[j][y2]--;
        }
    }
    int ans = 0;
    int layers = 0;
    for (int i = 0; i < SIZE-1; i++) {
        for (int j = 0; j < SIZE-1; j++) {

            if(barn[i][j] == k) ans++;
            barn[i][j+1] += barn[i][j];
        }
    }
    cout << ans;
}
