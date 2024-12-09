void reader::copyData(field &outField) {
#ifdef PLANAR
    for (int i=0; i < fieldData.shape()[0]; i++) {
        for (int k=0; k < fieldData.shape()[1]; k++) {
            outField.F(i, 0, k) = fieldData(i, k);
        }
    }
#else
    for (int i=0; i < fieldData.shape()[0]; i++) {
        for (int j=0; j < fieldData.shape()[1]; j++) {
            for (int k=0; k < fieldData.shape()[2]; k++) {
                outField.F(i, j, k) = fieldData(i, j, k);
            }
        }
    }
#endif
}