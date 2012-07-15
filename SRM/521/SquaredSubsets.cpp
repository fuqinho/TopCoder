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

class SquaredSubsets {
public:

  long long countSubsets(int n, vector <int> px, vector <int> py) {
    vector<int> x = px, y = py;
    x.push_back(-INF); x.push_back(INF); y.push_back(-INF); y.push_back(INF);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    y.erase(unique(y.begin(), y.end()), y.end());

    set<LL> res;

    for (int left = 1; left < x.size()-1; left++) {
      for (int right = left; right < x.size()-1; right++) {
        for (int top = 1; top < y.size()-1; top++) {
          for (int bottom = top; bottom < y.size()-1; bottom++) {
            int width = x[right] - x[left];
            int height = y[bottom] - y[top];
            int outer_width = x[right+1] - x[left-1];
            int outer_height = y[bottom+1] - y[top-1];
            if (width <= n && height <= n && outer_width > n && outer_height > n) {
              LL mask = 0;
              for (int i = 0; i < px.size(); i++) {
                if (px[i] >= x[left] && px[i] <= x[right] && py[i] >= y[top] && py[i] <= y[bottom]) {
                  mask |= (1LL<<i);
                }
              }
              if (mask) res.insert(mask);
            }
          }
        }
      }
    }

    return res.size();
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int n                     = 5;
			int x[]                   = {-5,0,5};
			int y[]                   = {0,0,0};
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 10;
			int x[]                   = {-5,0,5};
			int y[]                   = {0,0,0};
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 100000000;
			int x[]                   = {-1,-1,-1,0,1,1,1};
			int y[]                   = {-1,0,1,1,-1,0,1};
			long long expected__      = 21;

			clock_t start__           = clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 5;
			int x[]                   = {5,3,6,2,1,6,4,4,7,-1,-4,-7,2,-2,0};
			int y[]                   = {0,-1,8,-5,2,5,-8,8,-6,4,3,2,7,3,5};
			long long expected__      = 66;

			clock_t start__           = clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 1;
			int x[]                   = {-1,0};
			int y[]                   = {0,0};
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = SquaredSubsets().countSubsets(n, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
