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
int memo[51][51];

class P8XGraphBuilder {
public:
  int N;
  vector<int> scores;

  int rec(int unprocessed, int remain) {
    if (unprocessed == 0 && remain == 0) {
      return 0;
    }
    if (unprocessed == 0 && remain != 0) {
      return -INF;
    }
    if (memo[unprocessed][remain] != -1) return memo[unprocessed][remain];

    int best = -INF;
    for (int i = 0; i <= remain; i++) {
      int degree = i;
      if (remain == N-1) {
        if (i == 0) continue;
        else degree--;
      }
      int s = scores[degree] + rec(unprocessed + i - 1, remain - i);
      best = max(best, s);
    }

    return memo[unprocessed][remain] = best;
  }

  int solve(vector <int> scores) {
    this->scores = scores;
    this->N = scores.size()+1;

    memset(memo, -1, sizeof(memo));
    return rec(1, N-1);
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
			int scores[]              = {1, 3, 0};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int scores[]              = {0, 0, 0, 10};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int scores[]              = {1, 2, 3, 4, 5, 6};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int scores[]              = {5, 0, 0};
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int scores[]              = {1, 3, 2, 5, 3, 7, 5};
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

    case 5: {
			int scores[]              = {1,3,4,2,3,2,1,2,4,3,1,3,4,2,3,2,1,2,4,3,1,3,4,2,3,2,1,2,4,3,1,3,4,2,3,2,1,2,4,3,1,3,4,2,3,2,1,2,4,3};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int scores[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int scores[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = P8XGraphBuilder().solve(vector <int>(scores, scores + (sizeof scores / sizeof scores[0])));
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
