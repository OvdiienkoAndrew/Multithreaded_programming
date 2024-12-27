#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int Sum(int a, int b)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "ID потока = " << this_thread::get_id() << "============\t" << "DoWork STARTED\t=======" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));

    cout << "ID потока = " << this_thread::get_id() << "============\t" << "DoWork STOPPED\t=======" << endl;
    return a + b;
}

int main()
{

    int result;

    thread t([&result]()
             { result = Sum(2, 5); });

    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t.join();
    cout << "Sum result = " << result << endl;

    return 0;
}