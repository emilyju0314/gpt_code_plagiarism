int raConfig::findKey( const char * fieldName )
{
    for(int i = 0; i < this->length; i++ ) {
        if( strcmp( this->fields[i], fieldName )== 0 ) {
            return i;
        }
    }
    return -1;
}