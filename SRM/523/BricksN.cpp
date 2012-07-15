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

LL dp[51];
int memo[51][51];
const int MOD = 1000000007;

class BricksN {
public:
  int rec(int w, int h) {
    if (w == 0 || h == 0) return 1;
    if (memo[w][h] != -1) return memo[w][h];

    LL res = 0;
    for (int i = 0; i <= w; i++) {
      if (w-(i+1) >= 0) {
        LL tmp = dp[i] * rec(i, h-1) % MOD;
        res += (tmp * rec(w-(i+1), h)) % MOD;
      } else {
        res += dp[i] * rec(i, h-1);
      }
      res %= MOD;
    }
    return memo[w][h] = res;
  }

  int countStructures(int w, int h, int k) {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= w; i++) {
      for (int j = 1; j <= k && i-j >= 0; j++) {
        dp[i] += dp[i-j];
      }
      dp[i] %= MOD;
    }
    
    memset(memo, -1, sizeof(memo));
    return rec(w, h);
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
			int w                     = 3;
			int h                     = 1;
			int k                     = 3;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int w                     = 3;
			int h                     = 2;
			int k                     = 3;
			int expected__            = 83;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int w                     = 1;
			int h                     = 5;
			int k                     = 1;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int w                     = 10;
			int h                     = 10;
			int k                     = 3;
			int expected__            = 288535435;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases
    case 4: {
			int w                     = 50;
			int h                     = 50;
			int k                     = 50;
			int expected__            = 92324271;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int w                     = ;
			int h                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int w                     = ;
			int h                     = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BricksN().countStructures(w, h, k);
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
