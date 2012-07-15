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
int dp1[11];
int patterns[1<<10][1<<10];
LL dp2[11][1<<10];

class SmallBricks31 {
public:
  int w;
  int h;

  int count(int base, int top) {
    memset(dp1, 0, sizeof(dp1));
    dp1[0] = 1;
    for (int i = 0; i < w; i++) {
      // no block
      if (!(top & (1<<i))) {
        dp1[i+1] += dp1[i];
      }

      // block_1
      if ((top & (1<<i)) && (base & (1<<i))) {
        dp1[i+1] += dp1[i];
      }

      // block_2
      if (i >= 1 && 
          (top & (1<<i)) && (top & (1<<(i-1))) && 
          (base & (1<<i)) && (base & (1<<(i-1)))) {
        dp1[i+1] += dp1[i-1];
      }

      // block_3
      if (i >= 2 && 
          (top & (1<<i)) && (top & (1<<(i-1))) && (top & (1<<(i-2))) &&
          (base & (1<<i)) && (base & (1<<(i-2)))) {
        dp1[i+1] += dp1[i-2];
      }
    }
    return dp1[w];
  }
  
  int countWays(int w_, int h_) {
    w = w_;
    h = h_;

    for (int i = 0; i < (1<<w); i++) {
      for (int j = 0; j < (1<<w); j++) {
        patterns[i][j] = count(i, j);
      }
    }

    memset(dp2, 0, sizeof(dp2));
    dp2[0][(1<<w)-1] = 1;
    for (int i = 0; i < h; i++) {
      for (int base = 0; base < (1<<w); base++) {
        for (int top = 0; top < (1<<w); top++) {
          dp2[i+1][top] += dp2[i][base] * patterns[base][top];
          dp2[i+1][top] %= MOD;
        }
      }
    }

    return accumulate(dp2[h], dp2[h]+(1<<w), 0LL) % MOD;
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
			int w                     = 1;
			int h                     = 3;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int w                     = 3;
			int h                     = 1;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int w                     = 3;
			int h                     = 2;
			int expected__            = 84;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int w                     = 4;
			int h                     = 9;
			int expected__            = 132976888;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int w                     = 5;
			int h                     = 5;
			int expected__            = 11676046;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int w                     = 10;
			int h                     = 10;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int w                     = ;
			int h                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SmallBricks31().countWays(w, h);
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
