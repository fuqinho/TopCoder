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

int acum[31][31];

const int INF = 1000000000;

class DropCoins {
public:

  // get sum for area: row=[r0, r1), col=[c0,c1)
  int getSum(int r0, int r1, int c0, int c1) {
    return acum[r1][c1] - acum[r0][c1] - acum[r1][c0] + acum[r0][c0];
  }

  int getMinimum(vector <string> board, int K) {
    int N = board.size();
    int M = board[0].size();

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (board[i-1][j-1] == 'o') {
          acum[i][j] = acum[i-1][j] + acum[i][j-1] - acum[i-1][j-1] + 1;
        } else {
          acum[i][j] = acum[i-1][j] + acum[i][j-1] - acum[i-1][j-1];
        }
      }
    }

    int res = INF;
    for (int r0 = 0; r0 < N; r0++) {
      for (int r1 = r0+1; r1 <= N; r1++) {
        for (int c0 = 0; c0 < M; c0++) {
          for (int c1 = c0+1; c1 <= M; c1++) {
            if (getSum(r0, r1, c0, c1) == K) {
              int step = r0 + (N-r1) + min(r0, (N-r1)) + 
                         c0 + (M-c1) + min(c0, (M-c1));
              res = min(res, step);
            }
          }
        }
      }
    }

    if (res == INF) return -1;
    else return res;
  }
};



// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string board[]            = {".o.."
,"oooo"
,"..o."}
;
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {".....o"
,"......"
,"oooooo"
,"oooooo"
,"......"
,"o....."}
;
			int K                     = 12;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"...."
,".oo."
,".oo."
,"...."}
;
			int K                     = 3;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"......."
,"..ooo.."
,"ooooooo"
,".oo.oo."
,"oo...oo"}
;
			int K                     = 12;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"................."
,".ooooooo...oooo.."
,".ooooooo..oooooo."
,".oo.......oo..oo."
,".oo.......oo..oo."
,".ooooo.....oooo.."
,".ooooooo...oooo.."
,".....ooo..oo..oo."
,"......oo..oo..oo."
,".ooooooo..oooooo."
,".oooooo....oooo.."
,"................."}
;
			int K                     = 58;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DropCoins().getMinimum(vector <string>(board, board + (sizeof board / sizeof board[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
