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


class MagicBoard {
public:

  PII find_mark(vector<string> board) {
    REP(i, board.size()) REP(j, board[i].size()) {
      if (board[i][j] == '#') return PII(i, j);
    }
    return PII(-1, -1);
  }

  void bfs(vector<string>& board) {
    queue<PII> que;
    que.push(find_mark(board));
    while (!que.empty()) {
      int r = que.front().first;
      int c = que.front().second;
      que.pop();
      if (board[r][c] != '#') continue;
      board[r][c] = '.';
      REP(i, board.size()) if (board[i][c] == '#') que.push(PII(i, c));
      REP(i, board[0].size()) if (board[r][i] == '#') que.push(PII(r, i));
    }
  }

  bool isConnected(vector<string> board) {
    bfs(board);
    return find_mark(board) == PII(-1, -1);
  }
  
  string ableToUnlock(vector <string> board) {
    int odd_rows = 0;
    int odd_cols = 0; 
    REP(i, board.size()) {
      int cnt = 0;
      REP(j, board[i].size()) if (board[i][j] == '#') cnt++;
      if (cnt & 1) odd_rows++;
    }
    REP(j, board[0].size()) {
      int cnt = 0;
      REP(i, board.size()) if (board[i][j] == '#') cnt++;
      if (cnt & 1) odd_cols++;
    }

    if (odd_rows + odd_cols <= 2 && odd_rows <= 1 && isConnected(board)) {
      return "YES";
    } else {
      return "NO";
    }
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
