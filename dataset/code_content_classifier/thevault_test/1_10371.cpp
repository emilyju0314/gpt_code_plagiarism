double VuPerAreaInFrame(const gsl_vector* x, void* vParams) {
  OptimalFrameParams* params = reinterpret_cast<OptimalFrameParams*>(vParams);

  double width = gsl_vector_get(x, 0);
  double height = gsl_vector_get(x, 1);

  Point2f minCorner = params->frameCenter - Point2f(width/2.0, height/2.0);
  Point2f maxCorner = params->frameCenter + Point2f(width/2.0, height/2.0);

  double visualUtility = params->mosaic.GetIntegralValue(maxCorner) +
    params->mosaic.GetIntegralValue(minCorner) -
    params->mosaic.GetIntegralValue(Point2f(minCorner.x, maxCorner.y)) -
    params->mosaic.GetIntegralValue(Point2f(maxCorner.x, minCorner.y));
  return -(visualUtility / (width*height));
 
}