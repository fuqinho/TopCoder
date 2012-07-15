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
const int MAX_N = 474747;
bool is_prime[MAX_N+1];
int dp[MAX_N+1][2];

class PrimeCompositeGame {
public:

  int getMinimum(set<PII>& theSet, int bound) {
    while (!theSet.empty()) {
      set<PII>::iterator it = theSet.begin();
      if (it->second < bound)
        theSet.erase(it);
      else
        return it->first;
    }
    return 0;
  }

  int getMaximum(set<PII>& theSet, int bound) {
    while (!theSet.empty()) {
      set<PII>::reverse_iterator it = theSet.rbegin();
      if (it->second < bound) 
        theSet.erase(theSet.find(*it));
      else 
        return it->first;
    }
    return 0;
  }
    
  int theOutcome(int N, int K) {
    // prepare prime
    REP(i, MAX_N+1) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
      if (is_prime[i]) {
        for (int j = i*2; j <= N; j+=i) is_prime[j] = false;
      }
    }

    memset(dp, 0, sizeof(dp));
    set<PII> primePositive;
    set<PII> primeNegative;
    set<PII> compoPositive;
    set<PII> compoNegative;

    for (int i = 1; i <= N; i++) {
      for (int p = 0; p <= 1; p++) {
        int best = 0;
        // find minimum winning pos
        if (p == 0) {
          best = getMinimum(primePositive, i-K);
          if (best == 0) best = getMinimum(primeNegative, i-K);
        }
        else {
          best = getMaximum(compoNegative, i-K);
          if (best == 0) best = getMaximum(compoPositive, i-K);
        }

        // update dp table
        if (best == 0) {
          if (p == 0) dp[i][p] = -1;
          else dp[i][p] = 1;
        }
        else {
          if (best > 0) dp[i][p] = best + 1;
          else dp[i][p] = best - 1;
        }

        if (i != 1) {
          if (dp[i][p] > 0) {
            if (is_prime[i]) {
              if (p == 1) primePositive.insert(PII(dp[i][p], i));
            }
            else {
              if (p == 0) compoPositive.insert(PII(dp[i][p], i));
            }
          }
          else {
            if (is_prime[i]) {
              if (p == 1) primeNegative.insert(PII(dp[i][p], i));
            }
            else {
              if (p == 0) compoNegative.insert(PII(dp[i][p], i));
            }
          }
        }
      }
    }

    if (dp[N][0] > 0) return dp[N][0]-1;
    else return dp[N][0]+1;
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
			int N                     = 3;
			int K                     = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PrimeCompositeGame().theOutcome(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 58;
			int K                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PrimeCompositeGame().theOutcome(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 30;
			int K                     = 3;
			int expected__            = -2;

			clock_t start__           = clock();
			int received__            = PrimeCompositeGame().theOutcome(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 6;
			int K                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PrimeCompositeGame().theOutcome(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 526;
			int K                     = 58;
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = PrimeCompositeGame().theOutcome(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

    case 5: {
			int N                     = 1;
			int K                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PrimeCompositeGame().theOutcome(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
    case 6: {
			int N                     = 304124;
			int K                     = 288946;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PrimeCompositeGame().theOutcome(N, K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PrimeCompositeGame().theOutcome(N, K);
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
