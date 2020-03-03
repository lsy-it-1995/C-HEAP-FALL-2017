#include <iostream>
#include "heap.h"
#include <locale>
#include <time.h>

using namespace std;

int main()
{
    Heap<int> test;

//    test.insert(5);
//    cout<<test<<endl;
//    test.insert(40);
//    cout<<test<<endl;
//    test.insert(50);
//    cout<<test<<endl;
//    test.insert(4);
//    cout<<test<<endl;
//    test.insert(60);
//    cout<<test<<endl;
//    test.Pop();
//    cout<<test<<endl;
//    test.insert(30);
//    cout<<test<<endl;
//    test.insert(8);
//    cout<<test<<endl;
//    test.insert(80);
//    cout<<test<<endl;



    char userinput;
    srand(time(NULL));
    cout<<"[R]andom [I]nsert [P]op [E]xit"<<endl;
    while(cin>>userinput)
    {
        userinput = toupper(userinput);
        switch (userinput) {
        case 'R':
        {
            int f = rand()%100+1;
            cout<<"random number is : "<<f<<endl;
            test.insert(f);
            cout<<test<<endl;
        }
            break;
        case 'I':
        {
            int usernumber;
            cout<<"enter a number"<<endl;
            cin>>usernumber;
            test.insert(usernumber);
            cout<<test<<endl;
        }
            break;
        case 'P':
        {
            test.Pop();
            cout<<test<<endl;
        }
            break;
        case 'E':
            return 0;
        default:
            break;
        }
        cout<<"[R]andom [I]nsert [P]op [E]xit"<<endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}
