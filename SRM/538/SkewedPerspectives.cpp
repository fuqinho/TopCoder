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


class SkewedPerspectives {
public:
  bool check(vector<int> cubes, int B, int w, string view) {
    // corner case
    if (view.size() == 1 && view[0] == 'b') return false;
    if (view.size() >= 2 && view[0] == 'b' && view[1] != 'b') return false;

    w--;
    vector<int> bases;
    for (int i = 0; i < view.size(); i++) {
      if (view[i] == 'b') {
        // count length of b
        int b_len = 1;
        int j = i;
        while (j+1 < view.size() && view[j+1] == 'b') {
          b_len++;
          j++;
        }
        // use black block and slide to next column if the length of b is odd
        B -= (b_len + 1) / 2;
        if (b_len % 2 == 1) {
          w--;
          if (i == 0) bases.push_back(1);
          else bases.push_back(i-1);
        }
        i = j;
      } else {
        cubes[view[i]-'0']--;
      }
    }
    if (cubes[0] < 0 || cubes[1] < 0 || cubes[2] < 0 || B < 0 || w < 0) return false;

    // check odd bases
    int odd_bases = 0;
    int total_needs = 0;
    REP(i, bases.size()) {
      if(bases[i] % 2 == 1) odd_bases++;
      total_needs += bases[i];
    }
    if (accumulate(cubes.begin(), cubes.end(), 0) < odd_bases) return false;

    // check total base num
    if (accumulate(cubes.begin(), cubes.end(), 0) + B * 2 < total_needs) return false;

    return true;
  }

  vector <string> areTheyPossible(vector <int> cubes, int B, int w, vector <string> views) {
    vector<string> ans;
    REP(i, views.size()) {
      ans.push_back(check(cubes, B, w, views[i]) ? "valid" : "invalid");
    }
    return ans;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
