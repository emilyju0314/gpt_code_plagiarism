aura::Window* GetContainer(aura::Window* window) {
  // No containers for NULL or the root window itself.
  if (!window || !window->parent())
    return NULL;
  if (window->parent()->IsRootWindow())
    return window;
  return GetContainer(window->parent());
}