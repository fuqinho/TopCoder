#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define dump(x)  cerr << #x << " = " << (x) << endl;

class UnsortedSequence {
public:
    vector <int> getUnsorted(vector <int> s) {
        sort(s.begin(), s.end());
        vector<int> v = s;
        do {
            if (s != v) return v;
        } while (next_permutation(v.begin(), v.end()));
        return vector<int>(0);
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int s[]                   = {1,2};
			int expected__[]          = {2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int s[]                   = {1,2,3};
			int expected__[]          = {1, 3, 2 };

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int s[]                   = {7,2,2};
			int expected__[]          = {2, 7, 2 };

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int s[]                   = {1000};
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int s[]                   = {1,1};
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int s[]                   = {1,2,4,3};
			int expected__[]          = {1, 2, 4, 3 };

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 6: {
			int s[]                   = {2,8,5,1,10,5,9,9,3,10,5,6,6,2,8,2,10};
			int expected__[]          = {1, 2, 2, 2, 3, 5, 5, 5, 6, 6, 8, 8, 9, 10, 9, 10, 10 };

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int s[]                   = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int s[]                   = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 9: {
			int s[]                   = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = UnsortedSequence().getUnsorted(vector <int>(s, s + (sizeof s / sizeof s[0])));
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
