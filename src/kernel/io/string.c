#include <kernel/string.h>

size_t strlen(const char * _str) {
    for (size_t i=0;;i++)
        if (_str[i]==0) return i;
    return 0;
}

void* memcpy(void * _dst, const void * _src, const size_t nbytes) {
    unsigned char* dst = (unsigned char*) _dst;
	const unsigned char* src = (const unsigned char*) _src;
	for (size_t i = 0; i < nbytes; i++)
		dst[i] = src[i];
	return _dst;
}

void* memset(void * _dst, unsigned char _v, const size_t nbytes) {
    unsigned char* dst = (unsigned char*) _dst;
	for (size_t i = 0; i < nbytes; i++)
		dst[i] = _v;
	return _dst;
}
