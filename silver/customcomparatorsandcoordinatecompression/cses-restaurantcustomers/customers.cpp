#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("customers.in", "r", stdin);
    // freopen("customers.out", "w", stdout);

    int n; cin >> n;
    
    vector<int> in(n);
    vector<int> out(n);

    for (int i = 0; i < n; i++) {
        cin >> in[i];
        cin >> out[i];
    }

    sort(in.begin(), in.end());
    sort(out.begin(), out.end());

    vector<int> sums;
    int i = 0; 
    int j = 0;
    while (i != n && j != n) {
        if (in[i] < out[j]) {
            int sum = 0;
            do {
                sum++;
                i++;
            } while (in[i-1] == in[i]);
            sums.push_back(sum);
        }
        else if (in[i] > out[i]) {
            int sum = 0;
            do {
                sum--;
                j++;
            } while (out[j-1] == out[j]);
            sums.push_back(sum);
        }
        else {
            int sum = 0;
            do {
                sum++;
                i++;
            } while (in[i-1] == in[i]);
            do {
                sum--;
                j++;
            } while (out[j-1] == out[j]);
            sums.push_back(sum);
        }
    }
    int customers = 0;
    int ans = -1;
    for (int i = 0; i < sums.size(); i++) {
        customers += sums[i];
        ans = max(ans, customers);
    }
    cout << ans;
}
