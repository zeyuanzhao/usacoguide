#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sums.in", "r", stdin);
    // freopen("sums.out", "w", stdout);

    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int l = 0, r = 0, sum = 0;
    int count = 0;
    while (l < n && r <= n) {
        while (r < n) {
            sum += nums[r++];
            if (sum >= x) {
                break;
            }
        }
        if (sum == x) {
            count++;
        }
        sum -= nums[l++];
    }

    cout << count << endl;
}
