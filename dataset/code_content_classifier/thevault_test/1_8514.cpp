double LMatrix::at( int n, int m)
{

double Value=0;


          std::vector <double> R=m_Mat.at(n);
          Value=R.at(m);


return Value; 
}