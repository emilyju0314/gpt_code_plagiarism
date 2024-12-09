CustomCursor ( ::POINT hotspot, ::HBITMAP mask, ::HBITMAP color )
            : myInfo(hotspot,mask,color),
              myHandle(::CreateIconIndirect(&myInfo.get()))
        {
            if ( myHandle.bad() ) {
                UNCHECKED_WIN32C_ERROR(CreateIconIndirect,::GetLastError());
            }
        }