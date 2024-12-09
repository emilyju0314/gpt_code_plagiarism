bool solveMazeUtil(
	int maze[N][N], int x,
	int y, int sol[N][N])
{
	// if (x, y is goal) return true
	if (
		x == N - 1 && y == N - 1
		&& maze[x][y] == 1) {
		sol[x][y] = 1;
		return true;
	}

	// Check if maze[x][y] is valid
	if (isSafe(maze, x, y) == true) {
		// Check if the current block is already part of solution path.
		if (sol[x][y] == 1)
			return false;
	
		// mark x, y as part of solution path
		sol[x][y] = 1;

		/* Move forward in x direction */
		if (solveMazeUtil(
				maze, x + 1, y, sol)
			== true)
			return true;

		/* If moving in x direction doesn't give solution then Move down in y direction */
		if (solveMazeUtil(
				maze, x, y + 1, sol)
			== true)
			return true;
	
		/* If none of the above movements
		work then BACKTRACK: unmark
		x, y as part of solution path */
		sol[x][y] = 0;
		return false;
	}

	return false;
}