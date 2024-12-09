void Oni_Model_rotateTo(Oni_ModelPtr obj, double x, double y, double z){
		Oni::Model* model = (Oni::Model*)(obj);
		
		model->rotateTo(x,y,z);
	}