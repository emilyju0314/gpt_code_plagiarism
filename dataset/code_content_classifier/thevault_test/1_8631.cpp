void ofxFXObject::setTexture(ofBaseDraws& tex, int _texNum){ 
    if ((_texNum < nTextures) && ( _texNum >= 0)){
        textures[_texNum].begin(); 
        ofClear(0,0);
        ofSetColor(255);
        tex.draw(0,0); 
        textures[_texNum].end();
    }
}