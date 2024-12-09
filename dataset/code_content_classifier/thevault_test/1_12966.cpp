void ThermalEventCamera::setCompare(CompareFunc f)
{
	// update comparison function
	this->compare = f;
	// an uninitialised CompareFunc when compared to 0 returns true
	// if the function is initialised set flag
	if(f!=0){
		this->cmpSet = true;
	}
	else{	// if the user has passed a blank comparison function
		// clear flag
		this->cmpSet = false;
	}
}