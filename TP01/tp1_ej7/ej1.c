#include "charset.c"

int main()
{
    char *str = "Hola, este string contiene signos de puntuación; mas no son útiles pa mielda: por qué!? Ni idea.";
    char *comp = ".,:;!?";
    charset_t *chs = charsetInit();

    charsetAddFromString(chs,comp);
    //charsetPrint(chs);

    unsigned int respuesta = charsetGetChCount(str,chs);
    printf("La cantidad de signos de puntuación es de: %u",respuesta);
    return 0;
}
