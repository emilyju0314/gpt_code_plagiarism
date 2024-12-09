GLuint gen_program(const char* vertex_shader_src, const char* fragment_shader_src)
{
   GLuint vertexShader;
   GLuint fragmentShader;
   GLuint programObject;
   GLint linked;

   // Load the vertex/fragment shaders
   vertexShader = loadShader ( GL_VERTEX_SHADER, vertex_shader_src);
   fragmentShader = loadShader ( GL_FRAGMENT_SHADER, fragment_shader_src);

   // Create the program object
   programObject = glCreateProgram ();
   
   if ( programObject == 0 )
   {
       printf("program object is 0\n");
       return 0;
   }

   glAttachShader ( programObject, vertexShader );
   glAttachShader ( programObject, fragmentShader );

   // Bind vPosition to attribute 0   
   glBindAttribLocation ( programObject, 0, "vPosition" );

   // Link the program
   glLinkProgram ( programObject );

   // Check the link status
   glGetProgramiv ( programObject, GL_LINK_STATUS, &linked );

   if ( !linked ) 
   {
      GLint infoLen = 0;
      glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );
      
      if ( infoLen > 1 )
      {
         char* infoLog = (char *) malloc (sizeof(char) * infoLen );
         glGetProgramInfoLog ( programObject, infoLen, NULL, infoLog );
         printf( "Error linking program:\n%s\n", infoLog );            
         free ( infoLog );
      }

      glDeleteProgram ( programObject );
      printf("Program not linked\n");
      return 0;
   }

   // Store the program object
   return programObject;
}