#include <cstdio>
#include <cassert>
#include <vector>
#include <map>
using namespace std;


int mod(int x)
{
	int a = 32768;
	return (x % a + a) % a;
}

struct matrix {

	vector<vector<int>> elem;

	matrix(int r, int c) : elem(r, vector<int>(c, 0)) { }

	int row() const { return elem.size(); }
	int column() const { return elem[0].size(); }
	vector<int> &operator[](int idx) {
		return elem[idx];
	}
	const vector<int> &operator[](int idx) const {
		return elem[idx];
	}

	void print()
	{
		for(int i = 0; i < row(); ++i) {
			for(int j = 0; j < column(); ++j) {
				printf("%d%c", elem[i][j], j == column() - 1 ? '\n' : ' ');
			}
		}
	}

	matrix get(const matrix &e1, const matrix &e2)
	{
		matrix m(e1.column(), e2.column());
		for(int i = 0; i < e1.column(); ++i) {
			for(int j = 0; j < e2.column(); ++j)
				m[i][j] = elem[e1[0][i] - 1][e2[0][j] - 1];
		}

		return m;
	}

	matrix transpose()
	{
		matrix m(column(), row());
		for(int i = 0; i < column(); ++i) {
			for(int j = 0; j < row(); ++j)
				m[i][j] = elem[j][i];
		}

		return m;
	}

	friend matrix cat_h(const matrix &a, const matrix &b)
	{
		assert(a.row() == b.row());

		matrix m(a.row(), a.column() + b.column());

		for(int i = 0; i < a.row(); ++i) {
			for(int j = 0; j < a.column(); ++j)
				m[i][j] = a[i][j];
			for(int j = 0; j < b.column(); ++j)
				m[i][a.column() + j] = b[i][j];
		}

		return m;
	}

	friend matrix cat_v(const matrix &a, const matrix &b)
	{
		assert(a.column() == b.column());

		matrix m(a.row() + b.row(), a.column());

		for(int j = 0; j < a.column(); ++j) {
			for(int i = 0; i < a.row(); ++i)
				m[i][j] = a[i][j];
			for(int i = 0; i < b.row(); ++i)
				m[a.row() + i][j] = b[i][j];
		}

		return m;
	}

	friend matrix operator+(const matrix &a, const matrix &b)
	{
		assert(a.row() == b.row());
		assert(a.column() == b.column());

		matrix m(a.row(), a.column());
		for(int i = 0; i < a.row(); ++i) {
			for(int j = 0; j < a.column(); ++j)
				m[i][j] = mod(a[i][j] + b[i][j]);
		}

		return m;
	}

	friend matrix operator-(const matrix &a)
	{
		matrix m(a.row(), a.column());
		for(int i = 0; i < a.row(); ++i) {
			for(int j = 0; j < a.column(); ++j)
				m[i][j] = mod(-a[i][j]);
		}

		return m;
	}

	friend matrix operator-(const matrix &a, const matrix &b)
	{
		return a + (-b);
	}

	friend matrix operator*(const matrix &a, const matrix &b)
	{
		if(a.row() == 1 && a.column() == 1)
		{
			matrix m(b.row(), b.column());
			for(int i = 0; i < b.row(); ++i) {
				for(int j = 0; j < b.column(); ++j)
					m[i][j] = mod(b[i][j] * a[0][0]);
			}

			return m;
		}
		if(b.row() == 1 && b.column() == 1)
		{
			matrix m(a.row(), a.column());
			for(int i = 0; i < a.row(); ++i) {
				for(int j = 0; j < a.column(); ++j)
					m[i][j] = mod(a[i][j] * b[0][0]);
			}

			return m;
		}

		assert(a.column() == b.row());
		matrix m(a.row(), b.column());

		for(int i = 0; i < a.row(); ++i) {
			for(int j = 0; j < b.column(); ++j) {
				for(int k = 0; k < a.column(); ++k)
					m[i][j] = mod(m[i][j] + a[i][k] * b[k][j]);
			}
		}

		return m;
	}
};

vector<matrix> dict;

matrix expr(char *s, int &pos);

bool isdigit(char c)
{
	return c >= '0' && c <= '9';
}

matrix inum(char *s, int &pos)
{
	assert(isdigit(s[pos]));

	const int l = pos;
	while(isdigit(s[pos]))
		pos += 1;

	int num = 0;
	int mul = 1;
	for(int i = pos - 1; i >= l; --i, mul *= 10)
		num += (s[i] - '0') * mul;

	matrix m(1, 1);
	m[0][0] = num;

	return m;
}

matrix row(char *s, int &pos)
{
	matrix m = expr(s, pos);

	while(s[pos] == ' ') {
		pos += 1;
		m = cat_h(m, expr(s, pos));
	}

	return m;
}

matrix row_seq(char *s, int &pos)
{
	matrix m = row(s, pos);

	while(s[pos] == ';') {
		pos += 1;
		m = cat_v(m, row(s, pos));
	}

	return m;
}

matrix mat(char *s, int &pos)
{
	assert(s[pos] == '['); pos += 1;
	matrix m = row_seq(s, pos);
	assert(s[pos] == ']'); pos += 1;
	return m;
}

matrix primary(char *s, int &pos)
{
	matrix m(0, 0);
	const char c = s[pos];

	if(isdigit(c)) {
		m = inum(s, pos);
	} else if(c >= 'A' && c <= 'Z') {
		m = dict[c - 'A'];
		pos += 1;
	} else if(c == '[') {
		m = mat(s, pos);
	} else if(c == '(') {
		pos += 1;
		m = expr(s, pos);
		assert(s[pos] == ')');
		pos += 1;
	} else {
		assert(false);
	}

	while(s[pos] == '\'' || s[pos] == '(') {

		if(s[pos] == '\'') {
			m = m.transpose();
			pos += 1;
			continue;
		}

		pos += 1;
		matrix e1 = expr(s, pos);
		assert(s[pos] == ',');
		pos += 1;
		matrix e2 = expr(s, pos);
		assert(s[pos] == ')');
		pos += 1;

		m = m.get(e1, e2);
	}

	return m;
}

matrix factor(char *s, int &pos)
{
	bool neg = false;

	while(s[pos] == '-') {
		pos += 1;
		neg = !neg;
	}

	if(neg)
		return -primary(s, pos);
	return primary(s, pos);
}

matrix term(char *s, int &pos)
{
	matrix m = factor(s, pos);

	while(s[pos] == '*') {
		pos += 1;
		m = m * factor(s, pos);
	}

	return m;
}

matrix expr(char *s, int &pos)
{
	matrix m = term(s, pos);

	while(s[pos] == '-' || s[pos] == '+') {
		char c = s[pos];
		pos += 1;
		matrix mm = term(s, pos);
		if(c == '+')
			m = m + mm;
		else
			m = m - mm;
	}

	return m;
}

matrix assignment(char *s)
{
	assert(s[0] >= 'A' && s[0] <= 'Z');
	assert(s[1] == '=');

	char d = s[0];
	int pos = 2;
	matrix m = expr(s, pos);

	assert(s[pos] == '.');
	dict[d - 'A'] = m;

	return m;
}

int main()
{
	while(true) {

		int n;

		scanf("%d\n", &n);
		if(n == 0)
			break;

		dict.resize(26, matrix(0,0));

		for(int l = 0; l < n; ++l) {

			char s[256];

			scanf("%[^\n]\n", s);
			//printf("s: %s\n", s);
			matrix m = assignment(s);

			m.print();
		}

		printf("-----\n");
	}

	return 0;
}