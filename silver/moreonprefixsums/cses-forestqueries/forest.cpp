#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("forest.in",w "r", stdin);
    // freopen("forest.out", "w", stdout);

    int n, q; cin >> n >> q;
    vector<vector<int>> rowprefix(n+1, vector<int> (n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char inp; cin >> inp;
            rowprefix[i][j] = rowprefix[i][j-1] + (inp == '*' ? 1 : 0);
        }
    }
    
    vector<vector<int>> prefix(n+1, vector<int> (n+1, 0));
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            prefix[i][j] = prefix[i-1][j] + rowprefix[i][j];
        }
    }

    while (q--) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y1-1][x2] - prefix[y2][x1-1] + prefix[y1-1][x1-1] << endl;
    }
}
