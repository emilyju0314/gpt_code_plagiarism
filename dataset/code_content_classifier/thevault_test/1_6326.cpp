void Points::render()
{
  clock_t t1,t2,tt;
  if (total == 0 || elements == 0) return;
  assert(sorter.indices.size());

  tt = t1 = clock();

  // Index buffer object for quick display
  glBindVertexArray(vao);
  if (!indexvbo)
    glGenBuffers(1, &indexvbo);

  //Always set data size again in case changed
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexvbo);
  GL_Error_Check;
  //Initialise particle buffer
  if (glIsBuffer(indexvbo))
  {
    //Lock the update mutex, to wait for any updates to the sorter.indices to finish
    LOCK_GUARD(loadmutex);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sorter.indices.size() * sizeof(GLuint), sorter.indices.data(), GL_DYNAMIC_DRAW);
    debug_print("  %d byte IBO uploaded %d indices\n", sorter.indices.size() * sizeof(GLuint), sorter.indices.size());
  }
  else
    abort_program("IBO creation failed!\n");
  GL_Error_Check;

  t2 = clock();
  debug_print("  Total %.4lf seconds.\n", (t2-tt)/(double)CLOCKS_PER_SEC);
}