bool cFile::Open(FILE *File)
{
	this->Saved = true; //we haven't changed it yet
	this->CurrentAddr = 0;
	this->File = File;
	fseek(this->File, 0, SEEK_END);
	this->Size = ftell(this->File);
	rewind(this->File);
	return true;
}