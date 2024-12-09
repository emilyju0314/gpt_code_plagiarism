void RigidBody::computeMassAndInertiaTensorLocal(Vector3& inertiaTensorLocal, decimal& totalMass) const {

    inertiaTensorLocal.setToZero();
    totalMass = decimal(0.0);

    Matrix3x3 tempLocalInertiaTensor = Matrix3x3::zero();

    const Vector3 centerOfMassLocal = mWorld.mRigidBodyComponents.getCenterOfMassLocal(mEntity);

    // Compute the inertia tensor using all the colliders
    const Array<Entity>& colliderEntities = mWorld.mCollisionBodyComponents.getColliders(mEntity);
    for (uint32 i=0; i < colliderEntities.size(); i++) {

        const uint32 colliderIndex = mWorld.mCollidersComponents.getEntityIndex(colliderEntities[i]);

        const decimal colliderVolume = mWorld.mCollidersComponents.mCollisionShapes[colliderIndex]->getVolume();
        const decimal colliderMassDensity = mWorld.mCollidersComponents.mMaterials[colliderIndex].getMassDensity();
        const decimal colliderMass = colliderVolume * colliderMassDensity;

        totalMass += colliderMass;

        // Get the inertia tensor of the collider in its local-space
        Vector3 shapeLocalInertiaTensor = mWorld.mCollidersComponents.mCollisionShapes[colliderIndex]->getLocalInertiaTensor(colliderMass);

        // Convert the collider inertia tensor into the local-space of the body
        const Transform& shapeTransform = mWorld.mCollidersComponents.mLocalToBodyTransforms[colliderIndex];
        Matrix3x3 rotationMatrix = shapeTransform.getOrientation().getMatrix();
        Matrix3x3 rotationMatrixTranspose = rotationMatrix.getTranspose();
        rotationMatrixTranspose[0] *= shapeLocalInertiaTensor.x;
        rotationMatrixTranspose[1] *= shapeLocalInertiaTensor.y;
        rotationMatrixTranspose[2] *= shapeLocalInertiaTensor.z;
        Matrix3x3 inertiaTensor = rotationMatrix * rotationMatrixTranspose;

        // Use the parallel axis theorem to convert the inertia tensor w.r.t the collider
        // center into a inertia tensor w.r.t to the body origin.
        Vector3 offset = shapeTransform.getPosition() - centerOfMassLocal;
        decimal offsetSquare = offset.lengthSquare();
        Matrix3x3 offsetMatrix;
        offsetMatrix[0].setAllValues(offsetSquare, decimal(0.0), decimal(0.0));
        offsetMatrix[1].setAllValues(decimal(0.0), offsetSquare, decimal(0.0));
        offsetMatrix[2].setAllValues(decimal(0.0), decimal(0.0), offsetSquare);
        offsetMatrix[0] += offset * (-offset.x);
        offsetMatrix[1] += offset * (-offset.y);
        offsetMatrix[2] += offset * (-offset.z);
        offsetMatrix *= colliderMass;

        tempLocalInertiaTensor += inertiaTensor + offsetMatrix;
    }

    // Get the diagonal value of the computed local inertia tensor
    inertiaTensorLocal.setAllValues(tempLocalInertiaTensor[0][0], tempLocalInertiaTensor[1][1], tempLocalInertiaTensor[2][2]);
}