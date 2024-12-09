Locations::Locations(const eckit::Configuration & conf,
                     const eckit::mpi::Comm & comm) {
  const eckit::LocalConfiguration obsconf(conf, "obs space");
  const util::DateTime bgn = util::DateTime(conf.getString("window begin"));
  const util::DateTime end = util::DateTime(conf.getString("window end"));
  ioda::ObsTopLevelParameters obsparams;
  obsparams.validateAndDeserialize(obsconf);

  ioda::ObsSpace obspace(obsparams, comm, bgn, end, oops::mpi::myself());
  const size_t nlocs = obspace.nlocs();
  dist_ = obspace.distribution();

  lats_.resize(nlocs);
  lons_.resize(nlocs);
  times_.resize(nlocs);

  obspace.get_db("MetaData", "latitude", lats_);
  obspace.get_db("MetaData", "longitude", lons_);
  obspace.get_db("MetaData", "datetime", times_);
}