Shell::Shell(std::string nm,std::string filepath,double Eb,int Ns,double lnkMin,double lnkMax,int Nk,double lnqMin,double lnqMax,int Nq)
	{
		name = nm;
		Ebinding = Eb;
		neSecondary	=Ns;
		//Ionization form factor
			//Data range in k and q (logarithmically in units of aEM mElectron)
			logkMin=lnkMin;
			logkMax=lnkMax;
			logqMin=lnqMin;
			logqMax=lnqMax;
			nk=Nk;
			nq=Nq;
			dlogk=(logkMax-logkMin)/(nk-1);
			dlogq=(logqMax-logqMin)/(nq-1);

			//Import form factor table
			ifstream inputfile;
			inputfile.open(filepath);
			if (inputfile.good())
			{
				for(int ki=0;ki<Nk;ki++)
				{
					std::vector<double> qVector;
					for(int qi=0;qi<Nq;qi++)
					{
						double x;
		            	inputfile >>x;
						qVector.push_back(x);
					}
					FormFactor.push_back(qVector);
				}
		        inputfile.close();
	   		}
	   		else 
   			{
   				cerr <<"Error in Shell(): File " <<filepath <<" not found"<<endl;
   				std::exit(EXIT_FAILURE);
   			}
	}