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

const int MOD = 1000000007;

class SRMSystemTestPhase {
public:

  int countWays(vector <string> description) {
    int N = description.size();

    int comb[4][4]; memset(comb, 0, sizeof(comb));
    for (int i = 0; i <= 3; i++) {
      comb[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
      }
    }

    map<PII, LL> m[2];
    m[0][PII(-100,0)] = 1;

    REP (i, N) {
      int submission = count(ALL(description[i]), 'Y');
      for (int pass = 0; pass <= submission; pass++) {
        for (int chal = 0; pass+chal <= submission; chal++) {
          int patterns = comb[submission][pass] * comb[submission-pass][chal];
          PII p(-pass, chal);
          for (map<PII, LL>::iterator it = m[i&1].begin(); it != m[i&1].end(); it++) {
            if (it->first <= p) {
              m[(i+1)&1][p] += it->second * patterns;
              m[(i+1)&1][p] %= MOD;
            }
            else break;
          }
        }
      }

      m[i&1].clear();
    }
    
    LL res = 0;
    for (map<PII, LL>::iterator it = m[N&1].begin(); it != m[N&1].end(); it++) {
      res += it->second;
      res %= MOD;
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
			string description[]      = {"YYY"};
			int expected__            = 27;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string description[]      = {"YNN",
 "NYN"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string description[]      = {"YNN",
 "NNN",
 "NNY"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string description[]      = {"NNN",
 "NNN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string description[]      = {"YYY",
 "YNY",
 "NYY",
 "YYN",
 "YYY",
 "YNN"};
			int expected__            = 15176;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMSystemTestPhase().countWays(vector <string>(description, description + (sizeof description / sizeof description[0])));
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
