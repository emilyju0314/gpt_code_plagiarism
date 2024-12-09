BOOL CBasicCPU1EAX::OnInitDialog()
    {
     CLeaves::OnInitDialog();

     SETRESERVEDCOLOR(Reserved_31_28);

     c_ExtendedFamilyID.SetBkColor(RGB(255,255,0));
     x_ExtendedFamilyID.SetBkColor(c_ExtendedFamilyID.GetBkColor());

     c_ExtendedModelID.SetBkColor(RGB(255,128,255));
     x_ExtendedModelID.SetBkColor(c_ExtendedModelID.GetBkColor());

     c_FamilyID.SetBkColor(c_ExtendedFamilyID.GetBkColor());
     x_FamilyID.SetBkColor(c_FamilyID.GetBkColor());

     c_Model.SetBkColor(c_ExtendedModelID.GetBkColor());
     x_Model.SetBkColor(c_Model.GetBkColor());

     c_SteppingID.SetBkColor(RGB(255,179,102));
     x_SteppingID.SetBkColor(c_SteppingID.GetBkColor());
     return TRUE;  // return TRUE unless you set the focus to a control
    }