#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pthread_attr_t attr;
    size_t stack_size;
    void *stack_addr;

    // inizializza l'attributo per il thread corrente
    pthread_attr_init(&attr);

    // ottiene l'indirizzo di inizio dello stack e la dimensione dello stack del thread corrente
    pthread_getattr_np(pthread_self(), &attr);
    pthread_attr_getstack(&attr, &stack_addr, &stack_size);

    // calcola la dimensione effettiva dello stack
    size_t actual_stack_size = (char *)stack_addr - (char *)(stack_addr + stack_size);

    printf("Dimensione dello stack del thread: %zu byte\n", actual_stack_size);
    printf("Indirizzo dello stack: %p\n", actual_stack_size);
    printf("Dimensione dello stack: %zu byte\n", actual_stack_size);

    return 0;
}
