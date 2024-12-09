void GetConnectedPoints(stack<Point2i>* stack,
                        const Rect& frameBounds,
                        const Point2i& curPoint,
                        Blob::ConnectionType connectionType) {
  assert(stack);

  if (connectionType == Blob::EIGHT_CONNECTED) {
    // Add the diagonals
    AddSafeConnected(stack, frameBounds, 
                     Point2i(curPoint.x - 1, curPoint.y - 1));
    AddSafeConnected(stack, frameBounds,
                     Point2i(curPoint.x - 1, curPoint.y + 1));
    AddSafeConnected(stack, frameBounds,
                     Point2i(curPoint.x + 1, curPoint.y - 1));
    AddSafeConnected(stack, frameBounds,
                     Point2i(curPoint.x + 1, curPoint.y + 1));
  }

  // Add the adjacent pixels
  AddSafeConnected(stack, frameBounds, Point2i(curPoint.x - 1, curPoint.y));
  AddSafeConnected(stack, frameBounds, Point2i(curPoint.x + 1, curPoint.y));
  AddSafeConnected(stack, frameBounds, Point2i(curPoint.x, curPoint.y - 1));
  AddSafeConnected(stack, frameBounds, Point2i(curPoint.x, curPoint.y + 1));
}