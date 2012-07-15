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


class LongestSequence {
public:

  void dfs(int idx, int k, vector<int>& C, vector<bool>& visited) {
    for (int i = 0; i < C.size(); i++) {
      int next = idx + C[i];
      if (next >= 0 && next < k && !visited[next]) {
        visited[next] = true;
        dfs(next, k, C, visited);
      }
    }
  }

  bool check(int k, vector<int>& C) {
    vector<bool> visited(k, false);
    REP(i, C.size()) {
      if (C[i] > 0 && C[i] < k) {
        visited[C[i]] = true;
        dfs(C[i], k, C, visited);
      }
    }
    return !visited[0];
  }

  int maxLength(vector <int> C) {
    int N = C.size();
    int positives = 0;
    REP(i, N) if (C[i] > 0) positives++;
    if (positives == 0 || positives == N) return -1;

    // binary search
    int lb = 0, ub = 1000 * 2;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (check(mid+1, C)) {
        lb = mid;
      } else {
        ub = mid;
      }
    }

    return lb;
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
			int C[]                   = {-2,3};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int C[]                   = {524};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int C[]                   = {1, -1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int C[]                   = {11,-7};
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int C[]                   = {-227,690,590,-524};
			int expected__            = 713;

			clock_t start__           = clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int C[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int C[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int C[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LongestSequence().maxLength(vector <int>(C, C + (sizeof C / sizeof C[0])));
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
