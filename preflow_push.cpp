typedef signed kashkevich;
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl "\n"
#define INF 2000000000
#define INFLL 1000000000000000000ll
#define ft first
#define EPS 0.0001
#define sd second
#define pb push_back
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define openfiles ifstream cin("input.txt");ofstream cout("output.txt");
#define openfiles2 ifstream cin("teleports.in");ofstream cout("teleports.out");

    int T, n, m;
    int v;


    set<pair<int, pii>> S;
    set<int> pos;

    int M(const int &y, const int &x) {
        return (x - y < 0)? x - y + T : x - y;
    }

    void Add(int &x) {
        if (pos.size() == 0) {
            pos.insert(x);
            S.insert({0, {x, x}});
        } else {

            auto ait = upper_bound(pos.begin(), pos.end(), x),
                 bit = lower_bound(pos.begin(), pos.end(), x);
            if (ait == pos.end()) {
                ait = pos.begin();
            }
            int a = *ait;
            if (bit == pos.begin()) {
                bit = pos.end();
            }
            bit--;
            int b = *bit;

            //if (S.size() != 2)
            S.erase({M(b, a), {b, a}});
            S.insert({M(b, x), {b, x}});
            S.insert({M(x, a), {x, a}});

            pos.insert(x);

            //cout << "ADD " << x << " : " << a << " " << b << endl << endl;
        }
    }

    void Del(int &x) {
        if (pos.size() == 1) {
            S.clear();
            pos.clear();
        } else {

            auto ait = upper_bound(pos.begin(), pos.end(), x),
                 bit = lower_bound(pos.begin(), pos.end(), x);
            if (ait == pos.end()) {
                ait = pos.begin();
            }
            int a = *ait;
            if (bit == pos.begin()) {
                bit = pos.end();
            }
            bit--;
            int b = *bit;

            S.erase({M(b, x), {b, x}});
            S.erase({M(x, a), {x, a}});
            S.insert({M(b, a), {b, a}});

            pos.erase(x);

            //cout << "DEL " << x << " : " << a << " " << b << endl << endl;
        }
    }

    int Gotcha() {
        if (S.size() == 0 || S.size() == 1) {
            return T;
        }
        auto ait = S.end(),
             bit = S.end();
        bit--;
        bit--;
        ait--;
        //cout << ait -> ft << " " << ait -> sd << endl;
        //cout << bit -> ft << " " << bit -> sd << endl;
        //cout << endl;

        return ait->ft +
                bit->ft;
    }

kashkevich main(){
    //openfiles;
    //freopen("teleports.in", "r", stdin);
    //freopen("teleports.out", "w", stdout);
    //faster;

    //cin >> n >> m >> T >> v;
    scanf("%d%d%d%d", &n, &m, &T, &v);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Add(x);

        //for (auto x : S) std::cout << x.ft << " " << x.sd << endl;
        //std::cout << endl;
    }

    //cout << fixed << setprecision(7);
    //cout << Gotcha()/v << endl;
    printf("%f\n", Gotcha()/(2. * v));
    //cout << Gotcha()/(2. * v)<< endl;
    for (int i = 0; i < m; i++) {

        char x, levy;
        int f = 0;
        scanf("%c%c%d", &x, &levy, &f);
        if (x == '-') {
            Del(f);
        } else {
            Add(f);
        }

        //for (auto x : S) std::cout << x.ft << " " << x.sd << endl;
        //std::cout << endl;

        //cout << Gotcha()/v << endl;
        printf("%.7f\n", Gotcha()/2./v);
        //cout << Gotcha()/(2. * v) << endl;
    }
    return 0;
}
