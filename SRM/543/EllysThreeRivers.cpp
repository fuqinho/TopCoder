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


class EllysThreeRivers {
public:
  vector<int> width;
  vector<int> swim;
  int walk;
  int length;

  double recurse(int idx, double rem) {
    if (idx == 3) return rem/walk;

    double res = 100000.0;
    // ３分探索
    double lb = 0.0, ub = rem;
    for (int i = 0; i < 60; i++) {
      double third = (ub - lb) / 3;
      double mid1 = lb + third;
      double mid2 = lb + third * 2;
      double time1 = sqrt(width[idx]*width[idx]+mid1*mid1) / swim[idx] + recurse(idx+1, rem-mid1);
      double time2 = sqrt(width[idx]*width[idx]+mid2*mid2) / swim[idx] + recurse(idx+1, rem-mid2);
      res = min(res, min(time1, time2));
      if (time1 < time2) {
        ub = mid2;
      } else {
        lb = mid1;
      }
    }
    return res;
  }
  
  double getMin(int length, int walk, vector <int> width, vector <int> swim) {
    this->length = length;
    this->walk = walk;
    this->width = width;
    this->swim = swim;

    return recurse(0, length);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
