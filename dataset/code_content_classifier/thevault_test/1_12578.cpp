void Renderer::ApplyZoom() {
    sf::Vector2<float> fp, delta_cam;
    ScreenToWorld(cam_dest_screen, fp); // fp == cam_dest_World ??
    cam_zoom = cam_zoom*0.8 + cam_zoom_dest * 0.2;
    ScreenToWorld(cam_dest_screen, delta_cam); 
    cam_dest_world += delta_cam - fp;
    cam_world += delta_cam - fp;
    cam_world = cam_world * float(0.8) + cam_dest_world * float(0.2);
}