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

class DropCoins {
public:
    int getMinimum(vector <string> board, int K) {
        int mincost = 100000;
        for (int x1 = 0; x1 < board[0].size(); x1++) {
            for (int x2 = x1; x2 < board[0].size(); x2++) {
                for (int y1 = 0; y1 < board.size(); y1++) {
                    for (int y2 = y1; y2 < board.size(); y2++) {
                        int coin = 0;
                        for (int i = y1; i <= y2; i++) {
                            for (int j = x1; j <= x2; j++) {
                                if (board[i][j] == 'o') coin++;
                            }
                        }
                        if (coin == K) {
                            int costx1 = x1;
                            int costx2 = board[0].size() - 1 - x2;
                            int costy1 = y1;
                            int costy2 = board.size() - 1 - y2;
                            int cost = costx1 + costx2 + costy1 + costy2;
                            if (costx1 && costx2) cost += min(costx1, costx2);
                            if (costy1 && costy2) cost += min(costy1, costy2);
                            mincost = min(mincost, cost);
                        }
                    }
                }
            }
        }
        if (mincost == 100000) return -1;
        else return mincost;
    }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
