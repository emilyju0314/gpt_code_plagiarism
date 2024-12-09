bool
AttributeGroup::EqualTo(const AttributeGroup *atts) const
{
    // return immediately if its the same object
    if (this == atts)
       return true;

    // return immediately if it's a different type of object
    if (TypeName() != atts->TypeName())
        return false;

    int n = NumAttributes();

    for (int i=0; i<n; i++)
    {
        void *addr1   =       typeMap[i].address;
        void *addr2   = atts->typeMap[i].address;
        int   length  = typeMap[i].length;

        switch (GetFieldType(i))
        {
          case FieldType_int:
            if (!(EqualVal<int>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_intArray:
            if (!(EqualVal<int>::EqualArray(addr1,addr2,length)))
               return false;
            break;
          case FieldType_intVector:
            if (!(EqualVal<int>::EqualVector(addr1,addr2)))
               return false;
            break;
          case FieldType_bool:
            if (!(EqualVal<bool>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_boolVector:
            if (!(EqualVal<bool>::EqualVector(addr1,addr2)))
               return false;
            break;
          case FieldType_float:
            if (!(EqualVal<float>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_floatArray:
            if (!(EqualVal<float>::EqualArray(addr1,addr2,length)))
               return false;
            break;
          case FieldType_double:
            if (!(EqualVal<double>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_doubleArray:
            if (!(EqualVal<double>::EqualArray(addr1,addr2,length)))
               return false;
            break;
          case FieldType_doubleVector:
            if (!(EqualVal<double>::EqualVector(addr1,addr2)))
               return false;
            break;
          case FieldType_uchar:
            if (!(EqualVal<unsigned char>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_ucharArray:
            if (!(EqualVal<unsigned char>::EqualArray(addr1,addr2,length)))
               return false;
            break;
          case FieldType_ucharVector:
            if (!(EqualVal<unsigned char>::EqualVector(addr1,addr2)))
               return false;
            break;
          case FieldType_string:
            if (!(EqualVal<vtkstd::string>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_stringVector:
            if (!(EqualVal<vtkstd::string>::EqualVector(addr1,addr2)))
               return false;
            break;
          case FieldType_colortable:
            if (!(EqualVal<vtkstd::string>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_opacity:
            if (!(EqualVal<double>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_linestyle:
            if (!(EqualVal<int>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_linewidth:
            if (!(EqualVal<int>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_variablename:
            if (!(EqualVal<vtkstd::string>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_color:
          case FieldType_att:
            if (!(((AttributeGroup*)addr1)->EqualTo((AttributeGroup*)addr2)))
               return false;
            break;
          case FieldType_attVector:
            {
                AttributeGroupVector &a1 =*(AttributeGroupVector*)addr1;
                AttributeGroupVector &a2 =*(AttributeGroupVector*)addr2;
                if (!(EqualVal<AttributeGroup*>::EqualVector(&a1, &a2)))
                    return false;
            }
            break;
          case FieldType_enum:
            if (!(EqualVal<int>::EqualScalar(addr1,addr2)))
               return false;
            break;
          case FieldType_scalemode:
            if (!(EqualVal<int>::EqualScalar(addr1,addr2)))
               return false;
            break;
          default:
            cerr << "UNKNOWN TYPE IN AttributeGroup::EqualTo\n";
            return false;
        }
    }
    return true;
}