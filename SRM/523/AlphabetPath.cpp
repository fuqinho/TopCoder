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

class AlphabetPath {
public:
    string doesItExist(vector <string> letterMaze) {
        for (int i = 0; i < letterMaze.size(); i++) {
            for (int j = 0; j < letterMaze[i].size(); j++) {
                if (letterMaze[i][j] >= 'A' && letterMaze[i][j] < 'Z') {
                    bool hasPath = false;
                    if (i > 0 && letterMaze[i-1][j] == letterMaze[i][j] + 1) hasPath = true;
                    if (i < letterMaze.size() - 1 && letterMaze[i+1][j] == letterMaze[i][j] + 1) hasPath = true;
                    if (j > 0 && letterMaze[i][j-1] == letterMaze[i][j] + 1) hasPath = true;
                    if (j < letterMaze[i].size() - 1 && letterMaze[i][j+1] == letterMaze[i][j] + 1) hasPath = true;
                    if (hasPath == false) {
                        return "NO";
                    }
                }
            }
        }
        return "YES";
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
			string letterMaze[]       = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string letterMaze[]       = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string letterMaze[]       = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string letterMaze[]       = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string letterMaze[]       = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
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
