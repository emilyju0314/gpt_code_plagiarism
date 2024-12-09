bool Polygon::concave() {

	bool concave = false;
	vec2 v1, v2, v3;
	float d1;
	//must at least be a triangle (assuming closed polygon not line)
	assert(theVerts.size() >=3);
	//triangles cannot be concave
	if (theVerts.size() == 3)
		return false;

	//keep track of 3 vertices
	std::vector<vec2>::iterator cur;
	std::vector<vec2>::iterator before;
	std::vector<vec2>::iterator after;

	//for every vertex get before and after
	for (std::vector<vec2>::iterator it = theVerts.begin() ; 
		it != theVerts.end(); ++it) {

		//non-edge case set up
		cur = it;
		after = cur;
		before = cur;
		after++;
		//edge case at start, grab end
		if (cur == theVerts.begin()){
			before = theVerts.end();
		}
		before--;
		//edge case at end, grab beginning
		if (after == theVerts.end()){
			after = theVerts.begin();
		}
		v1 = *before;
		v2 = *cur;
		v3 = *after;
		//if any vertex is concave, break and return
		if ( magCross(v3, v2, v1) > 0) {
			concave = true;
			break;
		}		
	}
	
	return concave;
}