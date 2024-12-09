Vector3 RigidBody::computeCenterOfMass() const {

    decimal totalMass = decimal(0.0);
    Vector3 centerOfMassLocal(0, 0, 0);

    // Compute the local center of mass
    const Array<Entity>& colliderEntities = mWorld.mCollisionBodyComponents.getColliders(mEntity);
    for (uint32 i=0; i < colliderEntities.size(); i++) {

        const uint32 colliderIndex = mWorld.mCollidersComponents.getEntityIndex(colliderEntities[i]);

        const decimal colliderVolume = mWorld.mCollidersComponents.mCollisionShapes[colliderIndex]->getVolume();
        const decimal colliderMassDensity = mWorld.mCollidersComponents.mMaterials[colliderIndex].getMassDensity();

        const decimal colliderMass = colliderVolume * colliderMassDensity;

        totalMass += colliderMass;
        centerOfMassLocal += colliderMass * mWorld.mCollidersComponents.mLocalToBodyTransforms[colliderIndex].getPosition();
    }

    if (totalMass > decimal(0.0)) {
        centerOfMassLocal /= totalMass;
    }

    return centerOfMassLocal;
}