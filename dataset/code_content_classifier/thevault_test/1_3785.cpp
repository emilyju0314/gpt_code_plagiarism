void CPhysicsObject::LocalToWorld( Vector *worldPosition, const Vector &localPosition ) const
{
	matrix3x4_t matrix;
	GetPositionMatrix( &matrix );
	// copy in case the src == dest
	VectorTransform( Vector(localPosition), matrix, *worldPosition );
}