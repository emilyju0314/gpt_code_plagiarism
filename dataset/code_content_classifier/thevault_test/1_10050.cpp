int VideoChannelAGL::DeliverFrame(const VideoFrame& videoFrame) {
  _owner->LockAGLCntx();

  if (_texture == 0) {
    _owner->UnlockAGLCntx();
    return 0;
  }

  if (CalcBufferSize(kI420, videoFrame.width(), videoFrame.height()) !=
      _incomingBufferSize) {
    _owner->UnlockAGLCntx();
    return -1;
  }

  // Setting stride = width.
  int rgbret = ConvertFromYV12(videoFrame, kBGRA, 0, _buffer);
  if (rgbret < 0) {
    _owner->UnlockAGLCntx();
    return -1;
  }

  aglSetCurrentContext(_aglContext);

  // Put the new frame into the graphic card texture.
  // Make sure this texture is the active one
  glBindTexture(GL_TEXTURE_RECTANGLE_EXT, _texture);
  GLenum glErr = glGetError();
  if (glErr != GL_NO_ERROR) {
    _owner->UnlockAGLCntx();
    return -1;
  }

  // Copy buffer to texture
  glTexSubImage2D(GL_TEXTURE_RECTANGLE_EXT,
                  0, // Level, not use
                  0, // start point x, (low left of pic)
                  0, // start point y,
                  _width, // width
                  _height, // height
                  _pixelFormat, // pictue format for _buffer
                  _pixelDataType, // data type of _buffer
                  (const GLvoid*) _buffer); // the pixel data

  if (glGetError() != GL_NO_ERROR) {
    _owner->UnlockAGLCntx();
    return -1;
  }

  _bufferIsUpdated = true;
  _owner->UnlockAGLCntx();

  return 0;
}