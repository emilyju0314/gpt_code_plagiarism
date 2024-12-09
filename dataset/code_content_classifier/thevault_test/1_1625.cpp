PvlObject SpiceDbGen::Direct(QString quality, FileList fileList,
                             double startOffset, double endOffset) {
  PvlObject result;

  // Throw an error if no files are being added to this database for
  // this filter/regex
  if (fileList.empty()) {
    QString message = "Input filelist is empty!";
    throw IException(IException::User, message, _FILEINFO_);
  }

  for (int fileNum = 0 ; fileNum < fileList.size() ; fileNum++) {
    FileName currFile = fileList[fileNum];
    PvlGroup selection = AddSelection(currFile, startOffset, endOffset);
    selection += PvlKeyword("Type", quality);
    result.addGroup(selection);
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