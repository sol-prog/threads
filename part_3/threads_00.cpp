//Use a member function in a thread

#include <iostream>
#include <thread>
#include <string>

using namespace std;

class SaylHello{
public:

  //This function will be called from a thread
  void func(const string &name) {
     cout <<"Hello " << name << endl;
  };
};

int main(int argc, char* argv[])
{
  SaylHello x;

  //Use a member function in a thread
  thread t(&SaylHello::func, &x, "Tom");

  //Join the thread with the main thread
  t.join();

  return 0;
}
