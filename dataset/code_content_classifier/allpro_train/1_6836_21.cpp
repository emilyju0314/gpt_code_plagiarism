#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

class MatrixIndex :public pair<int, int>
{
public:
	MatrixIndex(int i, int j) :pair<int, int>(i, j){
	}
};

class Matrix :public vector< vector<char> >
{
public:
	Matrix(int col, int row)
	{
		resize(col);
		for (size_t i = 0; i < size(); ++i)
		{
			vector<char> & t = (*this)[i];
			t.resize(row);
		}
	}
};


class Keys //: public string
{
public:
	string keys;
	Keys(const Keys &_key) :keys(_key.keys)
	{

	}
	Keys(Matrix & c, list<int> & is, list<int> & js)
	{
		list<pair<int,int> > sorted_is;
		for (list<int>::iterator it = is.begin(); it != is.end(); ++it)
		{
			pair<int, int> sum(0,*it);
			for (list<int>::iterator jt = js.begin(); jt != js.end(); ++jt)
			{
				sum.first += c[*it][*jt];
			}
			sorted_is.push_back(sum);
		}
		sorted_is.sort();

		list<pair<int, int> > sorted_js;
		for (list<int>::iterator jt = js.begin(); jt != js.end(); ++jt)
		{
			pair<int, int> sum(0, *jt);
			for (list<int>::iterator it = is.begin(); it != is.end(); ++it)
			{
				sum.first += c[*it][*jt];
			}
			sorted_js.push_back(sum);
		}
		sorted_js.sort();

		keys.resize((sorted_js.size() + 1) * sorted_is.size());
		int i = 0;
		for (list<pair<int, int> >::iterator it = sorted_is.begin(); it != sorted_is.end(); ++it)
		{
			for (list<pair<int, int> >::iterator jt = sorted_js.begin(); jt != sorted_js.end(); ++jt)
			{
				keys[i++] = c[it->second][jt->second] + '0';
			}
			keys[i++] = '_';
		}
	}
};






void normalize_two(Matrix & c, list<int> & is, list<int> & js, list<MatrixIndex> & twos)
{
	//???
	list<int> is2;
	for (list<int>::iterator it = is.begin(); it != is.end(); ++it)
	{
		int & i = *it;
		bool b_ok = js.size()>0;
		int j=-1;
		for (list<int>::iterator jt = js.begin(); jt != js.end() && b_ok; ++jt)
		{
			j = *jt;
			b_ok = (c[i][j] == 2);
		}
		if (b_ok)
		{
			twos.push_back(MatrixIndex(i, j));
			js.remove(j);
		}
		else
		{
			is2.push_back(i);
		}
	}
	is = is2;
	list<int> js2;
	for (list<int>::iterator jt = js.begin(); jt != js.end(); ++jt)
	{
		int & j = *jt;
		int i = -1;
		bool b_ok = is.size()>0;
		for (list<int>::iterator it = is.begin(); it != is.end() && b_ok; ++it)
		{
			i = *it;
			b_ok = (c[i][j] == 2);
		}
		if (b_ok)
		{
			twos.push_back(MatrixIndex(-1,j));
			is.remove(i);
		}
		else
		{
			js2.push_back(j);
		}
	}
	js = js2;
}

class info
{
public:
	list<MatrixIndex> indexpair[3];
	int maxpairs;
	int K;
	bool complete;
	info() :K(0), complete(false), maxpairs(-1)
	{
	}
	info(int _K) :info()
	{
		K = _K;
	}
	info(list<MatrixIndex> _indexpair[3], int _K) :info(_K)
	{
		init(_indexpair);
	}
	info(const info & _inf, const int _K) :info(_K)
	{
		maxpairs = _inf.maxpairs;
		complete = _inf.complete;
		init(_inf.indexpair);
	}
	void init(const list<MatrixIndex> _indexpair[3])
	{
		for (int i = 0; i < 3; ++i)
		{
			indexpair[i] = _indexpair[i];
		}
		update();
	}
	void update()
	{
		int k = K;
		maxpairs = int(indexpair[0].size());
		if (k > 0)
		{
			//1
			int ones = min(k, int(indexpair[1].size()));
			k -= ones;
			maxpairs += ones;
		}
		if (k/2 > 0)
		{
			//2
			int twos = min(k/2, int(indexpair[2].size()));
			k -= twos*2;
			maxpairs += twos;
		}
		complete = (maxpairs == int(indexpair[0].size() + indexpair[1].size() + indexpair[2].size()));
	}
};
map<string, info> g_cache;

info & travers_all(Matrix & c, list<int> & is, list<int> & js, list<MatrixIndex> indexpair[3], int K)
{
	Keys key(c, is, js);
	map<string, info>::iterator it_inf = g_cache.find(key.keys);
	if (it_inf != g_cache.end())
	{
		return it_inf->second;
	}

	info inf(K);
	bool b_one = false;
	for (list<int>::iterator it = is.begin(); it != is.end(); ++it)
	{
		int & i = *it;
		for (list<int>::iterator jt = js.begin(); jt != js.end(); ++jt)
		{
			int & j = *jt;
			if (c[i][j] == 1)
			{
				list<int> is2(is);
				is2.remove(i);
				list<int> js2(js);
				js2.remove(j);
				indexpair[1].push_back(MatrixIndex(i, j));
				info _inf = travers_all(c, is2, js2, indexpair, K);
				//info current(_inf);
				//current.indexpair[1].push_back(MatrixIndex(i, j));
				_inf.indexpair[1].push_back(MatrixIndex(i, j));
				//for (int previ = 0; previ < 2; ++previ)
				//{
				//	for (list<MatrixIndex>::iterator prev = indexpair[previ].begin(); prev != indexpair[previ].end(); prev++)
				//	{
				//		current.indexpair[previ].push_back(*prev);
				//	}
				//}
				//current.update();
				if (b_one)
				{
					//update
					if (_inf.indexpair[1].size() > inf.indexpair[1].size())
					{
						inf = _inf;
					}
					//if (current.maxpairs > inf.maxpairs)
					//{
					//	inf = _inf;
					//}

				}
				else
				{
					b_one = true;
					inf = _inf;
				}
				indexpair[1].pop_back();
				if (inf.complete)
				{
				//	break;
				}
			}
		}
		if (inf.complete)
		{
			//break;
		}
	}
	if (b_one == false)
	{
		list<MatrixIndex> ip[3];
		//for (int i = 0; i < 3; ++i)
		//{
		//	ip[i] = indexpair[i];
		//}
		///one ???????????£???
		normalize_two(c, is, js, ip[2]);
		inf = info(ip, K);
		//static info sinfo;
		//sinfo = inf;
		//return sinfo;
	}
	/// all complete
	g_cache[key.keys] = inf;
	return g_cache[key.keys];
}

info & travers_select_zero(Matrix & c, list<int> & is, list<int> & js, list<MatrixIndex> indexpair[3], int K)
{
	Keys key(c, is, js);
	map<string, info>::iterator it_inf = g_cache.find(key.keys);
	if (it_inf != g_cache.end())
	{
		return it_inf->second;
	}
	info inf(K);
	bool b_zero = false;
	for (list<int>::iterator it = is.begin(); it != is.end(); ++it)
	{
		int & i = *it;
		for (list<int>::iterator jt = js.begin(); jt != js.end(); ++jt)
		{
			int & j = *jt;
			if (c[i][j] == 0)
			{
				list<int> is2(is);
				is2.remove(i);
				list<int> js2(js);
				js2.remove(j);
				indexpair[0].push_back(MatrixIndex(i, j));
				info _inf = travers_select_zero(c, is2, js2, indexpair, K);
				info total(_inf);
				for (list<MatrixIndex>::iterator prev = indexpair[0].begin(); prev != indexpair[0].end(); prev++)
				{
					total.indexpair[0].push_back(*prev);
				}
				total.update();
				_inf.indexpair[0].push_back(MatrixIndex(i, j));
				if (b_zero)
				{
					//update
					if (total.maxpairs > inf.maxpairs)
					{
						inf = _inf;
						inf.maxpairs = total.maxpairs;
						inf.complete = total.complete;
					}
				}
				else
				{
					b_zero = true;
					inf = _inf;
					inf.maxpairs = total.maxpairs;
					inf.complete = total.complete;
				}
				indexpair[0].pop_back();
			}
			if (inf.complete)
			{
				break;
			}
		}
		if (inf.complete)
		{
			break;
		}
	}
	if (b_zero == false)
	{
		///zero ???????????£???
		inf = travers_all(c, is, js, indexpair, K);
		inf.update();
	}
	/// all complete
	g_cache[key.keys] = inf;
	return g_cache[key.keys];
}

info & search_maxpair(Matrix & c, list<int> & is, list<int> & js, int K)
{
	list<MatrixIndex> indexpair[3];
	info & inf = travers_select_zero(c, is, js, indexpair, K);
	return inf;
}
int main(){

	std::istream & c_in = cin;

	int A, B, K;
	c_in >> A >> B >> K;
	Matrix a(A, B);
	for (size_t i = 0; i < a.size(); ++i)
	{
		vector<char> & t = a[i];
		for (size_t j = 0; j < t.size(); ++j)
		{
			c_in >> t[j];
			t[j] -= '0';
		}
	}
	Matrix b(B, A);
	for (size_t i = 0; i < b.size(); ++i)
	{
		vector<char> & t = b[i];
		for (size_t j = 0; j < t.size(); ++j)
		{
			c_in >> t[j];
			t[j] -= '0';
		}
	}

	Matrix c(A, B);
	for (size_t i = 0; i < c.size(); ++i)
	{
		for (size_t j = 0; j < c[i].size(); ++j)
		{
			c[i][j] = a[i][j] + b[j][i];
		}
	}
	list<int>is;
	list<int>js;
	for (int i = 0; i < A; ++i)
	{
		is.push_back(i);
	}
	for (int j = 0; j < B; ++j)
	{
		js.push_back(j);
	}


	info inf = search_maxpair(c, is, js, K);
	cout << inf.maxpairs << endl;
}