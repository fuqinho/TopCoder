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

const int MAX_HEIGHT = 100;
const int MAX_N = 50;
double dp[MAX_N+1][MAX_HEIGHT];

class PillarsDivTwo {
public:
  double maximalLength(vector <int> height, int w) {
    memset(dp, 0, sizeof(dp));
    int N = height.size();
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < height[i]; j++) {
        for (int k = 0; k < height[i-1]; k++) {
          dp[i][j] = max(dp[i][j], dp[i-1][k] + sqrt((double)w*w + (double)(j-k)*(j-k)));
        }
      }
    }
    return *max_element(dp[N-1], dp[N-1] + MAX_HEIGHT);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
