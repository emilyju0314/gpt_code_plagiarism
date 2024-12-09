static std::string Base64(unsigned char md[], unsigned len) {
  // encode base64
  BIO *fp = BIO_push(BIO_new(BIO_f_base64()),
                       BIO_new(BIO_s_mem()));    
  BIO_write(fp, md, len);
  BIO_ctrl(fp, BIO_CTRL_FLUSH, 0, NULL);    
  BUF_MEM *res;
  BIO_get_mem_ptr(fp, &res);   
  std::string ret(res->data, res->length - 1);
  BIO_free_all(fp);
  return ret;
}