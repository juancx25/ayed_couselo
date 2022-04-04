#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define MAX_CHAR_SIZE 256

typedef struct
{
    unsigned char v[MAX_CHAR_SIZE];
} charset_t;


charset_t* charsetInit();

void charsetFree(charset_t* charset);

void charsetAddCh(charset_t* charset,unsigned char pos);

void charsetRemoveCh(charset_t* charset,unsigned char pos);

void charsetAddRange(charset_t* charset,unsigned char pos_from,unsigned char pos_to);

void charsetAddFromString(charset_t* charset,char *str);

charset_t* charsetLink(charset_t *chs1,charset_t *chs2);
charset_t* charsetJunction(charset_t *chs1,charset_t *chs2);

charset_t* charsetDiff(charset_t *chs1,charset_t *chs2);

void charsetPrint(charset_t *charset);

unsigned int charsetGetChCount(char *str,charset_t *charset);
