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

const int MAX_FACTORS = 16;
int dp[2][1<<MAX_FACTORS];

class EllysNumbers {
public:


  void factorize(LL n, map<int, int>& res) {
    for (LL i = 2; i * i <= n; i++) {
      int cnt = 0;
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
      if (cnt != 0) res[i] += cnt;
    }
    if (n != 1) res[n]++;;
  }

  int get_mask(LL n, vector<LL>& factors)
  {
    int res = 0;
    REP(i, factors.size()) {
      if (n % factors[i] == 0) {
        n /= factors[i];
        res |= (1<<i);
      }
    }
    if (n != 1) res = 0;
    return res;
  }

  long long getSubsets(long long n, vector <string> special)
  {
    // input
    string s;
    REP(i, special.size()) s += special[i];
    istringstream iss(s);
    LL tmp;
    vector<LL> specials;
    while (iss >> tmp) specials.push_back(tmp);

    // factorize n
    map<int, int> facs;
    LL n2 = n;
    REP(i, specials.size()) {
      if (n2 % specials[i] == 0) {
        factorize(specials[i], facs);
        n2 /= specials[i];
      }
    }
    if (n2 > 1000000000) return 0;
    if (n2 != 1) {
      factorize(n2, facs);
    }

    vector<LL> factors;
    for (map<int, int>::iterator it = facs.begin(); it != facs.end(); it++) {
      LL f = 1;
      REP(i, it->second) f *= it->first;
      factors.push_back(f);
    }

    // DP
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < specials.size(); i++) {
      for (int mask = 0; mask < (1<<factors.size()); mask++) {
        dp[(i+1)&1][mask] = dp[i&1][mask];
      }
      if (n % specials[i] == 0) {
        int s_mask = get_mask(specials[i], factors);
        if (s_mask) {
          for (int mask = 0; mask < (1<<factors.size()); mask++) {
            if (!(mask & s_mask)) {
              dp[(i+1)&1][mask|s_mask] += dp[i&1][mask];
            }
          }
        }
      }
    }

    LL res = dp[specials.size()&1][(1<<factors.size())-1];
    if (find(specials.begin(), specials.end(), 1) != specials.end()) res *= 2;
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
