// TopCoder Open 2012 Round1B Div1 250
// System Test Passed

#include <iostream>
#include <vector>
using namespace std;

class FoxAndKgram {
public:
  bool canMake(vector<int>& nums, int k) {
    int madeRows = nums[k];
    for (int i = 1; i <= (k-1)/2; i++) {
      if (i == k-1-i)
        madeRows += nums[i] / 2;
      else
        madeRows += min(nums[i], nums[k-1-i]);
    }
    return madeRows >= k;
  }

  int maxK(vector <int> len) {
    vector<int> nums(51, 0);
    for (int i = 0; i < len.size(); i++) nums[len[i]]++;

    int answer = 0;
    for (int i = 1; i <= 50; i++) if (canMake(nums, i)) answer = i;
    return answer;
  }
};

