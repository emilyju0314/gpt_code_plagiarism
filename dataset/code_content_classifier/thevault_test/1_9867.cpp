void pqContextView::resetDisplay()
{
  vtkSMXYChartViewProxy *proxy =
      vtkSMXYChartViewProxy::SafeDownCast(this->getContextViewProxy());
  if (proxy)
    {
    proxy->GetChart()->RecalculateBounds();
    this->getWidget()->update();
    }
}