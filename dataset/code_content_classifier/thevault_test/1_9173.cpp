static inline void reset_bitfields(tw_event *revent)
{
    if (sizeof(revent->cv) == sizeof(uint32_t)){
        *(uint32_t*)&revent->cv = 0;
    }
    else if (sizeof(revent->cv) == sizeof(uint64_t)){
        *(uint64_t*)&revent->cv = 0;
    }
    else{
        memset(&revent->cv, 0, sizeof(revent->cv));
    }
}