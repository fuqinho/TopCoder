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


class FractionInDifferentBases {
public:
  LL gcd(LL m, LL n) {
    return n == 0 ? m : gcd(n, m%n);
  }

  LL prime_factor_product(LL n) {
    LL res = 1;
    for (LL i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        res *= i;
        while (n % i == 0) n /= i;
      }
    }
    if (n > 1) res *= n;
    return res;
  }

  LL count(LL start, LL interval, LL maxval) {
    if (maxval < start) return 0;
    return (maxval - start - 1) / interval;
  }

  long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B) {
    LL denom = Q / gcd(Q, P);
    LL interval = prime_factor_product(denom);
    return (B+1-A) - (B / interval - (A-1) / interval);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
