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

const int MAX_N = 51;
const int MOD = 1000000007;
int dp[MAX_N][MAX_N][MAX_N][MAX_N];

class AliceBobShuffle {
public:
  vector<int> AliceStart, BobStart, AliceEnd, BobEnd;

  int f(int a, int b, int c, int d) {
    if (dp[a][b][c][d] != -1) return dp[a][b][c][d];

    LL res = 0;
    if (a > 0) {
      if (c > 0 && AliceStart[a-1] == AliceEnd[c-1]) res += f(a-1, b, c-1, d);
      if (d > 0 && AliceStart[a-1] == BobEnd[d-1]) res += f(a-1, b, c, d-1);
    }
    if (b > 0) {
      if (c > 0 && BobStart[b-1] == AliceEnd[c-1]) res += f(a, b-1, c-1, d);
      if (d > 0 && BobStart[b-1] == BobEnd[d-1]) res += f(a, b-1, c, d-1);
    }
    return dp[a][b][c][d] = res % MOD;
  }

  int countWays(vector <int> AliceStart, vector <int> BobStart, vector <int> AliceEnd, vector <int> BobEnd) {
    this->AliceStart = AliceStart;
    this->BobStart = BobStart;
    this->AliceEnd = AliceEnd;
    this->BobEnd = BobEnd;

    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 1;
    return f(AliceStart.size(), BobStart.size(), AliceEnd.size(), BobEnd.size());
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
