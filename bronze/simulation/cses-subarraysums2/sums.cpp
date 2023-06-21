#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> sums(n+1, 0);
    for (int i = 1; i < n+1; i++) {
        sums[i] = sums[i-1] + arr[i];
    }
    
    int count = 0;
    for (int i = 1; i < n+1; i++) {
        for (int j = i; j < n+1; j++) {
            if (sums[j] - sums[i-1] == x) count++;
        }
    }
    cout << count;
}
