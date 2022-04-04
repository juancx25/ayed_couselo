#include "charset.c"

int main()
{
    char *str = "23/4+(5+2)*6-44";
    char *comp = "+-*/";

    charset_t *chs = charsetInit();
    charsetAddFromString(chs,comp);

    unsigned int count = charsetGetChCount(str,chs);
    printf("La cantidad de operadores es: %u",count);

    return 0;
}