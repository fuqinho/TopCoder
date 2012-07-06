#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


class CasketOfStar {
public:
  vector<int> weight;
  int memo[50][51];

  int dfs(int l, int r) {
    if (r-l == 2) return 0;
    if (memo[l][r] != -1) return memo[l][r];

    int res = 0;
    for (int i = l+1; i < r-1; i++) {
      res = max(res, dfs(l, i+1) + dfs(i, r) + weight[l] * weight[r-1]);
    }
    return memo[l][r] = res;
  }

  int maxEnergy(vector <int> weight) {
    this->weight = weight;
    memset(memo, -1, sizeof(memo));

    return dfs(0, weight.size());
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
