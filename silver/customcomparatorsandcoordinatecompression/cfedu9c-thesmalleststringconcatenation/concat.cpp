#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("concat.in", "r", stdin);
    // freopen("concat.out", "w", stdout);

    int n; cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    sort(words.begin(), words.end(), [](string a, string b) { return (a+b) < (b+a); });
    string res;
    for (string word : words) {
        res += word;
    }
    cout << res;
}
