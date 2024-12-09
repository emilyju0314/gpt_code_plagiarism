int shooting::SolveShootingContinuation(real const& continuationStep, real & Rdata, real const& Rgoal) const
{
	real Rstart = Rdata; // starting value

	int numParam = data->numParam;

	// continuation parameter (discrete continuation algortihm)
	real bStep = continuationStep;
	real b = (std::min<real>)(continuationStep,1.0);  // 1 is the max step
	real b_prec = 0;

	// initial data value
	Rdata = (1-b)*Rstart + b*Rgoal;

	// temporary values are initialized
	for (int k=0;k<numParam;k++){
		data->tab_param_temp[k] = data->tab_param[k];
	}

	for (int i = 0; i<data->numMulti + 1; i++) {
		// time
		data->time[i] = data->timed[i];
		// state
		for (int j = 0; j<data->dim; j++) data->X[i][j] = data->Xd[i][j];
	}

	bool condition = true;
	int ret;
	while(condition){
		//printf("data = %lf \n",Rdata);
		//printf("b = %lf \n",b);

		// solve the shooting problem
		ret = SolveShootingFunction(numParam, data->tab_param_temp);

		if (ret != 1){
			if (fabs(b-b_prec)<data->continuationStepMin){
				// continuation do not give satisfactory results
				//std::cout << "bmin reached (b = " << b << ")" << std::endl;
				condition = false;
			}

			// continuation parameters is decreased
			b = b_prec + (b-b_prec)/2;

			// data->tab_param_temp[k] is re-initialized
			for (int k=0;k<numParam;k++){
				data->tab_param_temp[k] = data->tab_param[k];
			}

			// *Rdata is updated
			Rdata = (1-b)*Rstart + b*Rgoal;

		}

		if(ret == 1){
			if (b==1){
				// continuation worked
				condition = false;
			}else{
				// continuation is not finished
				b_prec = b;
				b = (std::min<real>)(b+bStep,1.0);

				for (int k=0;k<numParam;k++){
					data->tab_param[k] = data->tab_param_temp[k];
				}

				Rdata = (1-b)*Rstart + b*Rgoal;
			}
		}

	}

	// update data
	if(ret == 1){
		for (int k=0;k<numParam;k++){
			data->tab_param[k] = data->tab_param_temp[k];
		}
	}

	// return
	return ret;
}