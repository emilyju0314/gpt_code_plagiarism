#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Polynomial {
    vector<int> coeffs; // coefficients of the polynomial

    Polynomial() {}
    Polynomial(vector<int>& c) : coeffs(c) {}

    void addTerm(int coeff) {
        coeffs.push_back(coeff);
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result;
        int size = max(coeffs.size(), other.coeffs.size());
        for (int i = 0; i < size; i++) {
            int coeff1 = (i < coeffs.size()) ? coeffs[i] : 0;
            int coeff2 = (i < other.coeffs.size()) ? other.coeffs[i] : 0;
            result.addTerm(coeff1 + coeff2);
        }
        return result;
    }

    void print() {
        for (int i = coeffs.size() - 1; i >= 0; i--) {
            if (coeffs[i] != 0) {
                if (i > 1) {
                    cout << coeffs[i] << "x^" << i << "+";
                } else if (i == 1) {
                    cout << coeffs[i] << "x" << "+";
                } else {
                    cout << coeffs[i];
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int N, M;
    while (cin >> N >> M && N != 0 && M != 0) {
        vector<Polynomial> network(N, Polynomial({0}));

        for (int i = 0; i < M; i++) {
            int u, v;
            string poly;
            cin >> u >> v >> poly;

            vector<int> coeffs;
            size_t pos = 0;
            while ((pos = poly.find("x")) != string::npos) {
                int coeff = stoi(poly.substr(0, pos));
                coeffs.push_back(coeff);
                poly.erase(0, pos + 1);
            }
            coeffs.push_back(stoi(poly));

            network[u - 1] = network[u - 1] + Polynomial(coeffs);
            reverse(coeffs.begin(), coeffs.end());
            network[v - 1] = network[v - 1] + Polynomial(coeffs);
        }

        network[0].print(); // print the maximal bandwidth between the 1st and N-th base stations
    }

    return 0;
}