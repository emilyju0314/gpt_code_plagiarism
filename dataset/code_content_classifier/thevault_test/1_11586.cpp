void cLevel::Load(const char* fname)
{
	for (int i = 0; i < GRIDHEIGHT; i++)
	{
		for (int j = 0; j < GRIDWIDTH; j++)
		{
			map[i][j] = 0;
		}
	}
	FILE *file = fopen(fname,"rt");
	for (int j = 0; j < GRIDHEIGHT; j++)
	{
		char line[128];
		fread(line, 1, 41, file);
		for (int i = 0; i < GRIDWIDTH; i++)
		{
			if(line[i]=='#') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	fclose(file);
}