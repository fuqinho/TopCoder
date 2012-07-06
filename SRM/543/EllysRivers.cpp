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

const double INF = 1000000000.0;

class EllysRivers {
public:
  vector<int> width;
  vector<int> speed;

  double distance(int i, int p, int q) {
    return sqrt((double)(q-p)*(q-p) + (double)width[i]*width[i]) / speed[i];
  }
  
  double getMin(int length, int walk, vector <int> width, vector <int> speed) {
    this->width = width;
    this->speed = speed;
    int N = width.size();
    vector<vector<double> > dp(N+1, vector<double>(length+1, INF));
    dp[N][length] = 0.0;
    for (int i = N-1; i >= 0; i--) {
      int q = length;
      for (int p = length; p >= 0; p--) {
        while (q > 0 && 
               distance(i, p, q) + dp[i+1][q] > distance(i, p, q-1) + dp[i+1][q-1]) q--;
        dp[i][p] = distance(i, p, q) + dp[i+1][q];
      }
    }
    
    double min_time = INF;
    for (int p = 0; p <= length; p++) {
      min_time = min(min_time, dp[0][p] + double(p) / walk);
    }
    return min_time;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
