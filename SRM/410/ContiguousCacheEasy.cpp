// Div2 Easy(250)
// System Test Passed

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class ContiguousCacheEasy {
public:
  int bytesRead(int n, int k, vector <int> addresses) {
    int top = 0; // キャッシュの先頭アドレス
    int bytesRead = 0; // メモリから読まれたバイト数
    for (int i = 0; i < addresses.size(); i++) {
      // 次に読むbyteがキャッシュの先頭より前だった場合
      if (addresses[i] < top) {
        // メモリから読むバイト数は、最大でもk
        bytesRead += min(k, top - addresses[i]);
        top = addresses[i];
      }
      // 次に読むbyteがキャッシュの最後より後だった場合
      else if (addresses[i] > top + k - 1) {
        bytesRead += min(k, addresses[i] - (top + k - 1));
        top = addresses[i] - k + 1;
      }
    }
    return bytesRead;
  }

 
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 100; int Arg1 = 5; int Arr2[] = {6, 0, 3, 20, 22, 16}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 13; verify_case(0, Arg3, bytesRead(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 1; int Arr2[] = {0, 4, 6, 6, 4, 10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, bytesRead(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 999; int Arr2[] = {0, 4, 123, 987, 999, 500, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, bytesRead(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ContiguousCacheEasy ___test;
    ___test.run_test(-1);
}
// END CUT HERE
