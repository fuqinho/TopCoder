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


const double INF = 10000.0;

class MergersDivTwo {
public:
  double findMaximum(vector <int> revenues, int k) {
    int N = revenues.size();
    sort(ALL(revenues));

    // dp[i]: i番目までmergeした時のi番目のrevenueの最大値
    vector<double> dp(N, -INF);
    for (int i = k; i <= N; i++) {
      dp[i-1] = accumulate(revenues.begin(), revenues.begin()+i, 0.0) / i;
    }
    for (int i = 0; i < N; i++) {
      if (dp[i] != -INF) {
        for (int j = i+k; j <= N; j++) {
          double r = (dp[i] + accumulate(revenues.begin()+i+1, revenues.begin()+j, 0.0)) / (j-i);
          dp[j-1] = max(dp[j-1], r);
        }
      }
    }
    return dp[N-1];
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
