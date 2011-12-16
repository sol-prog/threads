//Create a group of Posix threads from the main program

#include <iostream>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 10

//This function will be called from a thread
void *call_from_thread(void *){
	cout<<"Launched by thread\n";
	return NULL;
}

int main(){
	pthread_t *t = new pthread_t[NUM_THREADS];

	//Launch a group of threads
	for(int i=0;i<NUM_THREADS;i++){
		pthread_create(&t[i],NULL,call_from_thread,NULL);
	}

	cout<<"Launched from the main\n";
	
	//Join the threads with the main thread
	for(int i=0;i<NUM_THREADS;i++){
		pthread_join(t[i],NULL);
	}
	
	delete [] t;
	return(0);
}
