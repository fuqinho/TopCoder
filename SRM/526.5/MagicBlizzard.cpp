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


class MagicBlizzard {
public:
  double expectation(vector <int> range, vector <int> amount) {
    int N = range.size();
    vector<PII> r_a(N);
    REP(i, N) r_a[i] = PII(range[i], amount[i]);
    sort(ALL(r_a));

    int balls = 0;
    double res = 0;
    REP(i, N) {
      int side = r_a[i].first * 2 + 1;
      REP(k, r_a[i].second) {
        double x = (double)balls / ((double)side * side);
        res += (2.0 * x + 1);
        balls++;
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
			int range[]               = {1,0};
			int amount[]              = {1,1};
			double expected__         = 2.2222222222222223;

			clock_t start__           = clock();
			double received__         = MagicBlizzard().expectation(vector <int>(range, range + (sizeof range / sizeof range[0])), vector <int>(amount, amount + (sizeof amount / sizeof amount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int range[]               = {1,0};
			int amount[]              = {2,1};
			double expected__         = 3.666666666666667;

			clock_t start__           = clock();
			double received__         = MagicBlizzard().expectation(vector <int>(range, range + (sizeof range / sizeof range[0])), vector <int>(amount, amount + (sizeof amount / sizeof amount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int range[]               = {5,2,6,5};
			int amount[]              = {1,2,2,3};
			double expected__         = 8.46525111252384;

			clock_t start__           = clock();
			double received__         = MagicBlizzard().expectation(vector <int>(range, range + (sizeof range / sizeof range[0])), vector <int>(amount, amount + (sizeof amount / sizeof amount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int range[]               = {7,11,2,13,3,19,5,17};
			int amount[]              = {16,8,4,15,12,9,10,6};
			double expected__         = 98.55659436211914;

			clock_t start__           = clock();
			double received__         = MagicBlizzard().expectation(vector <int>(range, range + (sizeof range / sizeof range[0])), vector <int>(amount, amount + (sizeof amount / sizeof amount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int range[]               = {0,0,0,0,0,0,0,0,0,0};
			int amount[]              = {10000,10000,10000,10000,10000,10000,10000,10000,10000,10000};
			double expected__         = 1.0E10;

			clock_t start__           = clock();
			double received__         = MagicBlizzard().expectation(vector <int>(range, range + (sizeof range / sizeof range[0])), vector <int>(amount, amount + (sizeof amount / sizeof amount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int range[]               = ;
			int amount[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MagicBlizzard().expectation(vector <int>(range, range + (sizeof range / sizeof range[0])), vector <int>(amount, amount + (sizeof amount / sizeof amount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int range[]               = ;
			int amount[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MagicBlizzard().expectation(vector <int>(range, range + (sizeof range / sizeof range[0])), vector <int>(amount, amount + (sizeof amount / sizeof amount[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int range[]               = ;
			int amount[]              = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = MagicBlizzard().expectation(vector <int>(range, range + (sizeof range / sizeof range[0])), vector <int>(amount, amount + (sizeof amount / sizeof amount[0])));
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
