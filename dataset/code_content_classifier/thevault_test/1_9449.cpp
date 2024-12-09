MyController(Model *aModel, const mxArray* muscleActivations, double endTime) : ControlSetController(), 
        _model(aModel), _muscleActivations(muscleActivations), _endTime(endTime)
	{
        _numMuscleActivations = mxGetN(_muscleActivations); //number of columns
        _numMuscles =  mxGetM(_muscleActivations);//numRows
        _mxControlPointer = mxGetPr(_muscleActivations);
        
        _dt = endTime / ((double)_numMuscleActivations);
        
        setName("MuscleSynergyController");
        
        //check if the provided number control trajectories are equal to the number of muscles in the model
        if(_numMuscles != _model->getMuscles().getSize())
            throw "number of control trajectories are not equal to the number of muscles in the model!";
        
        //create a controlset
         _muscleControls = new ControlSet();
         
         //specify the controls
         readInControls();
         
         //publish the controlset
         setControlSet(_muscleControls);
	}