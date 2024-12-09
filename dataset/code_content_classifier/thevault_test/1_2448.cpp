void IpcressDataTable::setIpcressDataTypeKey() const {
  // Build the Ipcress key for the requested data.  Valid keys are: { ramg,
  // rsmg, rtmg, pmg, rgray, ragray, rsgray, pgray }

  if (opacityEnergyDescriptor == "gray") {
    switch (opacityModel) {
    case (rtt_cdi::ROSSELAND):

      switch (opacityReaction) {
      case (rtt_cdi::TOTAL):
        ipcressDataTypeKey = "rgray";
        dataDescriptor = "Gray Rosseland Total";
        break;
      case (rtt_cdi::ABSORPTION):
        ipcressDataTypeKey = "ragray";
        dataDescriptor = "Gray Rosseland Absorption";
        break;
      default:
        Assert(false);
        break;
      }
      break;

    case (rtt_cdi::PLANCK):

      switch (opacityReaction) {
      case (rtt_cdi::ABSORPTION):
        ipcressDataTypeKey = "pgray";
        dataDescriptor = "Gray Planck Absorption";
        break;
      default:
        Assert(false);
        break;
      }
      break;

    default:
      Assert(false);
      break;
    }
  } else // "mg"
  {
    switch (opacityModel) {
    case (rtt_cdi::ROSSELAND):

      switch (opacityReaction) {
      case (rtt_cdi::TOTAL):
        ipcressDataTypeKey = "rtmg";
        dataDescriptor = "Multigroup Rosseland Total";
        break;
      case (rtt_cdi::ABSORPTION):
        ipcressDataTypeKey = "ramg";
        dataDescriptor = "Multigroup Rosseland Absorption";
        break;
      case (rtt_cdi::SCATTERING):
        ipcressDataTypeKey = "rsmg";
        dataDescriptor = "Multigroup Rosseland Scattering";
        break;
      default:
        Assert(false);
        break;
      }
      break;

    case (rtt_cdi::PLANCK):

      switch (opacityReaction) {
      case (rtt_cdi::ABSORPTION):
        ipcressDataTypeKey = "pmg";
        dataDescriptor = "Multigroup Planck Absorption";
        break;
      default:
        Assert(false);
        break;
      }
      break;

    default:
      Assert(false);
      break;
    }
  }

  // Verify that the requested opacity type is available in the IPCRESS file.
  Insist(key_available(ipcressDataTypeKey, fieldNames),
         "requested opacity type is not available in the IPCRESS file.");
}