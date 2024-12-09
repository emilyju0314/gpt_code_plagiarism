void milkcat_yyrestart  (FILE * input_file , yyscan_t yyscanner)
{
    struct yyguts_t * yyg = (struct yyguts_t*)yyscanner;

	if ( ! YY_CURRENT_BUFFER ){
        milkcat_yyensure_buffer_stack (yyscanner);
		YY_CURRENT_BUFFER_LVALUE =
            milkcat_yy_create_buffer(yyin,YY_BUF_SIZE ,yyscanner);
	}

	milkcat_yy_init_buffer(YY_CURRENT_BUFFER,input_file ,yyscanner);
	milkcat_yy_load_buffer_state(yyscanner );
}