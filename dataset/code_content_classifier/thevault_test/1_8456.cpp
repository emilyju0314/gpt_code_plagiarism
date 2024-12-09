void glut_keyboard(uint8_t _key, int32_t _x, int32_t _y) {

  if(io->WantCaptureKeyboard){
    ImGui_ImplFreeGLUT_KeyboardFunc(_key, _x, _y);
  } else {
    switch (_key) {
      //escape key
      case 27:
        exit(0);
        break;
      case '.':
        glutFullScreenToggle();
        break;
      case ' ':
        camera_->stop();
        break;
      case 'w':
        camera_->forward();
        break;
      case 's':
        camera_->back();
        break;
      default:
        break;
    }
  }
}