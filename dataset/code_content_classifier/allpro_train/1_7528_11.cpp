#include<bits/stdc++.h>
using namespace std;

struct Peo
{
	int id;
	string name;
	int work;
};
bool operator<(const Peo &a,const Peo &b)
{
	if (a.work!=b.work)	return a.work>b.work;
	return a.id>b.id;
}
//==========template============
const string sez=" is not working now.";
const string working=" is working hard now.";
string name;
map<string,pair<int,int> > M; // name -> (id,work)
set<Peo> S;
set<Peo>::iterator it;
int num;
int n,m,ti;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin>>name;
		cin>>x;
		Peo tmp;
		tmp.name=name;
		tmp.work=x;
		tmp.id=i;
		M[name]=make_pair(i,x);
		S.insert(tmp);
	}
	ti=n;
	num=n/5;
	it=S.end();
	for (int i=1;i<=num;i++)
	{
		if (i==1)	it=S.begin();
		else it++;
	}
	cin>>m;
	for (int i=1;i<=m;i++)
	{
		char ch;
		cin>>ch;
		while (ch!='+' && ch!='-')	cin>>ch;
		if (ch=='+')
		{
			cin>>name;
			int x;
			cin>>x;
			Peo tmp;
			tmp.name=name;
			tmp.work=x;
			tmp.id=++ti;
			n++;
			M[name]=make_pair(ti,x);
			S.insert(tmp);
			int _num=n/5;
			if (num==0)
			{
				if (_num==0)
				{
					cout<< name << sez <<endl;
					it=S.end();
				}	else
				if (_num==1)
				{
					it=S.begin();
					if ((it->id)==ti)
					{
						cout<< name << working <<endl;
					}	else
					{
						cout<< name << sez <<endl;
						cout<<(it->name)<< working <<endl;
					}
				}
			}	else
			{
				int qaq=num;
				Peo las=*it;
				if (tmp<las)
				{
					cout<<name<< working <<endl;
					qaq++;
					while (qaq>_num)
					{
						qaq--;
						cout<<(it->name)<<  sez <<endl;
						it--;
					}
				}	else
				{
					if (qaq<_num)
					{
						qaq++;
						it++;
						if ((it->id) == ti)
						{
							cout<<name << working<<endl;
						}	else
						{
							cout<< name << sez << endl;
							cout<< it->name << working <<endl;
						}
					}	else
					{
						cout<< name << sez <<endl;
					}
				}
			}
			num=_num;
		}	else
		{
			cin>>name;
			pair<int,int> tmp1=M[name];
			Peo tmp;
			tmp.name=name;
			tmp.id=tmp1.first;
			tmp.work=tmp1.second;
			if (num!=0)
			{
				if (it->name==name)
				{
					num--;
					if (num==0)	it=S.end();else it--;
				}	else
				{
					if (tmp<(*it))	num--;
				}
			}
			S.erase(tmp);
			n--;
			int _num=n/5;
			while (num<_num)
			{
				if (num==0)
				{
					num++;
					it=S.begin();
					cout<< it->name << working <<endl;
				}	else
				{
					num++;
					it++;
					cout<< it->name << working <<endl;
				}
			}
			while (num>_num)
			{
				num--;
				cout<< it->name << sez << endl;
				if (num==0)	it=S.end();else it--;
			}
		}
	}
	return 0;
}