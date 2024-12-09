void flags(int argc,char* const* argv, CLIParams &params)
{
	if(params.wflag and argc > 3 and argc < 6)
	{
		for(int i=1;i<argc;++i)
		{
			if(argv[i][0] == '-' and argv[i][1] == 'w')
				i++;
			else
			{
				if(!params.imageflag)
				{
					params.imageName = argv[i];
					params.imageflag = true;
				}
				else
				{
					params.maskName = argv[i];
					params.maskflag = true;
				}
			}
		}
	}
	else
	{
		if(params.iflag and argc > 2 and argc < 5)
		{
			for(int i=1; i<argc; ++i)
			{
				if(argv[i][0] != '-')
				{
					if(!params.imageflag)
					{
						params.imageName = argv[i];
						params.imageflag = true;
					}
					else
					{
						params.maskName = argv[i];
						params.maskflag = true;
					}
				}
			}
		}

		else
		{
			if(!params.wflag and !params.iflag and argc > 1 and argc < 4)
			{
				for(int i=1; i<argc; ++i)
				{
					params.imageName = argv[1];
          std::cout << "\033[33;1mImagen capturada\033[0m" << std::endl;
					params.imageflag = true;
					if(argc == 3)
					{
						params.maskName = argv[2];
						params.maskflag = true;
					}
				}
			}
			else
			{
				std::cout << "\033[31;1mError en los argumentos. Verbose:" << params.verbose << std::endl;
				std::cout << "Se debe especificar una imagen obligatoriamente.\033[0m" << std::endl;
				mostrarUso(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
	}
}