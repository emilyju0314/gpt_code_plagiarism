void RopeScene::moveFirstRopeToHorizontalPosition() {

    // ---------- Move the first rope in a horizontal position ---------- //

    rp3d::Quaternion initOrientation = rp3d::Quaternion::fromEulerAngles(0, 0, -90 * rp3d::PI_RP3D / 180.0f);

    for (int i=1; i<NB_CAPSULES_PER_ROPE-1; i++) {

        // Initial position and orientation of the rigid body
        rp3d::Vector3 initPosition;

        initPosition = rp3d::Vector3(-5 - (i + 0.5) * CAPSULE_HEIGHT, 15 - CAPSULE_HEIGHT, 0);

        rp3d::Transform transform(initPosition, initOrientation);

        // Create a box and a corresponding rigid in the physics world
        mCapsules[i]->setTransform(transform);
    }

    rp3d::Vector3 box1Position(-5 - (NB_CAPSULES_PER_ROPE + 0.5) * CAPSULE_HEIGHT - BOX_SIZE * 0.5, 15 - CAPSULE_HEIGHT, 0);
    const rp3d::Transform box1Transform(box1Position, initOrientation);
    mBox1->setTransform(box1Transform);
}