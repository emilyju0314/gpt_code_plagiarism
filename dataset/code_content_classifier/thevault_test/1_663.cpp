Real // return the best score
score_l1_versus_l2(
	Reals const & l1,  // should be sorted
	Reals const & l2,  // -- ditto --
	Size & min_switchpoint // for i <= min_switchpoint, score += l1[i] - l2[i];
) //                            i >  min_switchpoint, score += l2[i] - l2[i];
{
	Real const epsilon( 1e-4 );

	runtime_assert( l1.front() >= l1.back()-epsilon ); // silly check for sorted
	runtime_assert( l2.front() >= l2.back()-epsilon ); // ditto

	Size const nsubjects( l2.size() );

	runtime_assert( l1.size() == nsubjects );

	Reals total_l1_minus_l2;

	Real total(0);
	for ( Size i=0; i< nsubjects; ++i ) {
		total += l1[i] - l2[i];
		total_l1_minus_l2.push_back( total );
	}

	runtime_assert( fabs( total_l1_minus_l2[ nsubjects-1 ] - 0.0 )<epsilon );

	Real best_score( 0.0 ), score;
	min_switchpoint = nsubjects-1; // this should give a score of 0.0

	total=0.;

	for ( Size i=nsubjects-1; i > 0; --i ) {
		total += l2[i] - l1[i];
		// this is the score if min_switchpoint were i-1:
		score = total_l1_minus_l2[ i-1 ] + total;
		if ( score >= best_score - epsilon ) { // choose smaller switchpoints with equal scores
			best_score = score;
			min_switchpoint = i-1;
		}
	}

	return best_score;

}