void gid_managed_deleter(id_type_impl* p)
        {
            // a credit of zero means the component is not (globally) reference
            // counted
            if (detail::has_credits(*p)) {
                // execute the deleter directly
                decrement_refcnt(p);
            }
            else {
                delete p;   // delete local gid representation if needed
            }
        }