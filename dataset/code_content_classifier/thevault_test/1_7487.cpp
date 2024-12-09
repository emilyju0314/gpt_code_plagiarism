void SoKnot::updateMesh(const float Tol) {

  knot->makeMesh(knot->nodes(),
		 knot->segments(),
		 knot->radius(),
		 Tol);

  _old_segments = knot->segments();
  _old_nodes = knot->nodes();
  _old_radius = knot->radius();

  nodes.setValue(knot->nodes());
  segments.setValue(knot->segments());
  radius.setValue(knot->radius());
}