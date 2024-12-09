__declspec( dllexport ) ClassDesc* LibClassDesc(int i)
{
	switch(i) {
		case 0: return GetExporterPluginDesc();
//		case 1: return GetExporterPluginObjDesc();
		default: return 0;
	}
}