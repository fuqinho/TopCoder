#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

const double PI  = acos(-1.0);

class TurtleSpy {
public:
  double maxDistance(vector <string> commands)
  {
    int forward = 0, backward = 0;
    vector<int> angles;
    for (int i = 0; i < commands.size(); i++) {
      istringstream iss(commands[i]);
      string command; int n;
      iss >> command >> n;
      if (command == "forward") forward += n;
      if (command == "backward") backward += n;
      if (command == "left") angles.push_back(360-n);
      if (command == "right") angles.push_back(n);
    }

    // どの角度が作成可能か調べる
    vector< vector<bool> > canMake(angles.size() + 1, vector<bool>(360, false));
    canMake[0][0] = true;
    for (int i = 0; i < angles.size(); i++) {
      for (int j = 0; j < 360; j++) {
        int addedAngle = (j + angles[i]) % 360;
        canMake[i+1][addedAngle] = canMake[i][addedAngle] || canMake[i][j];
      }
    }

    // 180度との最小の差分を計算
    int minDiff = 180;
    for (int i=0; i<360; i++) if(canMake[angles.size()][i]) minDiff = min(minDiff, abs(180-i));

    // 余弦定理
    double length_squared = (double)forward * forward + (double)backward * backward 
        - 2.0 * forward * backward * cos(PI * (180-minDiff) / 180);
    return sqrt(length_squared);
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
