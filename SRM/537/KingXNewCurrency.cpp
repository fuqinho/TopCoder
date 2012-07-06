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


class KingXNewCurrency {
public:
  int gcd(int a, int b) {
    if (a < b) swap(a, b);
    return b == 0 ? a : gcd(b, a%b);
  }

  int howMany(int A, int B, int X) {
    if (gcd(A, B) % X == 0) return -1;

    int res = 0;
    for (int Y = 1; Y <= max(A, B); Y++) {
      bool canMakeA = false, canMakeB = false;
      for (int i = 0; X*i <= A; i++) {
        if ((A - X*i) % Y == 0) {
          canMakeA = true;
          break;
        }
      }
      for (int i = 0; X*i <= B; i++) {
        if ((B - X*i) % Y == 0) {
          canMakeB = true;
          break;
        }
      }
      if (canMakeA && canMakeB) res++;
    }

    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
