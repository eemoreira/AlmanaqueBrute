const int MOD1 = 998244353;
const int MOD2 = 1e9 + 7;
using mint1 = Mint<MOD1>;
using mint2 = Mint<MOD2>;

struct Hash {
    mint1 h1;
    mint2 h2;
    Hash() { }
    Hash(mint1 _h1, mint2 _h2) : h1(_h1), h2(_h2) { }
    bool operator==(Hash o) const { return h1 == o.h1 && h2 == o.h2; }
    bool operator!=(Hash o) const { return h1 != o.h1 || h2 != o.h2; }
    bool operator<(Hash o) const { return h1 == o.h1 ? h2 < o.h2 : h1 < o.h1; }
    Hash operator+(Hash o) const { return {h1 + o.h1, h2 + o.h2}; }
    Hash operator-(Hash o) const { return {h1 - o.h1, h2 - o.h2}; }
    Hash operator*(Hash o) const { return {h1 * o.h1, h2 * o.h2}; }
    Hash operator/(Hash o) const { return {h1 / o.h1, h2 / o.h2}; }
};

const int PRIME = 1001003; // qualquer primo na ordem do alfabeto
const int MAXN = 1e6 + 5;
Hash PR = {PRIME, PRIME};
Hash invPR = {mint1(1) / PRIME, mint2(1) / PRIME};
Hash pot[MAXN], invpot[MAXN];
void precalc() {
    pot[0] = invpot[0] = Hash(1, 1);
    for (int i = 1; i < MAXN; i++) {
        pot[i] = pot[i - 1] * PR;
        invpot[i] = invpot[i - 1] * invPR;
    }
}

struct DynamicHashing {
    int N;
    FenwickTree<Hash> hsh;
    DynamicHashing() { }
    DynamicHashing(string s) : N(int(s.size())) {
        vector<Hash> v(N);
        for (int i = 0; i < N; i++) {
            int c = (int)s[i];
            v[i] = pot[i + 1] * Hash(c, c);
        }
        hsh = FenwickTree<Hash>(v);
    }
    Hash operator()(int l, int r) { return hsh.query(l, r) * invpot[l]; }
    void update(int i, char ch) {
        int c = (int)ch;
        hsh.updateSet(i, pot[i + 1] * Hash(c, c));
    }
};
