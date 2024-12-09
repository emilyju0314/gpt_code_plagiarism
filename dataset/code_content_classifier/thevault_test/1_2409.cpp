ParallelUnitTest::~ParallelUnitTest() {
  global_sum(numPasses);
  global_sum(numFails);
  if (node() == 0)
    out << resultMessage() << std::endl;
  // global_barrier();
  // out << resultMessage() << std::endl;
  global_barrier();
  // std::cout << "==> In ~ParallelUnitTest.  Calling mpi_finalize..." << std::endl;
  finalize();
  return;
}