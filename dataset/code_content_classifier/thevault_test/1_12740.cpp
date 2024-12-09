dualQuaternion dualQuaternion::sDLB(int inCount, const double inWeightList[], const dualQuaternion inDualQuatList[])
{
	assert(inCount>0);

	// Find max weight index for pivoting to that quaternion, so shortest arc is taken
	int pivot_idx = 0;
	for (int n=1; n<inCount; n++)
		if (inWeightList[pivot_idx] < inWeightList[n])
			pivot_idx = n;
	dualQuaternion const& dq_pivot = inDualQuatList[pivot_idx];

	dualQuaternion res(dualQuaternion::zero);
	for (int n=0; n<inCount; n++)
	{
		dualQuaternion const& dq = inDualQuatList[n];
		double weight = inWeightList[n];

		// Make sure dot product is >= 0
		if (dq.dotReal(dq_pivot)<0.0)
			weight = -weight;

		res += weight*dq;
	}

	res.normalizeIt();

	return res;
}