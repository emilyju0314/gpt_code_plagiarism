::INT_PTR indirect
    ( const ::DLGTEMPLATE * template_, ::HWND parent, ::DLGPROC callback )
    {
        const ::INT_PTR result = ::DialogBoxIndirect(
                                     0, template_, parent, callback
                                 );
        if ( result == static_cast<::INT_PTR>(-1) ) {
            UNCHECKED_WIN32C_ERROR(DialogBox,::GetLastError());
        }
        return (result);
    }