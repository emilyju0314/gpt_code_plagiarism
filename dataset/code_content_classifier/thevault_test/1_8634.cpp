void ofxFXObject::draw(int _x, int _y, float _width, float _height){
    if (_x == -1) _x = x;
    if (_y == -1) _y = y;
    
    if (_width == -1) _width = width;
    if (_height == -1) _height = height;
    
    ofPushStyle();
    ofEnableAlphaBlending();
    pingPong.dst->draw(_x, _y, _width, _height);
    ofPopStyle();
}