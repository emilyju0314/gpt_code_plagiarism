bool Polygon::isComplex(const Vertices &polygon)
        {
            bool isComplex = false;

            const int n = polygon.size();
            for (int i = 0; !isComplex && (i < n); i++)
            {
                const int j = i + 1;
                for (int k = j; !isComplex && (k < n); k++)
                {
                    const int l = (k + 1 < n) ? (k + 1) : 0;
                    const Segment s0(polygon[i], polygon[j]);
                    const Segment s1(polygon[k], polygon[l]);
                    const bool adjacent = (k == j) || (l == i);
                    const Intersection itc = s0.intersection(s1);
                    if (adjacent)
                    {
                        isComplex = (itc == Intersection::OVERLAP);
                    }
                    else
                    {
                        isComplex = (itc == Intersection::INTERSECT) || (itc == Intersection::OVERLAP);
                    }
                }
            }

            return isComplex;
        }