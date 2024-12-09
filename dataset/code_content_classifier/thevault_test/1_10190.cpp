RadeonProRender::matrix CameraLookAtToMatrix( RadeonProRender::float3 pos ,  RadeonProRender::float3 at,  RadeonProRender::float3 up)
{
	RadeonProRender::float3 directionVector =  RadeonProRender::normalize(at - pos);
	RadeonProRender::float3 right = normalize(RadeonProRender::cross(directionVector,up));

	// Warning: For rprCameraSetMotionTransform, we need to make sure to have both 'right' and 'up2' correctly orthogonal to 'directionVector'
	//           otherwise it may result into bad blur rendering.
	RadeonProRender::float3 up2 = normalize(RadeonProRender::cross(right,directionVector));

	RadeonProRender::matrix m(
		right.x,            right.y,            right.z,            0.0,
		up2.x,              up2.y,              up2.z,               0.0,
		-directionVector.x, -directionVector.y, -directionVector.z, 0.0,
		pos.x,              pos.y,              pos.z,              1.0
	);
	return m;
}