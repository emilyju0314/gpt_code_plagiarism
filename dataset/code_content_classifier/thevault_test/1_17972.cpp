GBool CharOutputDev::beginType3Char(GfxState *state, double x, double y, double dx, double dy, CharCode charid, Unicode *u, int uLen)
{
    msg("<debug> beginType3Char %d u=%d", charid, uLen?u[0]:0);
    type3active = 1;
    
    if(config_extrafontdata) {

	FontInfo*current_fontinfo = info->getFontInfo(state);
	if(!current_fontinfo) {
	    msg("<error> Couldn't find font info");
	    return gFalse;
	}
	gfxfont_t*current_gfxfont = current_fontinfo->getGfxFont();

	/*m.m00*=INTERNAL_FONT_SIZE;
	m.m01*=INTERNAL_FONT_SIZE;
	m.m10*=INTERNAL_FONT_SIZE;
	m.m11*=INTERNAL_FONT_SIZE;*/

	if(!current_fontinfo || (unsigned)charid >= current_fontinfo->num_glyphs || !current_fontinfo->glyphs[charid]) {
	    msg("<error> Invalid type3 charid %d for font %p", charid, current_fontinfo);
	    return gFalse;
	}
	gfxcolor_t col={0,0,0,0};
	CharCode glyphid = current_fontinfo->glyphs[charid]->glyphid;
	gfxmatrix_t m = current_fontinfo->get_gfxmatrix(state);
	this->transformXY(state, 0, 0, &m.tx, &m.ty);
	device->drawchar(device, current_gfxfont, glyphid, &col, &m);
    }


    /* the character itself is going to be passed using the draw functions */
    return gFalse; /* gTrue= is_in_cache? */
}