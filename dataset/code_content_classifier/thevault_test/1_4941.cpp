void RigidBody::updateMassFromColliders() {

    decimal totalMass = decimal(0.0);

    // Compute the total mass of the body
    const Array<Entity>& colliderEntities = mWorld.mCollisionBodyComponents.getColliders(mEntity);
    for (uint32 i=0; i < colliderEntities.size(); i++) {

        const uint32 colliderIndex = mWorld.mCollidersComponents.getEntityIndex(colliderEntities[i]);

        const decimal colliderVolume = mWorld.mCollidersComponents.mCollisionShapes[colliderIndex]->getVolume();
        const decimal colliderMassDensity = mWorld.mCollidersComponents.mMaterials[colliderIndex].getMassDensity();

        const decimal colliderMass = colliderVolume * colliderMassDensity;

        totalMass += colliderMass;
    }

    // Set the mass
    mWorld.mRigidBodyComponents.setMass(mEntity, totalMass);

    // If it is a dynamic body
    const BodyType type = mWorld.mRigidBodyComponents.getBodyType(mEntity);
    if (type == BodyType::DYNAMIC) {

        // Compute the inverse mass
        if (totalMass > decimal(0.0)) {
            mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(1.0) / totalMass);
        }
        else {
            mWorld.mRigidBodyComponents.setMassInverse(mEntity, decimal(0.0));
        }
    }

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Set mass=" + std::to_string(totalMass),  __FILE__, __LINE__);
}