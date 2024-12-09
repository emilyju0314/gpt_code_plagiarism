#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Term {
    int coefficient;
    int exponent;
};

vector<Term> parseExpression(string expr) {
    vector<Term> terms;
    string term = "";
    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '+' || expr[i] == '-') {
            int coeff = 1;
            if (term[0] == '-') {
                coeff = -1;
                term = term.substr(1);
            }
            size_t found = term.find('^');
            if (found != string::npos) {
                int exp = stoi(term.substr(found + 1));
                term = term.substr(0, found);
                terms.push_back({coeff, exp});
            } else {
                terms.push_back({coeff, 1});
            }
            term = "";
        } else {
            term += expr[i];
        }
    }
    int coeff = 1;
    if (term[0] == '-') {
        coeff = -1;
        term = term.substr(1);
    }
    size_t found = term.find('^');
    if (found != string::npos) {
        int exp = stoi(term.substr(found + 1));
        term = term.substr(0, found);
        terms.push_back({coeff, exp});
    } else {
        terms.push_back({coeff, 1});
    }
    return terms;
}

string computeGCM(vector<Term> terms1, vector<Term> terms2) {
    vector<Term> gcm;
    
    for (Term t1 : terms1) {
        for (Term t2 : terms2) {
            if (t1.exponent == t2.exponent) {
                int gcd = __gcd(t1.coefficient, t2.coefficient);
                if (gcd != 1) {
                    gcm.push_back({gcd, t1.exponent});
                }
            }
        }
    }
    
    string gcmExpr = "";
    for (Term t : gcm) {
        if (t.exponent == 0) {
            if (t.coefficient > 0) {
                gcmExpr += "+" + to_string(t.coefficient);
            } else {
                gcmExpr += to_string(t.coefficient);
            }
        } else if (t.exponent == 1) {
            gcmExpr += "+" + to_string(t.coefficient) + "x";
        } else {
            gcmExpr += "+" + to_string(t.coefficient) + "x^" + to_string(t.exponent);
        }
    }
    
    if (gcmExpr[0] == '+') {
        gcmExpr = gcmExpr.substr(1);
    }
    
    return gcmExpr;
}

int main() {
    string expr1, expr2;
    
    while (true) {
        getline(cin, expr1);
        if (expr1 == ".") {
            break;
        }
        getline(cin, expr2);
        
        vector<Term> terms1 = parseExpression(expr1);
        vector<Term> terms2 = parseExpression(expr2);
        
        string gcm = computeGCM(terms1, terms2);
        
        cout << gcm << endl;
    }
    
    return 0;
}