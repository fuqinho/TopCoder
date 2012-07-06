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


class KingdomAndTrees {
public:
  bool C(vector<int> heights, int level) {
    int minval = max(1, heights[0] - level);
    for (int i = 1; i < heights.size(); i++) {
      if (heights[i] + level > minval) {
        minval = max(minval+1, heights[i] - level);
      } else {
        return false;
      }
    }
    return true;
  }

  int minLevel(vector <int> heights) {
    int lb = -1, ub = 2000000000;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (C(heights, mid)) {
        ub = mid;
      } else {
        lb = mid;
      }
    }
    return ub;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
