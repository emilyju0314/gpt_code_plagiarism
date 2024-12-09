real reader::readData() {
    hid_t plist_id;

    hid_t fileHandle;

    hid_t dataSet;

    herr_t status;

    real time;

    // Create a property list for collectively opening a file by all processors
    plist_id = H5Pcreate(H5P_FILE_ACCESS);
    H5Pset_fapl_mpio(plist_id, MPI_COMM_WORLD, MPI_INFO_NULL);

    // First create a file handle with the path to the input file
    fileHandle = H5Fopen("output/restartFile.h5", H5F_ACC_RDONLY, plist_id);

    // Close the property list for later reuse
    H5Pclose(plist_id);

    // Read the scalar value containing the time from the restart file
    hid_t timeDSpace = H5Screate(H5S_SCALAR);
    dataSet = H5Dopen2(fileHandle, "Time", H5P_DEFAULT);
    status = H5Dread(dataSet, H5T_NATIVE_REAL, timeDSpace, timeDSpace, H5P_DEFAULT, &time);

    // Close dataset for future use and dataspace for clearing resources
    H5Dclose(dataSet);
    H5Sclose(timeDSpace);

    // Create a property list to use collective data read
    plist_id = H5Pcreate(H5P_DATASET_XFER);
    H5Pset_dxpl_mpio(plist_id, H5FD_MPIO_COLLECTIVE);

    for (unsigned int i=0; i < rFields.size(); i++) {
#ifdef PLANAR
        fieldData.resize(blitz::TinyVector<int, 2>(localSize[i](0), localSize[i](2)));
#else
        fieldData.resize(localSize[i]);
#endif

        // Create the dataset *for the array in memory*, linking it to the file handle.
        // Correspondingly, it will use the *core* dataspace, as only the core has to be written excluding the pads
        dataSet = H5Dopen2(fileHandle, rFields[i].fieldName.c_str(), H5P_DEFAULT);

        // Write the dataset. Most important thing to note is that the 3rd and 4th arguments represent the *source* and *destination* dataspaces.
        // The source here is the sourceDSpace pointing to the file. Note that its view has been adjusted using hyperslab.
        // The destination is the targetDSpace. Though the targetDSpace is smaller than the sourceDSpace,
        // only the appropriate hyperslab within the sourceDSpace is transferred to the destination.

        // Note that the targetDSpace and sourceDSpace have switched positions
        // This is another point where the reader differs from the writer
        status = H5Dread(dataSet, H5T_NATIVE_REAL, targetDSpace[i], sourceDSpace[i], plist_id, fieldData.dataFirst());
        if (status) {
            if (mesh.rank == 0) {
                std::cout << "Error in reading input from HDF file. Aborting" << std::endl;
            }
            MPI_Finalize();
            exit(0);
        }

        //Read data
        copyData(rFields[i]);

        H5Dclose(dataSet);
    }

    // CLOSE/RELEASE RESOURCES
    H5Pclose(plist_id);
    H5Fclose(fileHandle);

    return time;
}