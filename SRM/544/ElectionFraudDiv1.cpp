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

class ElectionFraudDiv1 {
public:
  int MinimumVoters(vector <int> percentages) {
    vector<int> minval(percentages.size());
    vector<int> maxval(percentages.size());

    for (int n = 1; n <= 201; n++) {
      for (int i = 0; i < percentages.size(); i++) {
        if (percentages[i] == 0) {
          minval[i] = 0;
        } else {
          minval[i] = max(0, ((percentages[i]*2-1) * n - 1) / 200 + 1);
        }
        maxval[i] = max(0, ((percentages[i]*2+1) * n - 1) / 200);
      }

      bool ok = true;
      for (int i = 0; i < percentages.size(); i++) {
        if (minval[i] > maxval[i]) {
          ok = false;
          break;
        }
      }
      if (ok && 
          accumulate(minval.begin(), minval.end(), 0) <= n &&
          accumulate(maxval.begin(), maxval.end(), 0) >= n) {
        return n;
      }
    }
    return -1;
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
			int percentages[]         = {33, 33, 33};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int percentages[]         = {29, 29, 43};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int percentages[]         = {12, 12, 12, 12, 12, 12, 12, 12};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int percentages[]         = {13, 13, 13, 13, 13, 13, 13, 13};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int percentages[]         = {0, 1, 100};
			int expected__            = 200;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int percentages[]         = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8, 4};
			int expected__            = 97;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

    case 6: {
			int percentages[]         = {50, 0, 50, 0};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
    case 7: {
			int percentages[]         = {0, 1, 98};
			int expected__            = 201;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int percentages[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ElectionFraudDiv1().MinimumVoters(vector <int>(percentages, percentages + (sizeof percentages / sizeof percentages[0])));
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



