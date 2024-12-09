double PER::avg(PowerProfile* pp,double duration){

  if (debug_>1)  printf("PER::avg()  starting calculations\n");	
	

	double avg_pow = 0 ;
	for (int i=0; i< pp->getNumElements()-1; i++){
		double a =  pp->getElement(i).power;
		//double b = pp->getElement(i+1).power;
		//cerr << "pot ist" << a << " "<< b << "---\n"; 		
		double dt = (pp->getElement(i+1).time -pp->getElement(i).time);
		avg_pow = avg_pow + a * dt;

		if (debug_>1)  printf("PER::avg()  power=%2.10f \t dt=%f\n",a,dt);
	}

	double a = pp->getElement(pp->getNumElements()-1).power;
	double dt = (duration -pp->getElement(pp->getNumElements()-1).time);
	
	//	avg_pow = avg_pow + pp->getElement(pp->getNumElements()-1).power * (duration -pp->getElement(pp->getNumElements()-1).time);
	avg_pow = avg_pow + a * dt;

	if (debug_>1)  printf("PER::avg()  power=%2.10f \t dt=%f duration=%f\n",a,dt,duration);

//cerr << "average0" << pp->getElement(1).time - pp->getElement(0).time;

	avg_pow = avg_pow / duration;

	if(debug_>1) printf("PER::avg() finished calculations: at %f average power=%2.10f\n", Scheduler::instance().clock(),avg_pow);

	return avg_pow;
}