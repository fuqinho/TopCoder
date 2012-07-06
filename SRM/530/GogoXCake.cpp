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


class GogoXCake {
public:
  string solve(vector <string> cake, vector <string> cutter) {
    int offset = 0;
    REP(j, cutter[0].size()) {
      if (cutter[0][j] == '.') {
        offset = j;
        break;
      }
    }

    REP(i, cake.size()) REP(j, cake[i].size()) {
      if (cake[i][j] == '.') {
        // cutterを、(i, j-offset)にあてる
        if (i + cutter.size() > cake.size() || j - offset + cutter[0].size() > cake[0].size()) return "NO";
        REP(ci, cutter.size()) REP(cj, cutter[0].size()) {
          if (cutter[ci][cj] == '.') {
            if (cake[i+ci][j-offset+cj] == '.') {
              cake[i+ci][j-offset+cj] = 'X';
            } else {
              return "NO";
            }
          }
        }
      }
    }
    return "YES";
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
