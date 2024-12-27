#include <iostream>
#include <thread>
#include <mutex>
#include <SimpleTimer.h>
using namespace std;

recursive_mutex rm;

void Foo(int a)
{
    rm.lock();
    cout << a << " ";
    this_thread::sleep_for(chrono::milliseconds(300));

    if (a <= 1)
    {
        cout << endl;
        rm.unlock();
        return;
    }
    a--;
    Foo(a);
    rm.unlock();
}

int main()
{

    thread t1(Foo, 10);
    // this_thread::sleep_for(chrono::milliseconds(600));
    thread t2(Foo, 10);

    t1.join();
    t2.join();

    return 0;
}