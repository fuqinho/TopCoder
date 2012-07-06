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

const int MAX_R = 50;
const int MAX_K = 50;
double dp[MAX_K+1][MAX_R][32];

class KingXMagicSpells {
public:
  double expectedNumber(vector <int> ducks, vector <int> spellOne, vector <int> spellTwo, int K) {
    memset(dp, 0, sizeof(dp));
    int N = ducks.size();
    REP(i, N) REP(j, 32) {
      dp[0][i][j] = (ducks[i] & (1<<j)) ? 1.0 : 0.0;
    }

    REP(k, K) {
      REP(i, N) REP(j, 32) {
        // pattern: xor
        if (spellOne[i] & (1<<j)) {
          dp[k+1][i][j] += (1.0 - dp[k][i][j]) * 0.5;
        } else {
          dp[k+1][i][j] += dp[k][i][j] * 0.5;
        }
        
        // pattern: move
        dp[k+1][spellTwo[i]][j] += dp[k][i][j] * 0.5;
      }
    }

    double res = 0.0;
    REP(i, 32) res += dp[K][0][i] * (1<<i);
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
