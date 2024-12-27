#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void DoWork(int &a)
{
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "ID потока = " << this_thread::get_id() << "============\t" << "DoWork STARTED\t=======" << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    a = a * 2;

    cout << "ID потока = " << this_thread::get_id() << "============\t" << "DoWork STOPPED\t=======" << endl;
}

int main()
{
    int q = 5;

    thread t(DoWork, std::ref(q));

    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t.join();
    cout << q << endl;

    return 0;
}