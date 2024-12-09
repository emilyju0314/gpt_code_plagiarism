bool SyncMediator::Commit(manifest::Manifest *manifest) {
  if (!params_->print_changeset && changed_items_ >= processing_dot_interval) {
    // line break the 'progress bar', see SyncMediator::PrintChangesetNotice()
    LogCvmfs(kLogPublish, kLogStdout, "");
  }

  LogCvmfs(kLogPublish, kLogStdout,
           "Waiting for upload of files before committing...");
  params_->spooler->WaitForUpload();

  if (!hardlink_queue_.empty()) {
    assert(handle_hardlinks_);

    LogCvmfs(kLogPublish, kLogStdout, "Processing hardlinks...");
    params_->spooler->UnregisterListeners();
    params_->spooler->RegisterListener(&SyncMediator::PublishHardlinksCallback,
                                       this);

    // TODO(rmeusel): Revise that for Thread Safety!
    //       This loop will spool hardlinks into the spooler, which will then
    //       process them.
    //       On completion of every hardlink the spooler will asynchronously
    //       emit callbacks (SyncMediator::PublishHardlinksCallback) which
    //       might happen while this for-loop goes through the hardlink_queue_
    //
    //       For the moment this seems not to be a problem, but it's an accident
    //       just waiting to happen.
    //
    //       Note: Just wrapping this loop in a mutex might produce a dead lock
    //             since the spooler does not fill it's processing queue to an
    //             unlimited size. Meaning that it might be flooded with hard-
    //             links and waiting for the queue to be processed while proces-
    //             sing is stalled because the callback is waiting for this
    //             mutex.
    for (HardlinkGroupList::const_iterator i = hardlink_queue_.begin(),
         iEnd = hardlink_queue_.end(); i != iEnd; ++i)
    {
      LogCvmfs(kLogPublish, kLogVerboseMsg, "Spooling hardlink group %s",
               i->master.GetUnionPath().c_str());
      params_->spooler->Process(i->master.GetUnionPath());
    }

    params_->spooler->WaitForUpload();

    for (HardlinkGroupList::const_iterator i = hardlink_queue_.begin(),
         iEnd = hardlink_queue_.end(); i != iEnd; ++i)
    {
      LogCvmfs(kLogPublish, kLogVerboseMsg, "Processing hardlink group %s",
               i->master.GetUnionPath().c_str());
      AddHardlinkGroup(*i);
    }
  }

  params_->spooler->UnregisterListeners();

  LogCvmfs(kLogPublish, kLogStdout, "Committing file catalogs...");
  if (params_->spooler->GetNumberOfErrors() > 0) {
    LogCvmfs(kLogPublish, kLogStderr, "failed to commit files");
    return false;
  }

  if (catalog_manager_->IsBalanceable()) {
    catalog_manager_->Balance();
  }
  catalog_manager_->PrecalculateListings();
  return catalog_manager_->Commit(params_->stop_for_catalog_tweaks,
                                  params_->manual_revision,
                                  manifest);
}