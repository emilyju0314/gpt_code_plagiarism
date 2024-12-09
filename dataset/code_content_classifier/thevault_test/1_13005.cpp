void LoadImplementationsRegister(void)
{
  // Loads acting on LineStress element
  REGISTER_LOAD_EX(Element2DC0LinearLineStress,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);

  // Loads acting on Beam element
  REGISTER_LOAD_EX(Element2DC1Beam,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);

  // Loads acting on QuadrilateralStress element
  REGISTER_LOAD_EX(Element2DC0LinearQuadrilateralStress,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element2DC0LinearQuadrilateralStress,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);

  // Loads acting on QuadrilateralStrain element
  REGISTER_LOAD_EX(Element2DC0LinearQuadrilateralStrain,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element2DC0LinearQuadrilateralStrain,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);

  // Loads acting on QuadrilateralMembrane element
  REGISTER_LOAD_EX(Element2DC0LinearQuadrilateralMembrane,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element2DC0LinearQuadrilateralMembrane,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);

  // Loads acting on TriangularStress element
  REGISTER_LOAD_EX(Element2DC0LinearTriangularStress,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element2DC0LinearTriangularStress,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);

  // Loads acting on TriangularStrain element
  REGISTER_LOAD_EX(Element2DC0LinearTriangularStrain,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element2DC0LinearTriangularStrain,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);

  // Loads acting on TriangularMembrane element
  REGISTER_LOAD_EX(Element2DC0LinearTriangularMembrane,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element2DC0LinearTriangularMembrane,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);

  // Loads acting on HexahedronStrain element
  REGISTER_LOAD_EX(Element3DC0LinearHexahedronStrain,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element3DC0LinearHexahedronStrain,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);

  // Loads acting on HexahedronMembrane element
  REGISTER_LOAD_EX(Element3DC0LinearHexahedronMembrane,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element3DC0LinearHexahedronMembrane,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);

  // Loads acting on Tetrahedron element
  REGISTER_LOAD_EX(Element3DC0LinearTetrahedronStrain,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element3DC0LinearTetrahedronStrain,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);
  REGISTER_LOAD_EX(Element3DC0LinearTetrahedronMembrane,LoadGravConst,LoadImplementationGenericBodyLoad::HandleLoad);
  REGISTER_LOAD_EX(Element3DC0LinearTetrahedronMembrane,LoadLandmark,LoadImplementationGenericLandmarkLoad::HandleLoad);


  // Add any additional loads here in a similar fashion...
  // Make sure that the pointer to the visit function is the correct one!!!

}