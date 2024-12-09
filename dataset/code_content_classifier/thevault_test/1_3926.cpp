bool isSafe(int maze[N][N], int x, int y)
{
	// if (x, y outside maze) return false
	if (
		x >= 0 && x < N && y >= 0
		&& y < N && maze[x][y] == 1)
		return true;

	return false;
}