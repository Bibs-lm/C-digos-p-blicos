#include <stdio.h>
#include <gmp.h>    // Biblioteca para números grandes

// Declarando pra main parar de me encher o saco
void factorial_iterative(int number, mpz_t result);

int main(void) {

    int number;

    printf("Digite um número: ");

    if (scanf("%d", &number) != 1) {
        printf("Erro: entrada inválida.\n");
        return -1;
    }

    if (number < 0) {
        printf("\nErro: fatorial de número negativo.\n");
        return -1;
    }

    mpz_t result;
    mpz_init(result); // Inicializa o resultado 

    
    factorial_iterative(number, result);

    printf("Fatorial Iterativo de %d: ", number);
    mpz_out_str(stdout, 10, result);

    // Libera a memória alocada
    mpz_clear(result);

    return 0;
}

void factorial_iterative(int number, mpz_t result) {

    mpz_set_ui(result, 1); // Inicializa o resultado com 1

    for (int i = 2; i <= number; i++) {
        mpz_mul_ui(result, result, i); // Multiplica o resultado pelo número atual
    }
}
