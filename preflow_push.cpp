typedef signed kashkevich;
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl "\n"
#define INF 2000000000
#define INFLL 7000000000000000000ll
#define ft first
#define EPS 0.000001
#define sd second
#define pb push_back
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define openfiles ifstream cin("input.txt");ofstream cout("output.txt");
#define in insert

int n, s, t, m;
vector<vector<int>> G, F;
vector<int> H, E;
vector<int> MaxH;

vector<int> aaa() {
    vector<int> MX;
    for (int i = 1; i <= n; i++) {
        if (E[i] > 0 && !MX.empty() && H[i] > H[MX[0]]) {
            MX.clear();
        }
        if (E[i] > 0 && (MX.empty() || H[i] == H[MX[0]])) {
            MX.pb(i);
        }
    }
    return MX;

}

signed main()
{
    //openfiles;
    //faster;

    cin >> n >> m;

    t = 0;
    s = n+1;

    G.assign(n+2, vector<int>(n+2, 0));
    F.assign(n+2, vector<int>(n+2, 0));
    E.assign(n+2, 0);
    H.assign(n+2, 0);
    E[0] = INF;
    H[0] = n+2;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        G[0][x] = 1;
        F[0][x] = G[0][x];
        F[x][0] = -F[0][x];
        E[x] = G[0][x];
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        G[x][s] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if (x == '1')
                G[i][j] = INF;
        }
    }

    while(!(MaxH = aaa()).empty()) {

        if (MaxH.empty()) {
            break;
        }

        for(int x : MaxH) {

            bool pushed = 0;

            for (int i = 0; i <= n+1 && E[x]; i++) {
                if (G[x][i] - F[x][i] > 0 && H[x] == H[i]+1) {
                    pushed = 1;
                    int d = min(G[x][i] - F[x][i], E[x]);
                    F[x][i] += d;
                    F[i][x] -= d;
                    E[x] -= d;
                    E[i] += d;
                }
            }

            if (!pushed) {

                int d = INF;
                for (int i = 0; i <= n+1; i++) {
                    if (G[x][i] - F[x][i] > 0) {
                        d = min(d, H[i]);
                    }
                }
                if (d < INF) {
                    H[x] = d + 1;
                }
                break;

            }

        }

    }


    int flow = 0;
    for (int j = 0; j <= n+1; j++) {

        if (G[0][j]) {
            flow += F[0][j];
        }

    }

    if (flow == m) {
        cout << "YES\n";
    } else {
        cout << "NO";
    }

    return 0;
}
