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

const LL MOD = 1000000009LL;
const LL THRESH = 1000000LL;

class MinskyMystery {
public:
  int computeAnswer(long long N) {
    if (N < 2) return -1;

    LL d = N;
    for (LL i = 2; i*i <= N; i++) {
      if (N % i == 0) {
        d = i;
        break;
      }
    }

    LL A = d;
    LL B = (((2*d-3) % MOD) * (N % MOD)) % MOD;
    LL C = (((2*d-2) % MOD) * (N % MOD)) % MOD;

    // if N = 15, D = ceil(15/2) + ceil(15/3)
    // if N = 7, D = ceil(7/2) + ceil(7/3) + ceil(7/4) + ceil(7/5) + ceil(7/6) + ceil(7/7)
    LL D = 0;
    if (d == N) {
      for (LL i = 2; (N+i-1)/i >= THRESH; i++) {
        D += (N+i-1)/i;
        D %= MOD;
      }
      for (LL y = min(N-1, THRESH-1); y >= 2; y--) {
        D += (y * (((N+(y-1)-1)/(y-1) - (N+y-1)/y) % MOD)) % MOD;
        D %= MOD;
      }
      D++;
    } else {
      // for big prime number
      for (LL i = 2; i <= d; i++) {
        D += (N+i-1)/i;
        D %= MOD;
      }
    }

    return (A + B + C + D) % MOD;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
