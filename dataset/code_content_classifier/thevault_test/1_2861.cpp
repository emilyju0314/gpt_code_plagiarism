void IpcStream::DiagnosticsIpc::Unlink(ErrorCallback callback)
{
    if (_isUnlinked)
        return;
    _isUnlinked = true;

    const int fSuccessUnlink = ::unlink(_pServerAddress->sun_path);
    if (fSuccessUnlink == -1)
    {
        if (callback != nullptr)
            callback(strerror(errno), errno);
        _ASSERTE(fSuccessUnlink == 0);
    }
}