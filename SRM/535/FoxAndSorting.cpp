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

const int DIGITS = 18;
LL memo[DIGITS*9+1][DIGITS+1];

class FoxAndSorting {
public:

  // 各桁の合計がsumで、桁数が最大max_digitsになっている数字の数を返す
  // max_digits=18の時は、数として成立している数(0で始まらない)
  // その他の時は、0始まりも加える。
  long long patterns(int sum, int max_digits) {
    if (memo[sum][max_digits] != -1) return memo[sum][max_digits];

    long long res = 0;
    if (sum == 0) res++; // ""をカウントに入れる

    // 頭の数字を0-9に分けて、max-digit-1のパターン数を足す
    for (int d=0; d<=9 && sum-d>=0; d++) {
      if (max_digits == 0) continue; // max_digits==0ならこれより短いのはない
      if (d == 0 && max_digits == DIGITS) continue; // 18桁の場合、頭に0は来れない
      res += patterns(sum-d, max_digits-1);
    }
    return memo[sum][max_digits] = res;
  }

  long long get(long long idx) {
    memset(memo, -1, sizeof(memo));
    
    int sum = 0;
    while (idx > patterns(sum, DIGITS)) {
      idx -= patterns(sum, DIGITS);
      sum++;
    }

    LL hoge = 0;
    for (int i = 0; i <=162; i++) hoge += patterns(i, DIGITS);

    LL res = 0;
    for (int i = 18; i >= 1; i--) {
      if (sum == 0) {
        if (idx == 1) break;
        idx--;
      }

      for (int d = 0; d<=9 && sum-d>=0; d++) {
        if (i == 18 && d == 0) continue;
        if (idx > patterns(sum-d, i-1)) {
          idx -= patterns(sum-d, i-1);
        } else {
          res = res*10 + d;
          sum -= d;
          break;
        }
      }
    }
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
