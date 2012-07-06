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


class MinCostPalindrome {
public:
  int getMinimum(string s, int oCost, int xCost) {
    int res = 0;
    for (int i = 0; i < s.size()/2; i++) {
      if (s[i] != '?' && s[s.size()-1-i] != '?') {
        if (s[i] != s[s.size()-1-i]) return -1;
      }
      else if (s[i] == '?' && s[s.size()-1-i] == '?') {
        res += min(oCost, xCost) * 2;
      }
      else if (s[i] == '?') {
        if (s[s.size()-1-i] == 'o') res += oCost;
        else res += xCost;
      }
      else {
        if (s[i] == 'o') res += oCost;
        else res += xCost;
      }
    }
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
