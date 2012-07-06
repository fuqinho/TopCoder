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


class Pillars {
public:
  double getExpectedLength(int w, int x, int y) {
    vector<double> lens(max(x,y));
    vector<int> nums(max(x,y));
    REP(i, lens.size()) {
      lens[i] = sqrt((double)w * w + (double)i * i);
    }
    REP(i, nums.size()) {
      if (i == 0) nums[i] = min(x, y);
      else nums[i] = min(x, max(0, y-i)) + min(max(0, x-i), y);
    }
    double ans = 0.0;
    REP(i, lens.size()) ans += lens[i] * nums[i];
    return ans / accumulate(nums.begin(), nums.end(), 0LL);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
