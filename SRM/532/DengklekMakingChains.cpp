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
#define RALL(a)  (a).rbegin(),(a).rend()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}


class DengklekMakingChains {
public:

  int score(string s) {
    int res = 0;
    REP(i, 3) if (s[i] != '.') res += s[i]-'0';
    return res;
  }
  string get_pattern(string s) {
    REP(i, 3) if (s[i] != '.') s[i] = '*';
    return s;
  }

  int maxBeauty(vector <string> chains) {
    int res = 0;
    vector<PII> left, right;
    vector<int> center;
    for (int i = 0; i < chains.size(); i++) {
      string pattern = get_pattern(chains[i]);
      if (pattern == "***") res += score(chains[i]);
      if (pattern == "*.." || pattern == "**.") left.push_back(PII(score(chains[i]), i));
      if (pattern == "..*" || pattern == ".**") right.push_back(PII(score(chains[i]), i));
      if (pattern == "*.*") {
        left.push_back(PII(chains[i][0]-'0', i));
        right.push_back(PII(chains[i][2]-'0', i));
      }
      if (pattern == ".*.") center.push_back(score(chains[i]));
    }
    sort(RALL(left));
    sort(RALL(right));
    int appendable = 0;
    if (left.size() && right.size() && left[0].second == right[0].second) {
      appendable = max(left[0].first + (right.size() >= 2 ? right[1].first : 0),
                       (left.size() >= 2 ? left[1].first : 0) + right[0].first);
    } else {
      appendable = (left.size() ? left[0].first : 0) + (right.size() ? right[0].first : 0);
    }

    int center_num = 0;
    if (center.size() > 0) center_num = *max_element(ALL(center));

    return max(res + appendable, center_num);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
