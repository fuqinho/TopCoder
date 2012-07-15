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
int N;
vector<int> G[16];
int know[2][16];

int A_BIT = (1 << 0);
int B_BIT = (1 << 1);
int SHARED_A_BIT = (1 << 2);
int SHARED_B_BIT = (1 << 3);

class Rumor {
public:
  int simulation(int priority) {
    int cycle = 0;
    REP(k, N+1) {
      bool updated = false;
      REP(i, N) know[(cycle+1)&1][i] = know[cycle&1][i];

      for (int i = 0; i < N; i++) {
        int rumor = 0;
        if ((know[cycle&1][i] & A_BIT) && !(know[cycle&1][i] & SHARED_A_BIT)) rumor |= A_BIT;
        if ((know[cycle&1][i] & B_BIT) && !(know[cycle&1][i] & SHARED_B_BIT)) rumor |= B_BIT;
        if (rumor == (A_BIT|B_BIT)) {
          if (priority & (1<<i)) rumor = B_BIT;
          else rumor = A_BIT;
        }
        
        if (rumor) {
          for (int j = 0; j < G[i].size(); j++) {
            int to = G[i][j];
            if (!(know[(cycle+1)&1][to] & rumor)) {
              know[(cycle+1)&1][to] |= rumor;
              updated = true;
            }
          }
          know[(cycle+1)&1][i] |= (rumor << 2);
        }
      }
      if (updated) cycle++;
      else break;
    }
    
    REP(i, N) if (!(know[0][i] & A_BIT) || !(know[0][i] & B_BIT)) return -1;

    return cycle;
  }

  int getMinimum(string knowledge, vector <string> graph) {
    N = knowledge.size();
    if (count(ALL(knowledge), 'Y') == N) return 0;

    REP(i, N) {
      G[i].clear();
      REP(j, N) {
        if (graph[i][j] == 'Y') G[i].push_back(j);
      }
    }

    int res = INF;
    for (int priority = 0; priority < (1 << N); priority++) {
      memset(know, 0, sizeof(know));
      REP(i, N) if (knowledge[i] == 'Y') know[0][i] = (A_BIT|B_BIT);
      res = min(res, simulation(priority));
    }

    if (res == INF) return -1;
    else return res;
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
			string knowledge          = "YNN";
			string graph[]            = {"NYN"
,"NNY"
,"NNN"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string knowledge          = "YNNY";
			string graph[]            = {"NYYN"
,"YNNY"
,"YNNY"
,"NYYN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string knowledge          = "YYYY";
			string graph[]            = {"NYNN"
,"YNYN"
,"NYNY"
,"NNYN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string knowledge          = "YYYYYN";
			string graph[]            = {"NYYYYN"
,"YNYYYN"
,"YYNYYN"
,"YYYNYN"
,"YYYYNN"
,"NNNNNN"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string knowledge          = "NNNY";
			string graph[]            = {"NNNN"
,"YNNN"
,"YNNN"
,"NYYN"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string knowledge          =  "NNNNNNNYYY";
			string graph[]            = {"NYNNYNNYNN"
,"NNYNYNNNNY"
,"YYNNNYNNNN"
,"YNNNYNYNNN"
,"NNYNNYNNYN"
,"NNNNYNNNYY"
,"NYNYNYNNNN"
,"NNNNNNYNYY"
,"NNNYNNNYNY"
,"NYYNNNNYNN"}
;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

    case 6: {
			string knowledge          = "NYNNNNNNNNNNNYN";
			string graph[]            = {"NNYNNYNNYYYNNYN", "NNNYYYNNNNNNNNY", "YNNNNNNNYNNYYNN", "NNNNYYYNYYNNNNN", "YNYNNNNNNNNNNNY", "NNNNNNNNNNNNNNN", "NYNNYYNNNNNNNNN", "NYNYNNYNNNNNNYN", "NYNNNNNNNNNNYNN", "NNYNYNNYYNNNNNN", "NNNNNYNNYNNNNNN", "NYNNNNYYNNNNYNN", "NNNNNYNNNNNNNYN", "NNNYYYNNNNNNYNN", "NNYNNNNNNNNNNNN"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string knowledge          = ;
			string graph[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string knowledge          = ;
			string graph[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Rumor().getMinimum(knowledge, vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
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
