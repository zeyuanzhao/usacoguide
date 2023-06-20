#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n; cin >> n;
    vector<string> segments;
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < n; i++) {
        string segment; int a; int b;
        cin >> segment >> a >> b;
        segments.push_back(segment);
        x.push_back(a);
        y.push_back(b);
    }
    
    int high = 999999;
    int low = -999999;
    bool start = false;
    for (int i = n-1; i >= 0; i--) {
        if (segments[i] == "on" && start) {
            low -= y[i];
            high -= x[i];
            low = max(low, 0);
            high = max(high, 0);
        } else if (segments[i] == "off" && start) {
            low += x[i];
            high += y[i];
        } else if (segments[i] == "none") {
            start = true;
            low = max(low, x[i]);
            high = min(high, y[i]);
        }
    }
    cout << low << " " << high << endl;

    high = 999999;
    low = -999999;
    start = false;
    for (int i = 0; i < n; i++) {
        if (segments[i] == "off" && start) {
            low -= y[i];
            high -= x[i];
            low = max(low, 0);
            high = max(high, 0);
        } else if (segments[i] == "on" && start) {
            low += x[i];
            high += y[i];
        } else if (segments[i] == "none") {
            start = true;
            low = max(low, x[i]);
            high = min(high, y[i]);
        }
    }
    cout << low << " " << high << endl;

}