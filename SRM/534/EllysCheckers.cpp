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

int memo[1<<20];

class EllysCheckers {
public:
  int dfs(int s) {
    s &= ~1;
    if (memo[s] != -1) return memo[s];

    int res = 0;
    for (int i = 0; i < 20; i++) {
      if (s & (1<<i)) {
        if (i > 0 && !(s & (1<<(i-1)))) {
          if (dfs((s & ~(1<<i)) | (1<<(i-1))) == 0) res = 1;
        }
        if (i > 2 && !(s & (1<<(i-3))) && (s & (1<<(i-1))) && (s & (1<<(i-2)))) {
          if (dfs((s & ~(1<<i)) | (1<<(i-3))) == 0) res = 1;
        }
      }
    }
    return memo[s] = res;
  }

  string getWinner(string board) {
    memset(memo, -1, sizeof(memo));
    int s = 0;
    for (int i = 0; i < board.size(); i++) {
      if (board[i] == 'o') s |= (1 << (board.size()-1-i));
    }
    return dfs(s) == 1 ? "YES" : "NO";
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
