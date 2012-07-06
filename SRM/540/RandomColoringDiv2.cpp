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


class RandomColoringDiv2 {
public:
  int patterns(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d) {
    if (d < 0) return 0;
    int r = min(maxR-1, startR + d) - max(0, startR - d) + 1;
    int g = min(maxG-1, startG + d) - max(0, startG - d) + 1;
    int b = min(maxB-1, startB + d) - max(0, startB - d) + 1;
    return r * g * b;
  }

  int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
    return patterns(maxR, maxG, maxB, startR, startG, startB, d2) -
           patterns(maxR, maxG, maxB, startR, startG, startB, d1-1);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
