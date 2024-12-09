PackageMergeImpl::PackageMergeImpl(std::weak_ptr<uml::Package > par_receivingPackage)
:PackageMergeImpl()
{
	m_receivingPackage = par_receivingPackage;
	m_owner = par_receivingPackage;
}