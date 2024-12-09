double dRdER(double ER,const DM_Particle& DM,double X,int Z,double A)
	{
		double mA = A*mNucleon;
		double nDM = rhoDM/DM.mass;
		double v = 1.0; //Cancels in the following expression
		return X/mA*nDM*(v*v*DM.dSdER(ER,Z,A,v))*EtaFunction(vMinimal_N(ER,DM.mass,A),vEarth);
	}