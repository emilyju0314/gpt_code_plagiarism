int 
ParseParams (int argc, char *argv[], int visualize = 0) 
{
    ACE_OS::sprintf(_name      ,"/%s/o:sound" ,argv[0]);
    ACE_OS::sprintf(_fgdataname,"/%s/i:fgdata",argv[0]);
    ACE_OS::sprintf(_netname   ,"default");
    ACE_OS::sprintf(_imgname,"/%s/o:img"   ,argv[0]);

	YARPString tmps;

	if (YARPParseParameters::parse(argc, argv, "help") 
		|| argc == 1 
		|| YARPParseParameters::parse(argc, argv, "?") 
		|| YARPParseParameters::parse(argc, argv, "-help"))
	{
		_help = true;
		return YARP_OK;
	}

	if (YARPParseParameters::parse(argc, argv, "-name", tmps))
	{
		ACE_OS::sprintf (_name, "%s/o:sound", tmps.c_str());
		ACE_OS::sprintf (_fgdataname,"%s/i:fgdata", tmps.c_str());
		ACE_OS::sprintf (_imgname,"%s/o:img", tmps.c_str());
	}

	if (YARPParseParameters::parse(argc, argv, "-c", &_Channels))
	{
		ACE_ASSERT (_Channels != 0 && _Channels < 3);
	}

	if (YARPParseParameters::parse(argc, argv, "-a", &_SamplesPerSec))
	{
		ACE_ASSERT (_SamplesPerSec != 0);
	}

	if (YARPParseParameters::parse(argc, argv, "-i", &_BitsPerSample))
	{
		ACE_ASSERT (_BitsPerSample != 0);
	}

	if (YARPParseParameters::parse(argc, argv, "-l", &_BufferLength))
	{
		ACE_ASSERT (_BufferLength != 0);
	}

	if (YARPParseParameters::parse(argc, argv, "-b", &_board_no))
	{
		//ACE_ASSERT (_Channels != 0 && _Channels < 3);
	}

	if (YARPParseParameters::parse(argc, argv, "-t"))
	{
		ACE_OS::fprintf(stdout, "soundgrabber acting as a receiver clients...\n");

		if (YARPParseParameters::parse(argc, argv, "-name", tmps))
		{
			ACE_OS::sprintf (_name, "%s/i:sound", tmps.c_str());
		} else {
			ACE_OS::sprintf (_name,"/%s/i:sound" , argv[0]);
		}
		_client = true;
		_simu   = false;
	}

	if (YARPParseParameters::parse(argc, argv, "-s"))
	{
		ACE_OS::fprintf(stdout, "soundgrabber simulating a soundgrabber...\n");
		_simu   = true;
		_client = false;
	}

	if (YARPParseParameters::parse(argc, argv, "-n", tmps))
	{
		ACE_OS::fprintf (stdout, "sending to network : %s\n", tmps.c_str());
		ACE_OS::sprintf (_netname, "%s", tmps.c_str());
	}

	if (YARPParseParameters::parse(argc, argv, "-f"))
	{
		ACE_OS::fprintf(stdout, "grabber receiving data from network mode...\n");
		_fgnetdata = true;
	}

	if (YARPParseParameters::parse(argc, argv, "-w", &_sizex))
	{
		ACE_ASSERT (_sizex <= 384 && _sizex > 0);
		ACE_ASSERT ((_sizex % 8) == 0);
	}

	if (YARPParseParameters::parse(argc, argv, "-h", &_sizey))
	{
		ACE_ASSERT (_sizey <= 272 && _sizey > 0);
	}

	if (YARPParseParameters::parse(argc, argv, "-b", &_board_no))
	{
		ACE_ASSERT (_board_no >= 0 && _board_no <= 1);
	}

	if (YARPParseParameters::parse(argc, argv, "-s"))
	{
		ACE_OS::fprintf (stdout, "simulating a grabber...\n");
		_simu = true;
	}

	if (YARPParseParameters::parse(argc, argv, "-f"))
	{
		ACE_OS::fprintf(stdout, "grabber receiving data from network mode...\n");
		_fgnetdata = true;
	}

	if (YARPParseParameters::parse(argc, argv, "-v", &_videotype))
	{
		ACE_OS::fprintf(stdout, "grabber working in ");
		switch(_videotype){
			case 0: ACE_OS::fprintf(stdout, "composite video mode...\n"); break;
			case 2: ACE_OS::fprintf(stdout, "s-video video mode...\n"); break;
		}
	}
			
	YARPParseParameters::parse(argc, argv, "-o", &_yoffset);
		
	if (_sizex == -1 && _sizey != -1)
		_sizex = _sizey;
	else
	if (_sizex != -1 && _sizey == -1)
		_sizey = _sizex;
	else
	if (_sizex == -1 && _sizey == -1)
		_sizex = _sizey = 128;

	if (YARPParseParameters::parse(argc, argv, "-c", &_Channels))
	{
		ACE_ASSERT (_Channels != 0 && _Channels < 3);
	}

	if (YARPParseParameters::parse(argc, argv, "-a", &_SamplesPerSec))
	{
		ACE_ASSERT (_SamplesPerSec != 0);
	}

	if (YARPParseParameters::parse(argc, argv, "-i", &_BitsPerSample))
	{
		ACE_ASSERT (_BitsPerSample != 0);
	}


	return YARP_OK; 
}