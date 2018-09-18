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
    vector<vector<vector<ll>>> Matrixes;

    vector<vector<ll>> multiMatrix(vector<vector<ll>> A, vector<vector<ll>> B) {
        vector<vector<ll>> C;
        C.assign(A.size(), vector<ll>(B[0].size(), 0));

        for (int i = 0; i < B.size(); i++) {
            for (int j = 0; j < B[i].size(); j++) {
                for (int h = 0; h < A.size(); h++) {
                    C[h][j] += A[h][i] * B[i][j];
                }
            }
        }

        return C;
    }

    vector<vector<ll>> binPowMatrix(vector<vector<ll>> A, int power) {
        Matrixes.clear();
        Matrixes.pb(A);
        for (int i = 2; i <= power; i <<= 1) {
            Matrixes.pb(multiMatrix(Matrixes[Matrixes.size()-1], Matrixes[Matrixes.size()-1]));
        }

        bool used = 0;
        vector<vector<ll>> B(A.size(), vector<ll>(A[0].size(), 0));

        int sc = 0;
        while (power) {
            if (power & 1) {
                if (used)
                    B = multiMatrix(B, Matrixes[sc]);
                else {
                    B = Matrixes[sc];
                    used = 1;
                }
            }
            sc++;
            power >>= 1;
        }

        return B;
    }

//#define KlishkevichVadimka
kashkevich main()
{
#ifndef KlishkevichVadimka
    faster
#else
    openfiles
#endif

    cin >> n;
    vector<vector<ll>> Fib = {{0, 1}};
    vector<vector<ll>> StartMatrix = {{0, 1}, {1, 1}};
    cout << multiMatrix(Fib, binPowMatrix(StartMatrix, n))[0][0];

}













