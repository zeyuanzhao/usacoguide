#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("books.in", "r", stdin);
    // freopen("books.out", "w", stdout);

    int n, t;
    cin >> n >> t;
    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }
    int l = 0, r = 0, cur = 0;
    int ans = 0;
    while (l < n && r < n) {
        while (r < n) {
            cur += books[r++];
            if (cur > t) {
                cur -= books[--r];
                break;
            }
        }
        ans = max(ans, r-l);
        cur -= books[l++];
    }
    cout << ans << endl;
}
