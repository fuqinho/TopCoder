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


class Mosquitoes {
public:
  int getNum(double t, vector <int> xInit, vector<int> v, int R) {
    int N = xInit.size();
    vector<double> pos(N);
    REP(i, N) pos[i] = xInit[i] + v[i] * t;
    sort(pos.begin(), pos.end());

    int res = 0;
    int l=0, r=0;
    while (l < N) {
      while (r+1 < N && pos[r+1] <= pos[l] + R*2 + EPS) r++;
      res = max(res, r-l+1);
      l++;
    }
    return res;
  }

  int getMaximum(vector <int> xInit, vector <int> v, int R) {
    int N = xInit.size();

    int best = getNum(0.0, xInit, v, R);
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++) {
        if (v[i] != v[j]) {
          double t = (double)abs(xInit[i] - xInit[j]) / abs(v[i] - v[j]);
          best = max(best, getNum(t, xInit, v, R));
        }
      }
    }

    return best;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
