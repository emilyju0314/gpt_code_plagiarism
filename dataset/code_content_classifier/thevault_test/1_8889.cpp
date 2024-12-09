bool IsDirectory(char *File)
{
	struct stat st;
	if(stat(File, &st) == 0 && S_ISDIR(st.st_mode)) return true;
	else if(!strcmp(File, "..")) return true; //for some reason this isn't listed as a directory O_o
	else return false;
}