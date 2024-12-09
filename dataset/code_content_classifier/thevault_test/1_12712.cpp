void IK_sdls::LoaderToTree::setQ(const double* q)
{
	IK_sdls::Node* n;

	int sj=0;
	n=getJoint(0);
	if (n->IsFreeJoint())
	{
		IK_sdls::FreeJoint* fj= ((IK_sdls::FreeJoint*)n);
		fj->_local.translation.x=q[0];
		fj->_local.translation.y=q[1];
		fj->_local.translation.z=q[2];
		fj->_local.rotation.w=q[_nDOF]; // redundant coordinate
		fj->_local.rotation.x=q[3];
		fj->_local.rotation.y=q[4];
		fj->_local.rotation.z=q[5];
		sj=6;
	}

	for(int j=sj,nj=numJoint(); j<nj; j++)
	{
		n=getJoint(j);
		n->SetTheta(q[mDQindex[j]]);
	}
	mTree.Compute();// updates effector positions too.
}