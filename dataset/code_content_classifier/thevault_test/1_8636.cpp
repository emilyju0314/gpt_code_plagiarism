static std::vector<Gosu::Color::Channel> bitmap_to_rgb(const Gosu::Bitmap& bmp)
{
    std::vector<Gosu::Color::Channel> rgb(static_cast<std::size_t>(bmp.width() * bmp.height() * 3));
    for (std::size_t offset = 0; offset < rgb.size(); offset += 3) {
        const Gosu::Color& color = bmp.data()[offset / 3];
        if (color.alpha == 0) {
            rgb[offset + 0] = 0xff;
            rgb[offset + 1] = 0x00;
            rgb[offset + 2] = 0xff;
        } else {
            rgb[offset + 0] = color.red;
            rgb[offset + 1] = color.green;
            rgb[offset + 2] = color.blue;
        }
    }
    return rgb;
}