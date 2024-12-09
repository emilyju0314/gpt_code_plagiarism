void splay(Vertex*& root, Vertex* v) {
  // DebugStream() << "    splaying ";  
  if (v == NULL) return;

  // DebugStream() << v->key << " on top of ";
  // if(root != nullptr)
  // {
    // DebugStream() << root-> key << std::endl;
  // }

  while (v->parent != NULL) {
    if (v->parent->parent == NULL) {
      // DebugStream() << "    small_rotation" << std::endl;
      small_rotation(v);
      break;
    }
    // DebugStream() << "    big_rotation" << std::endl;
    big_rotation(v);
  }

  // DebugStream() << "    changing root" << std::endl;
  root = v;
}