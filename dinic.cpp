#include <bits/stdc++.h>
#include <chrono>

using namespace std;

typedef tuple<int, int, int, int> t3;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define endl "\n"
#define ft first
#define sd second
#define openfiles ifstream cin ("input.txt"); ofstream cout ("output.txt");
#define INF 2147483647
#define INFLL 10000000000000000
#define pb push_back
#define in insert
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define EPS ld(0.00000000001)
#define MOD 1000000007

    int n, m;
    vector<t3> Edges;
    vector<vector<int>> G;
    vector<int> Used;
    vector<int> Ed;

//#define KlishkevichVadimka
signed main()
{
#ifndef KlishkevichVadimka
    faster
#else
    openfiles
    faster
#endif
    ;

    cin >> n >> m;
    G.resize(n+2+m);

    auto add = [&] (int v, int u, int c) {
        G[v].pb(Edges.size());
        Edges.pb(make_tuple(v, u, c, 0));
        G[u].pb(Edges.size());
        Edges.pb(make_tuple(u, v, 0, 0));
    };

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(0, i, x);
    }

    ll sum = 0ll;

    for (int i = n+1; i < n+1+m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, i, INF);
        add(b, i, INF);
        add(i, n+1+m, c);
        sum += c;
    }

    auto bfs = [&](int x) {
        deque<int> O = {x};
        Used[x] = 1;
        while (!O.empty() && !Used[n+1+m]) {
            x = O.front();
            O.pop_front();
            for (int y : G[x]) {
                if (!Used[get<1>(Edges[y])] && get<2>(Edges[y]) > get<3>(Edges[y])) {
                    Used[get<1>(Edges[y])] = Used[x] + 1;
                    O.pb(get<1>(Edges[y]));
                }
            }
        }
        return Used[n+1+m];
    };

    function<int(int, int)> dfs = [&] (int x, int flow) {
        if (x == n+1+m || !flow) return flow;
        for (; Ed[x] < G[x].size(); Ed[x]++) {
            int y = G[x][Ed[x]];
            if (Used[get<1>(Edges[y])] != Used[x] + 1) continue;
            int f = dfs(get<1>(Edges[y]), min(flow, get<2>(Edges[y]) - get<3>(Edges[y])));
            if (f) {
                get<3>(Edges[y]) += f;
                get<3>(Edges[y^1]) -= f;
                return f;
            }
        }
        return 0;
    };


    Used.assign(n+2+m, 0);
    Ed.assign(n+2+m, 0);

    while(bfs(0)) {
        ll flow = 0;
        while (flow = dfs(0, INF)) {
            sum -= flow;
        }
        Used.assign(n+2+m, 0);
        Ed.assign(n+2+m, 0);
    }

    cout << sum << endl;








}






















