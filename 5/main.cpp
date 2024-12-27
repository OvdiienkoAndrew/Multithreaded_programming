/*
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class MyClass
{
public:
    void DoWork()
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork STOPPED\t=======" << endl;
    }

    void DoWork2(int a)
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork2 STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "DoWork2 значение параметра\t" << a << endl;
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork2 STOPPED\t=======" << endl;
    }

    int Sum(int a, int b)
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "Sum STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));

        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "Sum STOPPED\t=======" << endl;
        return a + b;
    }
};

int main()
{
    int result;
    MyClass m;

    thread t([&]() // со всеми сразу по ссылке
             { result = m.Sum(2, 5); });

    for (size_t i = 1; i <= 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    t.join();
    cout << "Result\t" << result << endl;

    return 0;
}
*/

/*
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class MyClass
{
public:
    void DoWork()
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork STOPPED\t=======" << endl;
    }

    void DoWork2(int a)
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork2 STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "DoWork2 значение параметра\t" << a << endl;
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork2 STOPPED\t=======" << endl;
    }

    int Sum(int a, int b)
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "Sum STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));

        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "Sum STOPPED\t=======" << endl;
        return a + b;
    }
};

int main()
{

    MyClass m;

    // thread t([&]() // со всеми сразу по ссылке
    //          { result = m.Sum(2, 5); });

    thread t(&MyClass::DoWork, m);

    for (size_t i = 1; i <= 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    t.join();
    // cout << "Result\t" << result << endl;

    return 0;
}
*/

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class MyClass
{
public:
    void DoWork()
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork STOPPED\t=======" << endl;
    }

    void DoWork2(int a)
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork2 STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "DoWork2 значение параметра\t" << a << endl;
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "DoWork2 STOPPED\t=======" << endl;
    }

    int Sum(int a, int b)
    {
        this_thread::sleep_for(chrono::milliseconds(2000));
        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "Sum STARTED\t=======" << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));

        cout << "ID потока = " << this_thread::get_id() << "\t============\t" << "Sum STOPPED\t=======" << endl;
        return a + b;
    }
};

int main()
{

    MyClass m;

    // thread t([&]() // со всеми сразу по ссылке
    //          { result = m.Sum(2, 5); });

    thread t([&]()
             { m.DoWork2(5); });

    for (size_t i = 1; i <= 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    t.join();
    // cout << "Result\t" << result << endl;

    return 0;
}