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


class EllysXors {
public:
  long long getXor(long long N) {
    LL res = 0;
    for (int i = 0; i < 40; i++) {
      LL unit = (N+1) / ((1LL << i) * 2);
      LL rem = (N+1) % ((1LL << i) * 2);
      LL bits = unit * (1LL << i) + max(0LL, rem - (1LL << i));
      if (bits & 1) res |= (1LL << i);
    }
    return res;
  }
  long long getXor(long long L, long long R) {
    return getXor(R) ^ getXor(L-1);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
