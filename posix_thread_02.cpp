//Create a group of Posix threads from the main program

#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 10

typedef struct{
    int thread_id;
}thread_data;


//This function will be called from a thread
void *call_from_thread(void *args){
	thread_data *my_data = (thread_data *)args;
	cout<<"Launched by thread "<<my_data->thread_id<<endl;
	return NULL;
}

int main(){
	pthread_t *t = new pthread_t[NUM_THREADS];
	thread_data *td = new thread_data[NUM_THREADS];

	//Launch a group of threads
	for(int i=0;i<NUM_THREADS;i++){
		td[i].thread_id = i;
		pthread_create(&t[i],NULL,call_from_thread,(void *) &td[i]);
	}

	cout<<"Launched from the main\n";
	
	//Join the threads with the main thread
	for(int i=0;i<NUM_THREADS;i++){
		pthread_join(t[i],NULL);
	}
	
	delete [] t;
	delete [] td;
	return(0);
}
