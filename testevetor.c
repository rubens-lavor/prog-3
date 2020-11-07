#include <stdio.h>

void print_vetor(int vet, int n) {
    printf("%i\n", vet);

    int vetor[n];
    vetor[0] = vet;

    for (int i = 0; i < 10; i++) {
        printf("%i\n", vet+i);
    }

    
    for (int i = 0; i < 10; i++) {
        printf("valor %i\n", vetor[i]);
    }
    
}

int main() {
    int vetor[10];

    for (int i = 0; i < 10; i++) {
        vetor[i] = i * 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("valor %d endereço %d \n", vetor[i], &vetor[i]);
    }

    print_vetor(*vetor, 10);

    return 0;
}