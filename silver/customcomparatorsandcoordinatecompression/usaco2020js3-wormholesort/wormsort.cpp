#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("wormsort.in", "r", stdin);
    // freopen("wormsort.out", "w", stdout);

    int n, m; cin >> n >> m;
    vector<int> cows (n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    vector<tuple<int, int>> wormholes (m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        wormholes[a] = make_tuple(b, w);
        wormholes[b] = make_tuple(a, w);
    }
    
}
