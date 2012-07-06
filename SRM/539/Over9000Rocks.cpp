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


class Over9000Rocks {
public:
  int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
    int N = lowerBound.size();
    map<int, int> m;
    for (int i = 1; i < (1<<N); i++) {
      int lb = 0, ub = 0;
      REP(j, N) {
        if (i & (1<<j)) {
          lb += lowerBound[j];
          ub += upperBound[j];
        }
        m[lb]++;
        m[ub+1]--;
      }
    }

    int accum = 0;
    int res = 0;
    int start = 0;
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
      int next_accum = accum + it->second;
      if (accum == 0 && next_accum > 0) {
        start = it->first;
      }
      if (accum > 0 && next_accum == 0) {
        res += max(0, it->first - max(9001, start));
      }
      accum = next_accum;
    }

    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
