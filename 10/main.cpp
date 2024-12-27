/*
#include <iostream>
#include <thread>
#include <mutex>
#include <SimpleTimer.h>
using namespace std;

mutex mtx;

void Print(char ch)
{
    unique_lock<mutex> ul(mtx, std::defer_lock);

    this_thread::sleep_for(chrono::milliseconds(2000));
    ul.lock();

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout << endl;
    }
    cout << endl;

    ul.unlock();

    this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
    SimpleTimer iter;

    thread t1(Print, '*');
    thread t2(Print, '#');

    t1.join();
    t2.join();

    return 0;
}
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <SimpleTimer.h>
using namespace std;

mutex mtx;

void Print(char ch)
{
    unique_lock<mutex> ul(mtx, std::defer_lock);

    this_thread::sleep_for(chrono::milliseconds(2000));
    ul.lock();

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << ch;
            this_thread::sleep_for(chrono::milliseconds(10));
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    SimpleTimer iter;

    thread t1(Print, '*');
    thread t2(Print, '#');

    t1.join();
    t2.join();

    return 0;
}
