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

const int MAX_N = 30;
const int MAX_M = 30;
const int MAX_K = 8;
const int MOD = 1000000007;

int dp[MAX_N+1][MAX_M+1][MAX_K+1][1<<(MAX_K+1)];

class DengklekBuildingRoads {
public:

  int numWays(int N, int M, int K) {
    memset(dp, 0, sizeof(dp));
    dp[N][M][0][0] = 1;

    for (int i = N-1; i >= 0; i--) {
      for (int j = M; j >= 0; j--) {
        for (int mask = 0; mask < (1 << (K+1)); mask++) {
          if (!(mask & (1 << K))) {
            dp[i][j][K][mask] = dp[i+1][j][0][mask<<1];
          }
        }
        for (int k = K-1; k >= 0; k--) {
          for (int mask = 0; mask < (1 << (K+1)); mask++) {
            dp[i][j][k][mask] = dp[i][j][k+1][mask];
            if (j+1 <= M && i-(k+1) >= 0) {
              dp[i][j][k][mask] += dp[i][j+1][k][mask^(1<<0)^(1<<(k+1))];
              dp[i][j][k][mask] %= MOD;
            }
          }
        }
      }
    }
    return dp[0][0][0][0];
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
