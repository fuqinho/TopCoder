#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_STEP = 26;
const int MOD = 1000000007;

int memo[MAX_STEP][MAX_STEP][MAX_STEP][MAX_STEP][MAX_STEP];
vector<int> nums[5];

int dfs(int s0, int s1, int s2, int s3, int s4) {
  if (memo[s0][s1][s2][s3][s4] != -1) return memo[s0][s1][s2][s3][s4];

  long long res = 0;
  if ((nums[0][s0] & 1) && (nums[1][s1] & 1)) res += dfs(s0-1, s1-1, s2, s3, s4);
  if ((nums[1][s1] & 1) && (nums[2][s2] & 1)) res += dfs(s0, s1-1, s2-1, s3, s4);
  if ((nums[2][s2] & 1) && (nums[3][s3] & 1)) res += dfs(s0, s1, s2-1, s3-1, s4);
  if ((nums[3][s3] & 1) && (nums[4][s4] & 1)) res += dfs(s0, s1, s2, s3-1, s4-1);
  if ((nums[4][s4] & 1) && (nums[0][s0] & 1)) res += dfs(s0-1, s1, s2, s3, s4-1);

  int s0n = max(0, s0 - ((nums[0][s0] & 1) ? 2 : 1));
  int s1n = max(0, s1 - ((nums[1][s1] & 1) ? 2 : 1));
  int s2n = max(0, s2 - ((nums[2][s2] & 1) ? 2 : 1));
  int s3n = max(0, s3 - ((nums[3][s3] & 1) ? 2 : 1));
  int s4n = max(0, s4 - ((nums[4][s4] & 1) ? 2 : 1));
  if (s0 > 0 && s1 > 0) res += dfs(s0n, s1n, s2, s3, s4);
  if (s1 > 0 && s2 > 0) res += dfs(s0, s1n, s2n, s3, s4);
  if (s2 > 0 && s3 > 0) res += dfs(s0, s1, s2n, s3n, s4);
  if (s3 > 0 && s4 > 0) res += dfs(s0, s1, s2, s3n, s4n);
  if (s4 > 0 && s0 > 0) res += dfs(s0n, s1, s2, s3, s4n);

  return memo[s0][s1][s2][s3][s4] = res % MOD;
}

class EllysFiveFriends {
public:
  int getZero(vector <int> numbers) {
    for (int i=0; i<5; i++) nums[i].clear();
    memset(memo, -1, sizeof(memo));
    memo[0][0][0][0][0] = 1;

    for (int i = 0; i < numbers.size(); i++) {
      int n = numbers[i];
      nums[i].push_back(n);
      while (n) {
        if (n & 1) nums[i].push_back(n-1);
        n /= 2;
        nums[i].push_back(n);
      }
      sort(nums[i].begin(), nums[i].end());
      nums[i].erase(unique(nums[i].begin(), nums[i].end()), nums[i].end());
    }
    return dfs(nums[0].size()-1, nums[1].size()-1, nums[2].size()-1, nums[3].size()-1, nums[4].size()-1);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
