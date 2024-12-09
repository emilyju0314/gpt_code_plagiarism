bool cLevel::isValid(int x, int y) const
{ 
	if ((x < 0) || (x > 39)) return false; 
	if ((y < 0) || (y > 39)) return false;
	int m = map[x][y];
	if(m != 0) return false;
	return true;
}