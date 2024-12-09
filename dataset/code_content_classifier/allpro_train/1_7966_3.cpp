#include<iostream>
using namespace std;
#include<complex>
#include<vector>
void dft(vector<complex<double> >&A,int sign)
{
	int N=A.size()>>1;
	if(N==0)return;
	vector<complex<double> >F(N),G(N);
	for(int i=0;i<N;i++)
	{
		F[i]=A[i<<1];
		G[i]=A[i<<1|1];
	}
	dft(F,sign);
	dft(G,sign);
	complex<double>z(cos(M_PI/N),sin(M_PI/N)*sign),p=1;
	for(int i=0;i<N;i++)
	{
		A[i]=F[i]+p*G[i];
		A[i+N]=F[i]-p*G[i];
		p*=z;
	}
}
vector<long long>multiply(const vector<int>&A,const vector<int>&B)
{
	if(A.empty()||B.empty())
	{
		return(vector<long long>){};
	}
	int N=1;
	vector<long long>ret(A.size()+B.size()-1);
	while(N<ret.size())N<<=1;
	vector<complex<double> >F(N),G(N);
	for(int i=0;i<A.size();i++)F[i]=A[i];
	for(int i=0;i<B.size();i++)G[i]=B[i];
	dft(F,1);
	dft(G,1);
	for(int i=0;i<N;i++)F[i]*=G[i];
	dft(F,-1);
	for(int i=0;i<ret.size();i++)ret[i]=llround((F[i]/=N).real());
	return ret;
}
int N,M,K,L;
string B[500];
int main()
{
	cin>>N>>M>>K>>L;
	vector<int>b(M*M);
	for(int i=0;i<N;i++)
	{
		cin>>B[i];
		for(int j=0;j<N;j++)
		{
			b[i*M+j]=B[i][j]=='X';
		}
	}
	string S;cin>>S;
	vector<int>c(M*M);
	int x=0,y=0;
	for(int i=0;i<S.size();i++)
	{
		if(S[i]=='U')y--;
		else if(S[i]=='D')y++;
		else if(S[i]=='L')x--;
		else x++;
		c[y*M+x]+=1;
	}
	vector<long long>A=multiply(b,c);
	int cnt=0;
	for(int i=0;i<M*M;i++)cnt+=A[i]>=K;
	cout<<cnt<<endl;
}

