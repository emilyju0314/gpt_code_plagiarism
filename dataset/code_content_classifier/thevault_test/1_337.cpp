vector <int> interpolate(vector <int>& recurrence, long long k, int n){
    using namespace bbl;
    assert(recurrence.size() && (recurrence.size() % 2) == 0);

    vector <int> polynomial;
    int l = berlekamp_massey(recurrence, polynomial);
	reverse(polynomial.begin(), polynomial.begin() + l + 1);
    return interpolate(recurrence, polynomial, k, n);
}