void CGameResourcesExporter::GetFilesFromObjects()
{
    CUsedResources rs;
    GetIEditor()->GetObjectManager()->GatherUsedResources(rs);

    AZStd::copy(rs.files.begin(), rs.files.end(), AZStd::back_inserter(m_files));
}