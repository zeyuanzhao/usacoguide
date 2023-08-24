#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n, x; 
    cin >> n >> x;
    vector<pair<int, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    sort(nums.begin(), nums.end());
    
    if (n < 3 || x < 3) {
        return "IMPOSSIBLE";
    }

    for (int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        while (l < r) {
            int target = x - nums[i].first;
            if (l != i && r != i && nums[l].first + nums[r].first == target) {
                return "" + to_string(nums[l].second+1) + " " + to_string(nums[r].second+1) + " " + to_string(nums[i].second+1);
            }
            if (nums[l].first + nums[r].first < target) {
                l++;
            } else {
                r--;
            }
        }
    }

    return "IMPOSSIBLE";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("sum.in", "r", stdin);
    // freopen("sum.out", "w", stdout);

    cout << solve() << endl;
}
