void SyncMediator::AddLocalHardlinkGroups(const HardlinkGroupMap &hardlinks) {
  assert(handle_hardlinks_);

  for (HardlinkGroupMap::const_iterator i = hardlinks.begin(),
       iEnd = hardlinks.end(); i != iEnd; ++i)
  {
    if (i->second.hardlinks.size() != i->second.master.GetUnionLinkcount()) {
      LogCvmfs(kLogPublish, kLogStderr, "Hardlinks across directories (%s)",
               i->second.master.GetUnionPath().c_str());
      if (!params_->ignore_xdir_hardlinks)
        abort();
    }

    if (params_->print_changeset) {
      std::string changeset_notice = "add hardlinks around ("
                                   + i->second.master.GetUnionPath() + ")";
      for (SyncItemList::const_iterator j = i->second.hardlinks.begin(),
           jEnd = i->second.hardlinks.end(); j != jEnd; ++j)
      {
        changeset_notice += " " + j->second.filename();
      }
      PrintChangesetNotice(kAddHardlinks, changeset_notice);
    }

    if (params_->dry_run)
      continue;

    if (i->second.master.IsSymlink())
      AddHardlinkGroup(i->second);
    else
      hardlink_queue_.push_back(i->second);
  }
}