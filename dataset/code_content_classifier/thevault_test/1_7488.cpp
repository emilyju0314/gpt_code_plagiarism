void SoKnot::setKnot(Tube<Vector3>* t, const float Tol) {

  this->original = t;

  if (knot==NULL)
    knot = new Tube<Vector3>;
  else {
    delete knot;
    knot = new Tube<Vector3>;
  }

  *knot = *original;

  knot->makeMesh(t->nodes(),
		 t->segments(),		 
		 t->radius(),
		 Tol);

  _old_segments = t->segments();
  _old_nodes = t->nodes();
  _old_radius = t->radius();


/*
  sogl_tube_texcoords = NULL;

  // Fixme reinit the new texcoords
  reset_texcoords(t->segments(),t->nodes());
*/
}