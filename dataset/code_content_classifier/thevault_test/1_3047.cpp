void SetModelMatrix ( const matrix2x3& m )
{
	modelMatrix = m;
	mvpMatrix = modelMatrix * viewMatrix * projectionMatrix;
	LoadMatrix(mvpMatrix);
}