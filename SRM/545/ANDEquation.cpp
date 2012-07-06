#include <vector>
using namespace std;

class ANDEquation {
public:
  int restoreY(vector <int> A) {
    for (int i = 0; i < A.size(); i++) {
      int xs = ~0;
      for (int j = 0; j < A.size(); j++) {
        if (j != i) xs &= A[j];
      }
      if (A[i] == xs) return A[i];
    }
    return -1;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
