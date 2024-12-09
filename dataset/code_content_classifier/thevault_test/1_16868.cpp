static inline int check_pixel(JaniceConstImage image,
                               uint32_t x,
                               uint32_t y,
                               uint8_t red,
                               uint8_t green,
                               uint8_t blue)
{
    // Variable to hold pixel values
    uint8_t pixel;

    // Check the blue pixel first, remember OpenCV stores images in BGR order
    CHECK(abs(int(janice_image_access(image, 0, y, x)) - int(blue)) < 10,
          "Blue pixel doesn't match.",
          // Cleanup
          [](){})

    // Check the green pixel
    CHECK(abs(int(janice_image_access(image, 1, y, x)) - int(green)) < 10,
          "Green pixel doesn't match.",
          // Cleanup
          [](){})

    // Check the red pixel
    CHECK(abs(int(janice_image_access(image, 2, y, x)) - int(red)) < 10,
          "Red pixel doesn't match.",
          // Cleanup
          [](){})

    return 0;
}