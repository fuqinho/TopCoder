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

const int INF = 1000000000;

class CorrectMultiplicationTwo {
public:
  int getMinimum(int a, int b, int c) {
    int res = INF;
    for (int ca = 1; ca <= 1000000; ca++) {
      int cb = c / ca;
      int cc = ca * cb;
      if (cb > 0) {
        res = min(res, abs(a-ca) + abs(b-cb) + abs(c-cc));
      }
      cb++;
      cc = ca * cb;
      res = min(res, abs(a-ca) + abs(b-cb) + abs(c-cc));
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
			int a                     = 19;
			int b                     = 28;
			int c                     = 522;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 10;
			int b                     = 30;
			int c                     = 500;
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 111;
			int b                     = 111;
			int c                     = 12321;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 1000;
			int b                     = 100;
			int c                     = 10;
			int expected__            = 1089;

			clock_t start__           = clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int a                     = 399;
			int b                     = 522;
			int c                     = 199999;
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CorrectMultiplicationTwo().getMinimum(a, b, c);
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
