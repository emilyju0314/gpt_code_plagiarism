PvlObject SpiceDbGen::Direct(QString quality, QString location,
                             std::vector<QString> &filter, double startOffset, double endOffset) {
  PvlObject result;

  for (unsigned int i = 0; i < filter.size(); ++i) {
    //Create a list of all of the files matching the current filter
    QStringList files = GetFiles(FileName(location), filter[i]);

    // Throw an error if no files are being added to this database for
    // this filter/regex
    if (files.size() == 0) {
      QString message = "Your filter [" + location + "/" + filter[i] + "]"
                       + "has not detected any " + quality + " kernels";
      throw IException(IException::User, message, _FILEINFO_);
    }

    for (int fileNum = 0 ; fileNum < files.size() ; fileNum++) {
      FileName currFile((QString) location + "/" + files[fileNum]);
      PvlGroup selection = AddSelection(currFile, startOffset, endOffset);
      selection += PvlKeyword("Type", quality);
      result.addGroup(selection);
    }
  }

  // Check each group to make sure it is the same type as others
  PvlObject::PvlGroupIterator grp = result.beginGroup();

  while (grp != result.endGroup()) {
    // The kernel did not have any time coverage, so ignore it
    if (grp->name() == "No coverage" || grp->name() == "Null") {
      result.deleteGroup(grp->name());
    }
    else if (grp->name() == p_type) {
      grp->setName("Selection");
      grp++;
    }
    else {
      QString message = "A kernel of type [" + grp->name() + "] has been found in a directory for type [" + p_type + "]" ;
      throw IException(IException::Programmer, message, _FILEINFO_);
      break;
    }
  }

  if (p_type == "SPK") {
    result.setName("SpacecraftPosition");
  }
  else if (p_type == "CK") {
    result.setName("SpacecraftPointing");
  }

  return result;
}