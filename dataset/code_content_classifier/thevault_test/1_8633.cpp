void ofxFXObject::update(){
    
    // This process is going to be repited as many times as passes variable said
    for(int i = 0; i < passes; i++) {
        
        // All the process it´s done on the pingPong ofxSwapBuffer ( basicaly two ofFbo that have a swap() funtion )
        pingPong.dst->begin();
        
        ofClear(0);
        shader.begin();
        
        // The other ofFbo of the ofxSwapBuffer can be access by calling the unicode "backbuffer"
        shader.setUniformTexture("backbuffer", pingPong.src->getTextureReference(), 0 );
        
        // All the needed textures are provided to the shader by this loop
        for( int i = 0; i < nTextures; i++){
            string texName = "tex" + ofToString(i); 
            shader.setUniformTexture(texName.c_str(), textures[i].getTextureReference(), i+1 );
            string texRes = "size" + ofToString(i); 
            shader.setUniform2f(texRes.c_str() , (float)textures[i].getWidth(), (float)textures[i].getHeight());
        }
        
        // Also there are some standar variables that are passes to the shaders
        // this ones follows the standar used by Ricardo Caballero's webGL Sandbox
        // http://mrdoob.com/projects/glsl_sandbox/ and ShaderToy by Inigo Quilez http://www.iquilezles.org/apps/shadertoy/
        // webGL interactive GLSL editors
        //
        shader.setUniform1f("time", ofGetElapsedTimef() );
        shader.setUniform2f("size", (float)width, (float)height);
        shader.setUniform2f("resolution", (float)width, (float)height);
        shader.setUniform2f("mouse", (float)(ofGetMouseX()/width), (float)(ofGetMouseY()/height));
        
        // renderFrame() is a built-in funtion of ofxFXObject that only draw a white box in order to 
        // funtion as a frame here the textures could rest.
        // If you want to distort the points of a textures, probably you want to re-define the renderFrame funtion.
        renderFrame();
        
        shader.end();
        
        pingPong.dst->end();
        
        pingPong.swap();    // Swap the ofFbo's. Now dst is src and src is dst
    }
    
    pingPong.swap();        // After the loop the render information will be at the src ofFbo of the ofxSwapBuffer 
    // this extra swap() call will put it on the dst one. Witch sounds more reasonable...
}