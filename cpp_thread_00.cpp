//Create a C++11 thread from the main program


#include <iostream>
#include <thread>

using namespace std;

//This function will be called from a thread
void call_from_thread(){
	cout<<"Launched by thread"<<endl;
}


int main(){
	//Launch a thread
	thread t1 = thread(call_from_thread);
	
	//Join the thread with the main thread
	t1.join();
	return(0);
}
