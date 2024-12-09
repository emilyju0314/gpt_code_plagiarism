double dRdlog10Ee(double Ee,const DM_Particle& DM,const std::string& target,const Shell& shell)
	{
		double A = (target=="Xe")? 131.0 : 40.0;
		double mA = A*mNucleon;
		double qref = aEM*mElectron;
		double prefactor =log(10)* 1.0/mA*rhoDM/DM.mass*DM.sigma_e/8/pow(Reduced_Mass(DM.mass,mElectron),2.0);
		double sum=0.0;
		int ki =std::round ( (1.0/2.0*log(2.0*mElectron*Ee/qref/qref)-shell.logkMin)/shell.dlogk );
		if(ki>=shell.nk||ki<0) return 0.0;
		for(int qi=0;qi<shell.nq;qi++)
		{
			double q = qref*exp(shell.logqMin+(qi)*shell.dlogq);
			double vMin = (shell.Ebinding+Ee)/q+q/2.0/DM.mass;
			sum+=shell.dlogq*q*q*EtaFunction(vMin,vEarth)*pow(DM.FormFactor(q),2.0)*shell.FormFactor[ki][qi];
		}
		return prefactor*sum;
	}