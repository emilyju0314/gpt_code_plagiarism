void Delay(int Frames)
{
	int i;
	for(i=0; i<Frames; i++) sceDisplayWaitVblankStart();
}