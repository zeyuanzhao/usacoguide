#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n; cin >> n;
    vector<int> rooms(n);

    for (int i = 0; i < n; i++) {
        cin >> rooms[i];
    }

    int ans = INT32_MAX;
    for (int i = 0; i < n; i++) {
        int distance = 0;
        for (int j = 0; j < n; j++) {
            distance += j * rooms[(i+j)%n];
        }
        ans = min(ans, distance);
    }
    cout << ans;
}