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


class FoxAndIntegers {
public:
  vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC) {
    int A, B, C;
    if ((AminusB + AplusB) % 2 == 0) {
      A = (AminusB + AplusB) / 2;
    } else {
      return vector<int>();
    }
    if ((AplusB - AminusB) % 2 == 0) {
      B = (AplusB - AminusB) / 2;
    } else {
      return vector<int>();
    }
    C = B - BminusC;
    if (B + C == BplusC) {
      vector<int> res;
      res.push_back(A);
      res.push_back(B);
      res.push_back(C);
      return res;
    } else {
      return vector<int>();
    }
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
