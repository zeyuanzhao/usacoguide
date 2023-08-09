#include <bits/stdc++.h>
using namespace std;

struct Cow {
    int x;
    int y; 
    int id;
    Cow (int x_i, int y_i, int id_i) {
        x = x_i;
        y = y_i;
        id = id_i;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("rut.in", "r", stdin);
    // freopen("rut.out", "w", stdout);

    int N; cin >> N;
    vector<Cow> north;
    vector<Cow> east;

    for (int i = 0; i < N; i++) {
        char dir; cin >> dir;
        int x, y; cin >> x >> y;
        if (dir == 'N') {
            north.push_back(Cow(x, y, i));
        } else {
            east.push_back(Cow(x, y, i));
        }
    }
    sort(north.begin(), north.end(), [](Cow a, Cow b) { return a.x < b.x; });
    sort(east.begin(), east.end(), [](Cow a, Cow b) { return a.y < b.y; });

    vector<bool> stopped(N, false);
    vector<int> blame(N, 0);

    for (Cow n : north) {
        for (Cow e : east) {
            if (!stopped[n.id] && !stopped[e.id] && e.y >= n.y && n.x >= e.x) {
                int xdiff = n.x - e.x;
                int ydiff = e.y - n.y;
                if (xdiff > ydiff) {
                    stopped[e.id] = true;
                    blame[n.id] += 1 + blame[e.id];
                } else if (xdiff < ydiff) {
                    stopped[n.id] = true;
                    blame[e.id] += 1 + blame[n.id];
                }
            }
        }
    }
    for (int b : blame) {
        cout << b << endl;
    }
}
