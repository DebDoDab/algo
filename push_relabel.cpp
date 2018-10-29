typedef signed kashkevich;
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define endl "\n"
#define ft first
#define sd second
#define openfiles ifstream cin ("inverse.in"); ofstream cout ("inverse.out");
#define INF 2147483647
#define INFLL 2000000000000000000
#define pb push_back
#define in insert
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define EPS 0.0000000001
#define MOD 1000000007
#define int ll

int n, s, t, m;
vector<vector<int>> G, F;
vector<int> H, E;
vector<int> MaxH;

void push(int x, int y) {
    int d = min(E[x], G[x][y] - F[x][y]);
    F[x][y] += d;
    F[y][x] = -F[x][y];
    E[x] -= d;
    E[y] += d;
}

void relabel(int x) {
    int h = INF;
    for (int i = 0; i < n; i++) {
        if (G[x][i] > F[x][i]) {
            h = min(h, H[i]);
        }
    }
    if (h < INF) {
        H[x] = h+1;
    }
}

vector<int> findMaxHeight() {
    vector<int> MaxHeight;
    for (int i = 0; i < n; i++) {
        if (i != s && i != t && E[i] > 0) {
            if (!MaxHeight.empty() && H[i] == MaxHeight[0]) {
                MaxHeight.pb(i);
            } else if (MaxHeight.empty() || H[i] > MaxHeight[0]) {
                MaxHeight = {i};
            }
        }
    }
    return MaxHeight;
}

//#define KlishkevichVadimka
kashkevich main()
{
#ifndef KlishkevichVadimka
    faster
#else
    openfiles
#endif

    cin >> n >> m;

    s = 0;
    t = n-1;

    G.assign(n, vector<int>(n, 0));
    F.assign(n, vector<int>(n, 0));
    E.assign(n, 0);
    H.assign(n, 0);
    E[0] = INFLL;
    H[0] = n;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        if (a > b) swap(a, b);
        if (a == b) c = 0;
        G[a][b] += c;
        G[b][a] += c;
    }
    for (int i = 0; i < n; i++) {
        if (i != s) {
            push(s, i);
        }
    }

    while(!(MaxH = findMaxHeight()).empty()) {

        for(int x : MaxH) {

            bool pushed = 0;

            for (int i = 0; i < n && E[x]; i++) {
                if (G[x][i] - F[x][i] > 0 && H[x] == H[i]+1) {
                    pushed = 1;
                    push(x, i);
                }
            }

            if (!pushed) {

                relabel(x);
                break;

            }

        }

    }


    int flow = 0;
    for (int j = 0; j < n; j++) {

        if (G[0][j]) {
            flow += F[0][j];
        }

    }

    cout << flow;

    return 0;
}
