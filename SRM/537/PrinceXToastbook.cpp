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


class PrinceXToastbook {
public:
  double eat(vector <int> prerequisite) {
    double res = 0.0;
    REP(i, prerequisite.size()) {
      int count = 0;
      int cur = i;
      while (cur != -1) {
        cur = prerequisite[cur];
        count++;
        // check loop (this book can not be understood)
        if (count > prerequisite.size()) {
          count = -1;
          break;
        }
      }
      if (count != -1) {
        double p = 1.0;
        while (count > 0) {
          p /= count;
          count--;
        }
        res += p;
      }
    }
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
