void BallAndSocketJointScene::createBallAndSocketJoint() {

    // --------------- Create the box 1 --------------- //
    mBox1 = new Box(true, Vector3(4, 4, 4) ,  mPhysicsCommon, mPhysicsWorld, mMeshFolderPath);
    mBox1->setTransform(rp3d::Transform(rp3d::Vector3(0, 8, 0), rp3d::Quaternion::identity()));

    // Set the box color
    mBox1->setColor(mObjectColorDemo);
    mBox1->setSleepingColor(mSleepingColorDemo);

    mBox1->getRigidBody()->setType(rp3d::BodyType::STATIC);

    mPhysicsObjects.push_back(mBox1);

    // --------------- Create the box 2 --------------- //

    mBox2 = new Box(true, Vector3(4, 8, 4),  mPhysicsCommon, mPhysicsWorld, mMeshFolderPath);
    mBox2->setTransform(rp3d::Transform(rp3d::Vector3(0, 0, 0), rp3d::Quaternion::identity()));

    // Set the box color
    mBox2->setColor(mObjectColorDemo);
    mBox2->setSleepingColor(mSleepingColorDemo);

    mPhysicsObjects.push_back(mBox2);

    // --------------- Create the joint --------------- //

    // Create the joint info object
    rp3d::RigidBody* body1 = mBox1->getRigidBody();
    rp3d::RigidBody* body2 = mBox2->getRigidBody();
    rp3d::Vector3 body1Position = body1->getTransform().getPosition();
    rp3d::Vector3 body2Position = body2->getTransform().getPosition();
    const rp3d::Vector3 anchorPointWorldSpace = 0.5 * (body1Position + body2Position);
    rp3d::BallAndSocketJointInfo jointInfo(body1, body2, anchorPointWorldSpace);
    jointInfo.isCollisionEnabled = false;

    // Create the joint in the physics world
    mJoint = dynamic_cast<rp3d::BallAndSocketJoint*>(mPhysicsWorld->createJoint(jointInfo));
    mJoint->setConeLimitHalfAngle(90.0 * rp3d::PI_RP3D / 180.0);
    mJoint->enableConeLimit(true);

}