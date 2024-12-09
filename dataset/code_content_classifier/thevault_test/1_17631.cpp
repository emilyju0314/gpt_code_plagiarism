double Cutoff_Speed(const std::string& experiment,double mDM,int rank)
	{
		double vcut=0;
		if(experiment=="DAMIC")
		{
			double Ethr = 0.55*keV;
			double A = 28.0;
			vcut = vMinimal_N(Ethr,mDM,A);
		}
		else if(experiment == "XENON1T")
		{
			double Ethr = 5*keV;
			double A = 131.0;
			vcut = vMinimal_N(Ethr,mDM,A);
		}
		else if(experiment =="CRESST-II")
		{
			double Ethr = 307*eV;
			double resolution = Ethr/5.0;
			double Emin = Ethr-3.0*resolution;
			double A[3] = {16.,40.,184.};
			std::vector<double> v = {vMinimal_N(Emin,mDM,A[0]),vMinimal_N(Emin,mDM,A[1]),vMinimal_N(Emin,mDM,A[2])};
			vcut = *std::min_element(v.begin(),v.end());
		}
		else if(experiment =="CRESST-surface")
		{
			double Ethr = 19.7*eV;
			double resolution = 3.74*eV;
			double Emin = Ethr-3.0*resolution;
			double A[3] = {16.,27.};
			std::vector<double> v = {vMinimal_N(Emin,mDM,A[0]),vMinimal_N(Emin,mDM,A[1])};
			vcut = *std::min_element(v.begin(),v.end());
		}
		else if(experiment == "Semiconductor"||experiment=="SENSEI-surface"||experiment=="SENSEI"||experiment=="SuperCDMS"||experiment=="DAMIC-M")
		{
			double eps = (DMe_target=="Si") ? 3.6*eV : 2.9*eV;
			double Egap = (DMe_target=="Si") ? 1.11*eV : 0.67*eV;
			double Ethr = eps*(DMe_threshold-1.0)+Egap;
			vcut = sqrt(2.0*Ethr/mDM);
		}
		else if(experiment == "XENON10e" || experiment == "XENON100e")
		{
			vcut = sqrt(2*12.4*eV/mDM);
		}
		else if(experiment == "DarkSide-50")
		{
			vcut = sqrt(2*15.7*eV/mDM);
		}
		else
		{
			std::cerr <<"Error in Cutoff_Speed(): Experiment " <<experiment <<" not recognized."<<endl;
			std::exit(EXIT_FAILURE);
		}
		if(vcut>(vEarth+vesc))
		{
			if(rank==0) cout <<"Warning: vCutoff>vEsc+vEarth for mDM = " <<mDM <<"GeV."<<endl;
			vcut = -1;
		}
		return vcut;
	}