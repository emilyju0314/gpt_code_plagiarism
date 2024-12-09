void Renderer::ResizeWindow(const int& w, const int& h) {
    SetWindowRes(w, h);
    render_target.create(w, h);
    window.setView(sf::View {sf::FloatRect {0.0F, 0.0F, window_res.x, window_res.y}});
    frame_counter = 0;
}