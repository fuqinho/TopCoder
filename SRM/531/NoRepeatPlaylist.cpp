#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}

const int MOD = 1000000007;
const int MAX_N = 100;
const int MAX_P = 100;
int comb[MAX_N+1][MAX_N+1];

class NoRepeatPlaylist {
public:
  int numPlaylists(int N, int M, int P) {
    memset(comb, 0, sizeof(comb));
    REP(i, N+1) comb[i][0] = 1;
    REP(i, N) REP(j, N) if(i>=j) {
      comb[i+1][j+1] = (comb[i][j+1] + comb[i][j]) % MOD;
    }

    vector<LL> relax(N+1);
    for(int i = 0; i <= N; i++) {
      if (i < M) relax[i] = 0;
      else {
        relax[i] = 1;
        for (int j = 0; j < P; j++) {
          relax[i] *= (i - min(j, M));
          relax[i] %= MOD;
        }
      }
    }

    LL res = 0;
    for (int i = 0; i <= N; i++) {
      res += (LL)comb[N][i] * ((i&1) ? -1 : 1) * relax[N-i];
      res %= MOD;
    }

    return (res + MOD) % MOD;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
