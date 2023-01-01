struct nn::lmem::detail::HeapHead {
    int field_0;
    __int64 field_8;
    __int64 field_10;
    __int64 field_18;
    __int64 field_20;
    __int64 field_28;
    void *field_30;
    void *field_38;
    nn::os::MutexType mutex;
    char field_60;
    __int64 field_68;
    __int64 field_70;
    __int64 field_78;
    __int64 field_80;
    __int64 field_88;
};

struct nn::lmem::detail::HeapHead_Wrap {
    /* 0x00 */ nn::lmem::detail::HeapHead* heapHead;
    /* 0x08 */ s64 size;
}; // size = 0x10
