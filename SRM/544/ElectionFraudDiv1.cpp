#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define check(x) cerr << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;

class ElectionFraudDiv1 {
public:
  int MinimumVoters(vector <int> percentages) {
    vector<int> minval(percentages.size());
    vector<int> maxval(percentages.size());

    for (int n = 1; n <= 201; n++) {
      //printf("trying... %d\n", n);

      for (int i = 0; i < percentages.size(); i++) {
        if (percentages[i] == 0) {
          minval[i] = 0;
        } else {
          minval[i] = max(0, ((percentages[i]*2-1) * n - 1) / 200 + 1);
        }
        maxval[i] = max(0, ((percentages[i]*2+1) * n - 1) / 200);
      }
      //check(minval);
      //check(maxval);

      bool ok = true;
      for (int i = 0; i < percentages.size(); i++) {
        if (minval[i] > maxval[i]) {
          ok = false;
          break;
        }
      }
      if (ok && 
          accumulate(minval.begin(), minval.end(), 0) <= n &&
          accumulate(maxval.begin(), maxval.end(), 0) >= n) {
        return n;
      }
    }
    return -1;
  }
};








// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
