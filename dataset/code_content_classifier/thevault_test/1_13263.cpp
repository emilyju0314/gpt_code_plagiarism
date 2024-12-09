content::RenderFrameHost* InlineLoginUI::GetAuthIframe(
    content::WebContents* web_contents,
    const GURL& parent_origin,
    const std::string& parent_frame_name) {
  std::set<content::RenderFrameHost*> frame_set;
  web_contents->ForEachFrame(
      base::Bind(&AddToSetIfIsAuthIframe, &frame_set,
                 parent_origin, parent_frame_name));
  DCHECK_GE(1U, frame_set.size());
  if (!frame_set.empty())
    return *frame_set.begin();

  return NULL;
}