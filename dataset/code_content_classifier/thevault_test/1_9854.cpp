void
AttributeGroup::InterpolateLinear(const AttributeGroup *atts1,
                                  const AttributeGroup *atts2, double f)
{
    SelectAll();
    int n = NumAttributes();

    for (int i=0; i<n; i++)
    {
        if (!typeMap[i].selected)
            continue;

        void *addrOut = typeMap[i].address;
        void *addr1   = atts1->typeMap[i].address;
        void *addr2   = atts2->typeMap[i].address;
        int   length  = typeMap[i].length;

        if (addrOut == NULL || addr1 == NULL || addr2 == NULL)
            continue;

        switch (GetFieldType(i))
        {
          case FieldType_int:
            LinInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_intArray:
            LinInterp<int>::InterpArray(addrOut,addr1,addr2,length, f);
            break;
          case FieldType_intVector:
            LinInterp<int>::InterpVector(addrOut,addr1,addr2,f);
            break;
          case FieldType_bool:
            ConstInterp<bool>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_boolVector:
            ConstInterp<bool>::InterpVector(addrOut,addr1,addr2,f);
            break;
          case FieldType_float:
            LinInterp<float>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_floatArray:
            LinInterp<float>::InterpArray(addrOut,addr1,addr2,length, f);
            break;
          case FieldType_double:
            LinInterp<double>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_doubleArray:
            LinInterp<double>::InterpArray(addrOut,addr1,addr2,length, f);
            break;
          case FieldType_doubleVector:
            LinInterp<double>::InterpVector(addrOut,addr1,addr2,f);
            break;
          case FieldType_uchar:
            LinInterp<unsigned char>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_ucharArray:
            LinInterp<unsigned char>::InterpArray(addrOut,addr1,addr2,length, f);
            break;
          case FieldType_ucharVector:
            LinInterp<unsigned char>::InterpVector(addrOut,addr1,addr2,f);
            break;
          case FieldType_string:
            ConstInterp<vtkstd::string>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_stringVector:
            ConstInterp<vtkstd::string>::InterpVector(addrOut,addr1,addr2,f);
            break;
          case FieldType_colortable:
            ConstInterp<vtkstd::string>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_opacity:
            LinInterp<double>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_linestyle:
            ConstInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_linewidth:
            LinInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_variablename:
            ConstInterp<vtkstd::string>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_color:
          case FieldType_att:
            ((AttributeGroup*)addrOut)->
                                  InterpolateLinear((AttributeGroup*)addr1,
                                                    (AttributeGroup*)addr2, f);
            break;
          case FieldType_attVector:
            {
                AttributeGroupVector &out=*(AttributeGroupVector*)addrOut;
                AttributeGroupVector &a1 =*(AttributeGroupVector*)addr1;
                AttributeGroupVector &a2 =*(AttributeGroupVector*)addr2;
                int l0 = static_cast<int>(out.size());
                int l1 = static_cast<int>(a1.size());
                int l2 = static_cast<int>(a2.size());
                int lmax = (l1 > l2) ? l1 : l2;
                out.resize(lmax);
                if (lmax > l0)
                {
                    for (int j=l0; j<lmax; j++)
                    {
                        out[j] = CreateSubAttributeGroup(i);
                    }
                }
                LinInterp<AttributeGroup*>::InterpVector(&out, &a1, &a2, f);
            }
            break;
          case FieldType_enum:
            ConstInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_scalemode:
            ConstInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          default:
            cerr << "UNKNOWN TYPE IN AttributeGroup::InterpolateLinear\n";
            break;
        }
    }
}