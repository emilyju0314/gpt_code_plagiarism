void shutdown()
    {
        // Because of problems while dynamically loading/unloading the HDF5
        // libraries we need to manually call the HDF5 termination routines.
        ::H5close();
    }