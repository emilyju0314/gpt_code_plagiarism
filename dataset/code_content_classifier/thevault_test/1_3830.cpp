bool Anvil::WindowWin3264::init(const bool& in_visible)
{
    bool        result            = false;
    const char* window_class_name = (m_closable) ? "Anvil window (closable)"
                                                 : "Anvil window (non-closable)";

    if (m_window_owned)
    {
        std::stringstream class_name_sstream;
        HINSTANCE         instance           = ::GetModuleHandle(nullptr);
        WNDCLASSEX        window_class;
        RECT              window_rect;
        const uint32_t    window_size[2] =
        {
            m_width,
            m_height
        };


        // Initialize the window class structure:
        window_class.cbSize        = sizeof(WNDCLASSEX);
        window_class.style         = CS_HREDRAW | CS_VREDRAW;
        window_class.lpfnWndProc   = msg_callback_pfn_proc;
        window_class.cbClsExtra    = 0;
        window_class.cbWndExtra    = 0;
        window_class.hbrBackground = static_cast<HBRUSH>(::GetStockObject(WHITE_BRUSH) );
        window_class.hInstance     = instance;
        window_class.hIcon         = ::LoadIcon  (nullptr,  /* hInstance */
                                                  IDI_APPLICATION);
        window_class.hCursor       = ::LoadCursor(nullptr,  /* hInstance */
                                                  IDC_ARROW);
        window_class.lpszMenuName  = nullptr;
        window_class.lpszClassName = window_class_name;
        window_class.hIconSm       = ::LoadIcon(nullptr, /* hInstance */
                                                IDI_WINLOGO);

        if (!m_closable)
        {
            window_class.style |= CS_NOCLOSE;
        }

        /* Register window class. If more than one window is instantiated, this call may fail
         * but we don't really care.
         **/
        ::RegisterClassEx(&window_class);

        /* Create the window */
        window_rect.left   = 0;
        window_rect.top    = 0;
        window_rect.right  = static_cast<LONG>(window_size[0]);
        window_rect.bottom = static_cast<LONG>(window_size[1]);

        if (::AdjustWindowRect(&window_rect,
                               WS_OVERLAPPEDWINDOW,
                               FALSE /* bMenu */) == 0)
        {
            anvil_assert_fail();

            goto end;
        }

        /* NOTE: Anvil currently does not support automatic swapchain resizing so make sure the window is not scalable. */
        const auto visibility_flag = (in_visible) ? WS_VISIBLE : 0;

        m_window = ::CreateWindowEx(0,                    /* dwExStyle */
                                    window_class_name,
                                    m_title.c_str(),
                                    (WS_OVERLAPPEDWINDOW | visibility_flag | WS_SYSMENU) ^ WS_THICKFRAME,
                                    0, /* X */
                                    0, /* Y */
                                    window_rect.right - window_rect.left,
                                    window_rect.bottom - window_rect.top,
                                    nullptr, /* hWndParent */
                                    nullptr, /* hMenu */
                                    instance,
                                    nullptr); /* lParam */

        if (m_window == nullptr)
        {
            anvil_assert_fail();

            goto end;
        }
    }

    /* In order to verify if SetWindowLongPtr() has succeeded, we need to check the last thread-local error's value */
    ::SetLastError(0);

    if ((::SetWindowLongPtr(m_window,
                            GWLP_USERDATA,
                            reinterpret_cast<LONG_PTR>(this) ) == 0) &&
        (::GetLastError    ()                                  != 0) )
    {
        anvil_assert_fail();

        goto end;
    }

    result = true;
end:
    return result;
}