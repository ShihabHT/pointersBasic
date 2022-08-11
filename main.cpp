#include <iostream>

using namespace std;

/*
    We have several data types in c++, and pointer is
    another type of data which holds physical address
    value of a variable stored in memory. For a pointer
    variable, the type of the pointer variable and type
    of the variable we want to store the address of has to
    be the same.
*/
void print(void* p, char c){
    switch(c){
    case 'i':
        cout<<"Using void pointer in function : "<<*((int*)p)<<endl;//this is th way to access(change or print) the data
        break;
    case 'c':
        cout<<"Using void pointer in function : "<<*((char*)p)<<endl;
        break;
    }
}
int main()
{
    int n = 4;
    int* nPointer = &n;
    cout<< nPointer << endl;

    //VOID POINTER: can hold the address of any data type
    char ch = 'x';
    print(&n, 'i');
    print(&ch, 'c');

    //Pointer of pointer
    int x=9;
    int* p;
    int** po; //pointer of pointer variable
    p = &x;
    po = &p;
    cout<<"x : "<<x<<endl;
    cout<<"p : "<<p<<endl; //pointer(address) of variable x
    cout<<"po : "<<po<<endl; //Pointer of pointer p(address of address)
    cout<<"Value of po : "<<**po<<endl; //value of pointer of pointer

    //Pointer with array
    cout<<"\n.............................."<<endl;
    cout<<"Pointer with Array"<<endl;
    cout<<".............................."<<endl;
    int numArr[5] = {4, 3, 6, 7, 9};
    //If you only print the name of the array it gives the address of the 1st element
    cout<<"Printing the array name gives the address of 1st element : "<<numArr<<endl;
    cout<<"Address of 1st element : "<<&numArr[0] << endl;
    cout<<"2nd number : "<<numArr[2]<< endl;
    cout<<"Address of 2nd num : " << &numArr[2] << endl;
    cout<<"2nd number(using array name only) : "<<*(numArr+2)<<endl;
    cout<<"Address of 2nd num(using array name only) : "<<numArr+2<<endl;
    //accessing out of bound elements with pointer. in this case we are accessing other programs' memory, which could cause error
    cout<<"Out of bound array element : " << *(numArr+6) << endl;
    cout<<"Out of bound element address : " << numArr+6 << endl;

    /*Dynamic array : is array that is created in runtime. When we create an array this way
    we also have the responsibility of delete the array when we don't need it anymore.*/
    cout<< "\n.......................Dynamic......................" << endl;
    int size;
    cout<<"Dynamic Array size : ";
    cin>>size;
    //int myArray[size]; //static array
    cout<<"Array address with new keyword : "<<new int[size]<<endl; //this prints address of the array

    int* myArray = new int[size]; //Dynamic array declaration(uses new keyword)
    for(int i=0; i<size; i++){
        cout<<"Array["<<i<<"] : ";
        cin>>myArray[i];
    }
    for(int i=0; i<size; i++){
        cout<<*(myArray+i)<<"  "; //Dereferencing is also possible this way -myArray[i]
    }
    delete[]myArray; //this deallocates the memory it was using by if we print the array we will see that this still points to some address
    myArray = NULL; //When we write this line of code the array is not going to point to any address

/*
    Memory leak : Memory leakage occurs in C++ when programmers allocates
    memory by using new keyword and forgets to deallocate the memory by
    using delete(). This might cause huge problem with memory space.
    The compiler will not show it as a bug. So we have to
    be very careful here.
*/


    return 0;
}
