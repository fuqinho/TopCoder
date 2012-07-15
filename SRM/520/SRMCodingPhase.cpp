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


class SRMCodingPhase {
public:
  int countScore(vector <int> points, vector <int> skills, int luck) {
    int maxScore = 0;
    for (int mask = 1; mask < (1<<3); mask++) {
      for (int l1 = 0; l1 <= luck; l1++) {
        for (int l2 = 0; l1+l2 <= luck; l2++) {
          for (int l3 = 0; l1+l2+l3 <= luck; l3++) {
            int score = 0;
            int t1 = 0, t2 = 0, t3 = 0;
            if (mask & (1<<0)) {
              t1 = skills[0] - l1;
              if (t1 <= 0) break;
              score += points[0] - 2 * t1;
            }
            if (mask & (1<<1)) {
              t2 = skills[1] - l2;
              if (t2 <= 0) break;
              score += points[1] - 4 * t2;
            }
            if (mask & (1<<2)) {
              t3 = skills[2] - l3;
              if (t3 <= 0) break;
              score += points[2] - 8 * t3;
            }
            if (t1 + t2 + t3 <= 75) {
              maxScore = max(maxScore, score);
            }
          }
        }
      }
    }
    return maxScore;
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
			int points[]              = {250, 500, 1000};
			int skills[]              = {10, 25, 40};
			int luck                  = 0;
			int expected__            = 1310;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int points[]              = {300, 600, 900};
			int skills[]              = {30, 65, 90};
			int luck                  = 25;
			int expected__            = 680;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int points[]              = {250, 550, 950};
			int skills[]              = {10, 25, 40};
			int luck                  = 75;
			int expected__            = 1736;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int points[]              = {256, 512, 1024};
			int skills[]              = {35, 30, 25};
			int luck                  = 0;
			int expected__            = 1216;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int points[]              = {300, 600, 1100};
			int skills[]              = {80, 90, 100};
			int luck                  = 4;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int points[]              = ;
			int skills[]              = ;
			int luck                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMCodingPhase().countScore(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <int>(skills, skills + (sizeof skills / sizeof skills[0])), luck);
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
