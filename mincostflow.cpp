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

    struct rib {
        int dest, maxNumber, cost, flow, backRib;
    };

    ///n - number of verticles, m - number of ribs, k - flow, that we need, s - source, t - sink
    int n, m, k, s, t;
    vector<vector<rib>> G;

//#define KlishkevichVadimka
kashkevich main()
{
#ifndef KlishkevichVadimka
    faster
#else
    openfiles
#endif

    cin >> n >> m >> k >> s >> t;
    s--, t--;
    G.assign(n, vector<rib>(0, {0, 0, 0, 0, 0}));
    for (int i = 0; i < m; i++) {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        a--, b--;
        rib fst = {b, c, f, 0, int(G[b].size())},
            snd = {a, 0, -f, 0, int(G[a].size())};
        G[a].pb(fst);
        G[b].pb(snd);
    }

    int flow = 0, cost = 0;
    while (flow < k) {
        vector<int> Used(n), Dist(n, INF), Parent(n), ParentRib(n);
        deque<int> O;

        //levit
        O.pb(s);
        Dist[s] = 0;
        while (!O.empty()) {
            int x = O.front();
            O.pop_front();
            Used[x] = 2;
            for (int i = 0; i < G[x].size(); i++) {
                rib &r = G[x][i];
                if (r.flow < r.maxNumber && Dist[x] + r.cost < Dist[r.dest]) {
                    Dist[r.dest] = Dist[x] + r.cost;
                    if (Used[r.dest] == 0) {
                        O.pb(r.dest);
                    } else if (Used[r.dest] == 2) {
                        O.push_front(r.dest);
                    }
                    Used[r.dest] = 1;
                    Parent[r.dest] = x;
                    ParentRib[r.dest] = i;
                }
            }
        }

        //cant get to sink
        if (Dist[t] == INF) {
            break;
        }

        //flow, that we add at this iteration
        int addflow = k-flow;
        for (int x = t; x != s; x = Parent[x]) {
            addflow = min(addflow, G[Parent[x]][ParentRib[x]].maxNumber - G[Parent[x]][ParentRib[x]].flow);
        }
        
        //add flow
        for (int x = t; x != s; x = Parent[x]) {
            G[Parent[x]][ParentRib[x]].flow += addflow;
            G[x][G[Parent[x]][ParentRib[x]].backRib].flow -= addflow;
            cost += G[Parent[x]][ParentRib[x]].cost * addflow;
        }
        flow += addflow;

    }

    if (flow < k) {
        cout << -1 << endl;
    } else {
        cout << cost << endl;
    }

}














