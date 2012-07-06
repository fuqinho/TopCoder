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

double dp[1<<16][16];
int stronger[16][50];
int even[16][50];

class StrangeDictionary2 {
public:
  int N, L;
  vector<string> words;

  double probability(int alive, int cur) {
    if (!(alive & (1<<cur))) return 0.0;
    if (alive == (1<<cur)) return 1.0;
    if (dp[alive][cur] != -1) return dp[alive][cur];

    double p = 0.0;
    int d = 0;
    for (int i = 0; i < L; i++) {
      if (alive & stronger[cur][i]) {
        d++;
      } else {
        int next = alive & even[cur][i];
        if (next != alive) {
          d++;
          p += probability(next, cur);
        }
      }
    }
    return dp[alive][cur] = p / d;
  }

  void preprocess() {
    //memset(stronger, 0, sizeof(stronger));
    //memset(even, 0, sizeof(even));
    REP(k, L) {
      REP(i, N) {
        REP(j, N) {
          if (words[j][k] < words[i][k]) stronger[i][k] |= (1<<j);
          if (words[j][k] == words[i][k]) even[i][k] |= (1<<j);
        }
      }
    }
  }

  vector <double> getProbabilities(vector <string> words) {
    N = words.size();
    L = words[0].size();
    this->words = words;

    REP(i, 1<<N) REP(j, N) dp[i][j] = -1;
    preprocess();

    vector<double> res(N);
    REP(i, N) res[i] = probability((1<<N)-1, i);
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
