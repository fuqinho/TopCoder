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


class FoxAndBusiness {
public:
  int K;
  int totalWork;
  vector<int> a;
  vector<int> p;

  // C(x): 合計コストがx以下となるように選ぶことができる
  bool C(double x) {
    // TotalW/Σa * (3600K + Σap) <= x
    // TotalWΣap - xΣa <= -3600*TotalW*K
    // Σ(TotalW*ap - xa) <= -3600*TotalW*K
    // TotalW*ap - xaを先に計算して小さい方からK個取れば、選べるかチェックできる
    vector<double> d(a.size());
    REP(i, a.size()) d[i] =  (double)totalWork*a[i]*p[i] - x*a[i];
    sort(d.begin(), d.end());
    return accumulate(d.begin(), d.begin()+K, 0.0) <= -3600.0*totalWork*K;
  }

  double minimumCost(int K, int totalWork, vector <int> a, vector <int> p) {
    this->K = K;
    this->totalWork = totalWork;
    this->a = a;
    this->p = p;

    double lb = 0.0, ub = 1e11;
    REP(r, 70) { // 1e11 -> 幅1e-9 に必要な回数は、log2(1e20) <= 70
      double mid = (lb+ub)/2;
      if (C(mid)) ub = mid;
      else lb = mid;
    }
    return ub;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
