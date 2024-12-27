#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void DoWork(int a, int b, string msg)
{
    cout << msg << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "============\t" << "DoWork STARTED\t=======" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "a+b=" << a + b << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout << "============\t" << "DoWork STOPPED\t=======" << endl;
}

int main()
{
    thread th(DoWork, 1, 6, "our massange");

    for (size_t i = 0; true; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();

    return 0;
}