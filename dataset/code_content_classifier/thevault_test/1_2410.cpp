void ParallelUnitTest::status() {
  { // Provide some space before the report -- but keep all the processors in sync.  [KT: 2011/06/20
    // - Actually, ParallelUnitTest should only have a barrier on the destructor.  Otherwise, we can
    // find ourselves in a race condition between this function and the destructor (in the case of
    // an exception).]
    if (node() == 0)
      out << std::endl;
  }
  { out << "Done testing " << testName << " on node " << node() << "." << std::endl; }
  return;
}