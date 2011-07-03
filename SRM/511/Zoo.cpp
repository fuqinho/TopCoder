// Div2 Medium(500) / Div1 Easy(250)
// Passed System Test
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

typedef long long LL;

#define SZ(a) int((a).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

class Zoo {
public:
  long long theCount(vector <int> answers) {
    // 各数字が何回ずつでているかチェック
    vector<int> sec(41, 0); // 動物の回答は0-40までの41通り。罠。
    REP(i, SZ(answers)) sec[answers[i]]++;
    // その中で1と2は何回でてる?
    int num1 = 0, num2 = 0;
    REP(i, SZ(sec)) {
      if (sec[i] == 1) num1 ++;
      if (sec[i] == 2) num2 ++;
    }
    // 2, 2, 2, 1, 1, 0, 0, 0, 0, ...みたいな順で並んでなければ不正
    REP(i, SZ(sec)) {
      if (i < num2) if (sec[i] != 2) return 0;
      if (i >= num2 && i < num2 + num1) if (sec[i] != 1) return 0;
      if (i >= num2 + num1) if (sec[i] != 0) return 0;
    }
    // 2になっている部分は交換可能、1が1つ以上あればそこもまとめて交換可能
    LL result = 1ll << num2;
    if (num1 > 0) result <<= 1;
    
    return result;
  }
};


  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, theCount(Arg0)); }
	void test_case_1() { int Arr0[] = {5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, theCount(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(2, Arg1, theCount(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0, 2, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 8LL; verify_case(3, Arg1, theCount(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(4, Arg1, theCount(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  Zoo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
