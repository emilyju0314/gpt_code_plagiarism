quakelib::FloatList quakelib::SlipMap::gravity_changes(const VectorList &points, const float &lambda, const float &mu, const float &cutoff, bool free_air) {
    quakelib::FloatList gravity_changes;
    Okada block_okada;
    double gravity_change, slip, US, UD, UT, L, W, c, rake_cos, rake_sin, strike_cos, strike_sin, dip, strike, xp0, yp0, xp3, yp3, x, y, xp, yp;

    if (lambda <= 0 || mu <= 0) {
        throw std::invalid_argument("Lambda and mu must be greater than zero.");
    }

    for (VectorList::size_type point_id = 0; point_id != points.size(); point_id++) {
        gravity_changes.push_back(0.0);
    }

    for (SlippedElementList::size_type ele_id = 0; ele_id != involved_elements.size(); ele_id++) {
        slip = involved_elements[ele_id].slip();
        c = fabs(involved_elements[ele_id].max_depth());
        rake_cos = cos(involved_elements[ele_id].rake());
        rake_sin = sin(involved_elements[ele_id].rake());

        if (fabs(rake_cos) < TRIG_TOLERANCE) {
            rake_cos = 0.0;
        }

        if (fabs(rake_sin) < TRIG_TOLERANCE) {
            rake_sin = 0.0;
        }

        US = slip * rake_cos;
        UD = slip * rake_sin;
        UT = 0.0;

        L = (involved_elements[ele_id].vert(2) - involved_elements[ele_id].vert(0)).mag();
        W = (involved_elements[ele_id].vert(1) - involved_elements[ele_id].vert(0)).mag();

        dip = involved_elements[ele_id].dip();
        strike = involved_elements[ele_id].strike();

        strike_cos = cos(strike);
        strike_sin = sin(strike);

        if (fabs(strike_cos) < TRIG_TOLERANCE) {
            strike_cos = 0.0;
        }

        if (fabs(strike_sin) < TRIG_TOLERANCE) {
            strike_sin = 0.0;
        }

        xp0 = involved_elements[ele_id].vert(1)[0];
        yp0 = involved_elements[ele_id].vert(1)[1];

        xp3 = involved_elements[ele_id].implicit_vert()[0];
        yp3 = involved_elements[ele_id].implicit_vert()[1];

        /*
        std::cout << "v1: <" << involved_elements[ele_id].vert(0)[0] << ", " << involved_elements[ele_id].vert(0)[1] << ", " << involved_elements[ele_id].vert(0)[2] << ">" << std::endl;
        std::cout << "v2: <" << involved_elements[ele_id].vert(1)[0] << ", " << involved_elements[ele_id].vert(1)[1] << ", " << involved_elements[ele_id].vert(1)[2] << ">" << std::endl;
        std::cout << "v3: <" << involved_elements[ele_id].vert(2)[0] << ", " << involved_elements[ele_id].vert(2)[1] << ", " << involved_elements[ele_id].vert(2)[2] << ">" << std::endl;
        std::cout << "v4: <" << involved_elements[ele_id].implicit_vert()[0] << ", " << involved_elements[ele_id].implicit_vert()[1] << ", " << involved_elements[ele_id].implicit_vert()[2] << ">" << std::endl;
        std::cout << "L: " << L << std::endl;
        std::cout << "W: " << W << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout << "US: " << US << std::endl;
        std::cout << "UD: " << UD << std::endl;
        std::cout << "UT: " << UT << std::endl;
        std::cout << "dip: " << dip*180.0/M_PI << std::endl;
        std::cout << "rake: " << involved_elements[ele_id].rake()*180.0/M_PI << std::endl;
        std::cout << "strike: " << strike*180.0/M_PI << std::endl;
        std::cout << "xp0: " << xp0 << std::endl;
        std::cout << "yp0: " << yp0 << std::endl;
        */

        for (VectorList::size_type point_id = 0; point_id != points.size(); point_id++) {
            x = points[point_id][0];
            y = points[point_id][1];

            if (sqrt(pow((x-(xp0 + xp3)/2.0),2)+pow((y-(yp0+yp3)/2.0),2))/sqrt(L*W) > (cutoff + slip - 1.0) ) {
                gravity_change = 0.0;
            } else {

                xp = (x-xp0) * strike_sin + (y-yp0) * strike_cos;
                yp = -(x-xp0) * strike_cos + (y-yp0) * strike_sin;

                gravity_change = block_okada.calc_dg(quakelib::Vec<2>(xp,yp), c, dip, L, W, US, UD, UT, lambda, mu, free_air);

            }

            //std::cout << sqrt(pow((x-(xp0 + xp3)/2.0),2)+pow((y-(yp0 + yp3)/2.0),2))/sqrt(L*W) << " " << gravity_change << std::endl;

            gravity_changes[point_id] += gravity_change;
        }
    }

    return gravity_changes;

}