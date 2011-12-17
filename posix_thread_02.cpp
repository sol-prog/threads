//Create a group of Posix threads from the main program

#include <iostream>
#include <pthread.h>

static const int num_threads = 10;

typedef struct {
    int thread_id;
} thread_data;

//This function will be called from a thread

void *call_from_thread(void *args) {
    thread_data *my_data = (thread_data *) args;
    std::cout << "Launched by thread " << my_data->thread_id << std::endl;
    return NULL;
}

int main() {
    pthread_t t[num_threads];
    thread_data td[num_threads];

    //Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        td[i].thread_id = i;
        pthread_create(&t[i], NULL, call_from_thread, (void *) &td[i]);
    }

    std::cout << "Launched from the main\n";

    //Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(t[i], NULL);
    }

    return 0;
}
