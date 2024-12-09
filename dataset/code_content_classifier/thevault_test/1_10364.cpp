void AddSafeConnected(stack<cv::Point2i>* stack,
                      const Rect& frameBounds,
                      const cv::Point2i& point) {
  if (frameBounds.contains(point)) {
    stack->push(point);
  }    
}