void QVTKWidget::setDevice(vtkTDxDevice *device)
{
#ifdef Q_WS_X11
  if(this->GetInteractor()->GetDevice()!=device)
    {
    this->GetInteractor()->SetDevice(device);
    }
#else
  (void)device; // to avoid warnings.
#endif
}