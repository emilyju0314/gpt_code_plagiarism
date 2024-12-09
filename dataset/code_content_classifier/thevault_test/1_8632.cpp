void ofxFXObject::begin(int _texNum ) {
    if ((_texNum < nTextures) && ( _texNum >= 0)){
        ofPushStyle();
        ofPushMatrix();
        textures[_texNum].begin();
        ofClear(0,0);
    }
}