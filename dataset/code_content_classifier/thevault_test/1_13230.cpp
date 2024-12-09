bool ResetNodesForNewProcess(RenderViewHost* render_view_host,
                             FrameTreeNode* node) {
  if (render_view_host == node->current_frame_host()->render_view_host())
    node->ResetForNewProcess();
  return true;
}