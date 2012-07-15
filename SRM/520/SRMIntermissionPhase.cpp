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
const int MAX_SCORE = 20;
int ways[21][2][200002];
int dp[2][200002];



class SRMIntermissionPhase {
public:
  int countWays(vector <int> points_, vector <string> description_) {
    memset(ways, 0, sizeof(ways));
    memset(dp, 0, sizeof(dp));

    int N = description_.size();
    int M = points_[0] + points_[1] + points_[2];

    // make all inputs 1-indexed
    vector<int> points(points_.size()+1);
    points[0] = 0;
    REP(i, 3) points[i+1] = points_[i];

    vector<string> description(N+1);
    REP(i, N) {
      description[i+1] = " " + description_[i];
    }

    // ways[i][k][j]: i番目の人が、k問目までに最大でj点とっている時の点の取り方のパターン数
    //    ways[k][j] = ways[k][j-1] + (ways[k-1][j-minScore] - ways[k-1][j-maxScore-1])
    //                 最大j-1点の時   k問目で丁度j点(k-1問目まででj-max~j-min点)
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j <= M; j++) {
        ways[i][0&1][j+1] = 1;
      }
      for (int k = 1; k <= 3; k++) {
        for (int j = 0; j <= M; j++) {
          int minScore = 0, maxScore = 0;
          if (description[i][k] == 'Y') {
            minScore = 1;
            maxScore = min(j, points[k]);
          }
          ways[i][k&1][j+1] = (ways[i][k&1][j-1+1] + ways[i][(k-1)&1][j-minScore+1]) % MOD;
          ways[i][k&1][j+1] = (ways[i][k&1][j+1] - ways[i][(k-1)&1][j-maxScore-1+1] + MOD) % MOD;
        }
      }
    }

    // dp[i][j]: i番目の人がj点以下の時の、[i..N]の人のスコアボードのパターン数
    //     dp[i][j] = dp[i][j-1] + (ways[i][3][j]-ways[i][3][j-1]) * dp[i+1][j-1]
    //                              i番目の人が丁度スコアjを取る     i+1番目の人がj-1以下
    for (int j = -1; j <= M; j++) {
      dp[(N+1)&1][j+1] = 1;
    }
    for (int i = N; i >= 1; i--) {
      dp[i&1][-1+1] = 0;
      for (int j = 0; j <= M; j++) {
        dp[i&1][j+1] = dp[i&1][j-1+1];
        LL add = (LL)(ways[i][3&1][j+1] - ways[i][3&1][j-1+1] + MOD) * dp[(i+1)&1][j-1+1];
        dp[i&1][j+1] = (dp[i&1][j+1] + add) % MOD;
      }
    }

    return dp[1&1][M+1];
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
			int points[]              = {25000, 50000, 100000};
			string description[]      = {"YNN",
 "NNN"};
			int expected__            = 25000;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int points[]              = {30000, 60000, 90000};
			string description[]      = {"NYN",
 "NYN"};
			int expected__            = 799969993;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int points[]              = {25000, 45000, 110000};
			string description[]      = {"NNN",
 "YYY"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int points[]              = {25600, 51200, 102400};
			string description[]      = {"NYY",
 "YNY",
 "YYY",
 "YNN",
 "YYN",
 "NNY",
 "NYN",
 "NNN"};
			int expected__            = 867560805;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int points[]              = ;
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int points[]              = ;
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <string>(description, description + (sizeof description / sizeof description[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int points[]              = ;
			string description[]      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMIntermissionPhase().countWays(vector <int>(points, points + (sizeof points / sizeof points[0])), vector <string>(description, description + (sizeof description / sizeof description[0])));
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
