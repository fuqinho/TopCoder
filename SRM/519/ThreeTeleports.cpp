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

const LL INF = 1000000000000LL;

class ThreeTeleports {
public:
  int calc(int xMe, int yMe, int xHome, int yHome, 
      vector<int>& x0, vector<int>& y0, vector<int>& x1, vector<int>& y1) {

    vector<int> order;
    order.push_back(0);
    order.push_back(1);
    order.push_back(2);

    int curX, curY;
    LL res = INF;
    do {
      for (int mask = 0; mask < (1<<3); mask++) {
        for (int inv = 0; inv < (1<<3); inv++) {
          curX = xMe;
          curY = yMe;
          LL time = 0;
          for (int i = 0; i < 3; i++) {
            if (mask & (1<<i)) {
              if (inv & (1<<i)) {
                time += abs(x0[order[i]]-curX) + abs(y0[order[i]]-curY);
                time += 10;
                curX = x1[order[i]];
                curY = y1[order[i]];
              } else {
                time += abs(x1[order[i]]-curX) + abs(y1[order[i]]-curY);
                time += 10;
                curX = x0[order[i]];
                curY = y0[order[i]];
              }
            }
          }
          time += abs(xHome-curX) + abs(yHome-curY);
          res = min(res, time);
        }
      }
    } while (next_permutation(order.begin(), order.end()));
    return res;
  }

  int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports) {
    vector<int> x0(3), y0(3), x1(3), y1(3);
    REP(i, 3) {
      istringstream iss(teleports[i]);
      iss >> x0[i] >> y0[i] >> x1[i] >> y1[i];
    }

    return calc(xMe, yMe, xHome, yHome, x0, y0, x1, y1);
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
			int xMe                   = 3;
			int yMe                   = 3;
			int xHome                 = 4;
			int yHome                 = 5;
			string teleports[]        = {"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int xMe                   = 0;
			int yMe                   = 0;
			int xHome                 = 20;
			int yHome                 = 20;
			string teleports[]        = {"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"};
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int xMe                   = 0;
			int yMe                   = 0;
			int xHome                 = 20;
			int yHome                 = 20;
			string teleports[]        = {"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"};
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int xMe                   = 10;
			int yMe                   = 10;
			int xHome                 = 10000;
			int yHome                 = 20000;
			string teleports[]        = {"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"};
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int xMe                   = 3;
			int yMe                   = 7;
			int xHome                 = 10000;
			int yHome                 = 30000;
			string teleports[]        = {"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"};
			int expected__            = 117;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int xMe                   = 0;
			int yMe                   = 0;
			int xHome                 = 1000000000;
			int yHome                 = 1000000000;
			string teleports[]        = {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"};
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int xMe                   = ;
			int yMe                   = ;
			int xHome                 = ;
			int yHome                 = ;
			string teleports[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int xMe                   = ;
			int yMe                   = ;
			int xHome                 = ;
			int yHome                 = ;
			string teleports[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int xMe                   = ;
			int yMe                   = ;
			int xHome                 = ;
			int yHome                 = ;
			string teleports[]        = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThreeTeleports().shortestDistance(xMe, yMe, xHome, yHome, vector <string>(teleports, teleports + (sizeof teleports / sizeof teleports[0])));
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
