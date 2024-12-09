bool
TCRdistCalculator::check_tcr_string_ok( string const & tcr ) const
{
	strings const l( split_to_vector(tcr,",") );
	if ( l.size() != 2 ) return false;
	string const v( l[0] ), cdr3( l[1] );

	if ( v.size() == 3 && v[0] == 'V' ) { // vfam
		if ( v_family2vfam_num_.count(v) == 0 ) return false;
	} else { // v-gene
		if ( v_gene2v_num_.count(v) == 0 ) return false;
	}
	return check_cdr3_ok( cdr3 );
}