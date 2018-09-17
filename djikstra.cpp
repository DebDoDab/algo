typedef signed kashkevich;
#include <bits/stdc++.h>
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
#define pii pair<int, int>
#define pb push_back
#define in insert
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define EPS 0.0000000000001
#define MOD 1000000007

    int n, m;
    vector<vector<pii>> G;

//#define KlishkevichVadimka
kashkevich main()
{
#ifndef KlishkevichVadimka
    faster
#else
    openfiles
#endif

    cin >> n >> m;
    G.assign(n, vector<pii>(0, {0, 0}));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].pb({b, c});
        G[b].pb({a, c});
    }

    set<pii> O;
    vector<int> D(n, INF), P(n);
    O.in({0, 0});
    D[0] = 0;

    while (!O.empty()) {
        int x = O.begin() -> sd;
        O.erase(O.begin());
        for (pii y : G[x]) {
            if (D[y.ft] > D[x] + y.sd) {
                O.erase({D[y.ft], y.ft});
                D[y.ft] = D[x] + y.sd;
                O.in({D[y.ft], y.ft});
                P[y.ft] = x;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << " : " << D[i] << endl;
    }

}














