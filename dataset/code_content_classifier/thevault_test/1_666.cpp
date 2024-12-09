void
JunctionCounts::from_probs_map(
	map< string, Reals > const & pmap
)
{
	initialize_counts_and_probs_arrays(); // now the counts will be zeroed out-- signal that they are invalid

	for ( Size i=0; i< v_genes_.size(); ++i ) v_probs_[ v_genes_[i] ] = pmap.find("v_probs")->second[i];
	for ( Size i=0; i< d_genes_.size(); ++i ) d_probs_[ d_genes_[i] ] = pmap.find("d_probs")->second[i];
	for ( Size i=0; i< j_genes_.size(); ++i ) j_probs_[ j_genes_[i] ] = pmap.find("j_probs")->second[i];

	// trims
	foreach_( string g, v_genes_ ) {
		string const tag( "v_trim_probs:"+g );
		vector<Real> & trim_probs( v_trim_probs_.find(g)->second );
		for ( Size i=0; i< trim_probs.size(); ++i ) trim_probs[i] = pmap.find(tag)->second[i];
	}

	foreach_( string g, j_genes_ ) {
		string tag( "j_trim_probs:"+g );
		vector<Real> & trim_probs( j_trim_probs_.find(g)->second );
		for ( Size i=0; i< trim_probs.size(); ++i ) trim_probs[i] = pmap.find(tag)->second[i];
		tag = "j_trail_probs:"+g;
		Size const jlen( j_fasta_.find(g)->second.size() );
		runtime_assert( j_trail_probs_.find(g)->second.size() == jlen );
		for ( Size i=0; i< jlen; ++i ) j_trail_probs_.find(g)->second[i] = pmap.find(tag)->second[i];
	}


	foreach_( string g, d_genes_ ) {
		string const tag( "d_trim_probs:"+g );
		vector< vector<Real> > & trim_probs( d_trim_probs_.find(g)->second );
		Size const sz( trim_probs.size() );
		Size counter(0);
		for ( Size i=0; i< sz; ++i ) {
			for ( Size j=0; j< sz; ++j ) {
				trim_probs[i][j] = pmap.find(tag)->second[ counter ];
				++counter;
			}
		}
	}

	// now inserts
	for ( int i=0; i<= max_vj_insert_ ; ++i ) vj_insert_probs_[i] = pmap.find("vj_insert_probs")->second[i];
	for ( int i=0; i<= max_vdj_insert_; ++i ) vd_insert_probs_[i] = pmap.find("vd_insert_probs")->second[i];
	for ( int i=0; i<= max_vdj_insert_; ++i ) dj_insert_probs_[i] = pmap.find("dj_insert_probs")->second[i];

	// nuc probs
	{
		for ( Size i=0; i< alphabet_.size(); ++i ) {
			string const tag( "nuc_probs_"+alphabet_.substr(i,1));
			for ( Size j=0; j< alphabet_.size(); ++j ) {
				nuc_probs_[i][j] = pmap.find( tag )->second[ j ];
			}
		}
	}

	d_success_rate_ = pmap.find("d_success")->second.back();

}