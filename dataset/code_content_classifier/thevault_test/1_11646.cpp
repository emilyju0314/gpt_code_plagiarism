::INT_PTR direct
        ( ::HMODULE module, ::LPCWSTR name, ::HWND parent, ::DLGPROC callback )
    {
        const ::INT_PTR result = ::DialogBoxW(module, name, parent, callback);
        if ( result == static_cast<::INT_PTR>(result) ) {
            UNCHECKED_WIN32C_ERROR(DialogBox,::GetLastError());
        }
        return (result);
    }