Vertex* find(Vertex*& root, int key) {
  // DebugStream() << "    finding " << key << std::endl;
  // DebugStream() << "        before----------------------" << std::endl;
  // printTree(root, 4);

  if( root!= nullptr && root->key == key) return root;

  Vertex* v = root;
  Vertex* last = root;
  Vertex* next = NULL;
  while (v != NULL) {
    if (v->key >= key && (next == NULL || v->key < next->key)) {
      next = v;
    }
    last = v;
    if (v->key == key) {
      break;      
    }
    if (v->key < key) {
      v = v->right;
    } else {
      v = v->left;
    }
  }
  // if( last != nullptr) DebugStream() << "    last is " << last->key <<std::endl;
  splay(root, last);
  // DebugStream() << "      after----------------------" << std::endl;
  // printTree(root, 4);

  return next;
}