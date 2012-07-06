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


class CasketOfStarEasy {
public:
  int maxEnergy(vector <int> weight) {
    int N = weight.size();
    vector<vector<int> > dp(N, vector<int>(N+1));
    for (int w = 3; w <= N; w++) {
      for (int i = 0; i+w <= weight.size(); i++) {
        for (int j = i+1; j < i+w-1; j++) {
          dp[i][i+w] = max(dp[i][i+w], dp[i][j+1] + dp[j][i+w] + weight[i] * weight[i+w-1]);
        }
      }
    }
    return dp[0][N];
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
