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
#define INFLL 1000000000000000000
#define pii pair<int, int>
#define pb push_back
#define in insert
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define EPS 0.0000000000001
#define MOD 1000000007

struct query {
    int l, r, i;
    int block;
};

    int n, q;
    vector<int> A;
    vector<int> F;
    vector<query> QUERY;
    int l, r;
    ll ans;
    int sqrtsz;
    vector<pll> Ans;

    void rright() {
        ans -= A[r] * 1ll * F[A[r]] * F[A[r]];
        F[A[r]]++;
        ans += A[r] * 1ll * F[A[r]] * F[A[r]];
        r++;
    }
    void lleft() {
        --l;
        ans -= A[l] * 1ll * F[A[l]] * F[A[l]];
        F[A[l]]++;
        ans += A[l] * 1ll * F[A[l]] * F[A[l]];
    }
    void lright() {
        ans -= A[l] * 1ll * F[A[l]] * F[A[l]];
        F[A[l]]--;
        ans += A[l] * 1ll * F[A[l]] * F[A[l]];
        l++;
    }

//#define KlishkevichVadimka
kashkevich main()
{
#ifndef KlishkevichVadimka
    faster
#else
    openfiles
#endif

    cin >> n >> q;
    A.assign(n, 0);
    for (int &x : A) cin >> x;
    sqrtsz = sqrt(n);


    QUERY.resize(q);
    for (auto &x : QUERY) cin >> x.l >> x.r, x.l--;
    for (int i = 0; i < q; i++) QUERY[i].i = i, QUERY[i].block = QUERY[i].l / sqrtsz;
    sort(QUERY.begin(), QUERY.end(), [](query x, query y) {return (x.block < y.block || ( x.block == y.block && x.r < y.r ));});

    Ans.assign(q, {0, 0});
    F.assign(1000000, 0);
    for (int i = 0; i < q; i++) {
        if (i && QUERY[i].block != QUERY[i-1].block) {
            l = r = QUERY[i].l;
            ans = 0ll;
            F.assign(1000000, 0);
        }
        while (r < QUERY[i].r) {
            rright();
        }
        while (l < QUERY[i].l) {
            lright();
        }
        while (l > QUERY[i].l) {
            lleft();
        }

        Ans[i] = {QUERY[i].i, ans};
    }

    sort(Ans.begin(), Ans.end());
    for (auto x : Ans) cout << x.sd << endl;


}















