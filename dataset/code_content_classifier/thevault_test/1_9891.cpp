void pqTransferFunctionEditor::SetProxyValue(const char *name,
    QList<QVariant> val,
    bool updateFlag)
{
  vtkSMProxy
      *reprProxy =
          (this->Internals->Representation ? this->Internals->Representation->getProxy()
              : NULL);
  if (!reprProxy)
    {
    return;
    }

  vtkSMProperty* Property = reprProxy->GetProperty(name);
  pqSMAdaptor::setMultipleElementProperty(Property, val);
  if (updateFlag && !this->Internals->BlockSignals)
    {
    reprProxy->UpdateVTKObjects();
    this->updateAllViews();
    }
}