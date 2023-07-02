#include <pthread.h>
#include <stdio.h>

int main()
{
    // Recupera l'oggetto di attributi del thread corrente
    pthread_attr_t thread_attr;
    pthread_getattr_np(pthread_self(), &thread_attr);

    // Recupera la dimensione e l'indirizzo dello stack del thread corrente
    size_t stack_size;
    void *stack_addr;
    pthread_attr_getstack(&thread_attr, &stack_addr, &stack_size);

    // Stampa le informazioni relative al thread corrente
    printf("Thread ID: %lu\n", pthread_self());
    printf("Stack size: %ld bytes\n", stack_size);
    printf("Stack address: %p\n", stack_addr);

    // Dealloca l'oggetto di attributi del thread corrente
    pthread_attr_destroy(&thread_attr);

    return 0;
}
