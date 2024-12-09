#include <bits/stdc++.h>
using namespace std;

template<typename F, typename T, typename Func_mf, typename Func_op, typename Func_mv>
struct LazySegtree {
    int n, n_org;
    vector<T> dat;
    vector<F> laz;
    Func_mf merge_functions;
    Func_op operate;
    Func_mv merge_values;
    F fe;
    T te;

    LazySegtree(){}
    LazySegtree(int n_org,
                Func_mf merge_functions,
                Func_op operate,
                Func_mv merge_values,
                F fe, T te):
                n_org(n_org),
                merge_functions(merge_functions),
                operate(operate),
                merge_values(merge_values),
                fe(fe), te(te){
        n = 1;
        while(n < n_org) n <<= 1;
        dat.assign(2*n-1, te);
        laz.assign(2*n-1, fe);
    }

    void build(vector<T>& A){
        for(int k=0; k<int(A.size()); k++) dat[k+n-1] = A[k];
        for(int k=n-2; k>=0; k--) dat[k] = merge_values(dat[2*k+1], dat[2*k+2]);
    }

    void eval(int k, int w){
        if(laz[k] == fe) return;
        operate(dat[k], laz[k], w);
        if(k < n-1){
            merge_functions(laz[2*k+1], laz[k]);
            merge_functions(laz[2*k+2], laz[k]);
        }
        laz[k] = fe;
    }

    void update_between(int a, int b, F x){
        update(a, b+1, x, 0, 0, n);
    }

    void update(int a, int b, F x, int k, int lb, int rb){
        eval(k, rb-lb);
        if(b <= lb || rb <= a) return;
        if(a <= lb && rb <= b){
            merge_functions(laz[k], x);
            eval(k, rb-lb);
        }else{
            int mb = (lb+rb)>>1;
            update(a, b, x, 2*k+1, lb, mb);
            update(a, b, x, 2*k+2, mb, rb);
            dat[k] = merge_values(dat[2*k+1], dat[2*k+2]);
        }
    }

    T get_between(int a, int b){
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int lb, int rb){
        eval(k, rb-lb);
        if(rb<=a || b<=lb) return te;
        if(a<=lb && rb<=b) return dat[k];
        int mb = (lb+rb)>>1;
        T vl = query(a, b, 2*k+1, lb, mb);
        T vr = query(a, b, 2*k+2, mb, rb);
        return merge_values(vl, vr);
    }

    // [S, t] が条件checkを満たす最大のtを求める
	template<typename Func_ck>
    int lower_bound(int S, Func_ck check){
        T val = get_between(S, S);
        int k = S+n-1;
        int lb = S, rb = S+1;
        while(true){
            while(k%2){
                k = (k-1)/2;
                rb += rb-lb;
            }
			int w = rb-lb;
            eval(k, w);
            T val2 = merge_values(val, dat[k]);
            if(check(val2)){
                if(rb == n) return n_org-1;
                val = val2;
                k++;
				lb += w;
				rb += w;
            }else{
                break;
            }
        }
        while(k<n-1){
            int wh = (rb-lb)>>1;
            eval(2*k+1, wh);
            eval(2*k+2, wh);
            T val2 = merge_values(val, dat[2*k+1]);
            if(check(val2)){
                val = val2;
                k = 2*k+2;
                lb += wh;
            }else{
                k = 2*k+1;
                rb -= wh;
            }
        }
        return min(lb, n_org)-1;
    }
};

const int64_t MOD = 998244353;
void add(int64_t& a, int64_t b){
    a = (a+b) % MOD;
}
void mul(int64_t& a, int64_t b){
    a = a*b % MOD;
}

auto make_segtree = [](int N){
    using F = pair<int64_t, int64_t>;
    using T = int64_t;
    auto merge_functions = [](F& f, F& g){
        mul(f.first, g.first);
        mul(f.second, g.first);
        add(f.second, g.second);
    };
    auto operate = [](T& v, F& f, int w){
        mul(v, f.first);
        add(v, w * f.second);
    };
    auto merge_values = [](T& a, T& b){
        return (a+b) % MOD;
    };
    F fe = {1, 0};
    T te = 0;
    return LazySegtree<F, T, decltype(merge_functions), decltype(operate), decltype(merge_values)>
        (N, merge_functions, operate, merge_values, fe, te);
};

int main(){
    int N, Q;
    cin >> N >> Q;
    auto st = make_segtree(N);
    vector<int64_t> A(N);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);
    st.build(A);
    while(Q--){
        int t;
        scanf("%d", &t);
        if(t == 0){
            int l, r;
            int64_t b, c;
            scanf("%d %d %lld %lld", &l, &r, &b, &c);
            st.update_between(l, r-1, {b, c});
        }else{
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", st.get_between(l, r-1));
        }
    }
    return 0;
}
