#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class KleofasTail {
public:
  long long countGoodSequences(long long K, long long A, long long B) {
    if (K == 0) return B - A + 1;
    long long L = K, R = K;
    if (K % 2 == 0) R++;

    long long res = 0;
    while (L <= B) {
      if (R >= A) res += min(R, B) - max(L, A) + 1;
      L = L * 2;
      R = R * 2 + 1;
    }
    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
