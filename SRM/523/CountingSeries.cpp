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

class CountingSeries {
public:
    long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
        long long result = 0;
        if (upperBound >= a) result += (upperBound - a) / b + 1;
        if (upperBound >= c) {
            long long prod = c;
            while (prod <= upperBound) {
                if (prod - a < 0 || (prod - a) % b != 0) result++;
                if (d != 1) 
                    prod *= d;
                else
                    break;
            }
        }
        return result;
    }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
