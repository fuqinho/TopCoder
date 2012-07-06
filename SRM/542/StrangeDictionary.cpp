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


class StrangeDictionary {
public:
  vector <double> getExpectedPositions(vector <string> words) {
    int N = words.size();
    int L = words[0].size();
    vector<double> res(N);
    REP(i, N) {
      double p = 0.0;
      REP(j, N) {
        if (i == j) continue;
        int bigger = 0;
        int smaller = 0;
        REP(k, L) {
          if (words[j][k] > words[i][k]) bigger++;
          if (words[j][k] < words[i][k]) smaller++;
        }
        p += (double)smaller / (bigger + smaller);
      }
      res[i] = p;
    }
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
