#include "charset.c"

int main()
{
    char *str_invalido = "nombrenovalido";
    char *str_valido = "Nombre_recontra_valido_123";

    charset_t *chs = charsetInit();
    charsetAddRange(chs,'A','Z');
    charsetAddRange(chs,'a','z');
    charsetAddRange(chs,'0','9');
    charsetAddCh(chs,'-');charsetAddCh(chs,'_');

    

    return 0;
}