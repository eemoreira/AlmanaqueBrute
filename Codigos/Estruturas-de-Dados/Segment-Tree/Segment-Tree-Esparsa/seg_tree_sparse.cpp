template <ll MINL = (ll)-1e9 - 5, ll MAXR = (ll)1e9 + 5>
struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;

    vector<ll> t;
    vector<int> Lc, Rc;

    inline int newnode() {
        t.push_back(neutral);
        Lc.push_back(-1);
        Rc.push_back(-1);
        return (int)t.size() - 1;
    }

    inline int lc(int p) {
        if (Lc[p] == -1) Lc[p] = newnode();
        return Lc[p];
    }

    inline int rc(int p) {
        if (Rc[p] == -1) Rc[p] = newnode();
        return Rc[p];
    }

    SegTree() { newnode(); }

    ll query(int p, ll l, ll r, ll L, ll R) {
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        ll mid = l + (r - l) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(ll l, ll r) { return query(0, MINL, MAXR, l, r); }

    void update(int p, ll l, ll r, ll i, ll x, bool repl) {
        if (l == r) {
            if (repl) t[p] = x; // substitui
            else t[p] += x;     // soma
            return;
        }
        ll mid = l + (r - l) / 2;
        if (i <= mid) update(lc(p), l, mid, i, x, repl);
        else update(rc(p), mid + 1, r, i, x, repl);
        t[p] = merge(t[lc(p)], t[rc(p)]);
    }
    void sumUpdate(ll i, ll x) { update(0, MINL, MAXR, i, x, 0); }
    void assignUpdate(ll i, ll x) { update(0, MINL, MAXR, i, x, 1); }
};