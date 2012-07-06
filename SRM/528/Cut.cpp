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

const int INF = 1000000000;

class Cut {
public:
  int getMaximum(vector <int> eelLengths, int maxCuts) {
    int N = eelLengths.size();
    vector<PII> cands(N);
    REP(i, N) {
      if (eelLengths[i] % 10 == 0) {
        cands[i] = PII(eelLengths[i]/10, i);
      } else {
        cands[i] = PII(INF, i);
      }
    }
    sort(cands.begin(), cands.end());

    int res = 0;
    REP(i, N) {
      if (cands[i].first != INF) {
        if (maxCuts >= cands[i].first - 1) {
          maxCuts -= cands[i].first - 1;
          res += cands[i].first;
        } else {
          res += maxCuts;
          maxCuts = 0;
        }
      } else {
        int length = eelLengths[cands[i].second];
        if (maxCuts >= length / 10) {
          maxCuts -= length / 10;
          res += length / 10;
        } else {
          res += maxCuts;
          maxCuts = 0;
        }
      }
    }
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
