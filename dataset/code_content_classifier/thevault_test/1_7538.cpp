Fvector CControlJump::get_target(CObject *obj)
{
	u16 bone_id			= smart_cast<CKinematics*>(obj->Visual())->LL_GetBoneRoot			();
	CBoneInstance &bone = smart_cast<CKinematics*>(obj->Visual())->LL_GetBoneInstance		(bone_id);

	Fmatrix	global_transform;
	global_transform.mul	(obj->XFORM(),bone.mTransform);

	if (m_object->m_monster_type == CBaseMonster::eMonsterTypeOutdoor)
		return	(predict_position(obj, global_transform.c));
	else
		return	(global_transform.c);
}