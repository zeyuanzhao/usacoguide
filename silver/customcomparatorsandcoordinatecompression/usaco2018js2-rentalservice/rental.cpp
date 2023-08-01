#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    vector<pair<int, int>> stores(m);
    for (int i = 0; i < m; i++) {
        cin >> stores[i].first >> stores[i].second;
    }

    vector<int> rent(r);
    for (int i = 0; i < r; i++) {
        cin >> rent[i];
    }

    sort(cows.begin(), cows.end(), greater<int>());
    sort(stores.begin(), stores.end(), [](const pair<int, int> a, const pair<int, int> b) { return a.second > b.second; });
    sort(rent.begin(), rent.end(), greater<int>());

    int curr_cow = 0;
    int curr_store = 0;
    int curr_rent = 0;
    long long total = 0;

    while (curr_cow < n) {
        int milk_value = 0;
        vector<pair<int, int>> add_back;
        int reverse_store = 0;
        int reverse_cow = 0;
        while (cows[curr_cow] > 0 && curr_store < m) {
            int milk_amount = min(cows[curr_cow], stores[curr_store].first);
            reverse_cow += milk_amount;
            milk_value += milk_amount * stores[curr_store].second;
            cows[curr_cow] -= milk_amount;
            stores[curr_store].first -= milk_amount;
            add_back.push_back({curr_store, milk_amount});
            if (stores[curr_store].first == 0) { 
                curr_store++;
                reverse_store++;
            }
        }
        if (curr_rent >= r || milk_value > rent[curr_rent]) {
            total += milk_value;
            curr_cow++;
        } else {
            for (auto i : add_back) {
                stores[i.first].first += i.second;
            }
            curr_store -= reverse_store;
            total += rent[curr_rent];
            curr_rent++;
            cows[curr_cow] += reverse_cow;
            n--;
        }
    }
    cout << total;
}
