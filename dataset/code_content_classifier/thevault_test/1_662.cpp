inline
string
F( int const width, int const decimals, float const & t )
{
	stringstream out;
	out << fixed << showpoint << setprecision( decimals ) << setw( width ) << t;
	return out.str();
}