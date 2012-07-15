#include <string>
using namespace std;

class MagicStonesStore {
public:
  string ableToDivide(int n) {
    // ゴールドバッハの予想(4以上の偶数は素数の和で表せる)
    if (n == 1) return "NO";
    else return "YES";
  }
};
