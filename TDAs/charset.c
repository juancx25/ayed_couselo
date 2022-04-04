#include "charset.h"

charset_t* charsetInit()
{
    charset_t *charset = (charset_t *)calloc(1,sizeof(charset_t));
    return charset;
}

void charsetFree(charset_t* charset)
{
    free(charset);
    return;
}

void charsetAddCh(charset_t* charset,unsigned char pos)
{
    charset->v[pos] = 1;
    return;
}

void charsetRemoveCh(charset_t* charset,unsigned char pos)
{
    charset->v[pos] = 0;
    return;
}

void charsetAddRange(charset_t* charset,unsigned char pos_from,unsigned char pos_to)
{
    for (int i=pos_from;i<pos_to;i++)
    {
        charsetAddCh(charset,i);
    }
}

void charsetAddFromString(charset_t* charset,char *str)
{
    int strSize = strlen(str);
    for (int i=0;i<strSize;i++)
    {
        charsetAddCh(charset,str[i]);
    }
}

charset_t* charsetLink(charset_t *chs1,charset_t *chs2)
// OR gate (A+B)
{
    for (int i=0;i<MAX_CHAR_SIZE;i++)
    {
        chs1->v[i] = chs1->v[i] | chs2->v[i];
    }
    charsetFree(chs2);
    return chs1;
}

charset_t* charsetJunction(charset_t *chs1,charset_t *chs2)
// AND gate (AB)
{
    for (int i=0;i<MAX_CHAR_SIZE;i++)
    {
        chs1->v[i] = chs1->v[i] & chs2->v[i];
    }
    charsetFree(chs2);
    return chs1;
}

charset_t* charsetDiff(charset_t *chs1,charset_t *chs2)
// A*B'
{
    for (int i=0;i<MAX_CHAR_SIZE;i++)
    {
        chs1->v[i] = chs1->v[i] & !(chs2->v[i]);
    }
    charsetFree(chs2);
    return chs1;
}

void charsetPrint(charset_t *charset)
{
    for (int i=0;i<MAX_CHAR_SIZE;i++)
    {
        if (charset->v[i] == 1) printf("%c\n",i);
    }
    return;
}

unsigned int charsetGetChCount(char *str,charset_t *charset)
{
    unsigned int strSize = strlen(str);
    unsigned int count = 0;
    for (int i=0;i<strSize;i++)
    {
        for (int j=0;j<MAX_CHAR_SIZE;j++)
        {
            if ((charset->v[j] == 1) && (str[i] == j)) count++;
        }
    }
    return count;
}

//unsigned int charsetFindChar