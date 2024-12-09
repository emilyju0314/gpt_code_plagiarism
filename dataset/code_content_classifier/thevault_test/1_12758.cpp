Liegroup::dse3 DynamicsSimulator_TRL_penalty::calcMomentumCOMfromPose(int ichara, double delta_t, vectorn const& poseFrom, vectorn const& poseTo)
{
	VRMLloader* skel=_characters[ichara]->skeleton;
	TRL::BodyPtr cinfo=world.body(ichara);
	BoneForwardKinematics chain1(skel), chain2(skel);
	chain1.init();
	chain2.init();

	::vector3 com(0,0,0);
	Liegroup::dse3 H(0,0,0,0,0,0);

	m_real totalMass=0.0;
	chain1.setPoseDOF(poseFrom);
	chain2.setPoseDOF(poseTo);
	for(int ibone=1; ibone<skel->numBone(); ibone++)
	{
		VRMLTransform& bone=skel->VRMLbone(ibone);
		ASSERT(bone.mSegment);
		double mass=bone.mSegment->mass;
		com+=chain1.global(bone).toGlobalPos(bone.mSegment->centerOfMass)*mass;
		totalMass+=mass;
		//Liegroup::se3 V=transf_twist(chain1.global(bone), chain2.global(bone),delta_t);
		Liegroup::se3 V=transf_twist_nonlinear(chain1.global(bone), chain2.global(bone),delta_t);
		//printf("%d : %s, %f %f %f\n", ibone, V.W().output().ptr(), body->V[0], body->V[1], body->V[2]);
		//printf("%d : %s, %f %f %f\n", ibone, V.V().output().ptr(), body->V[3], body->V[4], body->V[5]);

		Liegroup::Inertia I(mass, bone.momentsOfInertia(), mass*bone.localCOM());
		H+=(I*V).inv_dAd(chain1.global(bone));
	}

	com/=totalMass;

	//printf("I: %f %f %f %f %f %f, %f,%f\n", I._I[0],I._I[1],I._I[2],I._I[3],I._I[4],I._I[5],I._m, totalMass);

	Liegroup::dse3 v;
	v.dAd(transf(quater(1,0,0,0), com), H);
	return v;
}