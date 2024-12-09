int new_tomo::construct_1D_reference()
{

	double Vs[1000];

	int idep, ilat, ilon;

	double SUM_VS;
	int npts_points;
	ofstream myfile;
	string reference_1D = "reference_1D.data";
	myfile.open(reference_1D.c_str());

	for(idep = 0; idep < this->num_dep ; idep++)
	{
		SUM_VS = 0;
		npts_points = 0;
		double dep_tmp = this->dep[idep];

		for(ilat = 0; ilat < this->num_lat;ilat ++)
			for(ilon = 0; ilon < this->num_lon; ilon ++)
			{
				double PREM_V;
				prem_s(dep_tmp,&PREM_V,0);
				SUM_VS +=  PREM_V * (1+this->my_cell[idep][ilat][ilon].dvs/100);
				npts_points++;
			}
		SUM_VS = SUM_VS / npts_points;
		myfile << dep_tmp << " "<< SUM_VS << endl;
	}

	myfile.close();
	return 0;
}