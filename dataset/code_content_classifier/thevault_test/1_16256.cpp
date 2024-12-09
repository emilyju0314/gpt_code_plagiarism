void PovrayWriter::writeCamera(ofstream& out)
    {
      /* TODO: compute adequate camera position (computation needs to be performed
         only once, same camera position will be used for all iterations) */

      /* TODO: check whether camera position and location have been specified in the
         init file, use them if present*/

      BoundingBox* box = getBoundingBox(out);
      int dow = Global::getGeo(WORLD);
      double centerx = (box->minx+box->maxx)/2.;
      double centery = (box->miny+box->maxy)/2.;
      double centerz = (box->minz+box->maxz)/2.;

      if (dow == 2)
      {
        out << "camera {" << endl;
        out << "\tlocation <" << centerx << ", " << centery << ", -3>" << endl;
        out << "\tlook_at  <" << centerx << ", " << centery << ",  0>" << endl;
        out << "}" << endl << endl;
      }
      else
      {
        out << "camera {" << endl;
        out << "\tlocation <"<< centerx <<", "<<centery<<", -3>" << endl;
        out << "\tlook_at  <"<< centerx <<", "<<centery<<",  "<<centerz<<">" << endl;
        out << "}" << endl << endl;
      }
    }