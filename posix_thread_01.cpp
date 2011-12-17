//Create a group of Posix threads from the main program

#include <iostream>
#include <pthread.h>

static const int num_threads = 10;

//This function will be called from a thread

void *call_from_thread(void *) {
    std::cout << "Launched by thread\n";
    return NULL;
}

int main() {
    pthread_t t[num_threads];

    //Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        pthread_create(&t[i], NULL, call_from_thread, NULL);
    }

    std::cout << "Launched from the main\n";

    //Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(t[i], NULL);
    }

    return 0;
}
