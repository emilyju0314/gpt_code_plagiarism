static void FreeTriangulateIO(triangulateio *t) {
  free(t->pointlist);
  free(t->pointattributelist);
  free(t->pointmarkerlist);
  free(t->trianglelist);
  free(t->triangleattributelist);
  free(t->trianglearealist);
  free(t->neighborlist);
  free(t->segmentlist);
  free(t->segmentmarkerlist);
  free(t->holelist);
  free(t->regionlist);
  free(t->edgelist);
  free(t->edgemarkerlist);
  free(t->normlist);
}