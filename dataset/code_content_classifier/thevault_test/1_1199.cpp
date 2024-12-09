arma::vec optimize_lars_gd(const arma::mat &X, const arma::mat &y, double lambda, const arma::vec &start, size_t max_num_iter = 50)
{
    arma::vec beta = start;
    arma::vec r = y - X * beta;
    double prev_rss = 0;
    double cur_rss = sum( r % r );
    int num_iter = 0;

    while( std::abs( prev_rss - cur_rss ) / prev_rss > 1e-20 && num_iter++ < max_num_iter )
    {
        prev_rss = cur_rss;
        for(int j = 0; j < X.n_cols; j++)
        {
            double beta_star = arma::dot( X.col( j ), r ) + beta[ j ];
            double update = std::abs( beta_star ) - lambda;
            update = (update > 0) ? update : 0;

            double new_beta = (beta_star > 0) ? update : -update;
            double beta_increase = new_beta - beta[ j ];

            beta[ j ] = new_beta;

            if( std::abs( beta_increase ) > 0 )
            {
                r = r - X.col( j ) * beta_increase;
            }
        }
        cur_rss = sum( r % r );
    }

    return beta;
}