BOOST_AUTO_TEST_CASE(service_file_link_bug)
{
  TmpDir tmpCachePath;
  RepoManagerOptions opts( RepoManagerOptions::makeTestSetup( tmpCachePath ) ) ;

  filesystem::mkdir( opts.knownReposPath );
  filesystem::mkdir( opts.knownServicesPath );
  RepoManager manager(opts);

  //test service
  ServiceInfo service("test", DATADIR.asDirUrl() );
  service.setEnabled(true);

  manager.addService(service);
  // now internally, service is associated with the file
  // where it was saved

  // the following line reset the file association with the bug
  manager.modifyService(service.alias(), service);
  // and the following modifyService fails because there is no
  // association
  manager.modifyService(service.alias(), service);
}