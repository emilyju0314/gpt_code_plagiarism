void key(unsigned char key, int /*x*/, int /*y*/)
{
    switch (key) 
    {
    case ' ':
        bPause = !bPause;
        break;
    case 27: // escape
    case 'q':
    case 'Q':
        cutilDeviceReset();
        exit(0); 
        break;
    case 13: // return
        if (bSupportDouble)
        {
            if (fp64)
                switchDemoPrecision<float, double>();
            else
                switchDemoPrecision<double, float>();

			shrLog("> %s precision floating point simulation\n", fp64 ? "Double" : "Single");
        }

		break;
    case '`':
        bShowSliders = !bShowSliders;
        break;
	case 'g':
	case 'G':
		bDispInteractions = !bDispInteractions;
		break;
    case 'p':
    case 'P':
        displayMode = (ParticleRenderer::DisplayMode)
                      ((displayMode + 1) % ParticleRenderer::PARTICLE_NUM_MODES);
        break;
    case 'c':
    case 'C':
        cycleDemo = !cycleDemo;
        shrLog("Cycle Demo Parameters: %s\n", cycleDemo ? "ON" : "OFF");
        break;
    case '[':
        activeDemo = (activeDemo == 0) ? numDemos - 1 : (activeDemo - 1) % numDemos;
        selectDemo(activeDemo);
        break;
    case ']':
        activeDemo = (activeDemo + 1) % numDemos;
        selectDemo(activeDemo);
        break;
    case 'd':
    case 'D':
        displayEnabled = !displayEnabled;
        break;
    case 'o':
    case 'O':
        activeParams.print();
        break;
    case '1':
        if (fp64)
            NBodyDemo<double>::reset(numBodies, NBODY_CONFIG_SHELL);
        else
            NBodyDemo<float>::reset(numBodies, NBODY_CONFIG_SHELL);
        break;
    case '2':
        if (fp64)
            NBodyDemo<double>::reset(numBodies, NBODY_CONFIG_RANDOM);
        else
            NBodyDemo<float>::reset(numBodies, NBODY_CONFIG_RANDOM);
        break;
    case '3':
        if (fp64)
            NBodyDemo<double>::reset(numBodies, NBODY_CONFIG_EXPAND);
        else
            NBodyDemo<float>::reset(numBodies, NBODY_CONFIG_EXPAND);
        break;
    }

    glutPostRedisplay();
}