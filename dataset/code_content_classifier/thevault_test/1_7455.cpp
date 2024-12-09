void DragFromBackgroundtoBGoal::event_handler(Event& e) {
  if(E_DRAGGED == e) can_succeed = false;
  if(E_RELEASE == e) {
    if(M5.background.contains(e.from) && !A.contains(e.from) && !B.contains(e.from) && B.contains(e.to)) success = can_succeed;
  }
}