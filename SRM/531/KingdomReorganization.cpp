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

class UnionFindTree {
public:
    UnionFindTree(int n) {
        rank = std::vector<int>(n, 0);
        par = std::vector<int>(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }
    int find(int x) {
        if (x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rank[rx] < rank[ry]) par[rx] = ry;
        else {
            par[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
private:
    std::vector<int> par;
    std::vector<int> rank;
};

class KingdomReorganization {
public:
    int conv(char c) {
        if (c >= 'A' && c <= 'Z') return c - 'A';
        else return c - 'a' + 26;
    }
    int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
        vector<pair<int, pair<int, int> > > edges;
        for (int i = 0; i < kingdom.size(); i++) {
            for (int j = 0; j < kingdom[i].size(); j++) {
                if (kingdom[i][j] == '1' && i < j) {
                    pair<int, int> path(i, j);
                    pair<int, pair<int, int> > info(conv(destroy[i][j]), path);
                    edges.push_back(info);
                }
            }
        }

        int cost = 0;
        UnionFindTree tree(kingdom.size());
        sort(edges.rbegin(), edges.rend());
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i].second.first;
            int y = edges[i].second.second;
            if (tree.same(x, y)) {
                cost += edges[i].first;
            } else {
                tree.unite(x, y);
            }
        }

        vector<pair<int, pair<int, int> > > edges2;
        for (int i = 0; i < kingdom.size(); i++) {
            for (int j = 0; j < kingdom[i].size(); j++) {
                if (kingdom[i][j] == '0' && i < j) {
                    pair<int, int> path(i, j);
                    pair<int, pair<int, int> > info(conv(build[i][j]), path);
                    edges2.push_back(info);
                }
            }
        }
        sort(edges2.begin(), edges2.end());
        for (int i = 0; i < edges2.size(); i++) {
            int x = edges2[i].second.first;
            int y = edges2[i].second.second;
            if (tree.same(x, y)) {
                //cost += edges[i].first;
            } else {
                tree.unite(x, y);
                cost += edges2[i].first;
            }
        }

        return cost;
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
			string kingdom[]          = {"000","000","000"};
			string build[]            = {"ABD","BAC","DCA"};
			string destroy[]          = {"ABD","BAC","DCA"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string kingdom[]          = {"011","101","110"};
			string build[]            = {"ABD","BAC","DCA"};
			string destroy[]          = {"ABD","BAC","DCA"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string kingdom[]          = {"011000","101000","110000","000011","000101","000110"};
			string build[]            = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
			string destroy[]          = {"ABDFFF","BACFFF","DCAFFF","FFFABD","FFFBAC","FFFDCA"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string kingdom[]          = {"0"};
			string build[]            = {"A"};
			string destroy[]          = {"A"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string kingdom[]          = {"0001","0001","0001","1110"};
			string build[]            = {"AfOj","fAcC","OcAP","jCPA"};
			string destroy[]          = {"AWFH","WAxU","FxAV","HUVA"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			string kingdom[]          = {"0000000000","0000000011","0001010000","0010010000","0000001000","0011000000","0000100000","0000000011","0100000101","0100000110"};
			string build[]            = {"AhPEqkSFMM","hAfKPtsDad","PfAyGQkaqN","EKyAeLpRpm","qPGeASfNwo","ktQLSAnCAK","SskpfnAdJS","FDaRNCdAZz","MaqpwAJZAn","MdNmoKSznA"};
			string destroy[]          = {"AgTqWWxEYH","gAXPgjzIRA","TXAleTmWvT","qPlAQkwxRO","WgeQAqgbJJ","WjTkqAiTzl","xzmwgiAuHb","EIWxbTuAwk","YRvRJzHwAn","HATOJlbknA"};
			int expected__            = 65;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string kingdom[]          = ;
			string build[]            = ;
			string destroy[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = KingdomReorganization().getCost(vector <string>(kingdom, kingdom + (sizeof kingdom / sizeof kingdom[0])), vector <string>(build, build + (sizeof build / sizeof build[0])), vector <string>(destroy, destroy + (sizeof destroy / sizeof destroy[0])));
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
