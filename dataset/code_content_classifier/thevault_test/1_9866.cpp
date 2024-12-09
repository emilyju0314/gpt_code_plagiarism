QWidget* pqContextView::getWidget()
{
  vtkSMContextViewProxy *proxy =
      vtkSMContextViewProxy::SafeDownCast(this->getProxy());
  return proxy ? proxy->GetChartWidget() : NULL;
}