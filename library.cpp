#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
// using mint = modint998244353;
// using mint = modint1000000007;
ll mod = 998244353;
// ll mod = 1000000007;
ll inf = 2e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(a) (a).begin(), (a).end()
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
#pragma GCC optimize("O3")
ll extGCD(ll a,ll b,ll &x,ll &y){
    // ax + by = gcd(a,b) = d
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b,a%b,y,x);
    y -= a/b*x;
    return d;
}
vector<int> manacher(string s){
    ll n = s.size();
    vector<int> R(n);
    ll r = -1;
    ll ri = 0;
    for(int i=0; i<n; i++){
        if(i >= r){
            ll c = 1;
            while(i+c >= 0 && i+c < n && s[i+c] == s[i-c])c++;
            R[i] = c;
            r = i+c-1;
            ri = i;
        }
        else{
            ll re = ri-(i-ri);
            if(R[re]+i-1 >= r){
                ll c = r-i;
                while(i+c >= 0 && i+c < n && s[i+c] == s[i-c])c++;
                R[i] = c;
                r = i+c-1;
                ri = i;
            }
            else{
                R[i] = R[re];
            }
        }
    }
    return R;
}
// template <class T> struct BIT{

//   public:
//     BIT() : _n(0) {}
//     BIT(int n) : _n(n), data(n) {}

//     void add(int p, T x) {
//         assert(0 <= p && p < _n);
//         p++;
//         while (p <= _n) {
//             data[p - 1] += x;
//             p += p & -p;
//         }
//     }
//     void set(int p, T x){
//         add(p,x-data[p]);
//     }
//     int min_left(T x){
//         int pos = -1;
//         if(x <= 0)return 0;
//         for(int i=1<<__lg(_n); i>0; i>>=1){
//             if(i+pos < _n && x > data[i+pos]){
//                 pos += i;
//                 x -= data[pos];
//             }
//         }
//         return pos+1;
//     }
//     T get(int p){
//         return data[p];
//     }
//     T sum(int l, int r) {
//         assert(0 <= l && l <= r && r <= _n);
//         return sum(r) - sum(l);
//     }

//   private:
//     int _n;
//     std::vector<T> data;

//     T sum(int r) {
//         T s = 0;
//         while (r > 0) {
//             s += data[r - 1];
//             r -= r & -r;
//         }
//         return s;
//     }
// };