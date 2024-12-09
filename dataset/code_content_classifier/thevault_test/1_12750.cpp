double GrahamScan::direction( std::pair<double,double> p0,
                          std::pair<double,double> p1,
                          std::pair<double,double> p2 )
    {
        return ( (p0.first - p1.first ) * (p2.second - p1.second ) )
               - ( (p2.first - p1.first ) * (p0.second - p1.second ) );
    }