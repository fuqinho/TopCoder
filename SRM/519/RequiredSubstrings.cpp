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

const int MOD = 1000000009;
int dp[51][1<<6][310];
string node[310];
int next[310][26];
int word_mask[310];

class RequiredSubstrings {
public:
  int solve(vector <string> words, int C, int L) {
    memset(dp, 0, sizeof(dp));
    memset(next, 0, sizeof(next));

    set<string> s;
    s.insert("");
    REP(i, words.size()) {
      REP(j, words[i].size()) {
        s.insert(words[i].substr(0, j+1));
      }
    }
    map<string, int> m;
    int state_num = 0;
    for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
      node[state_num] = *it;
      m[*it] = state_num;
      state_num++;
    }
    //REP(i, state_num) cerr << node[i] << endl;

    for (map<string, int>::iterator it= m.begin(); it != m.end(); it++) {
      for (char c = 'a'; c <= 'z'; c++) {
        string new_s = it->first + c;
        while (m.find(new_s) == m.end()) new_s = new_s.substr(1);
        next[it->second][c-'a'] = m[new_s];
      }
    }

    /*
    for (int i = 0; i < state_num; i++) {
      cerr << node[i] << "\t";
      for (int j = 0; j < 26; j++) cerr << next[i][j] << " ";
      cerr << endl;
    }
    */

    for (int i = 0; i < state_num; i++) {
      word_mask[i] = 0;
      for (int j = 0; j < words.size(); j++) {
        if (node[i].find(words[j]) != string::npos) word_mask[i] |= (1<<j);
      }
    }

    // dp[i][mask][j]: i文字目まででmaskの通りの文字が使われていて、現在の状態がjなパターンの数
    dp[0][0][0] = 1;
    for (int i = 1; i <= L; i++) {
      for (int mask = 0; mask < (1<<words.size()); mask++) {
        for (int j = 0; j < state_num; j++) {
          for (int c = 0; c < 26; c++) {
            int next_state = next[j][c];
            int next_mask = mask;
            next_mask |= word_mask[next_state];

            dp[i][next_mask][next_state] += dp[i-1][mask][j];
            dp[i][next_mask][next_state] %= MOD;
          }
        }
      }
    }

    int res = 0;
    for (int mask = 0; mask < (1<<words.size()); mask++) {
      int bit_count = 0;
      for (int i = 0; i < words.size(); i++) if (mask & (1<<i)) bit_count++;
      if (bit_count == C) {
        for (int i = 0; i < state_num; i++) {
          res += dp[L][mask][i];
          res %= MOD;
        }
      }
    }

    return res;
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
			string words[]            = {"a","aa","aaa","aaaa"};
			int C                     = 2;
			int L                     = 3;
			int expected__            = 50;

			clock_t start__           = clock();
			int received__            = RequiredSubstrings().solve(vector <string>(words, words + (sizeof words / sizeof words[0])), C, L);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string words[]            = {"abcdefgh"};
			int C                     = 0;
			int L                     = 7;
			int expected__            = 31810104;

			clock_t start__           = clock();
			int received__            = RequiredSubstrings().solve(vector <string>(words, words + (sizeof words / sizeof words[0])), C, L);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string words[]            = {"abcdefgh"};
			int C                     = 1;
			int L                     = 7;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = RequiredSubstrings().solve(vector <string>(words, words + (sizeof words / sizeof words[0])), C, L);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string words[]            = {"a","b","c","d"};
			int C                     = 3;
			int L                     = 3;
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = RequiredSubstrings().solve(vector <string>(words, words + (sizeof words / sizeof words[0])), C, L);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string words[]            = {"ab","bc","xy","yz"};
			int C                     = 2;
			int L                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = RequiredSubstrings().solve(vector <string>(words, words + (sizeof words / sizeof words[0])), C, L);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

    case 5: {
			string words[]            = {"abcdef", "cd"};
			int C                     = 1;
			int L                     = 6;
			int expected__            = 2280824;

			clock_t start__           = clock();
			int received__            = RequiredSubstrings().solve(vector <string>(words, words + (sizeof words / sizeof words[0])), C, L);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			string words[]            = ;
			int C                     = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RequiredSubstrings().solve(vector <string>(words, words + (sizeof words / sizeof words[0])), C, L);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string words[]            = ;
			int C                     = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RequiredSubstrings().solve(vector <string>(words, words + (sizeof words / sizeof words[0])), C, L);
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
