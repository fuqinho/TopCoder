#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}

class UnionFindTree {
public:
  UnionFindTree(int n) {
    rank = vector<int>(n, 0);
    par = vector<int>(n);
    for (int i = 0; i < n; i++) par[i] = i;
  }
  int find(int x) {
    if (x == par[x]) return x;
    else return par[x] = find(par[x]);
  }
  void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rank[rx] < rank[ry]) par[rx] = ry;
    else {
      par[ry] = rx;
      if (rank[rx] == rank[ry]) rank[rx]++;
    }
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
private:
  vector<int> par;
  vector<int> rank;
};

class KingdomReorganization {
public:
  int conv(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
  }

  int getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
    int N = kingdom.size();

    priority_queue<pair<int, PII> > que_destroy;
    priority_queue<pair<int, PII>, vector<pair<int, PII > >, greater<pair<int, PII> > > que_build;
    UnionFindTree tree(N);

    int total_destroy = 0;
    for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
      if (kingdom[i][j] == '1') {
        int cost = conv(destroy[i][j]);
        total_destroy += cost;
        que_destroy.push(make_pair(cost, PII(i, j)));
      } else {
        int cost = conv(build[i][j]);
        que_build.push(make_pair(cost, PII(i, j)));
      }
    }

    int res = 0;
    while (!que_destroy.empty()) {
      int cost = que_destroy.top().first;
      int x = que_destroy.top().second.first;
      int y = que_destroy.top().second.second;
      que_destroy.pop();
      if (!tree.same(x, y)) {
        total_destroy -= cost;
        tree.unite(x, y);
      }
    }
    res += total_destroy;

    while (!que_build.empty()) {
      int cost = que_build.top().first;
      int x = que_build.top().second.first;
      int y = que_build.top().second.second;
      que_build.pop();
      if (!tree.same(x, y)) {
        res += cost;
        tree.unite(x, y);
      }
    }

    return res;
  }
};





// Powered by FileEdit
// Powered by moj 4.16 [modified TZTester]
// Powered by CodeProcessor
