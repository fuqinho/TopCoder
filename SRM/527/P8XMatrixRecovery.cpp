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

class BipartGraph {
public:
  BipartGraph(int n) {
    G = VVI(n);
    match = VI(n);
    used = vector<bool>(n);
  }
  void AddEdge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int MaxMatch() {
    fill(ALL(match), -1);
    int res = 0;
    REP(i, G.size()) {
      if (match[i] < 0) {
        fill(ALL(used), false);
        if (dfs(i)) res++;
      }
    }
    return res;
  }
private:
  VVI G;
  VI match;
  vector<bool> used;
  bool dfs(int v) {
    used[v] = true;
    REP(i, G[v].size()) {
      int u = G[v][i];
      if (match[u] < 0 || (!used[match[u]] && dfs(match[u]))) {
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }
};

class P8XMatrixRecovery {
public:

  vector<string> rows;
  vector<string> columns;
  int R;
  int C;

  bool check() {
    BipartGraph G(C*2);
    
    REP(i, C) {
      REP(j, C) {
        bool ok = true;
        REP(k, R) {
          if ((rows[k][i] == '0' && columns[j][k] == '1') ||
              (rows[k][i] == '1' && columns[j][k] == '0')) {
            ok = false;
            break;
          }
        }
        if (ok) {
          G.AddEdge(i, C+j);
        }
      }
    }
    return G.MaxMatch() == C;
  }

  vector <string> solve(vector <string> rows_, vector <string> columns_) {
    rows = rows_;
    columns = columns_;
    R = rows.size();
    C = columns.size();
    
    REP(i, R) {
      REP(j, C) {
        if (rows[i][j] == '?') {
          rows[i][j] = '0';
          if (check() == true) continue;
          rows[i][j] = '1';
        }
      }
    }
    return rows;
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
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string rows[]             = {"10?"
,"?11"};
			string columns[]          = {"01"
,"10"
,"1?"}
;
			string expected__[]       = {"101", "011" };

			clock_t start__           = clock();
			vector <string> received__ = P8XMatrixRecovery().solve(vector <string>(rows, rows + (sizeof rows / sizeof rows[0])), vector <string>(columns, columns + (sizeof columns / sizeof columns[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string rows[]             = {"0"
,"?"
,"1"};
			string columns[]          = {"0?1"};
			string expected__[]       = {"0", "0", "1" };

			clock_t start__           = clock();
			vector <string> received__ = P8XMatrixRecovery().solve(vector <string>(rows, rows + (sizeof rows / sizeof rows[0])), vector <string>(columns, columns + (sizeof columns / sizeof columns[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string rows[]             = {"10"
,"01"};
			string columns[]          = {"10"
,"01"};
			string expected__[]       = {"10", "01" };

			clock_t start__           = clock();
			vector <string> received__ = P8XMatrixRecovery().solve(vector <string>(rows, rows + (sizeof rows / sizeof rows[0])), vector <string>(columns, columns + (sizeof columns / sizeof columns[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string rows[]             = {"??0"
,"11?"
,"?01"
,"1?1"};
			string columns[]          = {"1???"
,"?111"
,"0?1?"};
			string expected__[]       = {"010", "110", "101", "101" };

			clock_t start__           = clock();
			vector <string> received__ = P8XMatrixRecovery().solve(vector <string>(rows, rows + (sizeof rows / sizeof rows[0])), vector <string>(columns, columns + (sizeof columns / sizeof columns[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string rows[]             = ;
			string columns[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = P8XMatrixRecovery().solve(vector <string>(rows, rows + (sizeof rows / sizeof rows[0])), vector <string>(columns, columns + (sizeof columns / sizeof columns[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string rows[]             = ;
			string columns[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = P8XMatrixRecovery().solve(vector <string>(rows, rows + (sizeof rows / sizeof rows[0])), vector <string>(columns, columns + (sizeof columns / sizeof columns[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string rows[]             = ;
			string columns[]          = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = P8XMatrixRecovery().solve(vector <string>(rows, rows + (sizeof rows / sizeof rows[0])), vector <string>(columns, columns + (sizeof columns / sizeof columns[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
