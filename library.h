#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <functional>
#include <cassert>
using namespace std;

///////////////////////////////////////////////////////////////////
// for print-debugging
template<class T1,class T2> ostream& operator<<(ostream& o,const pair<T1,T2>& p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T>& v){o<<"[";for(typename vector<T>::const_iterator i=v.begin();i!=v.end();++i){if (i != v.begin()) o << ", ";o<<(*i);}o<<"]";return o;}
template<class T> ostream& operator<<(ostream& o, const set<T>& s){o<<"{";for(typename set<T>::const_iterator i=s.begin();i!=s.end();++i){if(i!=s.begin())o<<", ";o<<(*i);}o<<"}";return o;}
template<class K,class V> ostream& operator<<(ostream& o,const map<K,V>& m){o<<"{";for(typename map<K,V>::const_iterator i=m.begin();i!=m.end();++i){if(i!=m.begin())o<<", ";o<<i->first<<":"<<i->second;}o<<"}";return o;}
template<class T> ostream& operator<<(ostream& o,const vector<vector<T> >& m){o<<"[\n";for(typename vector<vector<T> >::const_iterator i=m.begin();i!=m.end();++i){o<<"  "<<(*i);o<<(i+1!=m.end()?",\n":"\n");}o<<"]\n";return o;}
string bitstr(int n,int d=0){string r;for(int i=0;i<d||n>0;++i,n>>=1){r+=(n&1)?"1":"0";}reverse(r.begin(),r.end());return r;}

//===============================================================//
//                        Number theory
//===============================================================//

///////////////////////////////////////////////////////////////////
// 拡張ユークリッドの互除法
// a, b (a > b)の最大公約数を求めると同時に、
// ax + by = gcd(a,b)を満たすx, yのペアを求める
int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

///////////////////////////////////////////////////////////////////
// エラトステネスのふるい
// n以下の素数のリストを返す
vector<int> getPrimes(int n) {
    vector<int> is_prime(n + 1, true);
    vector<int> res;
    for (int i=2; i<=n; i++) if (is_prime[i]) {
        res.push_back(i);
        for (int j=i*2; j<=n; j+=i) is_prime[j] = false;
    }
    return res;
}

///////////////////////////////////////////////////////////////////
// 素数判定
bool isPrime(int n) {
    for (int i=2; i*i<=n; i++) if (n%i == 0) return false;
    return n != 1;
}

///////////////////////////////////////////////////////////////////
// 素因数分解
map<int, int> factorize(int n) {
    map<int, int> res;
    for (int i = 2; i*i <= n; i++)
        while (n % i == 0) { res[i]++; n /= i; }
    if (n != 1) res[n] = 1;
    return res;
}

///////////////////////////////////////////////////////////////////
//// 合同式の値用クラス
//// 負の数を掛けないよう注意. 四則演算はセットで貼り付けないと危険.
struct mint {
    static const int n = 1000000007;
    int v;
    mint() : v(0) {}
    mint(int v) : v(v%n) {}
    mint& operator+= (const mint& o) {v = (v+o.v)%n; return *this;}
    mint& operator-= (const mint& o) {v = (v-o.v+n)%n; return *this;}
    mint& operator*= (const mint& o) {v = ((long long)v*o.v)%n; return *this;}
    mint& operator/= (const mint& o) {v = (o.inv()*=v).v; return *this;}
    mint inv() const {return (*this).pow(n-2);}
    mint pow(int e) const {mint r=1,x=v; while(e){if(e&1)r*=x; x*=x; e>>=1;} return r;}
    operator int() const {return v;}
};
mint operator+(const mint& x, const mint& y) {return (x.v+y.v)%mint::n;}
mint operator-(const mint& x, const mint& y) {return (x.v-y.v+mint::n)%mint::n;}
mint operator*(const mint& x, const mint& y) {return ((long long)x.v*y.v)%mint::n;}
mint operator/(const mint& x, const mint& y) {return x*y.inv();}
std::ostream& operator<<(std::ostream& os, const mint& x) {return os<<x.v;}

///////////////////////////////////////////////////////////////////
//// 有理数クラス
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a%b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
struct Rational {
    long long n, d;
    Rational(long long n, long long d): n(n),d(d) { reduce(); }
    Rational(): n(0),d(1) {};
    void reduce() {
        if (n == 0) {
            d = 1;
        } else {
            long long div = gcd(n, d);
            n /= div;
            d /= div;
        }
    }
};
Rational operator*(const Rational& l, const Rational& r) {
    return Rational(l.n * r.n, l.d * r.d);
}
Rational operator/(const Rational& l, const Rational& r) {
    return Rational(l.n * r.d, l.d * r.n);
}
Rational operator+(const Rational& l, const Rational& r) {
    long long deno = lcm(l.d, r.d);
    return Rational(deno / l.d * l.n + deno / r.d * r.n, deno);
}
Rational operator-(const Rational& l, const Rational& r) {
    long long deno = lcm(l.d, r.d);
    return Rational(deno / l.d * l.n - deno / r.d * r.n, deno);
}


//===============================================================//
//                        Linear Algebra
//===============================================================//
typedef vector<int> Vec;
typedef vector<Vec> Mat;
Mat E(size_t n) {
    Mat r(n, Vec(n));
    for (size_t i = 0; i < n; i++)
        r[i][i] = 1;
    return r;
}
Mat operator+(const Mat& x, const Mat& y) {
    assert(x.size() == y.size() && x[0].size() == y[0].size());
    Mat r(x.size(), Vec(y.size()));
    for (size_t i = 0; i < x.size(); i++)
        for(size_t j = 0; j < x[0].size(); j++)
            r[i][j] = x[i][j] + y[i][j];
    return r;
}
Mat operator*(const Mat& x, const Mat& y) {
    assert(x[0].size() == y.size());
    Mat r(x.size(), Vec(y[0].size()));
    for (size_t i = 0; i < r.size(); i++)
        for (size_t j = 0; j < r[0].size(); j++)
            for (size_t k = 0; k < y.size(); k++)
                r[i][j] += x[i][k] * y[k][j];
    return r;
}
// 累乗
Mat pow(const Mat& A, int p) {
    if (p == 0) return E(A.size());
    return (p & 1) ? A * pow(A, p-1) : pow(A*A, p/2);
}
// 累乗和
// A^1 + A^2 + ... + A^k
Mat lsum(const Mat& A, int k) {
    if (k == 0) return Mat(A.size(), Vec(A[0].size(), 0));
    if (k & 1) {
        return A * lsum(A, k-1) + A;
    } else {
        Mat B = lsum(A, k / 2);
        return B + (B * pow(A, k/2));
    }
}
// ガウスの消去法
// Ax = bを満たすxを返す (Vecのtypedefをdoubleにすること)
Vec gauss_jordan(const Mat& A, const Vec& b) {
    size_t n = A.size();
    Mat B(n, Vec(n+1));
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++) B[i][j] = A[i][j];
    for (size_t i = 0; i < n; i++) B[i][n] = b[i];
    
    for (size_t i = 0; i < n; i++) {
        size_t pivot = i;
        for (size_t j = i; j < n; j++) {
            if (abs(B[j][i]) > abs(B[pivot][i])) pivot = j;
        }
        swap(B[i], B[pivot]);
        
        if (abs(B[i][i]) < 1E-10) return Vec();
        
        for (size_t j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
        for (size_t j = 0; j < n; j++) if (j != i) {
            for (size_t k = i + 1; k <= n; k++) B[j][k] -= B[j][i] * B[i][k];
        }
    }
    Vec res(n);
    for (size_t i = 0; i < n; i++) res[i] = B[i][n];
    return res;
}
// A: Augmented matrix
// 係数拡大行列から解空間の次元を求めた時のコード(SRM 590 Med)
// この連立方程式はmod 2なのでxor使ってる。mod 素数のときはこの方法で解空間の次元が求まる。
long long getSolutionDim(Mat& A) {
    int R = A.size();
    int C = A[0].size();
    int row = 0, col = 0;
    while (row < R && col < C-1) {
        int pivot = row;
        while (pivot < R && A[pivot][col] == 0) pivot++;
        if (pivot != R) {
            swap(A[row], A[pivot]);
            for (int j = row + 1; j < R; j++) if (A[j][col] == 1) {
                for (int k = 0; k < C; k++) A[j][k] ^= A[row][k];
            }
            row++;
        }
        col++;
    }
    for (int i = row; i < R; i++) if (A[i][C-1]) return -1;
    return C- 1 - row;
}
// 拡大係数行列からrankを求めた時のメモ。合同式版。解がない時は-1を返す。
int getRank(Mat& A, int modulo) {
    int R = A.size();
    int C = A[0].size();
    int row = 0, col = 0;
    while (row < R && col < C-1) {
        int pivot = row;
        while (pivot < R && A[pivot][col] == 0) pivot++;
        if (pivot != R) {
            swap(A[row], A[pivot]);
            if (A[row][col] != 1) {
                int inv = INV5[A[row][col]];
                for (int j = col; j < C; j++) A[row][j] = (A[row][j] * inv) % modulo;
            }
            for (int j = row + 1; j < R; j++) if (A[j][col] != 0) {
                for (int k = col + 1; k < C; k++) A[j][k] = (A[j][k] - A[row][k] * A[j][col] + 100 * modulo) % modulo;
                A[j][col] = 0;
            }
            row++;
        }
        col++;
    }
    for (int i = row; i < R; i++) if (A[i][C-1]) return -1;
    return row;
}

//===============================================================//
//                        Geometry
//===============================================================//

///////////////////////////////////////////////////////////////////
// 2D vector
struct Vec { double x, y; Vec() {}; Vec(double x, double y): x(x), y(y) {}};
ostream& operator<<(ostream& o,const Vec& v) {o <<"(" << v.x << "," << v.y << ")"; return o;}
// comparer
bool operator==(const Vec& a, const Vec& b) {return a.x==b.x && a.y==b.y;}
bool operator!=(const Vec& a, const Vec& b) {return !(a==b); }
bool operator< (const Vec& a, const Vec& b) {return a.x<b.x || (!(b.x<a.x) && a.y<b.y);}
bool operator<=(const Vec& a, const Vec& b) {return !(b<a);}
bool operator> (const Vec& a, const Vec& b) {return b<a;}
bool operator>=(const Vec& a, const Vec& b) {return !(a<b);}
// basic operations
Vec operator-(const Vec& a, const Vec& b) {return Vec(a.x-b.x,a.y-b.y);}
Vec operator+(const Vec& a, const Vec& b) {return Vec(a.x+b.x,a.y+b.y);}
Vec operator*(const Vec& a, double m) {return Vec(a.x*m, a.y*m);}
Vec operator*(double m, const Vec& a) {return Vec(a.x*m, a.y*m);}
double dot(const Vec& a, const Vec& b) {return a.x*b.x+a.y*b.y;}
double cross(const Vec& a, const Vec& b) {return a.x*b.y-a.y*b.x;}
double norm(const Vec& a) {return sqrt(a.x*a.x+a.y*a.y);}
bool is_parallel(const Vec& a, const Vec& b) {return cross(a, b) == 0;}
int ccw(const Vec& a, const Vec& b) {double cp=cross(a, b); return cp?(cp>0?1:-1):0;}

// 2直線の交点
Vec intersection(const Vec& p1, const Vec& p2, const Vec& q1, const Vec& q2) {
    return p1 + (cross(q2-q1,q1-p1)/cross(q2-q1,p2-p1)) * (p2-p1);}
// 点と直線の距離
double distance(const Vec& p1, const Vec& p2, const Vec& q) {
    return abs(cross(p2-p1,q-p1))/norm(p2-p1);}
// 点qが線分p1p2上にあるかどうか
bool on_seg(const Vec& p1, const Vec& p2, const Vec& q) {
    return cross(p1-q,p2-q) == 0 && dot(p1-q,p2-q) <= 0;}
// 線分の交差判定
bool on_both_sides(const Vec& p1, const Vec& p2, const Vec& q1, const Vec& q2) {
    return ccw(p2-p1,q1-p1) * ccw(p2-p1,q2-p1) <= 0;
}
bool has_intersection(const Vec& p1, const Vec& p2, const Vec& q1, const Vec& q2) {
    if (is_parallel(p2-p1, q2-q1))
        return on_seg(p1,p2,q1) || on_seg(p1,p2,q2) || on_seg(q1,q2,p1) || on_seg(q1,q2,p2);
    else
        return on_both_sides(p1,p2,q1,q2) && on_both_sides(q1,q2,p1,p2);
}
// pがpsにより作られる多角形の内側にあるか判定.psは左回りを想定.
bool is_inside(const Vec& p, const vector<Vec>& ps) {
    for (int i = 0; i < ps.size(); i++) {
        Vec p_next = (i+1 < ps.size() ? ps[i+1] : ps[0]);
        if (cross(p_next - ps[i], p - ps[i]) < 0) return false;
    }
    return true;
}
// 凸包
vector<Vec> convex_hull(vector<Vec>& ps) {
    sort(ps.begin(), ps.end());
    int k = 0;
    vector<Vec> qs(ps.size() * 2);
    for (int i = 0; i < (int)ps.size(); i++) {
        while (k > 1 && ccw(qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for (int i = (int)ps.size()-2, t = k; i >= 0; i--) {
        while (k > t && ccw(qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}
    
/*
template<class T> struct Vec2d {
    T x, y;
    Vec2d() {};
    Vec2d(T x, T y): x(x), y(y) {}
};
template<class T> bool operator==(const Vec2d<T>& a, const Vec2d<T>& b) {return a.x==b.x && a.y==b.y;}
template<class T> bool operator!=(const Vec2d<T>& a, const Vec2d<T>& b) {return !(a==b); }
template<class T> bool operator< (const Vec2d<T>& a, const Vec2d<T>& b) {return a.x<b.x || (!(b.x<a.x) && a.y<b.y);}
template<class T> bool operator<=(const Vec2d<T>& a, const Vec2d<T>& b) {return !(b<a);}
template<class T> bool operator> (const Vec2d<T>& a, const Vec2d<T>& b) {return b<a;}
template<class T> bool operator>=(const Vec2d<T>& a, const Vec2d<T>& b) {return !(a<b);}
template<class T> ostream& operator<<(ostream& o,const Vec2d<T>& v) {o <<"(" << v.x << "," << v.y << ")"; return o;}
template<class T> Vec2d<T> operator-(const Vec2d<T>& a, const Vec2d<T>& b) {return Vec2d<T>(a.x-b.x,a.y-b.y);}
template<class T> Vec2d<T> operator+(const Vec2d<T>& a, const Vec2d<T>& b) {return Vec2d<T>(a.x+b.x,a.y+b.y);}
template<class T> T operator*(const Vec2d<T>& a, const Vec2d<T>& b) {return a.x*b.x+a.y*b.y;}

template<class T> T cross(const Vec2d<T>& a, const Vec2d<T>& b) {return a.x*b.y-a.y*b.x;}
template<class T> int ccw(const Vec2d<T>& a, const Vec2d<T>& b) {T cp=cross(a, b); return cp ? (cp>0?1:-1) : 0;}
template<class T> bool is_parallel(const Vec2d<T>& a, const Vec2d<T>& b) {return ccw(a, b) == 0;}
template<class T> bool is_inside(const Vec2d<T> p, const vector<Vec2d<T> >& ps) {
    for (int i = 0; i < ps.size(); i++) {
        Vec2d<T> p_next = (i+1 < ps.size() ? ps[i+1] : ps[0]);
        if (cross(p_next - ps[i], p - ps[i]) < 0) return false;
    }
    return true;
}
template<class T> vector<Vec2d<T> > convex_hull(vector<Vec2d<T> >& ps) {
    sort(ps.begin(), ps.end());
    int k = 0;
    vector<Vec2d<T> > qs(ps.size() * 2);
    for (int i = 0; i < (int)ps.size(); i++) {
        while (k > 1 && ccw(qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    for (int i = (int)ps.size()-2, t = k; i >= 0; i--) {
        while (k > t && ccw(qs[k-1] - qs[k-2], ps[i] - qs[k-1]) <= 0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}

///////////////////////////////////////////////////////////////////
// 2D segment
template<class T> struct Seg2d {
    Vec2d<T> o, t;
    Seg2d(const Vec2d<T>& o, const Vec2d<T>& t): o(o), t(t) {}
    Seg2d(T x1, T y1, T x2, T y2): o(Vec2d<T>(x1, y1)), t(Vec2d<T>(x2, y2)) {}
};
template<class T> ostream& operator<<(ostream& o,const Seg2d<T>& v){
    o << "[" << v.o << "->" << v.t << "]";
    return o;
}
template<class T> bool is_both_sides(const Seg2d<T>& a, const Seg2d<T>& b) {
    return ccw(a.t-a.o, b.o-a.o) * ccw(a.t-a.o, b.t-a.o) <= 0;
}
template<class T> bool is_parallel(const Seg2d<T>& a, const Seg2d<T>& b) {
    return is_parallel(a.t - a.o, b.t - b.o);
}
template<class T> bool is_on(const Vec2d<T>& p, const Seg2d<T>& s) {
    return ccw(s.o - p, s.t - p) == 0 && (s.o - p) * (s.t - p) <= 0;
}
template<class T> bool is_intersects(const Seg2d<T>& a, const Seg2d<T>& b) {
    if (is_parallel(a, b))
        return is_on(a.o, b) || is_on(a.t, b) || is_on(b.o, a) || is_on(b.t, a);
    else
        return is_both_sides(a, b) && is_both_sides(b, a);
}
 */

///////////////////////////////////////////////////////////////////
// 3D vector
struct vec3d {
    double x, y, z;
    vec3d() {};
    vec3d(double x, double y, double z): x(x), y(y), z(z) {}
};
vec3d operator+(const vec3d& a, const vec3d& b) {return vec3d(a.x+b.x, a.y+b.y, a.z+b.z);}
vec3d operator-(const vec3d& a, const vec3d& b) {return vec3d(a.x-b.x, a.y-b.y, a.z-b.z);}
double dot(const vec3d& a, const vec3d& b) {return a.x*b.x + a.y*b.y + a.z*b.z;}
vec3d cross(const vec3d& a, const vec3d& b) {return vec3d(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);}
double norm(const vec3d& a) {return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);}

//===============================================================//
//                        Combinatrics
//===============================================================//

//===============================================================//
//                        Data structures
//===============================================================//

///////////////////////////////////////////////////////////////////
// Union-Find Tree
struct UnionFind {
    UnionFind(int n) {
        p = rank = vector<int>(n, 0);
        for (int i=0; i<n; i++) p[i] = i;
    }
    int find(int x) { return x==p[x] ? p[x] : p[x]=find(p[x]); }
    bool same(int x, int y) { return find(x) == find(y); }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rank[rx] >= rank[ry]) p[ry] = rx; else p[rx] = ry;
        if (rank[rx] == rank[ry]) rank[rx]++;
    }
    int size() {
        int res = 0;
        for (unsigned int i=0; i<p.size(); i++) if (p[i] == i) res++;
        return res;
    }
    vector<int> p, rank;
};

///////////////////////////////////////////////////////////////////
// Binary Indexed Tree
struct BIT {
    vector<long long> bit;
    BIT(int n) { bit = vector<long long>(n+1); }
    long long sum(int i) {
        long long res = 0;
        while (i > 0) { res += bit[i]; i -= (i & -i); }
        return res;
    }
    long long sum(int i, int j) { return sum(j) - sum(i-1); }
    void add(unsigned int i, long long x) {
        while (i < bit.size()) { bit[i] += x; i += (i & -i); }
    }
};

///////////////////////////////////////////////////////////////////
// Meldable Heap
//  (confirmed at http://utpc2012.contest.atcoder.jp/tasks/utpc2012_12)
template<class T> class SkewHeap {
public:
    SkewHeap() : root(NULL), sz(0) {}
    bool empty()            { return root == NULL; }
    T top()                 { return root->val; }
    void push(T val)        { root = meld(root, new Node(val)); sz++; }
    void pop()              { Node* old = root; root = meld(root->l, root->r); delete old; sz--; }
    void meld(SkewHeap& a)  { root = meld(root, a.root); sz += a.size(); }
    int size()              { return sz; }
private:
    struct Node {
        Node *l, *r;
        T val;
        Node(T val) : l(NULL), r(NULL), val(val) {}
    };
    Node* root;
    int sz;
    Node* meld(Node* a, Node* b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        if (a->val < b->val) swap(a, b);
        a->r = meld(a->r, b);
        swap(a->l, a->r);
        return a;
    }
};

///////////////////////////////////////////////////////////////////
// Meldable Median Heap
//  (confirmed at http://utpc2012.contest.atcoder.jp/tasks/utpc2012_12)
template<class T> class MedianHeap {
public:
    bool empty() { return small.empty(); }
    T median() { return small.top(); }
    void push(T val) {
        if (small.size() == large.size()) small.push(val); else large.push(-val);
        maintain();
    }
    void pop() { small.pop(); maintain(); }
    void meld(MedianHeap& a) { small.meld(a.small); large.meld(a.large); maintain(); }
private:
    SkewHeap<T> small, large;
    void maintain() {
        while (small.size() > large.size()+1) {
            large.push(-small.top());
            small.pop();
        }
        while (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
        while (!small.empty() && !large.empty() && small.top() > -large.top()) {
            T s = small.top(), l = large.top();
            small.pop(); large.pop();
            small.push(-l); large.push(-s);
        }
    }
};

//===============================================================//
//                        Graph
//===============================================================//

///////////////////////////////////////////////////////////////////
// 二部グラフ
class BipartGraph {
public:
    BipartGraph(int n) {
        G = vector<vector<int> >(n);
        match = vector<int>(n);
        used = vector<bool>(n);
    }
    void addEdge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int maxMatch() {
        fill(match.begin(), match.end(), -1);
        int res = 0;
        for (unsigned int i=0; i<G.size(); i++) {
            if (match[i] < 0) {
                fill(used.begin(), used.end(), false);
                if (dfs(i)) res++;
            }
        }
        return res;
    }
private:
    vector<vector<int> > G;
    vector<int> match;
    vector<bool> used;
    bool dfs(int v) {
        used[v] = true;
        for (int i=0; i<G[v].size(); i++) {
            int u = G[v][i];
            if (match[u] < 0 || (!used[match[u]] && dfs(match[u]))) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }
};
// 動的メモリ確保しない版
const int BG_MAX_V = 100;
int BG_V;
int BG_G[BG_MAX_V][BG_MAX_V], BG_nE[BG_MAX_V];;
int BG_match[BG_MAX_V];
bool BG_used[BG_MAX_V];
void BG_init(int n) { BG_V = n; memset(BG_G, 0, sizeof(BG_G)), memset(BG_nE, 0, sizeof(BG_nE)); }
void BG_addEdge(int u, int v) { BG_G[u][BG_nE[u]++] = v, BG_G[v][BG_nE[v]++] = u; }
bool BG_dfs(int v) {
    BG_used[v] = true;
    for (int i = 0; i < BG_nE[v]; i++) {
        int u = BG_G[v][i], w = BG_match[u];
        if (w < 0 || (!BG_used[w] && BG_dfs(w))) { BG_match[v] = u, BG_match[u] = v; return true; }
    }
    return false;
}
int BG_maxMatch() {
    int res = 0;
    memset(BG_match, -1, sizeof(BG_match));
    for (int v = 0; v < BG_V; v++) if (BG_match[v] < 0) {
        memset(BG_used, 0, sizeof(BG_used));
        if (BG_dfs(v)) res++;
    }
    return res;
}

///////////////////////////////////////////////////////////////////
// 最大フロー
class Dinic {
public:
    Dinic(int nElement) {
        m_edges = vector< vector<Edge> >(nElement);
        m_level = vector<int>(nElement);
        m_iter = vector<int>(nElement);
    }
    void addEdge(int from, int to, int cap) {
        m_edges[from].push_back(Edge(to, cap, (int)m_edges[to].size()));
        m_edges[to].push_back(Edge(from, 0, (int)m_edges[from].size()-1));
    }
    int maxFlow(int s, int t) {
        int flow = 0;
        for (;;) {
            bfs(s);
            if (m_level[t] < 0) break;
            fill(m_iter.begin(), m_iter.end(), 0);
            int f = 0;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
private:
    struct Edge {
        int to, cap, rev;
        Edge(int t, int c, int r):to(t),cap(c),rev(r){}
    };
    static const int INF = 1000000000;
    vector< vector<Edge> > m_edges;
    vector<int> m_level;
    vector<int> m_iter;
    void bfs(int s) {
        fill(m_level.begin(), m_level.end(), -1);
        m_level[s] = 0;
        queue<int> que;
        que.push(s);
        while (que.size() > 0) {
            int v = que.front(); que.pop();
            for (unsigned int i = 0; i < m_edges[v].size(); i++) {
                Edge& e = m_edges[v][i];
                if (e.cap > 0 && m_level[e.to] == -1) {
                    m_level[e.to] = m_level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = m_iter[v]; i < m_edges[v].size(); i++) {
            Edge& e = m_edges[v][i];
            if (e.cap > 0 && m_level[e.to] > m_level[v]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    m_edges[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};

///////////////////////////////////////////////////////////////////
// 最小コストフロー
class MinCostFlowGraph {
public:
    MinCostFlowGraph(int n) : INF(100000000) {
        G = vector<vector<edge> >(n);
        h = vector<int>(n);
        dist = vector<int>(n);
        prevv = vector<int>(n);
        preve = vector<int>(n);
    }
    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back(edge(to, cap, cost, (int)G[to].size()));
        G[to].push_back(edge(from, 0, -cost, (int)G[from].size()-1));
    }
    int min_cost_flow(int s, int t, int f) {
        int res = 0;
        fill(h.begin(), h.end(), 0);
        while (f > 0) {
            priority_queue<PII, vector<PII>, greater<PII> > que;
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            que.push(PII(0, s));
            while (!que.empty()) {
                PII p = que.top(); que.pop();
                int v = p.second;
                if (dist[v] >= p.first) {
                    for (int i = 0; i < G[v].size(); i++) {
                        edge& e = G[v][i];
                        if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]) {
                            dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            que.push(PII(dist[e.to], e.to));
                        }
                    }
                }
            }
            if (dist[t] == INF) return -1;
            for (int v = 0; v < h.size(); v++) h[v] += dist[v];
            int d = f;
            for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
            f -= d;
            res += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge& e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
private:
    const int INF;
    typedef pair<int, int> PII;
    struct edge {
        int to, cap, cost, rev;
        edge(int t, int ca, int co, int r):to(t),cap(ca),cost(co),rev(r){}
    };
    vector<vector<edge> > G;
    vector<int> h, dist, prevv, preve;
};


///////////////////////////////////////////////////////////////////
// 強連結成分分解
class SCC {
public:
    SCC(int n) {
        e = re = vector<vector<int> >(n);
        cmp = vector<int>(n);
        used = vector<bool>(n);
    }
    void addEdge(int from, int to) {
        e[from].push_back(to);
        re[to].push_back(from);
    }
    pair<vector<vector<int> >, vector<int> > getSCCGraph() {
        fill(used.begin(), used.end(), false);
        for (int i = 0; i < (int)e.size(); i++) if (!used[i]) dfs(i);
        fill(used.begin(), used.end(), false);
        int n = 0;
        for (int i = (int)vs.size()-1; i >= 0; i--) if (!used[vs[i]]) rdfs(vs[i], n++);
        // make graph based on strongly connected components
        vector<vector<int> > g(n);
        for (size_t i = 0; i < e.size(); i++)
            for (size_t j = 0; j < e[i].size(); j++) {
                int from = cmp[i], to = cmp[e[i][j]];
                if (from != to && find(g[from].begin(), g[from].end(), to) == g[from].end())
                    g[from].push_back(to);
            }
        return make_pair(g, cmp);
    }
private:
    vector<vector<int> > e, re;
    vector<int> cmp, vs;
    vector<bool> used;
    void dfs(int v) {
        used[v] = true;
        for (size_t i = 0; i < e[v].size(); i++)
            if (!used[e[v][i]]) dfs(e[v][i]);
        vs.push_back(v);
    }
    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (size_t i = 0; i < re[v].size(); i++)
            if (!used[re[v][i]]) rdfs(re[v][i], k);
    }
};

///////////////////////////////////////////////////////////////////
// 頂点の次数がdeg[]で与えられるようなグラフが存在するならtrueを返す
bool havel_hakimi(vector<int> deg) {
    int N = (int)deg.size();
    if (*max_element(deg.begin(), deg.end()) >= N) return false;
    for (int k=0; k<N; k++) {
        sort(deg.rbegin(), deg.rend());
        for (int i=1; i<=deg[0]; i++) {
            if (deg[i] <= 0) return false;
            deg[i]--;
        }
        deg[0] = 0;
    }
    return true;
}


//===============================================================//
//                        String
//===============================================================//

///////////////////////////////////////////////////////////////////
// KMP法によって文字列TからパターンPにマッチするshiftの数をかぞえる
//  (confirmed at SRM 433 Div1 250)
int count_by_KMP(const string& T, const string& P) {
    // compute prefix funtion
    int m = (int)P.length();
    vector<int> p(m+1);
    p[1] = 0;
    int k = 0;
    for (int q = 2; q <= m; q++) {
        while (k > 0 && P[k] != P[q-1]) k = p[k];
        if (P[k] == P[q-1]) k = k+1;
        p[q] = k;
    }
    // pattern match
    int matches = 0;
    int q = 0;
    for (int i = 0; i < T.size(); i++) {
        while (q > 0 && P[q] != T[i]) q = p[q];
        if (P[q] == T[i]) q = q+1;
        if (q == m) {
            matches++;
            q = p[q];
        }
    }
    return matches;
}


//===============================================================//
//                        Test code
//===============================================================//

int main() {
    BipartGraph bg(10);
    bg.addEdge(0, 5); bg.addEdge(1, 5);
    cerr << bg.maxMatch() << endl;
    
    UnionFind uf(10);
    uf.unite(0, 1); uf.unite(1, 9); uf.unite(1, 5); uf.unite(2, 8);
    cerr << uf.same(1, 8) << endl;
    cerr << uf.same(5, 9) << endl;
    cerr << uf.size() << endl;
    
    mint a = 0;
    a += 3; a *= 3; a -= 2*a;
    cerr << a << endl;
    
    map<int,int> m = factorize(40);
    for (map<int,int>::iterator itr = m.begin(); itr != m.end(); itr++)
        cerr << itr->first << "^" << itr->second << " ";
    cerr << endl;
}
