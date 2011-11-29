#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define dump(x)  cerr << #x << " = " << (x) << endl;



class RainyRoad {
public:
    string isReachable(vector <string> road) {
        queue<pair<int, int> > q;
        q.push(pair<int, int>(0, 0));
        if (road[0][0] != '.') return "NO";
        road[0][0] = 'F';

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            if (road[r==0?1:0][c] == '.') {
                road[r==0?1:0][c] = 'F';
                q.push(pair<int, int>((r==0?1:0), c));
            }
            if (c < road[r].size() - 1 && road[r][c+1] == '.') {
                road[r][c+1] = 'F';
                q.push(pair<int, int>(r, c+1));
            }
            if (c < road[r].size() - 1 && road[r==0?1:0][c+1] == '.') {
                road[r==0?1:0][c+1] = 'F';
                q.push(pair<int, int>(r==0?1:0, c+1));
            }
        }

        for (int i = 0; i < road.size(); i++) {
            cerr << road[i] << endl;;
        }

        return road[0][road[0].size()-1] == 'F' ? "YES" : "NO";
    }
};



// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
