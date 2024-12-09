AVL_tree Allocate_AVL_tree(void)
{
    AVL_tree  temp_pointer;

    temp_pointer = (AVL_tree) malloc(sizeof(AVL_tree_element));
    if (temp_pointer == NULL) {
      fprintf(stderr, "Out of memory in Allocate_AVL_tree!\n");
      exit(-1);
    }
    return temp_pointer;
}