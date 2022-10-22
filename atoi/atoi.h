#ifndef __ATOI_H__
#define __ATOI_H__

#include <stddef.h>

int Atoi(const char *str, size_t base);
int AtoiBaseTen(const char *str);

char *Itoa(int num, char *buffer, size_t base);
char *ItoaBaseTen(int num, char *buffer);

#endif /* __ATOI_H__ */