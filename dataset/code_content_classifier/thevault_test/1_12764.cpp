MomentumConstraintInfo(VRMLloader const& l, IK_sdls::LoaderToTree* s):orig_chain((MotionLoader*)&l), loader(l),solver(s){
			deltaS.setSize(6); deltaS.setAllValue(0.0);
			Hcom.setSize(6);
			desired_vel.setSize(6);
			orig_chain.init();
		}