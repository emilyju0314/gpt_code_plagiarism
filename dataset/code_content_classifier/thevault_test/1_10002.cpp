void createPhysicsBoxFromEye(ISceneManager* scenemgr,IVideoDriver* driver,vector3df& position,vector3df& lookat){
	//create a dynamic rigidbody

		btCollisionShape* colShape = new btBoxShape(btVector3(5,5,5));
		//btCollisionShape* colShape = new btBoxShape(btScalar(1.));
		collisionShapes.push_back(colShape);

		/// Create Dynamic Objects
		btTransform startTransform;
		startTransform.setIdentity();

		btScalar mass(6.f);

		//rigidbody is dynamic if and only if mass is non zero, otherwise static
		bool isDynamic = (mass != 0.f);

		btVector3 localInertia(0, 0, 0);
		if (isDynamic)
			colShape->calculateLocalInertia(mass, localInertia);

		startTransform.setOrigin(btVector3(position.X, position.Y, position.Z));
		btQuaternion quat(btVector3(0.4,.02,.1),67);
		startTransform.setRotation(quat);

		//using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
		btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
		btRigidBody* body = new btRigidBody(rbInfo);
		body->setUserIndex(10);
		body->setDamping(0.01,0.01);


		ISceneNode* cubeNode = scenemgr->addCubeSceneNode(10.0f,NULL,-1,vector3df(0,3,10));
	    cubeNode->setMaterialType(EMT_SOLID);
	    cubeNode->setMaterialTexture(0,driver->getTexture("../media/box.jpg"));
        cubeNode->setMaterialFlag(video::EMF_LIGHTING, false);
		cubeNode->setVisible(false);
		

		body->setUserPointer(cubeNode);
		body->setFriction(1);
		btVector3 force(lookat.X,lookat.Y,lookat.Z);	


		dynamicsWorld->addRigidBody(body);
		body->applyImpulse(250*force,btVector3(0.,0.,0.));
 
 }