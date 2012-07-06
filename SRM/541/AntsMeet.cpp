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


class AntsMeet {
public:
  int countAnts(vector <int> x, vector <int> y, string direction) {
    int N = x.size();
    REP(i, N) { x[i]*=2; y[i]*=2; }
    LL alive = (1LL << N) - 1;

    REP(k, 4000) {
      map<PII, VI> m;
      REP(i, N) {
        if (alive & (1LL << i)) {
          // move
          if (direction[i] == 'N') y[i]++;
          else if (direction[i] == 'S') y[i]--;
          else if (direction[i] == 'E') x[i]++;
          else x[i]--;

          // check
          m[PII(x[i], y[i])].push_back(i);
          for (map<PII, VI>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second.size() >= 2) {
              for (int j = 0; j < it->second.size(); j++) {
                alive &= ~(1LL << it->second[j]);
              }
            }
          }
        }
      }
    }
    int res = 0;
    REP(i, N) if(alive & (1LL<<i)) res++;
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
