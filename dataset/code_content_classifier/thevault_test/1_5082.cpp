void ts::TeletextDescriptor::Entry::setFullNumber(uint8_t teletext_magazine_number, uint8_t teletext_page_number)
{
    page_number =
        100 * uint16_t(teletext_magazine_number == 0 ? 8 : teletext_magazine_number) +
        10 * uint16_t(teletext_page_number >> 4) +
        uint16_t(teletext_page_number & 0x0F);
}