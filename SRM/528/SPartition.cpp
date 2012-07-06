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

long long memo[21][21];
char wanted[21];

class SPartition {
public:

  string s;
  int n;

  long long rec(int a, int b) {
    if (a == n/2 && b == n/2) return 1;
    if (memo[a][b] != -1) return memo[a][b];

    long long res = 0;
    if (a < n/2 && s[a+b] == wanted[a]) {
      res += rec(a+1, b);
    }
    if (b < n/2 && s[a+b] == wanted[b]) {
      res += rec(a, b+1);
    }
    return memo[a][b] = res;
  }

  long long backtrack(int p, int nx, int no) {
    long long res = 0;
    if (nx == 0 && no == 0) {
      memset(memo, -1, sizeof(memo));
      res += rec(0, 0);
    } else {
      if (nx > 0) {
        wanted[p] = 'x';
        res += backtrack(p+1, nx-1, no);
      }
      if (no > 0) {
        wanted[p] = 'o';
        res += backtrack(p+1, nx, no-1);
      }
    }
    return res;
  }

  long long getCount(string s) {
    this->s = s;
    this->n = s.size();
    int xNum = count(ALL(s), 'x');
    int oNum = count(ALL(s), 'o');

    if (xNum % 2 == 0 && oNum % 2 == 0) {
      return backtrack(0, xNum/2, oNum/2);
    } else {
      return 0;
    }
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
