void reader::initLimits() {
    hid_t sDSpace;
    hid_t tDSpace;

    herr_t status;

    blitz::TinyVector<int, 3> gloSize, sdStart, locSize;

#ifdef PLANAR
    hsize_t dimsf[2];           /* dataset dimensions */
    hsize_t offset[2];          /* offset of hyperslab */
#else
    hsize_t dimsf[3];           /* dataset dimensions */
    hsize_t offset[3];          /* offset of hyperslab */
#endif

    for (unsigned int i=0; i < rFields.size(); i++) {
        gloSize = mesh.globalSize;
        if (not rFields[i].xStag) {
            gloSize(0) -= 1;
        }

#ifndef PLANAR
        if (not rFields[i].yStag) {
            gloSize(1) -= 1;
        }
#else
        gloSize(1) = 1;
#endif

        if (not rFields[i].zStag) {
            gloSize(2) -= 1;
        }

        locSize = mesh.collocCoreSize;
        if (rFields[i].xStag) {
            // Though the last point (which is shared across 2 processors) was excluded for some subdomains in the writer class, while reading, these overlapping points have to be considered
            // This is one point where reader differs from writer
            locSize(0) = mesh.staggrCoreSize(0);
        }

#ifndef PLANAR
        if (rFields[i].yStag) {
            // As with X direction, all subdomains include both the boundary points (which may be shared across 2 processors)
            locSize(1) = mesh.staggrCoreSize(1);
        }
#else
        locSize(1) = 1;
#endif

        if (rFields[i].zStag) {
            locSize(2) = mesh.staggrCoreSize(2);
        }

        // Since only the last rank along X and Y directions include the extra point (shared across processors), subArrayStarts are same for all ranks
        sdStart = mesh.subarrayStarts;

        // Create a dataspace representing the full limits of the array - this is the target dataspace
#ifdef PLANAR
        dimsf[0] = locSize(0);
        dimsf[1] = locSize(2);
        tDSpace = H5Screate_simple(2, dimsf, NULL);
#else
        dimsf[0] = locSize(0);
        dimsf[1] = locSize(1);
        dimsf[2] = locSize(2);
        tDSpace = H5Screate_simple(3, dimsf, NULL);
#endif

        // Modify the view of the *target* dataspace by using a hyperslab - *this view will be used to read from memory*

        // ************* NOTE: Check if the hyperslab view must be changed to take care of the common point at the the MPI decomposed sub-domain boundaries ****************//
#ifdef PLANAR
        dimsf[0] = locSize(0);
        dimsf[1] = locSize(2);
        offset[0] = 0;
        offset[1] = 0;
#else
        dimsf[0] = locSize(0);
        dimsf[1] = locSize(1);
        dimsf[2] = locSize(2);
        offset[0] = 0;
        offset[1] = 0;
        offset[2] = 0;
#endif

        status = H5Sselect_hyperslab(tDSpace, H5S_SELECT_SET, offset, NULL, dimsf, NULL);
        if (status) {
            if (mesh.rank == 0) {
                std::cout << "Error in creating hyperslab while writing data. Aborting" << std::endl;
            }
            MPI_Finalize();
            exit(0);
        }

        // Create a dataspace representing the full limits of the global array - i.e. the dataspace for input file
#ifdef PLANAR
        dimsf[0] = gloSize(0);
        dimsf[1] = gloSize(2);
        sDSpace = H5Screate_simple(2, dimsf, NULL);
#else
        dimsf[0] = gloSize(0);
        dimsf[1] = gloSize(1);
        dimsf[2] = gloSize(2);
        sDSpace = H5Screate_simple(3, dimsf, NULL);
#endif

        // Modify the view of the *source* dataspace by using a hyperslab according to its position in the global file dataspace
#ifdef PLANAR
        dimsf[0] = locSize(0);
        dimsf[1] = locSize(2);
        offset[0] = sdStart[0];
        offset[1] = sdStart[2];
#else
        dimsf[0] = locSize(0);
        dimsf[1] = locSize(1);
        dimsf[2] = locSize(2);
        offset[0] = sdStart[0];
        offset[1] = sdStart[1];
        offset[2] = sdStart[2];
#endif

        status = H5Sselect_hyperslab(sDSpace, H5S_SELECT_SET, offset, NULL, dimsf, NULL);
        if (status) {
            if (mesh.rank == 0) {
                std::cout << "Error in creating hyperslab while writing data. Aborting" << std::endl;
            }
            MPI_Finalize();
            exit(0);
        }

        localSize.push_back(locSize);
        sourceDSpace.push_back(sDSpace);
        targetDSpace.push_back(tDSpace);
    }
}