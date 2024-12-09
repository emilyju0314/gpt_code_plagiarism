double TimeViewPlugin::RoundDouble(double x) const
    {
        if ((std::numeric_limits<double>::max() - 0.5) <= x)
        {
            return std::numeric_limits<double>::max();
        }

        if ((-1 * std::numeric_limits<double>::max() + 0.5) > x)
        {
            return (-1 * std::numeric_limits<double>::max());
        }

        double intpart;
        double fractpart = modf(x, &intpart);

        if (fractpart >= 0.5)
        {
            return (intpart + 1);
        }
        else
        if (fractpart >= -0.5)
        {
            return intpart;
        }
        else
        {
            return (intpart - 1);
        }
    }