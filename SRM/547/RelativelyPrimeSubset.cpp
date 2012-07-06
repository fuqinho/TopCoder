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


const int PRIMES[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
const int PRIME_NUM = sizeof(PRIMES)/sizeof(PRIMES[0]);

class RelativelyPrimeSubset {
public:
  int getMask(int n) {
    int res = 0;
    REP(i, PRIME_NUM) {
      if (n % PRIMES[i] == 0) res |= (1<<i);
    }
    return res;
  }

  int findSize(vector <int> S) {
    int N = S.size();
    vector<int> masks(N);
    REP(i, N) masks[i] = getMask(S[i]);
    
    vector<vector<int> > dp(N+1, vector<int>(1<<PRIME_NUM, -1));
    dp[0][0] = 0;
    int res = 0;
    REP(i, N) {
      int mask = getMask(S[i]);
      REP(j, 1<<PRIME_NUM) dp[i+1][j] = dp[i][j];
      REP(j, 1<<PRIME_NUM) {
        if (dp[i][j] != -1 && !(j & mask)) {
          dp[i+1][j|mask] = max(dp[i+1][j|mask], dp[i][j] + 1);
          res = max(res, dp[i+1][j|mask]);
        }
      }
    }
    /*
    REP(i, N+1) {
      REP(j, 1<<3) cerr << dp[i][j] << " ";
      cerr << endl;
    }
    */
    
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
