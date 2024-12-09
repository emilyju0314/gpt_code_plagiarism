#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string rookPos, knightPos;
    cin >> rookPos >> knightPos;
    
    // Parse the positions of the rook and knight
    int rookX = rookPos[0] - 'a' + 1;
    int rookY = rookPos[1] - '0';
    int knightX = knightPos[0] - 'a' + 1;
    int knightY = knightPos[1] - '0';
    
    // Calculate the distance between the rook and knight
    int dx = abs(rookX - knightX);
    int dy = abs(rookY - knightY);
    
    // Count the number of squares that are attacked by the rook
    int rookAttackedSquares = 2 * 8 - 2;
    
    // Count the number of squares that are attacked by the knight
    int knightAttackedSquares = 8;
    
    // Calculate the total number of squares on the board
    int totalSquares = 8 * 8;
    
    // Calculate the number of squares that are attacked by both the rook and knight
    int commonSquares = max(0, (dx + dy) - 1);
    
    // Calculate the number of squares that are available for the new knight
    int availableSquares = totalSquares - rookAttackedSquares - knightAttackedSquares + commonSquares;
    
    cout << availableSquares << endl;
    
    return 0;
}