#include "stdio.h"
#include "inttypes.h"
#include "string.h"
#include "locale.h"
uint8_t buscar_caracter_en_str(char *str, char ch);
uint8_t cantidad_caracteres_en_str(char *str, char *cmp);
int main()
{
    setlocale(LC_ALL, "spanish");

    char *str_ej1 = "Hola, este string contiene signos de puntuación; mas no son útiles pa mielda: por qué!? Ni idea.";
    char *str_ej2 = "(14+3)/7-3*4+(2/3)+5";
    char *str_ej3_0 = "esteusuarioesinvalido";
    char *str_ej3_1 = "usuarioinvalido";


    char *comparador_ej1 = ".,:;?!";
    char *comparador_ej2 = "+-/*";

    uint8_t re1 = cantidad_caracteres_en_str(str_ej1,comparador_ej1);
    uint8_t re2 = cantidad_caracteres_en_str(str_ej2,comparador_ej2);

    printf("Cantidad de signos de puntuación: %u\n",re1);
    printf("Cantidad de operadores: %u\n",re2);
    return 0;
}

//Buscar caracter en string
uint8_t buscar_caracter_en_str(char *str, char ch)
{
    uint8_t strSize = strlen(str);
    uint8_t count = 0;
    for (int i=0;i<strSize;i++)
    {
        uint8_t caca = *(str+i);
        if (ch == *(str+i))
        {
            count++;
        }
    }
    return count;
}

//Compare dos strings

uint8_t cantidad_caracteres_en_str(char *str, char *cmp)
{
    uint8_t cmpSize = strlen(cmp);
    uint8_t count = 0;
    for (int i=0;i<cmpSize;i++)
    {
        count += buscar_caracter_en_str(str,*(cmp+i));
    }
    return count;
}
