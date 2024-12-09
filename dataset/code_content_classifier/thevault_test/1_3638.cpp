static btVector3 calculateBuoyantCenter(btRigidBody *pBody, btVector3 &planePos, btVector3 &planeNorm) {
	btVector3 center(0, 0, 0);

	btVector3 relPlanePos = pBody->getWorldTransform().inverse() * planePos;
	btVector3 relNorm = quatRotate(pBody->getWorldTransform().getRotation().inverse(), planeNorm);

	btCollisionShape *pShape = pBody->getCollisionShape();
	if (pShape->getShapeType() == COMPOUND_SHAPE_PROXYTYPE) {
		btCompoundShape *pCompound = (btCompoundShape *)pShape;
		for (int i = 0; i < pCompound->getNumChildShapes(); i++) {
			btCollisionShape *pChild = pCompound->getChildShape(i);
			if (pChild->getShapeType() == CONVEX_HULL_SHAPE_PROXYTYPE) {
				center += calcConvexCenter((btConvexHullShape *)pChild, relPlanePos, relNorm);
			}
		}

		if (pCompound->getNumChildShapes() > 0)
			center /= static_cast<btScalar>(pCompound->getNumChildShapes());
	}

	return center;
}