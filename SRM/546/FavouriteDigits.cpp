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

const int MAX_DIGITS = 18;


class FavouriteDigits {
public:
  LL get_max(const vector<int>& cur, int digit1, int count1, int digit2, int count2) {
    bool leading0 = true;
    for (int i = MAX_DIGITS-1; i >= 0; i--) {
      if (cur[i] == -1) break;
      if (cur[i] != 0) leading0 = false;
      if (!leading0) {
        if (cur[i] == digit1) count1--;
        if (cur[i] == digit2) count2--;
      }
    }
    count1 = max(0, count1);
    count2 = max(0, count2);

    LL mult = 1;
    LL res = 0;
    for (int i = 0; i < MAX_DIGITS; i++) {
      if (cur[i] == -1) {
        if (count1 > 0) {
          count1--;
          res += digit1 * mult;
        } else if (count2 > 0) {
          count2--;
          res += digit2 * mult;
        } else {
          res += 9 * mult;
        }
      } else {
        res += cur[i] * mult;
      }
      mult *= 10;
    }
    if (count1 != 0 || count2 != 0) return -1;
    else return res;
  }

  long long findNext(long long N, int digit1, int count1, int digit2, int count2) {
    if (digit1 > digit2) {
      swap(digit1, digit2);
      swap(count1, count2);
    }
    vector<int> cur(MAX_DIGITS, -1);
    LL maxVal = 0;
    for (int i = MAX_DIGITS-1; i >= 0; i--) {
      for (int j = 0; j <= 9; j++) {
        cur[i] = j;
        maxVal = get_max(cur, digit1, count1, digit2, count2);
        if (maxVal >= N) {
          break;
        }
      }
    }
    return maxVal;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
