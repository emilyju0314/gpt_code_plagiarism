bool CFrameBufferObject::initialize(unsigned int width, unsigned int height, fboConfig & rConfigFBO, fboData & rActiveFBO)
{
    //Framebuffer config options
    vector<bufferConfig> colorConfigs;
    vector<bufferConfig> depthConfigs;
    bufferConfig temp;

    //add default color configs
	temp.name   = (m_bUseFloat ? "RGBA32F" : "RGBA8");
	temp.bits   = (m_bUseFloat ? 32 : 8);
	temp.format = (m_bUseFloat ? GL_RGBA32F_ARB : GL_RGBA8);
	colorConfigs.push_back( temp);

    //add default depth configs
    temp.name = "D24";
    temp.bits = 24;
    temp.format = GL_DEPTH_COMPONENT24;
    depthConfigs.push_back( temp );

    // If the FBO can be created, add it to the list of available configs, and make a menu entry
    string root = colorConfigs[0].name + " " + depthConfigs[0].name;

    rConfigFBO.colorFormat	= colorConfigs[0].format;
    rConfigFBO.depthFormat	= depthConfigs[0].format;
    rConfigFBO.redbits		= colorConfigs[0].bits;
    rConfigFBO.depthBits	= depthConfigs[0].bits;

    //single sample
    rConfigFBO.name				= root;
    rConfigFBO.coverageSamples	= 0;
    rConfigFBO.depthSamples		= 0;

    create( width, height, rConfigFBO, rActiveFBO );

    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);

    if (m_bUseFloat) {
	// load fragment programs
	const char* strTextureProgram2D = 
                   "!!ARBfp1.0\n"
                   "TEX result.color, fragment.texcoord[0], texture[0], 2D;\n"
                   "END\n";

        m_textureProgram = nv::CompileASMShader( GL_FRAGMENT_PROGRAM_ARB, strTextureProgram2D );

	    const char* strOverlayProgram = 
		    "!!ARBfp1.0\n"
		    "TEMP t;\n"
		    "TEX t, fragment.texcoord[0], texture[0], 2D;\n"
		    "MOV result.color, t;\n"
		    "END\n";
	    
        m_overlayProgram = nv::CompileASMShader( GL_FRAGMENT_PROGRAM_ARB, strOverlayProgram );
    }

    return CHECK_FBO;
}