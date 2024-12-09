void Propagate(Event& event,double &weight,std::mt19937& PRNG,double logXi=-1.0)
	{
		//If this is the first iteration we set log(1-xi) and the weight.
			if(logXi<0.0)
			{
				double Xi = ProbabilitySample(PRNG);
				logXi =(-1.0)*log(1.0-Xi);
				weight=(1.0+IS_MFP)*pow(1.0-Xi,IS_MFP);

			}
		//Initial layer and potentially next layer
			int layer_old = Current_Layer(event);
			double vz= event.Velocity()[2];
			int next_layer = (vz>0)? layer_old-1 : layer_old+1;
		//Distance to next layer boundary
			double v = event.Speed();
			double t_exit;
			if(next_layer==0) 					t_exit = -event.Position()[2]/vz;
			else if(next_layer==Detector_Index)	t_exit = (-Detector_Depth-event.Position()[2])/vz;
			else if(vz>0)						t_exit = (-Layers[layer_old-1].depth-event.Position()[2])/vz;
			else								t_exit = (-Layers[next_layer-1].depth-event.Position()[2])/vz;
			double d = t_exit*v;
		//Mean free path
			double mfp = Layers[layer_old-1].MFP(v)*(1.0+IS_MFP);
		//a) The particle did not leave the layer
			if(logXi<d/mfp)
			{
				double L = logXi * mfp;
				double dt = L/v;
				event.IncreaseTime(dt);
				event.IncreasePosition(dt*event.Velocity());
			}
		//b) The particle reaches space or the detector
			else if(next_layer == 0 || next_layer == Detector_Index)
			{
				double L = d+10.0*meter;
				double dt = L/v;
				event.IncreaseTime(dt);
				event.IncreasePosition(dt*event.Velocity());
			}
		//c) The particle reaches the next layer
			else
			{
				double dt = (d+1.0e-6*meter)/v;
				event.IncreaseTime(dt);
				event.IncreasePosition(dt*event.Velocity());
				if(Current_Layer(event)==layer_old) cout <<"Transition from " <<layer_old <<" to " <<layer_old <<" at z=" <<event.Position()[2]/meter <<"m."<<endl;
				logXi-=d/mfp;
				Propagate(event,weight,PRNG,logXi);
			}
	}