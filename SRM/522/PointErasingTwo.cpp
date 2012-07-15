#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define dump(x)  cerr << #x << " = " << (x) << endl;

class PointErasingTwo {
public:
    int getMaximum(vector <int> y) {
        int result = 0;
        for (int i = 0; i < y.size(); i++) {
            int y1 = y[i];
            for (int j = i + 1; j < y.size(); j++) {
                int y2 = y[j];
                if (y1 != y2) {
                    int sum = 0;
                    for (int k = i + 1; k <= j - 1; k++) {
                        if ((y[k] < y1 && y[k] > y2) || (y[k] < y2 && y[k] > y1)) {
                            sum ++;
                        }
                    }
                    result = max(result, sum);
                }
            }
        }
        return result;
    }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
