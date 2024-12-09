void createChain(int chainitemscount,btVector3& suspensionPoint,ISceneManager* scenemgr,IVideoDriver* driver){

	 //create a few dynamic rigidbodies
		// Re-using the same collision is better for memory usage and performance
        btBoxShape* colShape = createBoxShape(btVector3(4,4,1));
		 
		collisionShapes.push_back(colShape);

		/// Create Dynamic Objects
		btTransform startTransform;
		startTransform.setIdentity();

		btScalar	mass(1.f);

		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		bool isDynamic = (mass != 0.f);

		btVector3 localInertia(0,0,0);
		if (isDynamic)
			colShape->calculateLocalInertia(mass,localInertia);
		 
		btAlignedObjectArray<btRigidBody*> boxes;
		int lastBoxIndex = chainitemscount-1;
		for(int i=0;i<chainitemscount;++i) {
			startTransform.setOrigin(btVector3(
				btScalar(suspensionPoint.x()),
									 btScalar(suspensionPoint.y()+i*2),
									 btScalar(suspensionPoint.z())
									 )
									 );
			boxes.push_back(createRigidBody(dynamicsWorld, (i  ==lastBoxIndex)?0:mass,startTransform,colShape));

			IMeshSceneNode* cubeNode = scenemgr->addCubeSceneNode(8.0f,NULL,-1,vector3df(0,0,0),vector3df(0,0,0),
				vector3df(1,1,0.25f));
			cubeNode->setMaterialType(EMT_SOLID);
			cubeNode->setMaterialTexture(0,driver->getTexture("../media/steel-box.jpg"));
			cubeNode->setMaterialFlag(video::EMF_LIGHTING, false);
			boxes[i]->setUserPointer(cubeNode);
		} 
		 
		//add N-1 spring constraints
		for(int i=0;i<chainitemscount-1;++i) {
			btRigidBody* b1 = boxes[i];
			btRigidBody* b2 = boxes[i+1];
			 
			btPoint2PointConstraint* leftSpring = new btPoint2PointConstraint(*b1, *b2, btVector3(-2,4,0), btVector3(-2,-4,0));
			 
			dynamicsWorld->addConstraint(leftSpring);
			 
			btPoint2PointConstraint* rightSpring = new btPoint2PointConstraint(*b1, *b2, btVector3(2,4,0), btVector3(2,-4,0));

			dynamicsWorld->addConstraint(rightSpring);
		}
}