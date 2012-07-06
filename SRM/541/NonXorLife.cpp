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

const int MAX_STEP = 1500;
bool checked[MAX_STEP*2+50][MAX_STEP*2+50];

const int DR[] = {0, 0, -1, 1};
const int DC[] = {-1, 1, 0, 0};

class NonXorLife {
public:
  int countAliveCells(vector <string> field, int K) {
    memset(checked, 0, sizeof(checked));
    queue<pair<int, PII> > que;
    int count = 0;
    for (int i = 0; i < field.size(); i++) {
      for (int j = 0; j < field[i].size(); j++) {
        if (field[i][j] == 'o') {
          count++;
          checked[i+MAX_STEP][j+MAX_STEP] = true;
          que.push(make_pair(0, PII(i+MAX_STEP, j+MAX_STEP)));
        }
      }
    }

    while (!que.empty()) {
      int depth = que.front().first;
      int r = que.front().second.first;
      int c = que.front().second.second;
      que.pop();
      if (depth >= K) break;
      
      for (int k = 0; k < 4; k++) {
        int nr = r + DR[k];
        int nc = c + DC[k];
        if (!checked[nr][nc]) {
          checked[nr][nc] = true;
          count++;
          que.push(make_pair(depth+1, PII(nr, nc)));
        }
      }
    }
    
    return count;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
