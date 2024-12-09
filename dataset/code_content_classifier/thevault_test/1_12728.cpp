void DynamicsSimulator_TRL_penalty::getLinkData(int ichara, LinkDataType t, vectorn& out)
{
	VRMLloader const& l=*_characters[ichara]->skeleton;

	out.resize(l.dofInfo.numDOF());

	OpenHRP::DynamicsSimulator& s=*this;
	TRL::BodyPtr cinfo=world.body(ichara);

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

			switch(t)
			{
			case OpenHRP::DynamicsSimulator::JOINT_VALUE:
				{
					p=j->p;
					quater q=toBase(j->attitude());
					imag=q.w;
					v.x=q.x;v.y=q.y;v.z=q.z;
				}
				break;
			case OpenHRP::DynamicsSimulator::JOINT_VELOCITY:
				{
					quater q=toBase(j->attitude());
					p=j->v;
					v=j->w;
					p.rotate(q.inverse());
					v.rotate(q.inverse());
					imag=0.0;
				}
				break;
			case OpenHRP::DynamicsSimulator::JOINT_ACCELERATION:
				p=j->dv;
				v=j->dw;
				imag=0.0;
				break;
			case OpenHRP::DynamicsSimulator::JOINT_TORQUE: p=j->fext;
				v=j->tauext;
				imag=0.0;
				break;
			default:
				ASSERT(0);
			}

			
			out.setVec3(sTDOF, p);
			out[sRDOF]=imag;
			out.setVec3(sRDOF+1, v);

		}
		else if (b.mJoint->jointType==HRP_JOINT::BALL){
			TRL::Link* j=getTRLlink(cinfo,b.mJoint->jointStartId);

			ASSERT(l.dofInfo.hasQuaternion(i));
			int sRDOF=l.dofInfo.startR(i);

			switch(t)
			{
			case OpenHRP::DynamicsSimulator::JOINT_VALUE:
				{
					quater q=toBase(j->attitude());
					imag=q.w;
					v.x=q.x;v.y=q.y;v.z=q.z;
				}
				break;
			case OpenHRP::DynamicsSimulator::JOINT_VELOCITY:
				v=j->w;
				imag=0.0;
				break;
			case OpenHRP::DynamicsSimulator::JOINT_ACCELERATION:
				v=j->dw;
				imag=0.0;
				break;
			case OpenHRP::DynamicsSimulator::JOINT_TORQUE:
				v=j->tauext;
				imag=0.0;
				break;
			default:
				ASSERT(0);
			}
			
			out[sRDOF]=imag;
			out.setVec3(sRDOF+1, v);
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
					out[sDOF+jj]=getTRLlink(cinfo,jj+sj)->q;
					break;
				case OpenHRP::DynamicsSimulator::JOINT_VELOCITY:
					out[sDOF+jj]=getTRLlink(cinfo,jj+sj)->dq;
					break;
				case OpenHRP::DynamicsSimulator::JOINT_ACCELERATION:
					out[sDOF+jj]=getTRLlink(cinfo,jj+sj)->ddq;
					break;
				case OpenHRP::DynamicsSimulator::JOINT_TORQUE:
					out[sDOF+jj]=getTRLlink(cinfo,jj+sj)->u;
					break;

				default:
					ASSERT(0);
				}
			}
		}

	}
}