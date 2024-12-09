dualQuaternion dualQuaternion::sDIB(int inCount, const double inWeightList[], const dualQuaternion inDualQuatList[], double inPrecision)
{
	assert(inCount>0);
	dualQuaternion b = sDLB(inCount, inWeightList, inDualQuatList);

	// Find max weight index for pivoting to that quaternion, so shortest arc is taken
	int pivot_idx = 0;
	for (int n=1; n<inCount; n++)
		if (inWeightList[pivot_idx] < inWeightList[n])
			pivot_idx = n;
	dualQuaternion const& dq_pivot = inDualQuatList[pivot_idx];

	// Iteratively refine
	enum { MAX_DIB_ITERS = 20 };
	for (int iter=0; iter<MAX_DIB_ITERS; ++iter)
	{
		const dualQuaternion inv_b = b.inverse();
		dualQuaternion x(dualQuaternion::zero);
		for (int i=0; i<inCount; i++)
		{
			dualQuaternion dq		= inDualQuatList[i];
			double weight			= inWeightList[i];

			// Make sure dot product is >= 0
			if (dq.dotReal(dq_pivot)<0.0)
				dq.negateIt();

			dualQuaternion xi		= inv_b * dq;
			x += weight*xi.log();
		}

		double norm = x.dot(x);

		b = b * x.exp();

		if (norm < inPrecision) 
			return b;				
	}

	// Failed to converge. At least normalize.
	b.normalizeIt();

	return b;
}