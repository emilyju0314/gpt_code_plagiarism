vec2 InputSystem::ConvertHatToVector(uint32_t hat_enum) const {
  switch (hat_enum) {
    case SDL_HAT_LEFTUP:
      return vec2(-1, -1);
    case SDL_HAT_UP:
      return vec2(0, -1);
    case SDL_HAT_RIGHTUP:
      return vec2(1, -1);
    case SDL_HAT_LEFT:
      return vec2(-1, 0);
    case SDL_HAT_CENTERED:
      return vec2(0, 0);
    case SDL_HAT_RIGHT:
      return vec2(1, 0);
    case SDL_HAT_LEFTDOWN:
      return vec2(-1, 1);
    case SDL_HAT_DOWN:
      return vec2(0, 1);
    case SDL_HAT_RIGHTDOWN:
      return vec2(1, 1);
    default:
      LogError(
          kApplication,
          "InputSystem::ConvertHatToVector: Unknown SDL Hat Enum Value!\n");
      return vec2(0, 0);
  }
}