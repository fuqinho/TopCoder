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

class SRMRoomAssignmentPhase {
public:
    int countCompetitors(vector <int> ratings, int K) {
        int higher = 0;
        REP(i, ratings.size()) if (ratings[i] > ratings[0]) higher++;
        return higher / K;
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
			int ratings[]             = {491, 981, 1199, 763, 994, 879, 888};
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int ratings[]             = {1024, 1000, 600};
			int K                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int ratings[]             = {505, 679, 900, 1022};
			int K                     = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int ratings[]             = {716, 58, 1000, 1004, 912, 822, 453, 1100, 558};
			int K                     = 3;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int ratings[]             = {422, 623, 1023, 941, 882, 776, 852, 495, 803, 622, 618, 532, 751, 500};
			int K                     = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int ratings[]             = {1197, 1198, 1196, 1195, 1199};
			int K                     = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int ratings[]             = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SRMRoomAssignmentPhase().countCompetitors(vector <int>(ratings, ratings + (sizeof ratings / sizeof ratings[0])), K);
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
