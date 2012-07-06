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

const LL INF = 10000000000000000LL;

class RectangularSum {
public:
  int height;
  int width;

  // 選択する領域の幅をx, 高さをy, 左上の数をkとしたとき、
  // 2S = x*y*(2*k + (x-1) + w*(y-1)) を利用して調べる
  bool check(LL x, LL y, LL S) {
    LL tmp = S / (x*y);
    LL tmp2 = (x - 1) + width*(y - 1);

    LL k = tmp - tmp2; if (k&1) return false;
    k >>= 1;
    if (k >= 0 && (k/width + y) <= height && (k%width + x) <= width) {
      return true;
    } else {
      return false;
    }
  }
  
  vector<LL> get_factors(LL n) {
    vector<LL> res;
    for (LL i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        res.push_back(i);
        res.push_back(n/i);
      }
    }
    sort(ALL(res));
    res.erase(unique(ALL(res)), res.end());
    return res;
  }

  long long minimalArea(int height, int width, long long S) {
    this->height = height;
    this->width = width;
    LL res = INF;
    S*=2;

    vector<LL> factors = get_factors(S);

    for (int i = 0; i < factors.size(); i++) {
      LL x = factors[i];
      for (int j = i; j < factors.size(); j++) {
        LL y = factors[j];
        if (x*y > S) break;
        if (S % (x*y) == 0) {
          if (check(x, y, S) || check(y, x, S)) {
            res = min(res, x * y);
          }
        }
      }
    }

    if (res == INF) return -1;
    else return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
