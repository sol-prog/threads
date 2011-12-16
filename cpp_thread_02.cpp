//Create a group of C++11 threads from the main program

#include <iostream>
#include <thread>

using namespace std;

#define NUM_THREADS 10

//This function will be called from a thread
void call_from_thread(int tid){
	cout<<"Launched by thread "<<tid<<endl;
}

int main(){
	thread *t = new thread[NUM_THREADS];

	//Launch a group of threads
	for(int i=0;i<NUM_THREADS;i++){
		t[i] = thread(call_from_thread,i);
	}
	
	cout<<"Launched from the main\n";
		
	//Join the threads with the main thread
	for(int i=0;i<NUM_THREADS;i++){
		t[i].join();
	}

	delete [] t;
	return(0);
}
