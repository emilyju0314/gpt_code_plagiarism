void ParallelDebug::testDoubleDofs(Mesh* mesh)
    {
      FUNCNAME("ParallelDebug::testDoubleDofs()");

      map<WorldVector<double>, DegreeOfFreedom> cMap;
      int foundError = 0;

      TraverseStack stack;
      ElInfo* elInfo = stack.traverseFirst(mesh, -1, Mesh::CALL_LEAF_EL | Mesh::FILL_COORDS);
      while (elInfo)
      {
        for (int i = 0; i < mesh->getGeo(VERTEX); i++)
        {
          WorldVector<double>& c = elInfo->getCoord(i);
          if (cMap.count(c) == 0)
          {
            cMap[c] = elInfo->getElement()->getDof(i, 0);
          }
          else
          {
            if (cMap[c] != elInfo->getElement()->getDof(i, 0))
            {
              MSG("[DBG] Found two DOFs %d and %d with the same coords %f %f %f!\n",
                  cMap[c], elInfo->getElement()->getDof(i, 0),
                  c[0], c[1], mesh->getDim() == 3 ? c[2] : 0.0);
              foundError = 1;
            }
          }
        }

        elInfo = stack.traverseNext(elInfo);
      }

      mpi::globalAdd(foundError);
      TEST_EXIT(foundError == 0)("Error found on at least one rank!\n");
    }