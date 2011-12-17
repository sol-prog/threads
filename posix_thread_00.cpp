//Create a Posix thread from the main program

#include <iostream>
#include <pthread.h>

//This function will be called from a thread

void *call_from_thread(void *) {
    std::cout << "Launched by thread" << std::endl;
    return NULL;
}

int main() {
    pthread_t t;

    //Launch a thread
    pthread_create(&t, NULL, call_from_thread, NULL);

    //Join the thread with the main thread
    pthread_join(t, NULL);

    return 0;
}
