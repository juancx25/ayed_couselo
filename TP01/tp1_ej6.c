#include "charset.c"

int main()
{
    charset_t *chs1 = charsetInit();
    charset_t *chs2 = charsetInit();
    //charsetAddRange(chs1,'A','Z');
    charsetAddFromString(chs1,"AaEeIiOoUu");
    charsetPrint(chs1);
    return 0;
}