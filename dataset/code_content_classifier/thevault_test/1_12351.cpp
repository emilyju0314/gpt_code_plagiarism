bool NodeGraph::LinesIntersect(double Ax, double Ay, double Bx, double By,
        double Cx, double Cy, double Dx, double Dy,
        double* X, double* Y)
    {
        double distAB, theCos, theSin, newX, ABpos;

        //  Fail if either line segment is zero-length.
        if ((Ax == Bx && Ay == By) || (Cx == Dx && Cy == Dy))
        {
            return false;
        }

        //  Fail if the segments share an end-point.
        if ((Ax == Cx && Ay == Cy) || (Bx == Cx && By == Cy) || (Ax == Dx && Ay == Dy) || (Bx == Dx && By == Dy))
        {
            return false;
        }

        //  (1) Translate the system so that point A is on the origin.
        Bx -= Ax;
        By -= Ay;
        Cx -= Ax;
        Cy -= Ay;
        Dx -= Ax;
        Dy -= Ay;

        //  Discover the length of segment A-B.
        distAB = sqrt(Bx * Bx + By * By);

        //  (2) Rotate the system so that point B is on the positive X axis.
        theCos  = Bx / distAB;
        theSin  = By / distAB;
        newX    = Cx * theCos + Cy * theSin;
        Cy      = Cy * theCos - Cx * theSin;
        Cx      = newX;
        newX    = Dx * theCos + Dy * theSin;
        Dy      = Dy * theCos - Dx * theSin;
        Dx      = newX;

        //  Fail if segment C-D doesn't cross line A-B.
        if ((Cy < 0.0 && Dy < 0.0) || (Cy >= 0.0 && Dy >= 0.0))
        {
            return false;
        }

        //  (3) Discover the position of the intersection point along line A-B.
        ABpos = Dx + (Cx - Dx) * Dy / (Dy - Cy);

        //  Fail if segment C-D crosses line A-B outside of segment A-B.
        if (ABpos < 0.0 || ABpos > distAB)
        {
            return false;
        }

        //  (4) Apply the discovered position to line A-B in the original coordinate system.
        if (X)
        {
            *X = Ax + ABpos * theCos;
        }
        if (Y)
        {
            *Y = Ay + ABpos * theSin;
        }

        // intersection found
        return true;
    }