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


class GogoXReimuHakurai {
public:
  int solve(vector <string> choices) {
    int N = choices.size();

    vector<vector<bool> > reachable(N, vector<bool>(N));
    REP(i, N) REP(j, N) {
      if (choices[i][j] == 'Y') reachable[i][j] = true;
    }
    REP(k, N) REP(i, N) REP(j, N) {
      if (reachable[i][k] && reachable[k][j]) reachable[i][j] = true;
    }
    if (reachable[0][N-1] == false) return 0;

    vector<bool> nice(N);
    nice[0] = nice[N-1] = true;
    for (int i = 1; i < N-1; i++) {
      if (reachable[0][i] && reachable[i][N-1]) nice[i] = true;
    }

    int nice_edges = 0;
    REP(i, N) REP(j, N) {
      if (choices[i][j] == 'Y' && nice[i] && nice[j]) nice_edges++;
    }
    int nice_nodes = 0;
    REP(i, N) if (nice[i]) nice_nodes++;

    return nice_edges - (nice_nodes - 2);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
