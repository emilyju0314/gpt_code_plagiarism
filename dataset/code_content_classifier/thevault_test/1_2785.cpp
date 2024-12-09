void freezeSubgraph(ObjHeader* root) {
  if (root == nullptr) return;
  // First check that passed object graph has no cycles.
  // If there are cycles - run graph condensation on cyclic graphs using Kosoraju-Sharir.
  ContainerHeader* rootContainer = containerFor(root);
  if (isPermanentOrFrozen(rootContainer)) return;

  MEMORY_LOG("Run freeze hooks on subgraph of %p\n", root);

  // Note: Actual freezing can fail, but these hooks won't be undone, and moreover
  // these hooks will run again on a repeated freezing attempt.
  runFreezeHooksRecursive(root);

  MEMORY_LOG("Freeze subgraph of %p\n", root)

  #if USE_GC
    auto state = memoryState;
    // Free cyclic garbage to decrease number of analyzed objects.
    checkIfForceCyclicGcNeeded(state);
  #endif

  // Do DFS cycle detection.
  bool hasCycles = false;
  KRef firstBlocker = root->has_meta_object() && ((root->meta_object()->flags_ & MF_NEVER_FROZEN) != 0) ?
    root : nullptr;
  KStdVector<ContainerHeader*> order;
  depthFirstTraversal(rootContainer, &hasCycles, &firstBlocker, &order);
  if (firstBlocker != nullptr) {
    MEMORY_LOG("See freeze blocker for %p: %p\n", root, firstBlocker)
    ThrowFreezingException(root, firstBlocker);
  }
  ContainerHeaderSet newlyFrozen;
  // Now unmark all marked objects, and freeze them, if no cycles detected.
  if (hasCycles) {
    freezeCyclic(root, order, &newlyFrozen);
  } else {
    freezeAcyclic(rootContainer, &newlyFrozen);
  }
  MEMORY_LOG("Graph of %p is %s with %d elements\n", root, hasCycles ? "cyclic" : "acyclic", newlyFrozen.size())

#if USE_GC
  // Now remove frozen objects from the toFree list.
  // TODO: optimize it by keeping ignored (i.e. freshly frozen) objects in the set,
  // and use it when analyzing toFree during collection.
  for (auto& container : *(state->toFree)) {
    if (!isMarkedAsRemoved(container) && container->frozen()) {
      RuntimeAssert(newlyFrozen.count(container) != 0, "Must be newly frozen");
      container = markAsRemoved(container);
    }
  }
#endif
}