#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>

typedef std::pair<int,int> P;

bool compare( const P& lhs, const P& rhs )
{
	if( lhs.first != rhs.first )
		return lhs.first > rhs.first;

	return lhs.second < rhs.second;
}

int main()
{
	int n;
	std::cin >> n;
	
	std::vector<P> vec;
	while( n-- )
	{
		int a, v;
		std::cin >> a >> v;
		vec.push_back( std::make_pair( v, a ) );
	}

	std::sort( vec.begin(), vec.end(), compare );

	std::cout << vec[0].second << " " << vec[0].first << std::endl;

	return 0;
}