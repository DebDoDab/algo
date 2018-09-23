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

struct node {
    int cnt, max0, max1, t;
};

    int n, m;
    vector<node> D;

    node merge(node x, node y) {
        return {x.cnt + y.cnt, max(x.max0, y.max0), max(x.max1, y.max1), 0};
    }

    void build(int v, int l, int r) {
        if (l == r) {
            D[v] = {0, r, -INF, 0};
        } else {
            int m = (l + r) / 2;

            build(v<<1, l, m);
            build(v<<1|1, m+1, r);

            D[v] = merge(D[v<<1], D[v<<1|1]);
        }
    }

    void push(int v, int l, int r) {
        int c = D[v].t;
        D[v].t = 0;
        int m = (r + l) / 2;
        if (c == 1) {
            D[v<<1].cnt = (m - l +1);
            D[v<<1].max0 = -INF;
            D[v<<1].max1 = m;
            D[v<<1].t = 1;

            D[v<<1|1].cnt = (r - m);
            D[v<<1|1].max0 = -INF;
            D[v<<1|1].max1 = r;
            D[v<<1|1].t = 1;
        } else {
            D[v<<1].cnt = 0;
            D[v<<1].max1 = -INF;
            D[v<<1].max0 = m;
            D[v<<1].t = 2;

            D[v<<1|1].cnt = 0;
            D[v<<1|1].max1 = -INF;
            D[v<<1|1].max0 = r;
            D[v<<1|1].t = 2;
        }
    }

    pii get(int v, int l, int r, int tl, int tr) {

        if (tl > tr) return {-INF, -INF};

        if (l == tl && r == tr) {
            return {D[v].max0, D[v].max1};
        }

        if (D[v].t > 0) {
            push(v, l, r);
        }

        int m = (l + r) / 2;
        pii x = get(v<<1, l, m, tl, min(m, tr));
        pii y = get(v<<1|1, m+1, r, max(tl, m+1), tr);
        return {max(x.ft, y.ft), max(x.sd, y.sd)};

    }

    void add(int v, int l, int r, int tl, int tr, int c) {

        if (tl > tr) return ;

        if (l == tl && r == tr) {
            if (c == 1) {
                D[v].cnt = (r - l +1);
                D[v].max0 = -INF;
                D[v].max1 = r;
                D[v].t = 1;
            } else {
                D[v].cnt = 0;
                D[v].max1 = -INF;
                D[v].max0 = r;
                D[v].t = 2;
            }
            return;
        }

        if (D[v].t > 0) {
            push(v, l, r);
        }

        int m = (l + r) / 2;
        add(v<<1, l, m, tl, min(m, tr), c);
        add(v<<1|1, m+1, r, max(tl, m+1), tr, c);

        D[v] = merge(D[v<<1], D[v<<1|1]);
        return ;

    }

//#define KlishkevichVadimka
kashkevich main()
{
#ifndef KlishkevichVadimka
    faster
#else
    openfiles
#endif

    cin >> m;
    n = 100050;
    D.resize(4*n);
    build(1, 0, n-1);
    for (int i = 0; i < m; i++) {
        string s; int x;
        cin >> s >> x;
        x = n - x - 1;
        if (s[0] == 'a') {
            pii y = get(1, 0, n-1, 0, x);
            //cout << y.ft << " " << y.sd << endl;

            add(1, 0, n-1, y.ft, x, 2);
            add(1, 0, n-1, y.ft, y.ft, 1);
        } else {
            pii y = get(1, 0, n-1, 0, x);

            add(1, 0, n-1, y.sd, x, 1);
            add(1, 0, n-1, y.sd, y.sd, 2);
        }

        cout << D[1].cnt << endl;
    }

}
















