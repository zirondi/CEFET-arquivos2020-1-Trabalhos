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

void printRegistro(Registro* r) {
    printf("Id: %.i\n", r->id_inscricao);
    printf("Curso: %.20s\n", r->curso);
    printf("CPF: %.15s\n", r->cpf);
    printf("Data Nacimento: %.11s\n", r->dataNacimento);
    printf("Sexo: %c \n", r->sexo);
    printf("Email: %.40s\n", r->email);
    printf("Opcao Quadro: %c\n", r->opcaoQuadro);
}

void printCPF(Registro* r) {
    printf("CPF: %.15s\n", r->cpf);
}

int compara(const void* r1, const void* r2)
{
    return ((Registro*)r1)->id_inscricao > ((Registro*)r2)->id_inscricao;
}




int main() {
    FILE *entrada, *saida;
    Registro registro1, registro2;
    long count = 0, qtd;

    //Abrindo os arquivos
    entrada = fopen("./candidatos.dat", "rb");
    saida = fopen("./candidatos_saida.dat", "wb");
    
    qtd = fread(&registro1, sizeof(Registro), 1, entrada);

    while (qtd > 0) {
        qtd = fread(&registro2, sizeof(Registro), 1, entrada);

        if ((strcmp(registro1.cpf, registro2.cpf) == 0) && qtd) {
            if (registro2.id_inscricao > registro1.id_inscricao) {
                registro1 = registro2;
            }
        }
        else {
            fwrite(&registro1, sizeof(Registro), 1, saida);
            registro1 = registro2;
        }
        count++;
    }
    
    if (count > 0) {
        fwrite(&registro1, sizeof(Registro), 1, saida);
    }
    
    fclose(entrada);
    fclose(saida);
}