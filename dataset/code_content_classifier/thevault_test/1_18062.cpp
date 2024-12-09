void MakeSingleColorImage(QImage& img, const QColor& colorbase, double opacity = 1)
{
    //Opacity representation in percentage (0, 1) i.e. (0%, 100%)
    if(opacity > 1 && opacity < 0) opacity = 1;

    img = img.convertToFormat(QImage::Format_ARGB32);
    for (int x = img.width(); x--; )
    {
        for (int y = img.height(); y--; )
        {
            const QRgb rgb = img.pixel(x, y);
            img.setPixel(x, y, qRgba(colorbase.red(), colorbase.green(), colorbase.blue(), opacity * qAlpha(rgb)));
        }
    }
}