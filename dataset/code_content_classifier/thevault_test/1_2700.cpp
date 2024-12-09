Intersection Segment::intersection(const Segment &s2) const
        {
            Intersection result = Intersection::ERROR;

            const Segment &s1 = *this;
            const Point u = s1.p1 - s1.p0;
            const Point v = s2.p1 - s2.p0;
            const Point w = s1.p0 - s2.p0;
            const double d = u.perp(v);
            if (std::abs(d) < epsilon_)
            {
                // they parallel, including if any is a point
                const double uPerpW = std::abs(u.perp(w));
                const double vPerpW = std::abs(v.perp(w));
                if ((uPerpW > epsilon_) || (vPerpW > epsilon_))
                {
                    result = Intersection::PARALLEL; // they are not collinear (or very near to each other)
                }
                else
                {
                    // collinear or degenerate; check if they are degenerate points
                    const double du = u.dot(u);
                    const double dv = v.dot(v);
                    if ((du < epsilon_) && (dv < epsilon_))
                    {
                        // both segments are points
                        if (s1.p0.dist(s2.p0) < epsilon_)
                        {
                            // they are the same point (or too near)
                            result = Intersection::INTERSECT;
                        }
                        else
                        {
                            result = Intersection::COLLINEAR;
                        }
                    }
                    else if (std::abs(du) < epsilon_)
                    {
                        // s1 is a single point (or a very small line)
                        if (s2.inSegment(s1.p0))
                        {
                            result = Intersection::INTERSECT; // and is part of s2
                        }
                        else
                        {
                            result = Intersection::COLLINEAR; // but is not part of s2
                        }
                    }
                    else if (std::abs(dv) < epsilon_)
                    {
                        // s2 is a single point (or a very small line)
                        if (s1.inSegment(s2.p0))
                        {
                            result = Intersection::INTERSECT; // and is part of s1
                        }
                        else
                        {
                            result = Intersection::COLLINEAR; // but is not part of s1
                        }
                    }
                    else
                    {
                        // they are collinear; check if they overlap
                        const Point w2 = s1.p1 - s2.p0;
                        double t0 = (std::abs(v.x) > epsilon_) ? (w.x / v.x) : (w.y / v.y);
                        double t1 = (std::abs(v.x) > epsilon_) ? (w2.x / v.x) : (w2.y / v.y);
                        if (t0 > t1)
                        {
                            const double temp = t0;
                            t0 = t1;
                            t1 = temp;
                        }

                        if ((t0 > 1.0) || (t1 < 0.0))
                        {
                            result = Intersection::COLLINEAR;
                        }
                        else
                        {
                            t0 = std::max(0.0, t0);
                            t1 = std::min(1.0, t1);
                            if (t0 == t1)
                            {
                                result = Intersection::INTERSECT;
                            }
                            else
                            {
                                result = Intersection::OVERLAP;
                            }
                        }
                    }
                }
            }
            else
            {
                // the segments are skew and may intersect in a point
                const double si = v.perp(w) / d;
                if ((si < lo_) || (si > hi_))
                {
                    result = Intersection::DISJOINT;
                }
                else
                {
                    const double ti = u.perp(w) / d;
                    if ((ti < lo_) || (ti > hi_))
                    {
                        result = Intersection::DISJOINT;
                    }
                    else
                    {
                        result = Intersection::INTERSECT;
                    }
                }
            }

            return result;
        }