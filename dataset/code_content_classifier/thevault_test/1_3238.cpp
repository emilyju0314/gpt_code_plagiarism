CString FileErrorMessage(const CFileException *fe, UINT mode /*=CFile::modeRead|CFile::modeWrite*/)
{
		CString retval;                                         // Returned error message
		CFileStatus fs;                                         // Current file status (if access error)
		UINT drive_type;                                        // Type of drive where the file is
	char rootdir[4] = "?:\\";			// Use with GetDriveType

		if (mode == CFile::modeRead)
				retval.Format("An error occurred reading from the file \"%s\".\n", fe->m_strFileName);
		else if (mode = CFile::modeWrite)
				retval.Format("An error occurred writing to the file \"%s\".\n", fe->m_strFileName);
		else
				retval.Format("An error occurred using the file \"%s\".\n", fe->m_strFileName);

		switch (fe->m_cause)
		{
		case CFileException::none:
				ASSERT(0);                                                      // There should be an error for this function to be called
				retval += "Apparently there was no error!";
				break;
#if _MSC_VER < 1400  // generic is now a C++ reserved word
		case CFileException::generic:
#else
		case CFileException::genericException:
#endif
				retval += "The error is not specified.";
				break;
		case CFileException::fileNotFound:
				ASSERT(mode != CFile::modeWrite);       // Should be reading from an existing file
				retval += "The file does not exist.";
				break;
		case CFileException::badPath:
				retval += "The file name contains invalid characters or the drive\n"
							  "or one or more component directories do not exist.";
				break;
		case CFileException::tooManyOpenFiles:
				retval += "There are too many open files in this system.\n"
								  "Try closing some programs or rebooting the system.";
				break;
		case CFileException::accessDenied:
				// accessDenied (or errno == EACCES) is a general purpose error
				// value and can mean many things.  We try to find out more about
				// the file to work out what exactly went wrong.
				if (!CFile::GetStatus(fe->m_strFileName, fs))
				{
						if (fe->m_strFileName.Compare("\\") == 0 ||
							fe->m_strFileName.GetLength() == 3 && fe->m_strFileName[1] == ':' && fe->m_strFileName[2] == '\\')
						{
								retval += "This is the root directory.\n"
												  "You cannot use it as a file.";
						}
						else if (mode == CFile::modeWrite)
						{
								retval += "Check that you have permission to write\n"
												  "to the directory and that the disk is\n"
												  "not write-protected or read-only media.";
						}
						else
								retval += "Access denied. Check that you have permission\n"
												  "to read the directory and use the file.";
				}
				else if (fs.m_attribute & CFile::directory)
						retval += "This is a directory - you cannot use it as a file.";
				else if (fs.m_attribute & (CFile::volume|CFile::hidden|CFile::system))
						retval += "The file is a special system file.";
				else if ((fs.m_attribute & CFile::readOnly) && mode != CFile::modeRead)
						retval += "You cannot write to a read-only file.";
				else
						retval += "You cannot access this file.";
				break;
		case CFileException::invalidFile:
				ASSERT(0);                                                              // Uninitialised or corrupt file handle
				retval += "A software error occurred: invalid file handle.\n"
								  "Please report this defect to the software vendor.";
				break;
		case CFileException::removeCurrentDir:
				retval += "An attempt was made to remove the current directory.";
				break;
		case CFileException::directoryFull:
				ASSERT(mode != CFile::modeRead);        // Must be creating a file
				retval += "The file could not be created because the directory\n"
								  "for the file is full.  Delete some files from the\n"
								  "root directory or use a sub-directory.";
				break;
		case CFileException::badSeek:
				ASSERT(0);                                                      // Normally caused by a bug
				retval += "A software error occurred: seek to bad file position.";
				break;
		case CFileException::hardIO:
				if (fe->m_strFileName.GetLength() > 2 && fe->m_strFileName[1] == ':')
						rootdir[0] = fe->m_strFileName[0];
				else
						rootdir[0] = _getdrive() + 'A' - 1;

				drive_type = GetDriveType(rootdir);
				switch (drive_type)
				{
				case DRIVE_REMOVABLE:
				case DRIVE_CDROM:
						retval += "There was a problem accessing the drive.\n"
										  "Please ensure that the medium is present.";
						break;
				case DRIVE_REMOTE:
						retval += "There was a problem accessing the file.\n"
										  "There may be a problem with your network.";
						break;
				default:
						retval += "There was a hardware error.  There may be\n"
										  "a problem with your computer or disk drive.";
						break;
				}
				break;
		case CFileException::sharingViolation:
				retval += "SHARE.EXE is not loaded or the file is in use.\n"
								  "Check that SHARE.EXE is installed, then try\n"
								  "closing other programs or rebooting the system";
				break;
		case CFileException::lockViolation:
				retval += "The file (or part thereof) is in use.\n"
								  "Try closing other programs or rebooting the system";
				break;
		case CFileException::diskFull:
				ASSERT(mode != CFile::modeRead);        // Must be writing to a file
				retval += "The file could not be written as the disk is full.\n"
								  "Please delete some files to make room on the disk.";
				break;
		case CFileException::endOfFile:
				ASSERT(mode != CFile::modeWrite);       // Should be reading from a file
				retval += "An attempt was made to access an area past the end of the file.";
				break;
		default:
				ASSERT(0);
				retval += "An undocumented file error occurred.";
				break;
		}
		return retval;
}