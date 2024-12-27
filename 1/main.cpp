/*
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main()
{

    cout << "Start Main" << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));

    cout << this_thread::get_id() << endl;

    cout << "End Main" << endl;
}
*/

/*
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void DoWork()
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tDoWork " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    thread th(DoWork);
    th.detach();

    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}
*/

/*
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void DoWork()
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tDoWork " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    thread th(DoWork);
    thread th2(DoWork);

    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    th.join();
    th2.join();
    return 0;
}
*/

#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void DoWork()
{
    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tDoWork " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    DoWork();
    DoWork();

    for (size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return 0;
}