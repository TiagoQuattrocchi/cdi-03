#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 4096

int read_file(char *text, char *filename);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Uso: ./readability file\n");
        return 1;
    }

    char text[MAX];

    if (read_file(text, argv[1])) {
        printf("Archivo no encontrado\n");
        return 1;
    }

    int i = 0;
    int letras = 0;
    int palabras = 1;
    int oraciones = 0;

    while(text[i])
    {   
        char c = text[i];
       
        if(isalpha(c) && c > 19 && c < 127){
            letras++;
         
        }
        if(isspace(text[i])){
            palabras++;
        }
        if(text[i]=='.' ||text[i]=='!'||text[i]=='?'){
            oraciones++;
        }
        i++;    
    }


    float s = ((float) oraciones / palabras) * 100;
    float l = ((float) letras / palabras) * 100;

    float grado = 0.0588 * l - 0.296 * s - 15.8;
 
    

    if (grado < 1) 
    {
        printf("Before grade 1");
    }
    else if (grado > 16) 
    {
        printf("Grade 16+");
    }
    else {
        printf("El grado es %d\n", (int)round(grado));
    }
    return 0;
}

int read_file(char *text, char *filename) {

    FILE *fp;
    char c;
    char full_name[30];
    
    sprintf(full_name, "texts/%s.txt", filename);
    fp = fopen(full_name, "r");
    
    if (!fp) {
        return 1;
    } 
    do
    {
        c = getc(fp);
        *text = c;
        text++;
        /* code */
    } while (c != EOF);
    text--;
    *text = '\0';

    return 0;
}
