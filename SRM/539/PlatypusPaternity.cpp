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


class PlatypusPaternity {
public:
  int maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups) {
    int res = 0;
    int N = siblingGroups[0].size();
    REP(i, femaleCompatibility.size()) {
      REP(j, maleCompatibility.size()) {
        REP(k, siblingGroups.size()) {
          bool isOK = true;
          int cnt = 0;
          REP(l, N) {
            if (siblingGroups[k][l] == 'Y') { 
              if (femaleCompatibility[i][l] == 'Y' && maleCompatibility[j][l] == 'Y') {
                cnt++;
              } else {
                isOK = false;
                break;
              }
            }
          }
          if (isOK) {
            res = max(res, cnt + 2);
          }
        }
      }
    }
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
