void
AttributeGroup::InterpolateConst(const AttributeGroup *atts1,
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

        switch (GetFieldType(i))
        {
          case FieldType_int:
            ConstInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_intArray:
            ConstInterp<int>::InterpArray(addrOut,addr1,addr2,length, f);
            break;
          case FieldType_intVector:
            ConstInterp<int>::InterpVector(addrOut,addr1,addr2,f);
            break;
          case FieldType_bool:
            ConstInterp<bool>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_boolVector:
            ConstInterp<bool>::InterpVector(addrOut,addr1,addr2,f);
            break;
          case FieldType_float:
            ConstInterp<float>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_floatArray:
            ConstInterp<float>::InterpArray(addrOut,addr1,addr2,length, f);
            break;
          case FieldType_double:
            ConstInterp<double>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_doubleArray:
            ConstInterp<double>::InterpArray(addrOut,addr1,addr2,length, f);
            break;
          case FieldType_doubleVector:
            ConstInterp<double>::InterpVector(addrOut,addr1,addr2,f);
            break;
          case FieldType_uchar:
            ConstInterp<unsigned char>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_ucharArray:
            ConstInterp<unsigned char>::InterpArray(addrOut,addr1,addr2,length, f);
            break;
          case FieldType_ucharVector:
            ConstInterp<unsigned char>::InterpVector(addrOut,addr1,addr2,f);
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
            ConstInterp<double>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_linestyle:
            ConstInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_linewidth:
            ConstInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_variablename:
            ConstInterp<vtkstd::string>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_color:
          case FieldType_att:
            ((AttributeGroup*)addrOut)->
                                   InterpolateConst((AttributeGroup*)addr1,
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
                ConstInterp<AttributeGroup*>::InterpVector(&out, &a1, &a2, f);
            }
            break;
          case FieldType_enum:
            ConstInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          case FieldType_scalemode:
            ConstInterp<int>::InterpScalar(addrOut,addr1,addr2,f);
            break;
          default:
            cerr << "UNKNOWN TYPE IN AttributeGroup::InterpolateConst\n";
            break;
        }
    }
}