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


class BinaryCards {
public:

  int getDigits(LL n) {
    int res = 0;
    while (n) {
      res++;
      n >>= 1;
    }
    return res;
  }

  long long largestNumber(long long A, long long B) {
    if (A == B) return A;
    
    int digits = getDigits(B);
    for (int i = 0; i < digits-1; i++) {
      if (B & (1LL<<i)) {
        if (B - (1LL<<i) > A) {
          B -= (1LL<<i);
        } else {
          break;
        }
      }
    }
  
    for (int i = 0; i < digits; i++) {
      if (!(B & (1LL<<i))) {
        B += (1LL<<i);
      } else {
        break;
      }
    }

    return B;
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
			long long A               = 6;
			long long B               = 6;
			long long expected__      = 6;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long A               = 6;
			long long B               = 7;
			long long expected__      = 7;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long A               = 6;
			long long B               = 8;
			long long expected__      = 15;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long A               = 1;
			long long B               = 11;
			long long expected__      = 15;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			long long A               = 35;
			long long B               = 38;
			long long expected__      = 39;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			long long A               = 1125899906842630LL;
			long long B               = 1125899906842632LL;
			long long expected__      = 1125899906842639LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

    case 6: {
			long long A               = 337007621073450791LL;
			long long B               = 337259621176923563LL;
			long long expected__      = 337769972052787199LL;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 7: {
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = BinaryCards().largestNumber(A, B);
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
