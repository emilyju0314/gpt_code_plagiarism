double magCross(vec2 v1, vec2 v2, vec2 v3) {
	double v = ((v2.x()-v1.x())*(v3.y()-v2.y()) - (v3.x()-v2.x())*(v2.y()-v1.y()));
	//cout << "v1: " << v1 << " v2: " << v2 << " v3: " << v3 <<  " mag: " << v << endl;
	return v;
}