#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Petugas{
    char* nama;
    char* SHIFT;
    int id;
    int skor;
} Petugas;

typedef struct PetugasArray{
    int size;
    int anggota;
    Petugas* Arr;
} PetugasArray;

PetugasArray* initialize(int size){
    PetugasArray* new = (PetugasArray*)malloc(sizeof(PetugasArray));
    new->Arr = (Petugas*)malloc(sizeof(Petugas)*size);
    new->anggota = 0;
    return new;
}

void newPetugas(PetugasArray* Array, char* nama, char* SHift, int id, int skor){
    int index = Array->anggota;
    Array->Arr[index].id = id;
    Array->Arr[index].nama = (char*)malloc(sizeof(char)*20);
    strcpy(Array->Arr[index].nama, nama);
    Array->Arr[index].SHIFT = (char*)malloc(sizeof(char)*20);
    strcpy(Array->Arr[index].SHIFT, SHift);
    Array->Arr[index].skor = skor;
    Array->anggota++;
}

void algo(PetugasArray* Array){
    char* SHIFT[3] = {"PAGI", "SIANG", "MALAM"};
    for(int i = 0; i < 3; i++){
        Petugas temp;
        temp.id = -999;
        for(int j = 0; j < Array->anggota; j++){
            if (strcmp(Array->Arr[j].SHIFT, SHIFT[i]) == 0){
                if (temp.id != -999){
                    if (Array->Arr[j].skor > temp.skor){
                        temp = Array->Arr[j];
                    } else if (Array->Arr[j].skor == temp.skor && Array->Arr[j].id < temp.id){
                        temp = Array->Arr[j];
                    } else if (Array->Arr[j].id == temp.id && strcmp(Array->Arr[j].nama, temp.nama) < 0){
                        temp = Array->Arr[j];
                    }
                } else {
                    temp = Array->Arr[j];
                }
            }
        }
        if (temp.id == -999){
            printf("%s -\n", SHIFT[i]);
        } else {
            printf("%s %s %d %d\n", SHIFT[i], temp.nama, temp.id, temp.skor);
        }
    }
}

int main(){
    int size; int id; int skor;
    char nama[30]; char SHIFT[10];
    scanf("%d", &size);
    PetugasArray* ArrayP = initialize(size);
    // printf("initsuk");
    for(int i = 0; i < size; i++){
        // scanf("%s %d %s %d", &ArrayP->Arr[i].nama, &ArrayP->Arr[i].id, &ArrayP->Arr[i].SHIFT, &ArrayP->Arr[i].skor);
        scanf("%s %d %s %d", nama, &id, SHIFT, &skor);
        newPetugas(ArrayP, nama, SHIFT, id, skor);

    }

    // for(int i = 0; i < size; i++){
    //     printf("%s %d %s %d\n", ArrayP->Arr[i].nama, ArrayP->Arr[i].id, ArrayP->Arr[i].SHIFT, ArrayP->Arr[i].skor);
    // }

    algo(ArrayP);

    return 0;
}
