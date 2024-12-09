static bool parseStringList( const string& filename, vector<string>& gcb_l, vector<string>& rgb_l )
{
   // fail if dir
   if( is_dir( filename.c_str() ) )
   {
      cout << "Can't parse directory as string list.." << endl;
      return false;
   }
   
   // fail if file doesn't exist
   if( !file_exists(filename.c_str()) )
   {
      return false;
   }

   string prefix;
   string fname;
   
   size_t found = filename.find_last_of("/");
   if( found == string::npos )
   {
      prefix = "";
      fname = filename;
   }
   else
   {
      prefix = filename.substr(0,found);
      fname  = filename.substr(found+1);
   }
   printf("\tprefix : [%s]\n",prefix.c_str());
   printf("\tfname  : [%s]\n",fname.c_str());
   
   // open the file
   FileStorage fs(filename, FileStorage::READ);
   gcb_l.resize(0);
   rgb_l.resize(0);
   if( !fs.isOpened() )
      return false;
   
   cout << "parsing [" << filename << "]\n";

   // first load all GRAY CODE BINARY images
   FileNode gcb_images = fs["gcb_images"];
   if( gcb_images.type() == FileNode::SEQ )
   {
       FileNodeIterator gcb_it = gcb_images.begin(), gcb_it_end = gcb_images.end();
       for( ; gcb_it != gcb_it_end; ++gcb_it )
       {
          // add prefix if no slash present in path
          if( ((string)*gcb_it).find("/") == string::npos )
          {
             if( prefix != "" )
                gcb_l.push_back(prefix +"/"+ (string)*gcb_it);
             else
                gcb_l.push_back((string)*gcb_it);
             
          }
          // omit prefix if slash is present in path
          else
          {
             gcb_l.push_back((string)*gcb_it);
          }
          cout << "[" << gcb_l[gcb_l.size()-1] << "]" <<  endl;
       }
   }
   
   // next load all RGB MONOCHROME images
   FileNode rgb_images = fs["rgb_images"];
   if( rgb_images.type() == FileNode::SEQ )
   {
       FileNodeIterator rgb_it = rgb_images.begin(), rgb_it_end = rgb_images.end();
       for( ; rgb_it != rgb_it_end; ++rgb_it )
       {
          // add prefix if no slash present in path
          if( ((string)*rgb_it).find("/") == string::npos )
          {
             if( prefix != "" )
                rgb_l.push_back(prefix +"/"+ (string)*rgb_it);
             else
                rgb_l.push_back((string)*rgb_it);
             
          }
          // omit prefix if slash is present in path
          else
          {
             rgb_l.push_back((string)*rgb_it);
          }
          cout << "[" << rgb_l[rgb_l.size()-1] << "]" <<  endl;
       }
   }
   
   printf("gcb images : %d, rgb images: %d\n",(int)gcb_l.size(),(int)rgb_l.size());
   
   return true;
}