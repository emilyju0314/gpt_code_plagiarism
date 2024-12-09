QString MosaicGridTool::latType() {
    QString result;

    if (getWidget()->getProjection()) {
      if (getWidget()->getProjection()->projectionType() == Projection::Triaxial) {
        TProjection *tproj = (TProjection *) getWidget()->getProjection();
        result = tproj->LatitudeTypeString();
      }
    }

    return result;
  }