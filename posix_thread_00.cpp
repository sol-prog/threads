//Create a Posix thread from the main program


#include <iostream>
#include <pthread.h>

using namespace std;

//This function will be called from a thread
void *call_from_thread(void *){
	cout<<"Launched by thread"<<endl;
	return NULL;
}


int main(){
	pthread_t t;

	//Launch a thread
	pthread_create(&t,NULL,call_from_thread,NULL);
	
	//Join the thread with the main thread
	pthread_join(t,NULL);
	return(0);
}
