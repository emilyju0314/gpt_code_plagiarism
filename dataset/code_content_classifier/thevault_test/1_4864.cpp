void RopeScene::updatePhysics() {

    if (nbIterations < nbTorqueIterations) {
        mBox2->getRigidBody()->applyLocalTorque(rp3d::Vector3(0, 1000, 0));
    }

    nbIterations++;

    SceneDemo::updatePhysics();
}