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


class MagicalSquare {
public:
  long long getCount(vector <string> rowStrings, vector <string> columnStrings) {
    bool eq[51][3][51][3][51];
    memset(eq, 0, sizeof(eq));
    REP(len, 51) REP(i, 3) REP(a, 51) REP(j, 3) REP(b, 51) {
      if (a + len <= rowStrings[i].size() && b + len <= columnStrings[j].size()) {
        if (rowStrings[i].substr(a, len) == columnStrings[j].substr(b, len)) {
          eq[len][i][a][j][b] = true;
        }
      }
    }

    long long res = 0;
    for (int a = 0; a <= rowStrings[0].size(); a++) {
      for (int b = 0; a+b <= rowStrings[0].size(); b++) {
        for (int x = 0; x <= rowStrings[1].size(); x++) {
          for (int y = 0; y <= rowStrings[1].size(); y++) {
            int c = rowStrings[0].size() - a - b;
            int z = rowStrings[1].size() - x - y;

            int p = columnStrings[0].size() - a - x;
            int q = columnStrings[1].size() - b - y;
            int r = columnStrings[2].size() - c - z;
            /* the number of letters in each cell are as follows
                 a b c
                 x y z
                 p q r
            */
            if (p+q+r == rowStrings[2].size() &&
                eq[a][0][0][0][0] &&
                eq[x][1][0][0][a] &&
                eq[p][2][0][0][a+x] &&
                eq[b][0][a][1][0] &&
                eq[y][1][x][1][b] &&
                eq[q][2][p][1][b+y] &&
                eq[c][0][a+b][2][0] &&
                eq[z][1][x+y][2][c] &&
                eq[r][2][p+q][2][c+z]) {
              res++;
            }
          }
        }
      }
    }
    return res;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			string rowStrings[]       = {"f", "o", "x"}
;
			string columnStrings[]    = {"f", "o", "x"}
;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string rowStrings[]       = {"x", "x", "x"};
			string columnStrings[]    = {"x", "", "xx"};
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string rowStrings[]       = {"cd", "cd", "cd"};
			string columnStrings[]    = {"dvd", "dvd", "dvd"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string rowStrings[]       = {"abab", "ab", "abab"};
			string columnStrings[]    = {"abab", "ab", "abab"};
			long long expected__      = 11;

			clock_t start__           = clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string rowStrings[]       = {"qwer", "asdf", "zxcv"};
			string columnStrings[]    = {"qaz", "wsx", "erdfcv"};
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

    case 5: {
			string rowStrings[]       = {"xx", "xxx", "xx"};
			string columnStrings[]    = {"xx", "xx", "xx"};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string rowStrings[]       = ;
			string columnStrings[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string rowStrings[]       = ;
			string columnStrings[]    = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MagicalSquare().getCount(vector <string>(rowStrings, rowStrings + (sizeof rowStrings / sizeof rowStrings[0])), vector <string>(columnStrings, columnStrings + (sizeof columnStrings / sizeof columnStrings[0])));
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
