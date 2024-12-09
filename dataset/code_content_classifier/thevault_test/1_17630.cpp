double DM_Particle::sigmaSI(int Z,double A) const
		{
			double X=-1.0;
			double mAux=-1.0;
			if(ZorA=="Z") 
			{
				X=Z;
				mAux = mProton;
			}
			else if (ZorA=="A") 
			{
				X=A;
				mAux = mNucleon;
			}
			else 
			{
				std::cerr <<"Error in sigmaSI: ZorA = " <<ZorA <<" not recognized."<<endl;
				std::exit(EXIT_FAILURE);
			}
			return sigma_n*pow(Reduced_Mass(mass,NucleusMass(A)),2.0)/pow(Reduced_Mass(mass,mAux),2.0)*pow(X,2.0);
		}