Collider* RigidBody::addCollider(CollisionShape* collisionShape, const Transform& transform) {

    // Create a new entity for the collider
    Entity colliderEntity = mWorld.mEntityManager.createEntity();

    // Check that the transform is valid
    if (!transform.isValid()) {
        RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Error, Logger::Category::Collider,
                 "Error when adding a collider: the init transform is not valid",  __FILE__, __LINE__);
    }
    assert(transform.isValid());

    // Create a new collider for the body
    Collider* collider = new (mWorld.mMemoryManager.allocate(MemoryManager::AllocationType::Pool,
                                      sizeof(Collider))) Collider(colliderEntity, this, mWorld.mMemoryManager);

    // Add the collider component to the entity of the body
    Vector3 localBoundsMin;
    Vector3 localBoundsMax;
    // TODO : Maybe this method can directly returns an AABB
    collisionShape->getLocalBounds(localBoundsMin, localBoundsMax);
    const Transform localToWorldTransform = mWorld.mTransformComponents.getTransform(mEntity) * transform;
    Material material(mWorld.mConfig.defaultFrictionCoefficient, mWorld.mConfig.defaultBounciness);
    ColliderComponents::ColliderComponent colliderComponent(mEntity, collider, AABB(localBoundsMin, localBoundsMax),
                                                            transform, collisionShape, 0x0001, 0xFFFF, localToWorldTransform, material);
    bool isSleeping = mWorld.mRigidBodyComponents.getIsSleeping(mEntity);
    mWorld.mCollidersComponents.addComponent(colliderEntity, isSleeping, colliderComponent);

    mWorld.mCollisionBodyComponents.addColliderToBody(mEntity, colliderEntity);

    // Assign the collider with the collision shape
    collisionShape->addCollider(collider);

#ifdef IS_RP3D_PROFILING_ENABLED


	// Set the profiler
    collider->setProfiler(mProfiler);

#endif

    // Compute the world-space AABB of the new collision shape
    AABB aabb;
    collisionShape->computeAABB(aabb, mWorld.mTransformComponents.getTransform(mEntity) * transform);

    // Notify the collision detection about this new collision shape
    mWorld.mCollisionDetection.addCollider(collider, aabb);

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Body,
             "Body " + std::to_string(mEntity.id) + ": Collider " + std::to_string(collider->getBroadPhaseId()) + " added to body",  __FILE__, __LINE__);

    RP3D_LOG(mWorld.mConfig.worldName, Logger::Level::Information, Logger::Category::Collider,
             "Collider " + std::to_string(collider->getBroadPhaseId()) + ":  collisionShape=" +
             collider->getCollisionShape()->to_string(),  __FILE__, __LINE__);

    // Return a pointer to the collider
    return collider;
}