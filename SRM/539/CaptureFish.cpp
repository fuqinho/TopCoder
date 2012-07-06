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


class CaptureFish {
public:
  int getParity(string fish) {
    int N = fish.size();
    int patterns = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j <= N; j++) {
        // inside
        bool capture_x_in = false;
        bool capture_o_in = false;
        for (int k = i; k < j; k++) {
          if (fish[k] == 'O') capture_o_in = true;
          if (fish[k] == 'X') capture_x_in = true;
        }
        if (capture_x_in && capture_o_in) continue;
        
        // outside
        bool capture_x_out = false;
        bool capture_o_out = false;
        for (int k = 0; k < i; k++) {
          if (fish[k] == 'O') capture_o_out = true;
          if (fish[k] == 'X') capture_x_out = true;
        }
        for (int k = j; k < N; k++) {
          if (fish[k] == 'O') capture_o_out = true;
          if (fish[k] == 'X') capture_x_out = true;
        }
        if (capture_x_out && capture_o_out) continue;

        if (capture_x_in && capture_x_out) continue;
        if (capture_o_in && capture_o_out) continue;

        patterns++;
      }
    }
    return patterns % 2;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
