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

LL C[11][11];
LL POW8[11];

class SumOfLuckiness {
public:

  long long patterns(int digits, int n4, int n7) {
    if (n4 < 0 || n7 < 0 || digits < n4+n7) return 0;
    return C[digits][n4] * C[digits-n4][n7] * POW8[digits-n4-n7];;
  }

  long long countSum(string s, int n4, int n7) {
    long long res = 0;
    for (int i = 0; i < s.size(); i++) {
      for (int d = 0; d < s[i]-'0'; d++) {
        if (d == 4) {
          res += patterns(s.size()-1-i, n4-1, n7);
        }
        else if (d == 7) {
          res += patterns(s.size()-1-i, n4, n7-1);
        }
        else {
          res += patterns(s.size()-1-i, n4, n7);
        }
      }
      if (s[i] == '4') n4--;
      if (s[i] == '7') n7--;
    }
    return res;
  }

  long long countSum(int n) {
    ostringstream oss; oss << n;
    string s = oss.str();

    long long total = 0;
    for (int n4 = 0; n4 <= 10; n4++) {
      for (int n7 = 0; n7 <= 10; n7++) {
        total += abs(n4 - n7) * countSum(s, n4, n7);
      }
    }
    return total;
  }
  
  long long theSum(int A, int B) {
    for (int i = 0; i <= 10; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        C[i][j] = C[i-1][j] + C[i-1][j-1];
      }
    }
    POW8[0] = 1;
    for (int i = 0; i < 10; i++) {
      POW8[i+1] = POW8[i] * 8;
    }
    return countSum(B+1) - countSum(A);
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
			int A                     = 1;
			int B                     = 10;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = SumOfLuckiness().theSum(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 40;
			int B                     = 47;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = SumOfLuckiness().theSum(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 58;
			int B                     = 526;
			long long expected__      = 231;

			clock_t start__           = clock();
			long long received__      = SumOfLuckiness().theSum(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 4444;
			int B                     = 7777;
			long long expected__      = 2338;

			clock_t start__           = clock();
			long long received__      = SumOfLuckiness().theSum(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 585858585;
			int B                     = 858585858;
			long long expected__      = 287481025;

			clock_t start__           = clock();
			long long received__      = SumOfLuckiness().theSum(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int A                     = ;
			int B                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SumOfLuckiness().theSum(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SumOfLuckiness().theSum(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SumOfLuckiness().theSum(A, B);
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
