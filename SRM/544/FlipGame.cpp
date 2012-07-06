#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define check(x) cerr << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;

class FlipGame {
public:
  bool allzero(vector<string>& board) {
    REP(i, board.size()) REP(j, board[i].size()) {
      if (board[i][j] != '0') return false;
    }
    return true;
  }

  int minOperations(vector <string> board) {
    int count = 0;
    while (!allzero(board)) {
      count++;
      int flip_pos = -1;
      REP(i, board.size()) {
        for (int j = board[i].size() - 1; j >= 0; j--) {
          if (board[i][j] == '1') {
            flip_pos = max(flip_pos, j);
          }
          if (j <= flip_pos) board[i][j] = (board[i][j] == '1' ? '0' : '1');
        }
      }
    }
    return count;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
