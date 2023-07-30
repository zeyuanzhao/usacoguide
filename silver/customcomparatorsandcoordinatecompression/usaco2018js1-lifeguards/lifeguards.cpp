#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int l, r;
    bool operator<(const Cow &y) { return l < y.l; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n; cin >> n;

    vector<Cow> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].l >> cows[i].r;
    }
    
    sort(cows.begin(), cows.end());

    int right = 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (cows[i].r > right) {
            total += cows[i].r - max(right, cows[i].l);
            right = cows[i].r;
        }
    }

    right = 0;
    int minAloneTime = total;
    Cow end;
    end.l = cows[n-1].r;
    cows.push_back(end);
    for (int i = 0; i < n; i++) {
        int aloneTime = min(cows[i+1].l, cows[i].r) - max(cows[i].l, right);
        minAloneTime = min(minAloneTime, aloneTime);
        right = max(right, cows[i].r);
    }

    cout << total - max(0, minAloneTime);
}
