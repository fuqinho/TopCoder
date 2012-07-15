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


class MultiplesWithLimit {
public:
  string minMultiples(int N, vector <int> forbiddenDigits) {
    int available = (1<<10)-1;
    REP(i, forbiddenDigits.size()) available &= ~(1 << forbiddenDigits[i]);

    vector<string> best(N);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int now = q.front(); q.pop();
      for (int d = 0; d <= 9; d++) if (available & (1<<d)) {
        if (now == 0 && d == 0) continue;

        int nxt = (now * 10 + d) % N;
        if (best[nxt] == "") {
          best[nxt] = best[now] + char('0' + d);
          q.push(nxt);
          if (nxt == 0) goto END;
        }
      }
    }
END:

    if (best[0] == "") {
      return "IMPOSSIBLE";
    } else {
      if (best[0].size() >= 9) {
        ostringstream oss;
        oss << best[0].substr(0, 3) << "..." << best[0].substr(best[0].size()-3, 3)
            << "(" << best[0].size() << " digits)";
        return oss.str();
      } else {
        return best[0];
      }
    }
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int N                     = 8;
			int forbiddenDigits[]     = {2,3,4,5,6,7,8,9};
			string expected__         = "1000";

			clock_t start__           = clock();
			string received__         = MultiplesWithLimit().minMultiples(N, vector <int>(forbiddenDigits, forbiddenDigits + (sizeof forbiddenDigits / sizeof forbiddenDigits[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 9;
			int forbiddenDigits[]     = {1,3,4,5,6,7,8,9};
			string expected__         = "222...222(9 digits)";

			clock_t start__           = clock();
			string received__         = MultiplesWithLimit().minMultiples(N, vector <int>(forbiddenDigits, forbiddenDigits + (sizeof forbiddenDigits / sizeof forbiddenDigits[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 524;
			int forbiddenDigits[]     = {5,2,4};
			string expected__         = "3668";

			clock_t start__           = clock();
			string received__         = MultiplesWithLimit().minMultiples(N, vector <int>(forbiddenDigits, forbiddenDigits + (sizeof forbiddenDigits / sizeof forbiddenDigits[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 10000;
			int forbiddenDigits[]     = {0};
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = MultiplesWithLimit().minMultiples(N, vector <int>(forbiddenDigits, forbiddenDigits + (sizeof forbiddenDigits / sizeof forbiddenDigits[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 1;
			int forbiddenDigits[]     = {0,1,2,3,4,5,6,7,8,9};
			string expected__         = "IMPOSSIBLE";

			clock_t start__           = clock();
			string received__         = MultiplesWithLimit().minMultiples(N, vector <int>(forbiddenDigits, forbiddenDigits + (sizeof forbiddenDigits / sizeof forbiddenDigits[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int forbiddenDigits[]     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MultiplesWithLimit().minMultiples(N, vector <int>(forbiddenDigits, forbiddenDigits + (sizeof forbiddenDigits / sizeof forbiddenDigits[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int forbiddenDigits[]     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MultiplesWithLimit().minMultiples(N, vector <int>(forbiddenDigits, forbiddenDigits + (sizeof forbiddenDigits / sizeof forbiddenDigits[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int forbiddenDigits[]     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MultiplesWithLimit().minMultiples(N, vector <int>(forbiddenDigits, forbiddenDigits + (sizeof forbiddenDigits / sizeof forbiddenDigits[0])));
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
