void SoKnot::getPrimitiveCount(SoGetPrimitiveCountAction * action) {

  if (!this->shouldPrimitiveCount(action)) return;
  action->addNumTriangles(2 * this->segments.getValue() *
                          this->nodes.getValue());

}