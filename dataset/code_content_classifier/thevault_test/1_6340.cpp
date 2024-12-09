void LinesSorted::render()
{
  clock_t t1,t2;
  if (linecount == 0 || elements == 0) return;
  assert(sorter.buffer);

  t1 = clock();

  //Prepare the Index buffer
  if (!indexvbo)
    glGenBuffers(1, &indexvbo);

  //Always set data size again in case changed
  glBindVertexArray(vao);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexvbo);
  GL_Error_Check;
  if (glIsBuffer(indexvbo))
  {
    //Lock the update mutex, to wait for any updates to the indexlist to finish
    LOCK_GUARD(loadmutex);
    //NOTE: linecount holds the filtered count of triangles to actually render as opposed to total in buffer
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, linecount * 2 * sizeof(GLuint), sorter.indices.data(), GL_DYNAMIC_DRAW);
    debug_print("  %d byte IBO uploaded %d indices (%d tris)\n", linecount*2 * sizeof(GLuint), linecount*2, linecount);
  }
  else
    abort_program("IBO creation failed\n");
  GL_Error_Check;

  t2 = clock();
  debug_print("  %.4lf seconds to upload %d indices (%d tris)\n", (t2-t1)/(double)CLOCKS_PER_SEC, sorter.indices.size(), linecount);
  t1 = clock();
  //After render(), copy filtered count to elements, indices.size() is unfiltered
  elements = linecount * 2;
}