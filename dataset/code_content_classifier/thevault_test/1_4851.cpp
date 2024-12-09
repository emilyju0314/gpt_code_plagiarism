void NarrowPhaseInput::reserveMemory() {

    mSphereVsSphereBatch.reserveMemory();
    mSphereVsCapsuleBatch.reserveMemory();
    mCapsuleVsCapsuleBatch.reserveMemory();
    mSphereVsConvexPolyhedronBatch.reserveMemory();
    mCapsuleVsConvexPolyhedronBatch.reserveMemory();
    mConvexPolyhedronVsConvexPolyhedronBatch.reserveMemory();
}