uint cFile::Save()
{
	int Count = 0, s = this->BufferData.size();
	fseek(this->File, 0, SEEK_SET);
	
	for(int i=0; i<s; i++)
	{
		if(this->IsBuffered(i))
			Count += fwrite(&this->BufferData[i], 1, 1, this->File);
		else fseek(this->File, 1, SEEK_CUR); //stay in sync
	}
	
	//fprintf(stderr, "Saved %d/%d\n", Count, s);
	if(Count)
	{
		this->BufferData.clear();
		this->BufferMap.clear();
		this->Saved = true;
	}
	return Count;
}