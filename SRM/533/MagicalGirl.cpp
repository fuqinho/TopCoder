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


class MagicalGirl {
public:
  double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain) {
    int N = day.size();
    // sort by day
    vector<pair<int, pair<int,int> > > witches(N);
    REP(i, N) {
      witches[i].first = day[i];
      witches[i].second.first = win[i];
      witches[i].second.second = gain[i];
    }
    sort(ALL(witches));

    vector<vector<double> > dp(N+1, vector<double>(M+1));
    for (int i = 0; i <= M; i++) dp[N][i] = i;
    
    for (int i = N-1; i >= 0; i--)
    {
      int day_to_next = (i == 0 ? witches[i].first : witches[i].first - witches[i-1].first);
      for (int j = 1; j <= M; j++)
      {
        if (j - day_to_next > 0)
        {
          int next_mp = j - day_to_next;
          double rem_ignore = day_to_next + dp[i+1][next_mp];
          double rem_lose = day_to_next;
          double rem_win = day_to_next + dp[i+1][min(M, next_mp + witches[i].second.second)];
          double rem_exp = (witches[i].second.first*rem_win + (100-witches[i].second.first)*rem_lose) / 100.0;
          dp[i][j] = max(rem_ignore, rem_exp);
        } else {
          dp[i][j] = j;
        }
      }
    }
    return dp[0][M];
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
