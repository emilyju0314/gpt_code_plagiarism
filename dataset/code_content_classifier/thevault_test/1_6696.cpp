double TfrcAgent::rfc3390(int )
{
        if (size_ <= 1095) {
                return (4.0);
        } else if (size_ < 2190) {
                return (3.0);
        } else {
                return (2.0);
        }
}