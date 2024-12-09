bool Adafruit_USBD_Device::addInterface(Adafruit_USBD_Interface& itf)
{
  uint8_t* desc = _desc_cfg+_desc_cfg_len;
  uint16_t const len = itf.getInterfaceDescriptor(_itf_count, desc, _desc_cfg_maxlen-_desc_cfg_len);
  uint8_t* desc_end = desc+len;

  const char* desc_str = itf.getStringDescriptor();

  if ( !len ) return false;

  // Parse interface descriptor to update
  // - Interface Number & string descriptor
  // - Endpoint address
  while (desc < desc_end)
  {
    if (desc[1] == TUSB_DESC_INTERFACE)
    {
      tusb_desc_interface_t* desc_itf = (tusb_desc_interface_t*) desc;
      if (desc_itf->bAlternateSetting == 0)
      {
        _itf_count++;
        if (desc_str && (_desc_str_count < STRING_DESCRIPTOR_MAX) )
        {
          _desc_str_arr[_desc_str_count] = desc_str;
          desc_itf->iInterface = _desc_str_count;
          _desc_str_count++;

          // only assign string index to first interface
          desc_str = NULL;
        }
      }
    }else if (desc[1] == TUSB_DESC_ENDPOINT)
    {
      tusb_desc_endpoint_t* desc_ep = (tusb_desc_endpoint_t*) desc;
      desc_ep->bEndpointAddress |= (desc_ep->bEndpointAddress & 0x80) ? _epin_count++ : _epout_count++;
    }

    if (desc[0] == 0) return false;
    desc += desc[0]; // next
  }

  _desc_cfg_len += len;

  // Update configuration descriptor
  tusb_desc_configuration_t* config = (tusb_desc_configuration_t*)_desc_cfg;
  config->wTotalLength = _desc_cfg_len;
  config->bNumInterfaces = _itf_count;

  return true;
}