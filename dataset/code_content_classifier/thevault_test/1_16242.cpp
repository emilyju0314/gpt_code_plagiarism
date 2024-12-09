void ParallelDebug::testGlobalIndexByCoords(MeshDistributor& pdb, Mesh* mesh)
    {
      FUNCNAME("ParallelDebug::testGlobalIndexByCoords()");

      // Get FE space with basis functions of the highest degree
      MultiLevelDofComm& dofComm = pdb.dofComms[mesh];

      for (size_t i = 0; i < pdb.dofMaps.size(); i++)
      {
        vector<const FiniteElemSpace*> dofMapSpaces = pdb.dofMaps[i]->getFeSpaces(mesh);

        if(dofMapSpaces.empty())
          continue;

        const FiniteElemSpace* feSpace = NULL;
        ParallelDofMapping* dfmap = pdb.dofMaps[i];

        size_t j = pdb.meshToFeSpaces[mesh].size() - 1;
        for( ; j >= 0; j--)
          if(find(dofMapSpaces.begin(), dofMapSpaces.end(), pdb.meshToFeSpaces[mesh][j])
              != dofMapSpaces.end())
            break;
        feSpace = pdb.meshToFeSpaces[mesh][j];

        TEST_EXIT(dfmap || feSpace)("Something is wrong.\n");

        DOFVector<WorldVector<double>> coords(feSpace, "tmp");
        mesh->getDofIndexCoords(coords);

        int nLevels = pdb.levelData.getNumberOfLevels();
        for (int level = 0; level < nLevels; level++)
        {
          MPI::Intracomm& mpiComm = pdb.levelData.getMpiComm(level);
          if (mpiComm == MPI::COMM_SELF)
            continue;

          //       int mpiRank = mpiComm.Get_rank();
          //       int mpiSize = mpiComm.Get_size();

          typedef map<int, WorldVector<double>> CoordsIndexMap;
          CoordsIndexMap coordsToIndex;

          DOFIterator<WorldVector<double>> it(&coords, USED_DOFS);
          for (it.reset(); !it.end(); ++it)
          {
            int idx = (*dfmap)[feSpace][it.getDOFIndex()].global;
            coordsToIndex[idx] = *it;
            // 	MSG("   CHECK FOR DOF %d/%d AT COORDS %f %f %f\n",
            // 	    it.getDOFIndex(),
            // 	    coordsToIndex[(*it)],
            // 	    (*it)[0], (*it)[1], (pdb.mesh->getDim() == 3 ? (*it)[2] : 0.0));
          }

          StdMpi<CoordsIndexMap> stdMpi(mpiComm, true);
          for (DofComm::Iterator it(dofComm[level].getSendDofs(), feSpace);
               !it.end(); it.nextRank())
            stdMpi.send(it.getRank(), coordsToIndex);
          for (DofComm::Iterator it(dofComm[level].getRecvDofs(), feSpace);
               !it.end(); it.nextRank())
            stdMpi.recv(it.getRank());

          stdMpi.startCommunication();

          int foundError = 0;
          for (DofComm::Iterator it(dofComm[level].getRecvDofs(), feSpace);
               !it.end(); it.nextRank())
          {
            CoordsIndexMap& otherCoords = stdMpi.getRecvData(it.getRank());

            for (; !it.endDofIter(); it.nextDof())
            {
              WorldVector<double> recvCoords = coords[it.getDofIndex()];
              int idx = (*dfmap)[feSpace][it.getDofIndex()].global;

              TEST_EXIT_DBG(otherCoords.count(idx))("Global index not found in neighbour partition\n");

              WorldVector<double> diff = otherCoords[idx] - recvCoords;
              double dist = sqrt(diff*diff);
              if (dist > DBL_TOL)
              {
                stringstream oss;
                oss.precision(5);
                oss << "DOF at coords ";
                for (int i = 0; i < Global::getGeo(WORLD); i++)
                  oss << recvCoords[i] << " ";
                oss << " do not fit together on rank "
                    << mpiComm.Get_rank() << " (global index: "
                    << it.getDofIndex() << ") and on rank "
                    << it.getRank() << " "
                    << "  - LEVEL " << level;

                MSG("[DBG] %s\n", oss.str().c_str());

                foundError = 1;
              }
            }
          }

          mpi::globalAdd(foundError);
          TEST_EXIT(foundError == 0)("Error found on at least on rank!\n");
        }
      }
    }