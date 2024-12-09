ClippingPlaneLocator::ClippingPlaneLocator(Vrui::LocatorTool * locatorTool,
		GeometryViewer* _geometryViewer) :
	BaseLocator(locatorTool, _geometryViewer), clippingPlane(0) {
	/* Find a clipping plane index for this locator: */
	ClippingPlane * clippingPlanes = _geometryViewer->getClippingPlanes();
	for (int i=0; i<_geometryViewer->getNumberOfClippingPlanes(); ++i)
		if (!clippingPlanes[i].isAllocated()) {
			clippingPlane=&clippingPlanes[i];
			break;
		}

	/* Allocate the clipping plane: */
	if (clippingPlane!=0) {
		clippingPlane->setActive(false);
		clippingPlane->setAllocated(true);
	}
}