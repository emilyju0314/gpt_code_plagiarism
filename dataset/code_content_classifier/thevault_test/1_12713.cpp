void matrix3::CrossProduct( vector3 const&v, matrix3 &Dst )const
{
	Dst._11 = _12 * v.z - _13 * v.y;
	Dst._12 = _13 * v.x - _11 * v.z;
	Dst._13 = _11 * v.y - _12 * v.x;
	Dst._21 = _22 * v.z - _23 * v.y;
	Dst._22 = _23 * v.x - _21 * v.z;
	Dst._23 = _21 * v.y - _22 * v.x;
	Dst._31 = _32 * v.z - _33 * v.y;
	Dst._32 = _33 * v.x - _31 * v.z;
	Dst._33 = _31 * v.y - _32 * v.x;
}