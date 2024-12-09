void
adjust_sampling_probs(
	Reals const & target,
	Reals const & sampled,
	Reals & probs, //  used to make the distn seen in sampled
	string const tag = string()
)
{
	Real const sampling_adjustment_factor( 1.0 ); // -sampling_adjustment_factor in tmp.compare_probs.v[456].log
	Size const n( probs.size() );
	runtime_assert( target.size() == n );
	runtime_assert( sampled.size() == n );

	Real total(0), totdev(0), jsd(0.);
	for ( Size i=0; i< n; ++i ) {
		Real oldvalue( probs[i] ), newvalue( probs[i] ); // default is to reuse old value
		if ( sampled[i] < 1e-9 ) {
			if ( target[i] > 1e-9 ) {
				newvalue = max( oldvalue, target[i] );
			}
		} else {
			Real const ratio( target[i] / sampled[i] ),
				rescale( exp( sampling_adjustment_factor * log ( max( 0.5, min( 2.0, ratio ) ) ) ) );
			newvalue = rescale * oldvalue;
		}
		probs[i] = newvalue;
		total += newvalue;
		if ( !tag.empty() ) {
			cout << "adjust_sampling_probs: " << I(3,i) <<
				" target: " << F(9,6,target[i]) <<
				" sampled: " << F(9,6,sampled[i]) <<
				" old_probs: " << F(9,6,oldvalue) <<
				" new_probs: " << F(9,6,newvalue) << ' ' << tag << endl;
		}
		{ // diagnostics
			totdev += fabs( target[i] - sampled[i] );
			Real const avgprob( 0.5 *( target[i] + sampled[i] ) ), tinyprob(1e-9);
			if ( avgprob > tinyprob ) {
				if (  target[i] > tinyprob ) jsd += 0.5 * (  target[i] * log(  target[i]/avgprob ) / log(2.0) );
				if ( sampled[i] > tinyprob ) jsd += 0.5 * ( sampled[i] * log( sampled[i]/avgprob ) / log(2.0) );
			}
		}
	}
	if ( !tag.empty() ) {
		cout << "adjust_sampling_probs: totdev: " << F(12,6,totdev) << " jsd: " << F(12,6,jsd) << ' ' << tag << endl;
	}

	if ( total >1e-9 ) { // now normalize
		for ( Size i=0; i< n; ++i ) {
			probs[i] /= total;
		}
	}
}