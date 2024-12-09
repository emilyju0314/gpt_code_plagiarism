static const char* GetMeshOrNodeName(const FbxMesh* mesh) {
  const char* const mesh_name = mesh->GetName();
  if (mesh_name && mesh_name[0]) return mesh_name;
  const FbxNode* const node = mesh->GetNode();
  return node ? node->GetName() : nullptr;
}