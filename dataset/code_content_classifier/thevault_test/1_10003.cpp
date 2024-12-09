void renderPhysicsObjectsPose(){
 
 //print positions of all objects
	  int numOfObjects = dynamicsWorld->getNumCollisionObjects();
	 stringw str = L"Number of physics objects:";
	 str+=numOfObjects;	
	 str+= L"\nPress C to drop a box\n";	
	 str+= L"Press H to Create a Chain\n";	
	 str+= L"Press E to Fire a box\n";	

	 textNode->setText(str.c_str());
	
		for (int j = numOfObjects - 1; j >= 0; j--)
		{
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
			btRigidBody* body = btRigidBody::upcast(obj);
			btTransform trans;
			if (body && body->getMotionState())
			{
				body->getMotionState()->getWorldTransform(trans);			 
				
			 ISceneNode* cube = reinterpret_cast<ISceneNode*>( body->getUserPointer());
			 if(cube != NULL){//update cubes only
				 btVector3 origin = trans.getOrigin();
				 //update rotation
				 btQuaternion rot = trans.getRotation();
				 quaternion q(rot.getX(),rot.getY(),rot.getZ(),rot.getW());
				 vector3df Euler;
				 q.toEuler(Euler);
                 Euler *= RADTODEG;

				 cube->setPosition(vector3df(origin.getX(),origin.getY(),origin.getZ()));				
				 cube->setRotation(Euler);
				 cube->setVisible(true);
			 }
			}
			else
			{
				trans = obj->getWorldTransform();
			}			
			 
		} 
 }