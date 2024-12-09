error_t PipeIO::CanRead( bool& bCanRead ) const
{
  error_t retCode = GOGOCM_UIS__NOERROR;
  DWORD   nBytesAvailable;

  // Verify IPC handle.
  assert( m_Handle != INVALID_HANDLE_VALUE );

  // Take a peek at the pipe to see if we've got stuff to read.
  if( PeekNamedPipe( m_Handle, NULL, 0, NULL, &nBytesAvailable, NULL ) == 0 )
  {
    // PeekNamedPipe failed.
    retCode = GOGOCM_UIS_PEEKPIPEFAILED;
    nBytesAvailable = 0;
  }

  // Set whether we can read or not.
  bCanRead = (nBytesAvailable > 0);


  // Return operation result.
  return retCode;
}