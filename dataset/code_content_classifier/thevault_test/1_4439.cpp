vtkPExodusIIReader::vtkPExodusIIReader()
{
  this->ProcRank = 0;
  this->ProcSize = 1;
  // NB. SetController will initialize ProcSize and ProcRank
  this->Controller = 0;
  this->SetController( vtkMultiProcessController::GetGlobalController() );
  this->FilePattern = 0;
  this->CurrentFilePattern = 0;
  this->FilePrefix = 0;
  this->CurrentFilePrefix = 0;
  this->FileRange[0] = -1;
  this->FileRange[1] = -1;
  this->CurrentFileRange[0] = 0;
  this->CurrentFileRange[1] = 0;
  this->NumberOfFiles = 1;
  this->FileNames = NULL;
  this->NumberOfFileNames = 0;
  this->MultiFileName = new char[vtkPExodusIIReaderMAXPATHLEN];
  this->XMLFileName=NULL;
  this->LastCommonTimeStep = -1;
}