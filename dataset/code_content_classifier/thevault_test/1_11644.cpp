w32::dword watch ( void * context )
    {
            // Usy synchronous calls to list changes.
        w32::mt::ManualResetEvent& done =
            *reinterpret_cast< w32::mt::ManualResetEvent* >(context);
        w32::fs::Changes changes(".", w32::fs::Changes::Filter::all());
        
            // Make handle set for wait notification.
        w32::Waitable::Set handles;
        handles |= changes.handle();
        handles |= done.handle();
        
            // Log all changes until requested to exit.
        for ( ; (w32::Waitable::any(handles) == 0); changes.next() ) {
            std::cout << "Something changed!" << std::endl;
        }

        return (0);
    }