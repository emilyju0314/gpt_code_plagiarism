void vtkScatterPlotPainter::RenderInternal(vtkRenderer *ren, vtkActor *actor, 
                                   unsigned long typeflags, 
                                   bool forceCompileOnly)
{
  this->Timer->StartTimer();
  if(this->GlyphMode & vtkScatterPlotMapper::UseGlyph)
    {
    this->RenderGlyphs(ren, actor, typeflags, forceCompileOnly);
    }
  else
    {
    this->RenderPoints(ren, actor, typeflags, forceCompileOnly);
    }
  this->Timer->StopTimer();
  this->TimeToDraw = this->Timer->GetElapsedTime();
}