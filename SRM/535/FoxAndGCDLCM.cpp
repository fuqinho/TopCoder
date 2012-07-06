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


class FoxAndGCDLCM {
public:
  LL gcd(LL n, LL m) {
    if (n < m) swap(n, m);
    return m == 0 ? n : gcd(m, n%m);
  }

  long long get(long long G, long long L) {
    if (L % G) return -1;
    LL ab = L / G;
    LL ans = 1000000000000000LL;
    for (LL a = 1; a*a <= ab; a++) {
      if (ab % a == 0) {
        LL b = ab / a;
        if (gcd(a, b) == 1) {
          ans = min(ans, G*(a+b));
        }
      }
    }
    return ans;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
