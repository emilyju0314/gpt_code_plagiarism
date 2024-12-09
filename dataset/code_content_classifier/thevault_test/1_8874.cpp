static CS_RETCODE
run_command(CS_COMMAND *cmd, const char *sql, CS_INT *rowcount)
{
	CS_RETCODE ret;

	if (cmd == NULL) {
		return CS_FAIL;
	}

	ret = ct_command(cmd, CS_LANG_CMD, (CS_VOID *)sql, CS_NULLTERM, CS_UNUSED);
	if (ret != CS_SUCCEED) {
		return ret;
	}
	ret = ct_send(cmd);
	if (ret != CS_SUCCEED) {
		return ret;
	}

	return handle_returns(cmd, rowcount);
}