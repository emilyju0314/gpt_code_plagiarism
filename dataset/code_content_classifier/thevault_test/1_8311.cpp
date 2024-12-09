void process_image_callback(const sensor_msgs::Image img)
{

    int red_pixel = 255;
    bool is_ball_found = false;
    int pixel_region = 0;

    // Loop through each pixel in the image and check if there's a bright white one
    // Then, identify if this pixel falls in the left, mid, or right side of the image
    // Depending on the white ball position, call the drive_bot function and pass velocities to it
    for (int i = 0; i < img.height * img.step; i += 3)
    {
        if ((img.data[i] == red_pixel) && (img.data[i + 1] == 0) && (img.data[i + 2] == 0))
        {
            pixel_region = i % img.step;

            if (pixel_region < (img.step / 3 * 2)) // Center
                drive_robot(0.5, 0);
            else if (pixel_region < img.step / 3) // Left
                drive_robot(0.5, 1.0);

            else
                drive_robot(0.5, -1); // Right
            is_ball_found = true;
            break;
        }
    }
    // Request a stop when there's no white ball seen by the camera
    if (is_ball_found == false)
        drive_robot(0, 0);
}