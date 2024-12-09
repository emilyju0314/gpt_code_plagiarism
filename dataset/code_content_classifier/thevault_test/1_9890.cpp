ImproperUseException::ImproperUseException(vtkstd::string reason)
{
    if (reason == "")
        msg = "The pipeline object is being used improperly.";
    else
        msg = "The pipeline object is being used improperly: " + reason;
}