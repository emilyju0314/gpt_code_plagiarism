void
JunctionCounts::read_probs_and_counts_from_file(
	string const & filename,
	bool const save_old_counts = false
)
{
	if ( verbose() ) cout << "JunctionCounts::read_probs_and_counts_from_file: " << filename << endl;
	ifstream data( filename.c_str() );

	if ( !save_old_counts ) initialize_counts_and_probs_arrays();

	string line, tag;
	Size num_success_rate_lines( 0 );
	while ( getline( data, line ) ) {
		istringstream l( line );
		l >> tag;
		Real p;
		string g;
		Size ii, jj, c, seqlen;
		if ( tag == "v_probs:" ) {
			l >> p >> g >> c;
			v_counts_[g] += c;
			v_probs_[g] = p;
		} else if ( tag == "j_probs:" ) {
			l >> p >> g >> c;
			j_counts_[g] += c;
			j_probs_[g] = p;
		} else if ( tag == "d_probs:" ) {
			l >> p >> g >> c;
			d_counts_[g] += c;
			d_probs_[g] = p;
		} else if ( tag == "v_trim_probs:" ) {
			l >> ii >> p >> g >> c;
			v_trim_counts_.find(g)->second[ii] += c;
			v_trim_probs_.find(g)->second[ii] = p;
		} else if ( tag == "j_trim_probs:" ) {
			l >> ii >> p >> g >> c;
			j_trim_counts_.find(g)->second[ii] += c;
			j_trim_probs_.find(g)->second[ii] = p;
		} else if ( tag == "j_trail_probs:" ) {
			l >> ii >> p >> g >> c;
			j_trail_counts_.find(g)->second[ii] += c;
			j_trail_probs_.find(g)->second[ii] = p;
		} else if ( tag == "d_trim_probs:" ) {
			l >> seqlen >> ii >> jj >> p >> g >> c;
			d_trim_counts_.find(g)->second[ii][jj] += c;
			d_trim_probs_.find(g)->second[ii][jj] = p;
		} else if ( tag == "vj_insert_probs:" ) {
			l >> ii >> p >> c;
			vj_insert_counts_[ii] += c;
			vj_insert_probs_[ii] = p;
		} else if ( tag == "vd_insert_probs:" ) {
			l >> ii >> p >> c;
			vd_insert_counts_[ii] += c;
			vd_insert_probs_[ii] = p;
		} else if ( tag == "dj_insert_probs:" ) {
			l >> ii >> p >> c;
			dj_insert_counts_[ii] += c;
			dj_insert_probs_[ii] = p;
		} else if ( tag == "d_success_rate:" ) {
			l >> d_success_rate_;
			++num_success_rate_lines;
		} else if ( tag == "nuc_probs:" ) {
			l >> ii >> jj >> p >> c;
			nuc_probs_[ii][jj] = p;
			nuc_counts_[ii][jj] += c;
		}
		runtime_assert( !l.fail() );
	} // while getline

	data.close();

	if ( num_success_rate_lines != 1 ) {
		cout << "ERROR bad number of d_success_rate_ lines: " << num_success_rate_lines << ' ' << filename << endl;
		cerr << "ERROR bad number of d_success_rate_ lines: " << num_success_rate_lines << ' ' << filename << endl;
		runtime_assert( false );
	}

	//compute_probs(); // based on the counts...

}