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


class CoinReversing {
public:
  double expectedHeads(int N, vector <int> a) {
    double p = 1.0;
    for (int i = 0; i < a.size(); i++) {
      double turn = (double)a[i] / N;
      p = (1.0 - p) * turn + p * (1.0 - turn); 
    }
    return p * N;
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			int N                     = 3;
			int a[]                   = {2,2};
			double expected__         = 1.6666666666666667;

			clock_t start__           = clock();
			double received__         = CoinReversing().expectedHeads(N, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 10;
			int a[]                   = {10,10,10};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = CoinReversing().expectedHeads(N, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 10;
			int a[]                   = {2,7,1,8,2,8};
			double expected__         = 4.792639999999999;

			clock_t start__           = clock();
			double received__         = CoinReversing().expectedHeads(N, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 1000;
			int a[]                   = {916,153,357,729,183,848,61,672,295,936};
			double expected__         = 498.1980774932278;

			clock_t start__           = clock();
			double received__         = CoinReversing().expectedHeads(N, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int a[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CoinReversing().expectedHeads(N, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int a[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CoinReversing().expectedHeads(N, vector <int>(a, a + (sizeof a / sizeof a[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int a[]                   = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = CoinReversing().expectedHeads(N, vector <int>(a, a + (sizeof a / sizeof a[0])));
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
