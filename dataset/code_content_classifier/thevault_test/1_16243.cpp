void ParallelDebug::testDofContainerCommunication(MeshDistributor& pdb, Mesh* mesh)
    {
      FUNCNAME("ParallelDebug::testDofContainerCommunication()");

      MSG("WARNING: ONLY LEVEL 0 TEST!\n");

      typedef map<int, map<const FiniteElemSpace*, DofContainer>>::iterator it_type;

      MPI::Intracomm& mpiComm = pdb.levelData.getMpiComm(0);
      MultiLevelDofComm& dofComm = pdb.dofComms[mesh];

      map<int, int> sendNumber;
      for (it_type it = dofComm[0].getSendDofs().begin();
           it != dofComm[0].getSendDofs().end(); ++it)
        for (map<const FiniteElemSpace*, DofContainer>::iterator dcIt = it->second.begin();
             dcIt != it->second.end(); ++dcIt)
          sendNumber[it->first] += dcIt->second.size();

      map<int, int> recvNumber;
      for (it_type it = dofComm[0].getRecvDofs().begin();
           it != dofComm[0].getRecvDofs().end(); ++it)
        for (map<const FiniteElemSpace*, DofContainer>::iterator dcIt = it->second.begin();
             dcIt != it->second.end(); ++dcIt)
          recvNumber[it->first] += dcIt->second.size();

      StdMpi<int> stdMpi(mpiComm);
      stdMpi.send(sendNumber);
      for (it_type it = dofComm[0].getRecvDofs().begin();
           it != dofComm[0].getRecvDofs().end(); ++it)
        stdMpi.recv(it->first);

      stdMpi.startCommunication();

      int foundError = 0;
      for (map<int, int>::iterator it = stdMpi.getRecvData().begin();
           it != stdMpi.getRecvData().end(); ++it)
      {
        if (it->second != recvNumber[it->first])
        {
          ERROR("Rank expectes %d DOFs to receive from rank %d, but %d DOFs are received!\n",
                recvNumber[it->first], it->first, it->second);
          foundError = 1;
        }
      }

      std::set<DegreeOfFreedom> sendDofs;
      for (DofComm::Iterator it(dofComm[0].getSendDofs(), pdb.meshToFeSpaces[mesh][0]);
           !it.end(); it.nextRank())
        for (; !it.endDofIter(); it.nextDof())
          sendDofs.insert(it.getDofIndex());

      for (DofComm::Iterator it2(dofComm[0].getRecvDofs(), pdb.meshToFeSpaces[mesh][0]);
           !it2.end(); it2.nextRank())
        for (; !it2.endDofIter(); it2.nextDof())
          TEST_EXIT(!sendDofs.count(it2.getDofIndex()))
          ("Send and recv dof contaniners share same dof %d.\n", it2.getDofIndex());

      mpi::globalAdd(foundError);
      TEST_EXIT(foundError == 0)("Error found on at least one rank!\n");
    }