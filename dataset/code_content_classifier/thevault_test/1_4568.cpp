Value* BuilderRecorder::CreateFMed3(
    Value*        pValue1,              // [in] First value
    Value*        pValue2,              // [in] Second value
    Value*        pValue3,              // [in] Third value
    const Twine&  instName)             // [in] Name to give instruction(s)
{
    return Record(Opcode::FMed3, pValue1->getType(), { pValue1, pValue2, pValue3 }, instName);
}