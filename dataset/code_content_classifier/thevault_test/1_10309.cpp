void Date::setyear(int y){
	//does not allow negative years to be input
	if(y < 0) {
		cout<< "We don't believe in time before Christ" << endl;
		year = 0;
	}
	else{
		year = y;
	}
}