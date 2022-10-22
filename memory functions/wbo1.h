#ifndef __WBO1_H__
#define __WBO1_H__

#include <stddef.h> /* size_t */

void *Memset(void *dest, int c, size_t size_to_fill);
void *Memcpy(void *dest, const void *source, size_t size_to_copy);
void *Memmove(void *dest, const void *source, size_t size_to_copy);



#endif
