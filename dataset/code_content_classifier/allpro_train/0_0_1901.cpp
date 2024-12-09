To solve this problem, you can use a breadth-first search algorithm. Here's the pseudo-code for the approach:

1. Define a structure for each state of the heliline, which includes the center point (x, y), the rotation count, and the distance from the starting point.
2. Initialize a queue and push the initial state of the heliline (center at S, rotation count 0, distance 0) to the queue.
3. While the queue is not empty, pop the front element and check if it is at the goal point G. If yes, output the rotation count and break the loop.
4. Otherwise, iterate through all possible translations from the current state and push the new states to the queue if they do not intersect with obstacles or have already been visited.
5. Repeat steps 3-4 until the goal is reached or no more valid states can be found.
6. If the goal was not reached, output -1 indicating that it is not possible to move to the goal point without hitting obstacles.

You can implement this algorithm in C++ using the standard library data structures and functions. You can define classes for the state of the heliline and the obstacles, and use a queue to store and manage the states during the search process. Finally, output the minimum number of rotational actions required or -1 if it is not possible to move to the goal point without hitting obstacles.