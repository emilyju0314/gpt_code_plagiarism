void Tool::addTo(ViewportMainWindow *pViewPortMnWin) {
    addTo(pViewPortMnWin->workspace());
    addToPermanent(pViewPortMnWin->permanentToolBar());
    addToActive(pViewPortMnWin->activeToolBar());
    addTo(pViewPortMnWin->toolPad());
    if(!menuName().isEmpty()) {
      QMenu *menu = pViewPortMnWin->getMenu(menuName());
//      if (menu->actions().size() > 0) menu->addSeparator();
      addTo(menu);
    }

    //connect(this, SIGNAL(clearWarningSignal ()), pViewPortMnWin, SLOT(resetWarning ()));
  }