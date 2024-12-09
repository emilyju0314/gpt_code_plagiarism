Real
compute_cluster_size_score(
	Size const num_center_nbrs, // max nbr number for cluster member
	Size const num_clustered_tcrs,
	Size const similarity_mode,
	Real const nbr_pval_threshold
)
{
	using namespace boost::math;
	static bool init( false );
	static map< pair<Size,Real>, Reals > precomputed_nbr_rates;

	if ( !init ) {
		init = true;
		string const filename( misc::dbdir + "nbr_rates_for_P_size_calc.txt" );
		strings lines;
		read_lines_from_file( filename, lines );
		foreach_( string line, lines ) {
			istringstream l(line);
			string tmp;
			Size l_sim_mode;
			Real l_nbr_pval_threshold;
			l >> tmp >> l_sim_mode >> tmp >> l_nbr_pval_threshold >> tmp;
			Reals nbr_rates;
			while ( !l.fail() ) {
				Real rate;
				l >> rate;
				if ( !l.fail() ) nbr_rates.push_back( rate );
			}
			cout << "Read " << nbr_rates.size() << " precomputed_nbr_rates for similarity_mode: " << l_sim_mode <<
				" and nbr_pval_threshold: " << l_nbr_pval_threshold << endl;
			precomputed_nbr_rates[ make_pair( l_sim_mode, l_nbr_pval_threshold ) ] = nbr_rates;
		}
	}

	Reals nbr_rates;

	if ( similarity_mode == 1 ) {
		nbr_rates.push_back( nbr_pval_threshold );
	} else { // look for info in the file
		for ( map< pair<Size,Real>, Reals >::const_iterator it= precomputed_nbr_rates.begin();
					it!= precomputed_nbr_rates.end(); ++it ) {
			if ( it->first.first == similarity_mode && fabs( log( it->first.second ) - log( nbr_pval_threshold ) )<.1 ) {
				// match
				nbr_rates = it->second;
			}
		}
	}

	if ( nbr_rates.empty() ) {
		cerr << "Failed to find precomputed information for computing cluster size score:: " <<
			" similarity_mode: " << similarity_mode << " nbr_pval_threshold: " << nbr_pval_threshold << endl;
		return 1.0;
	}

	//
	Real P_size(0); // odds of seeing an equal or greater neighbor number, given the total number of tcrs clustered

	Real const wt( 1.0/ nbr_rates.size() );
	foreach_( Real rate, nbr_rates ) {
		P_size += wt * cdf( complement( binomial( num_clustered_tcrs-1, rate ), num_center_nbrs-1 ) );
	}

	return P_size;
}