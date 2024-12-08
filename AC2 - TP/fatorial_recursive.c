#include <stdio.h>
#include <gmp.h>    // Biblioteca para números grandes

// Declaração da função
void factorial_recursive(int number, mpz_t result);

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

    factorial_recursive(number, result);

    printf("Fatorial Recursivo de %d: ", number);
    mpz_out_str(stdout, 10, result);

    // Libera a memória alocada
    mpz_clear(result);

    return 0;
}

void factorial_recursive(int number, mpz_t result) {

    if (number == 0 || number == 1) {

        mpz_set_ui(result, 1); // Base case: fatorial de 0 ou 1 é 1
    } 
    else {
        mpz_t temp;
        mpz_init(temp);

        factorial_recursive(number - 1, temp); // Chamada recursiva
        mpz_mul_ui(result, temp, number); // Multiplica o resultado

        mpz_clear(temp); // Libera a memória temporária
    }
}
