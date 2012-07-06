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

const LL INF = 100000000000000000LL;

class ImportantSequence {
public:
  int getCount(vector <int> B, string operators) {
    bool is_minus = false;
    LL constant = 0;
    LL max_val = INF;
    LL min_val = 1;
    for (int i = 0; i < B.size(); i++) {
      if (operators[i] == '+') {
        is_minus = !is_minus;
        constant = B[i] - constant;
      } else {
        constant -= B[i];
      }
      
      if (is_minus) {
        max_val = min(max_val, constant - 1);
      } else {
        min_val = max(min_val, 1 - constant);
      }
    }
    if (min_val > max_val) {
      return 0;
    } else {
      if (max_val == INF) return -1;
      else return max_val - min_val + 1;
    }
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
