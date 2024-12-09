void CPhysicsObject::WorldToLocal( Vector *localPosition, const Vector &worldPosition ) const
{
	matrix3x4_t matrix;
	GetPositionMatrix( &matrix );
	// copy in case the src == dest
	VectorITransform( Vector(worldPosition), matrix, *localPosition );
}