void Fl_Text_Display::buffer( Fl_Text_Buffer *buf ) {
  /* If the text display is already displaying a buffer, clear it off
   of the display and remove our callback from it */
  if ( buf == mBuffer) return;
  if ( mBuffer != 0 ) {
    // we must provide a copy of the buffer that we are deleting!
    char *deletedText = mBuffer->text();
    buffer_modified_cb( 0, 0, mBuffer->length(), 0, deletedText, this );
    free(deletedText);
    mNBufferLines = 0;
    mBuffer->remove_modify_callback( buffer_modified_cb, this );
    mBuffer->remove_predelete_callback( buffer_predelete_cb, this );
  }
  
  /* Add the buffer to the display, and attach a callback to the buffer for
   receiving modification information when the buffer contents change */
  mBuffer = buf;
  if (mBuffer) {
    mBuffer->add_modify_callback( buffer_modified_cb, this );
    mBuffer->add_predelete_callback( buffer_predelete_cb, this );
    
    /* Update the display */
    buffer_modified_cb( 0, buf->length(), 0, 0, 0, this );
  }
  
  /* Resize the widget to update the screen... */
  resize(x(), y(), w(), h());
}