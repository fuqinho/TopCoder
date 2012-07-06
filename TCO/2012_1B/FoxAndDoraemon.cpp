// TopCoder Open 2012 Round1B Div1 500
// System Test Passed

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class FoxAndDoraemon {
public:
  int minTime(vector <int> workCost, int splitCost) {
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i = 0; i < workCost.size(); i++) que.push(workCost[i]);
    while (que.size() > 1) {
      int x = que.top(); que.pop();
      int y = que.top(); que.pop();
      que.push(max(x, y) + splitCost);
    }
    return que.top();
  }
};

