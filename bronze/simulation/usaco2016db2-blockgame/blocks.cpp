#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n; cin >> n;
    unordered_map<char, int> answer;
    for (char c = 'a'; c <= 'z'; c++) {
        answer[c] = 0;
    }

    unordered_map<char, int> aletters;
    unordered_map<char, int> bletters;
    for (int i = 0; i < n; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            aletters[c] = 0;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            bletters[c] = 0;
        }
        string a, b;
        cin >> a >> b;
        for (auto c : a) {
            aletters[c]++;
        }
        for (auto c : b) {
            bletters[c]++;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            answer[c] += max(aletters[c], bletters[c]);
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        cout << answer[c] << endl;
    }
}
