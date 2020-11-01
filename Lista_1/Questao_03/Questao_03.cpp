#include <iostream>
#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

#pragma pack(1)
#pragma warning(suppress : 26)

typedef struct _Registro Registro;

struct _Registro {
    int id_inscricao;
    char curso[20];
    char cpf[15];
    char dataNacimento[11];
    char sexo;
    char email[40];
    char opcaoQuadro;
};


void printEmail(Registro* r) {
    printf("Email: %.15s\n", r->email)  ;
}

int compara(const void* r1, const void* r2)
{
    return ((Registro*)r1)->id_inscricao > ((Registro*)r2)->id_inscricao;
}


int main() {
    FILE* candidatosA, * candidatosB;
    Registro registroA, registroB;
    long count = 0, qtdA, qtdB;
    int contador = 0;

    //Abrindo os arquivos
    candidatosA = fopen("C:/Users/Convidado/Desktop/2020-1/Arquivos/CEFET-arquivos2020-1-Trabalhos/Lista_1/Questao_03/candidatosA.dat", "rb");
    candidatosB = fopen("C:/Users/Convidado/Desktop/2020-1/Arquivos/CEFET-arquivos2020-1-Trabalhos/Lista_1/Questao_03/candidatosB.dat", "rb");

    
    qtdA = fread(&registroA, sizeof(Registro), 1, candidatosA);

    while (qtdA > 0) {
        qtdB = fread(&registroB, sizeof(Registro), 1, candidatosB);

        while (qtdB > 0) {
            if (strcmp(registroA.cpf, registroB.cpf) == 0) {
                printEmail(&registroA);
                break;
            }
            qtdB = fread(&registroB, sizeof(Registro), 1, candidatosB);
        }
        fseek(candidatosB, 0, SEEK_SET);
        qtdA = fread(&registroA, sizeof(Registro), 1, candidatosA);
    }

    fclose(candidatosA);
    fclose(candidatosB);
}