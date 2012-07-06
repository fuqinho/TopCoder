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

class MergersDivOne {
public:
  double findMaximum(vector <int> r) {
    int N = r.size();
    sort(ALL(r));
    vector<double> dp(N);

    for (int i = 2; i <= N; i++) {
      dp[i-1] = accumulate(r.begin(), r.begin()+i, 0.0) / i;
    }
    for (int i = 1; i < N; i++) {
      for (int j = i+2; j <= N; j++) {
        dp[j-1] = max(dp[j-1], (dp[i] + accumulate(r.begin()+i+1, r.begin()+j, 0.0)) / (j-i));
      }
    }
    return dp[N-1];
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
