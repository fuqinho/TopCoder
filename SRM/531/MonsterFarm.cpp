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

const int MOD = 1000000007;

class MonsterFarm {
public:
  int numMonsters(vector <string> transforms) {
    int N = transforms.size();
    vector<vector<int> > to(N);
    REP(i, N) {
      istringstream iss(transforms[i]);
      int tmp;
      while (iss >> tmp) to[i].push_back(tmp-1);
    }
    
    // find loop by warshall-floyd
    vector<vector<bool> > cango(N, vector<bool>(N, false));
    REP(i, to.size()) REP(j, to[i].size()) cango[i][to[i][j]] = true;
    REP(k, N) REP(i, N) REP(j, N) {
      if (cango[i][k] && cango[k][j]) cango[i][j] = true;
    }
    
    // check the number of outlets
    vector<int> degree(N);
    REP(i, to.size()) degree[i] = to[i].size();

    // check infinity
    REP(i, N) {
      if (cango[0][i] && cango[i][i] && degree[i] >= 2) {
        return -1;
      }
    }

    // if the number will stop at finite constants, the number of steps is at most N
    // (after removing cycles, the rest is DAG and the longest pash is N)
    vector<vector<int> > nums(N+1, vector<int>(N));
    nums[0][0] = 1;
    REP(k, N) {
      REP(i, N) {
        REP(j, to[i].size()) {
          nums[k+1][to[i][j]] += nums[k][i];
          nums[k+1][to[i][j]] %= MOD;
        }
      }
    }
    
    return accumulate(nums[N].begin(), nums[N].end(), 0LL) % MOD;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
