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

const LL MOD = 1000000007;

class AkariDaisukiDiv1 {
public:
  
  int countF(string A, string B, string C, string S, string F, int k) {
    string x = S;
    LL count = 0;
    int cycles = 0;

    while (x.size() < F.size() && cycles < k) {
      x = A + x + B + x + C;
      cycles ++;
    }
    for (int i = 0; i < x.size(); i++) {
      if (x.substr(i, F.size()) == F) count++;
    }
    if (cycles == k) return count;

    string prefix = x.substr(0, F.size());
    string suffix = x.substr(x.size()-F.size());

    int additional = 0;
    for (; cycles < min(k, 50); cycles++) {

      additional = 0;
      string Ax = A + prefix;
      for (int i = 0; i < A.size(); i++) {
        if (Ax.substr(i, F.size()) == F) additional++;
      }
      string xBx = suffix + B + prefix;
      for (int i = suffix.size()-F.size()+1; i < suffix.size()+B.size(); i++) {
        if (xBx.substr(i, F.size()) == F) additional++;
      }
      string xC = suffix + C;
      for (int i = suffix.size()-F.size()+1; i < xC.size(); i++) {
        if (xC.substr(i, F.size()) == F) additional++;
      }

      prefix = Ax.substr(0, F.size());
      suffix = xC.substr(xC.size()-F.size());
      
      count = (count * 2 + additional) % MOD;
    }
    for (; cycles < k; cycles++) {
      count = (count * 2 + additional) % MOD;
    }

    return count;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
