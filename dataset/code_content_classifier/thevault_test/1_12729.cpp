void DynamicsSimulator_TRL_penalty::setLinkData(int ichara, LinkDataType t, vectorn const& in)
{
	VRMLloader const& l=*this->_characters[ichara]->skeleton;

	ASSERT(in.size()==l.dofInfo.numDOF());

	OpenHRP::DynamicsSimulator& s=*this;
	TRL::BodyPtr cinfo=this->world.body(ichara);

	vector3 p;
	double imag;
	vector3 v;

	for(int i=1; i<l.numBone(); i++)
	{
		VRMLTransform& b=(VRMLTransform&)l.bone(i);
		if(b.mJoint->jointType==HRP_JOINT::FIXED) continue;

		if(b.mJoint->jointType==HRP_JOINT::FREE)
		{
			TRL::Link* j=getTRLlink(cinfo,b.mJoint->jointStartId);

			ASSERT(l.dofInfo.hasTranslation(i));
			ASSERT(l.dofInfo.hasQuaternion(i));
			int sTDOF=l.dofInfo.startT(i);
			int sRDOF=l.dofInfo.startR(i);
			ASSERT(sRDOF-sTDOF==3);
			p=in.toVector3(sTDOF);
			imag=in[sRDOF];
			v=in.toVector3(sRDOF+1);

			switch(t)
			{
			case OpenHRP::DynamicsSimulator::JOINT_VALUE:
				{
					j->p=p;
					quater q(imag,v.x, v.y, v.z);
					q.normalize();
					j->setAttitude(toOpenHRP(q));
				}
				break;
			case OpenHRP::DynamicsSimulator::JOINT_VELOCITY:
				{
					::vector3 bv,bw;
					quater q=toBase(j->attitude());
					p.rotate(q);
					v.rotate(q);
					j->w=v;

					// this line is important because j->v is calculated from j->vo.
					j->vo= p - cross(j->w,j->p);
					j->v= p;

					imag=0.0;
				}
				break;
			case OpenHRP::DynamicsSimulator::JOINT_ACCELERATION:
				
				j->dw=v;

				// this line is important as j->dv is calculated form j->dvo.
				j->dvo = p - cross(j->dw, j->p) - cross(j->w, j->v);
				j->dv=p;
				
				imag=0.0;
				break;
			case OpenHRP::DynamicsSimulator::JOINT_TORQUE:
				j->fext=p;
				j->tauext=v;
				imag=0.0;
				break;
			default:
				ASSERT(0);
			}
		}
		else if(b.mJoint->jointType==HRP_JOINT::BALL)
		{
			TRL::Link* j=getTRLlink(cinfo,b.mJoint->jointStartId);

			int sRDOF=l.dofInfo.startR(i);
			imag=in[sRDOF];
			v=in.toVector3(sRDOF+1);

			switch(t)
			{
			case OpenHRP::DynamicsSimulator::JOINT_VALUE:
				{
					quater q(imag,v.x, v.y, v.z);
					q.normalize();
					j->setAttitude(toOpenHRP(q));
				}
				break;
			case OpenHRP::DynamicsSimulator::JOINT_VELOCITY:
				j->w=v;
				break;
			case OpenHRP::DynamicsSimulator::JOINT_ACCELERATION:
				j->dw=v;
				break;
			case OpenHRP::DynamicsSimulator::JOINT_TORQUE:
				//				j->tauext=v;
				break;
			default:
				ASSERT(0);
			}
		}
		else
		{
			int sj=b.mJoint->jointStartId;
			int sDOF=l.dofInfo.startT(i);
			int nDOF=l.dofInfo.endR(i)-sDOF;
			for(int jj=0; jj<nDOF; jj++)
			{

				switch(t)
				{
				case OpenHRP::DynamicsSimulator::JOINT_VALUE:
					getTRLlink(cinfo,sj+jj)->q=in[sDOF+jj];
					break;
				case OpenHRP::DynamicsSimulator::JOINT_VELOCITY:
					getTRLlink(cinfo,jj+sj)->dq=in[sDOF+jj];
					break;
				case OpenHRP::DynamicsSimulator::JOINT_ACCELERATION:
					getTRLlink(cinfo,jj+sj)->ddq=in[sDOF+jj];
					break;
				case OpenHRP::DynamicsSimulator::JOINT_TORQUE:
					getTRLlink(cinfo,jj+sj)->u=in[sDOF+jj];
					break;
				default:
					ASSERT(0);
				}
			}
		}
	}

	if(t==OpenHRP::DynamicsSimulator::JOINT_ACCELERATION)
	{
		// calc link->vo, w, R, p, sw, sv, v, cv, cw, wc, ...
		TRL::ForwardDynamicsABM* fd=world.forwardDynamics(ichara);
		fd->calcABMPhase1(); // position, velocity fk + gravity
		fd->calcAccelFK();	
		_updateCharacterPose();
	}
}