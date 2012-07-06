#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)

const int MAX_N = 40;
const int MAX_C = 50;
double dp[MAX_N][MAX_C][MAX_C][MAX_C];
double accum[MAX_C+1][MAX_C+1][MAX_C+1];

class RandomColoring {
public:
  double range_sum(int r1, int r2, int g1, int g2, int b1, int b2) {
    double res = accum[r2][g2][b2]
               - accum[r1][g2][b2] - accum[r2][g1][b2] - accum[r2][g2][b1]
               + accum[r2][g1][b1] + accum[r1][g2][b1] + accum[r1][g1][b2]
               - accum[r1][g1][b1];
    return res;
  }

  double getProbability(int N, int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
    memset(dp, 0, sizeof(dp));
    memset(accum, 0, sizeof(accum));

    // dp[i][r][g][b]: i枚目を(r,g,b)で塗った後に、uglyになっている確率
    REP(r, maxR) REP(g, maxG) REP(b, maxB) {
      if (abs(r-startR) <= d2 && abs(g-startG) <= d2 && abs(b-startB) <= d2 &&
          (abs(r-startR) >= d1 || abs(g-startG) >= d1 || abs(b-startB) >= d1)) {
        dp[N-1][r][g][b] = 0.0;
      } else {
        dp[N-1][r][g][b] = 1.0;
      }
    }

    for (int i = N-2; i >= 0; i--) {
      // 累積和を求める
      // accum[r][g][b]: R:[0,r), G:[0,g), B:[0,b)の範囲の和
      REP(r, maxR) REP(g, maxG) REP(b, maxB) {
        accum[r+1][g+1][b+1] = dp[i+1][r][g][b]
                             + accum[r][g+1][b+1] + accum[r+1][g][b+1] + accum[r+1][g+1][b]
                             - accum[r][g][b+1] - accum[r][g+1][b] - accum[r+1][g][b]
                             + accum[r][g][b];
      }

      // DPテーブル更新
      REP(r, maxR) REP(g, maxG) REP(b, maxB) {
        int rb = max(0, r-d2);
        int re = min(maxR, r+d2+1);
        int gb = max(0, g-d2);
        int ge = min(maxG, g+d2+1);
        int bb = max(0, b-d2);
        int be = min(maxB, b+d2+1);
        int cnt = (re-rb)*(ge-gb)*(be-bb);
        double sum_p = range_sum(rb, re, gb, ge, bb, be);
        if (d1 > 0) {
          rb = max(0, r-d1+1);
          re = min(maxR, r+d1);
          gb = max(0, g-d1+1);
          ge = min(maxG, g+d1);
          bb = max(0, b-d1+1);
          be = min(maxB, b+d1);
          cnt -= (re-rb)*(ge-gb)*(be-bb);
          sum_p -= range_sum(rb, re, gb, ge, bb, be);
        }
        if (cnt == 0) {
          dp[i][r][g][b] = 0.0;
        } else {
          dp[i][r][g][b] = sum_p / cnt;
        }
      }
    }
    return dp[0][startR][startG][startB];
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
