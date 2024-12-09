int new_tomo::output_tomography_info()
{

	cout << "======================== Output Tomography info =====================" << endl;
	this->output_tomo_file = "output_tomo." + this->MODEL;

	// define output file parameter
	ofstream myfile;
	myfile.open(this->output_tomo_file.c_str());


	// first output dimensions
	myfile << this->num_dep << endl;
	myfile << this->num_lat << endl;
	myfile << this->num_lon << endl;
	

	// output model file
	int idep,ilat,ilon;
	cout << "Dimensions" << this->num_dep << this->num_lat << this->num_lon << endl;
	for(idep = 0; idep < this->num_dep;idep++)
	{	
	for(ilat = 0; ilat < this->num_lat;ilat++)
	for(ilon = 0; ilon < this->num_lon;ilon++)
	{
		//normalize
		double xx,yy,zz;

		double dep = this->dep[idep];
		double lat = this->lat[ilat];
		double lon = this->lon[ilon];
		double dvs = this->my_cell[idep][ilat][ilon].dvs;
		sph2cart(lat, lon, dep, &xx, &yy, &zz);
		double RADIUS = 6371;
		xx = xx/RADIUS;
		yy = yy/RADIUS;
		zz = zz/RADIUS;

	myfile <<setw(10)<<setprecision(5) << xx << "   " << yy << "   " << zz << "   " << dvs <<"   " <<dep <<"   "<< lat <<"   " << lon << endl;


	}
	}



	myfile.close();

	return 0;
}