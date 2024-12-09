void ApplyClipPlaneToProjectionMatrix( D3DXMATRIX &projMatrix, const Vector4D& clipPlane )
{
	Vector4D q;

	// Invalid projection matrix. (Sometimes we get in here with an identity transform as the projection matrix)
	if ( projMatrix._43 == 0.0f )
	{
		return;
	}

	// Calculate the clip-space corner point opposite the clipping plane
	// as (sgn(clipPlane.x), sgn(clipPlane.y), 1, 1) and
	// transform it into camera space by multiplying it
	// by the inverse of the projection matrix

	q.x = ( sgn( clipPlane.x ) + projMatrix._31 ) / projMatrix._11;
	q.y = ( sgn( clipPlane.y ) + projMatrix._32 ) / projMatrix._22;
	q.z = -1.0f;
	q.w = ( 1.0f + projMatrix._33 ) / projMatrix._43;

	// Calculate the scaled plane vector
	Vector4D c = clipPlane * ( 1.0f / DotProduct4D( clipPlane, q ) );

	// Replace the third row of the projection matrix
	projMatrix._13 = c.x;
	projMatrix._23 = c.y;
	projMatrix._33 = c.z;
	projMatrix._43 = c.w;
}