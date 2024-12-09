bool QVTKWidget::event(QEvent* e)
{
  if(e->type() == QEvent::ParentAboutToChange)
    {
    this->markCachedImageAsDirty();
    if (this->mRenWin)
      {
      // Finalize the window to remove graphics resources associated with
      // this window
      if(this->mRenWin->GetMapped())
        {
        this->mRenWin->Finalize();
        }
      }
    }
  else if(e->type() == QEvent::ParentChange)
    {
    if(this->mRenWin)
      {
      x11_setup_window();
      // connect to new window
      this->mRenWin->SetWindowId( reinterpret_cast<void*>(this->winId()));

      // start up the window to create graphics resources for this window
      if(isVisible())
        {
        this->mRenWin->Start();
        }
      }
    }
  
  if(QObject::event(e))
    {
    return TRUE;
    }

  if(e->type() == QEvent::KeyPress)
    {
    QKeyEvent* ke = static_cast<QKeyEvent*>(e);
    this->keyPressEvent(ke);
    return ke->isAccepted();
    }

  return QWidget::event(e);
}