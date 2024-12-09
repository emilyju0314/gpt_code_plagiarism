float GetDistanceBetween(Ship* a, Ship* b) {
	float tx = b->x - a->x;
	float ty = b->y - a->y;
	
	return sqrtf(tx*tx + ty*ty);
}