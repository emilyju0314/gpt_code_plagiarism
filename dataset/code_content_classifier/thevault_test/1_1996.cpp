void fix_normals(void)
{
    for(unsigned j=0; j<g_trianglesNo; j++) {
	Vector3 worldPointA = g_vertices[g_triangles[j]._idx1];
	Vector3 worldPointB = g_vertices[g_triangles[j]._idx2];
	Vector3 worldPointC = g_vertices[g_triangles[j]._idx3];
	Vector3 AB = worldPointB;
	AB -= worldPointA;
	Vector3 AC = worldPointC;
	AC -= worldPointA;
	Vector3 cr = cross(AB, AC);
	cr.normalize();
	g_triangles[j]._normal = cr;
	g_vertices[g_triangles[j]._idx1]._normal += cr;
	g_vertices[g_triangles[j]._idx2]._normal += cr;
	g_vertices[g_triangles[j]._idx3]._normal += cr;
    }
    for(unsigned j=0; j<g_trianglesNo; j++) {
	g_vertices[g_triangles[j]._idx1]._normal.normalize();
	g_vertices[g_triangles[j]._idx2]._normal.normalize();
	g_vertices[g_triangles[j]._idx3]._normal.normalize();
    }
}