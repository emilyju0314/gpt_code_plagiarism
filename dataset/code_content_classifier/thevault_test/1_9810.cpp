int shooting::SolveShootingContinuation(real const& continuationStep) const
{
	int numParam = data->numParam;

	// parameter for spatial continuation (discrete continuation algortihm)
	real bStep = continuationStep;
	real b = (std::min<real>)(continuationStep, 1.0);  // 1 is the max step
	real b_prec = 0;

	for (int i=0; i<data->numMulti+1; i++){
		// time
		data->time[i] = (1-b) * data->time_prec[i] + b * data->timed[i];
		// state
		for(int j=0;j<data->dim;j++) data->X[i][j] = (1-b)*data->X_prec[i][j] + b*data->Xd[i][j];
	}

	// temporary values are initialized
	for (int k=0;k<numParam;k++){
		data->tab_param_temp[k] = data->tab_param[k];
	}

	bool condition = true;
	int ret;
	while(condition){
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

			for (int i=0; i<data->numMulti+1; i++){
				// time
				data->time[i] = (1-b) * data->time_prec[i] + b * data->timed[i];
				// state
				for(int j=0;j<data->dim;j++) data->X[i][j] = (1-b)*data->X_prec[i][j] + b*data->Xd[i][j];
			}

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

				for (int i=0; i<data->numMulti+1; i++){
					// time
					data->time[i] = (1-b) * data->time_prec[i] + b * data->timed[i];
					// state
					for(int j=0;j<data->dim;j++) data->X[i][j] = (1-b)*data->X_prec[i][j] + b*data->Xd[i][j];
				}
				
			}
		}

	}

	// update data
	if(ret == 1){
		for (int k=0;k<numParam;k++){
			data->tab_param[k] = data->tab_param_temp[k];
		}

		for (int i=0; i<data->numMulti+1; i++){
			// time
			data->time_prec[i] = data->timed[i];
			// state
			for(int j=0;j<data->dim;j++) data->X_prec[i][j] = data->Xd[i][j];
		}

	}

	// return
	return ret;
}