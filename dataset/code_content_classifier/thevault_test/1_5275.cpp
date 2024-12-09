bool ts::LNB::set(const UString& s)
{
    // Split a comma-separated string
    UStringVector values;
    s.split(values);

    // Interpret values
    bool ok = false;
    if (values.size() == 1) {
        // no high band
        ok = values[0].toInteger(_low_frequency);
        _high_frequency = _switch_frequency = 0;
    }
    else if (values.size() == 3) {
        ok = values[0].toInteger(_low_frequency) && values[1].toInteger(_high_frequency) && values[2].toInteger(_switch_frequency);
    }

    if (ok) {
        // Convert values from MHz to Hz
        _low_frequency *= 1000000;
        _high_frequency *= 1000000;
        _switch_frequency *= 1000000;
    }
    else {
        // In case of errors, all values are zero
        _low_frequency = _high_frequency = _switch_frequency = 0;
    }

    return ok;
}