void field::setInterpolationSlices() {
    // INTERPOLATION SLICES FOR INTERPOLATING VALUES OF Vx FROM THE vfield
    // In all the below slices, we are considering interpolations between the following 8 variables
    //
    // Vx, Vy, Vz - these are face centered variables sitting on X, Y and Z planes respectively (like velocity)
    // Wx, Wy, Wz - these are edge centered variables sitting on X, Y and Z axes respectively (like vorticity)
    // Pc - this a cell centered variable (like temperature)
    // Qv - this a vertex centered variable (I don't know if anything sits here. But hey! completeness!)
    if (not xStag) {
        if (yStag) {
            if (zStag) {
                /* coll stag stag */
                /**X-Face centered configuration - Vx **/

                /* Interpolation of data - Vx ---> Vx
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => no change
                 *      - Z direction => no change
                 **/
                VxIntSlices.resize(1);
                VxIntSlices(0) = fCore;

                /* Interpolation of data - Vy ---> Vx
                 * Interpolation types:
                 *      - X direction => staggered to collocated
                 *      - Y direction => collocated to staggered
                 *      - Z direction => no change
                 **/
                VyIntSlices.resize(4);
                VyIntSlices(0) = fCore;
                VyIntSlices(1) = shift(1, VyIntSlices(0), -1);
                VyIntSlices(2) = shift(0, VyIntSlices(0), 1);
                VyIntSlices(3) = shift(1, VyIntSlices(2), -1);

                /* Interpolation of data - Vz ---> Vx
                 * Interpolation types:
                 *      - X direction => staggered to collocated
                 *      - Y direction => no change
                 *      - Z direction => collocated to staggered
                 **/
                VzIntSlices.resize(4);
                VzIntSlices(0) = fCore;
                VzIntSlices(1) = shift(2, VzIntSlices(0), -1);
                VzIntSlices(2) = shift(0, VzIntSlices(0), 1);
                VzIntSlices(3) = shift(2, VzIntSlices(2), -1);

                /* Interpolation of data - Pc ---> Vx
                 * Interpolation types:
                 *      - X direction => staggered to collocated
                 *      - Y direction => no change
                 *      - Z direction => no change
                 **/
                PcIntSlices.resize(2);
                PcIntSlices(0) = fCore;
                PcIntSlices(1) = shift(0, PcIntSlices(0), 1);

            } else {
                /* coll stag coll */
                /**Y-Edge centered configuration - Wy **/

                /* Interpolation of data - Vx ---> Wy
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => no change
                 *      - Z direction => staggered to collocated
                 **/
            }
        } else {
            if (zStag) {
                /* coll coll stag */
                /**Z-Edge centered configuration - Wz **/

                /* Interpolation of data - Vx ---> Wz
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => staggered to collocated
                 *      - Z direction => no change
                 **/
            } else {
                /* coll coll coll */
                /**Vertex centered configuration - Qv **/

                /* Interpolation of data - Vx ---> Qv
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => staggered to collocated
                 *      - Z direction => staggered to collocated
                 **/
            }
        }
    } else {
        if (yStag) {
            if (zStag) {
                /* stag stag stag */
                /**Cell centered configuration - Pc **/

                /* Interpolation of data - Vx ---> Pc
                 * Interpolation types:
                 *      - X direction => collocated to staggered
                 *      - Y direction => no change
                 *      - Z direction => no change
                 **/
                VxIntSlices.resize(2);
                VxIntSlices(0) = fCore;
                VxIntSlices(1) = shift(0, VxIntSlices(0), -1);

                /* Interpolation of data - Vy ---> Pc
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => collocated to staggered
                 *      - Z direction => no change
                 **/
                VyIntSlices.resize(2);
                VyIntSlices(0) = fCore;
                VyIntSlices(1) = shift(1, VyIntSlices(0), -1);

                /* Interpolation of data - Vz ---> Pc
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => no change
                 *      - Z direction => collocated to staggered
                 **/
                VzIntSlices.resize(2);
                VzIntSlices(0) = fCore;
                VzIntSlices(1) = shift(2, VzIntSlices(0), -1);

                /* Interpolation of data - Pc ---> Pc
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => no change
                 *      - Z direction => no change
                 **/
                PcIntSlices.resize(1);
                PcIntSlices(0) = fCore;

            } else {
                /* stag stag coll */
                /**Z-Face centered configuration - Vz **/

                /* Interpolation of data - Vx ---> Vz
                 * Interpolation types:
                 *      - X direction => collocated to staggered
                 *      - Y direction => no change
                 *      - Z direction => staggered to collocated
                 **/
                VxIntSlices.resize(4);
                VxIntSlices(0) = fCore;
                VxIntSlices(1) = shift(0, VxIntSlices(0), -1);
                VxIntSlices(2) = shift(2, VxIntSlices(0), 1);
                VxIntSlices(3) = shift(0, VxIntSlices(2), -1);

                /* Interpolation of data - Vy ---> Vz
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => collocated to staggered
                 *      - Z direction => staggered to collocated
                 **/
                VyIntSlices.resize(4);
                VyIntSlices(0) = fCore;
                VyIntSlices(1) = shift(1, VyIntSlices(0), -1);
                VyIntSlices(2) = shift(2, VyIntSlices(0), 1);
                VyIntSlices(3) = shift(1, VyIntSlices(2), -1);

                /* Interpolation of data - Vz ---> Vz
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => no change
                 *      - Z direction => no change
                 **/
                VzIntSlices.resize(1);
                VzIntSlices(0) = fCore;

                /* Interpolation of data - Pc ---> Vz
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => no change
                 *      - Z direction => staggered to collocated
                 **/
                PcIntSlices.resize(2);
                PcIntSlices(0) = fCore;
                PcIntSlices(1) = shift(2, PcIntSlices(0), 1);

            }
        } else {
            if (zStag) {
                /* stag coll stag */
                /**Y-Face centered configuration - Vy **/

                /* Interpolation of data - Vx ---> Vy
                 * Interpolation types:
                 *      - X direction => collocated to staggered
                 *      - Y direction => staggered to collocated
                 *      - Z direction => no change
                 **/
                VxIntSlices.resize(4);
                VxIntSlices(0) = fCore;
                VxIntSlices(1) = shift(0, VxIntSlices(0), -1);
                VxIntSlices(2) = shift(1, VxIntSlices(0), 1);
                VxIntSlices(3) = shift(0, VxIntSlices(2), -1);

                /* Interpolation of data - Vy ---> Vy
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => no change
                 *      - Z direction => no change
                 **/
                VyIntSlices.resize(1);
                VyIntSlices(0) = fCore;

                /* Interpolation of data - Vz ---> Vy
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => staggered to collocated
                 *      - Z direction => collocated to staggered
                 **/
                VzIntSlices.resize(4);
                VzIntSlices(0) = fCore;
                VzIntSlices(1) = shift(2, VzIntSlices(0), -1);
                VzIntSlices(2) = shift(1, VzIntSlices(0), 1);
                VzIntSlices(3) = shift(2, VzIntSlices(2), -1);

                /* Interpolation of data - Pc ---> Vy
                 * Interpolation types:
                 *      - X direction => no change
                 *      - Y direction => staggered to collocated
                 *      - Z direction => no change
                 **/
                PcIntSlices.resize(2);
                PcIntSlices(0) = fCore;
                PcIntSlices(1) = shift(1, PcIntSlices(0), 1);

            } else {
                /* stag coll coll */
                /**X-Edge centered configuration - Wx **/

                /* Interpolation of data - Vx ---> Wx
                 * Interpolation types:
                 *      - X direction => collocated to staggered
                 *      - Y direction => staggered to collocated
                 *      - Z direction => staggered to collocated
                 **/
            }
        }
    }

    // RESET INTERPOLATION SLICES FOR PLANAR GRID
#ifdef PLANAR
    if (fieldName == "Vy") {
        VxIntSlices.resize(1);
        VyIntSlices.resize(1);
        VzIntSlices.resize(1);

        VxIntSlices(0) = fCore;
        VyIntSlices(0) = fCore;
        VzIntSlices(0) = fCore;
    } else if (fieldName == "Vx") {
        VyIntSlices.resize(1);

        VyIntSlices(0) = fCore;
    } else if (fieldName == "Vz") {
        VyIntSlices.resize(1);

        VyIntSlices(0) = fCore;
    }
#endif
}