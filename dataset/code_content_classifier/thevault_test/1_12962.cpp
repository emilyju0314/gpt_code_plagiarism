void manual_read(ThermalEventCamera *cc)
{
	while(1){
		cc->read(); // update frame data
		cc->printFrame(); // print framme data as colors
	}
}