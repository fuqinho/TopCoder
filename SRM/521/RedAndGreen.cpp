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

class RedAndGreen {
public:
    int minPaints(string row) {
        int minRepaint = row.size();
        for (int i = 0; i <= row.size(); i++) {
            int rePaint = 0;
            for (int j = 0; j < row.size(); j++) {
                if (j < i) {
                    if (row[j] != 'R') rePaint++;
                } else {
                    if (row[j] != 'G') rePaint++;
                }
            }
            minRepaint = min(minRepaint, rePaint);
        }
        return minRepaint;
    }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
