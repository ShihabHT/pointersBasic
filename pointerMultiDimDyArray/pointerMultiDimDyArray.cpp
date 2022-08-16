#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int rows, cols;
    cout<<"Rows X Columns : ";
    cin>>rows>>cols;

    int** table = new int*[rows];
    for(int i=0; i<rows; i++){
        table[i] = new int[cols];
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            table[i][j] = 10+(rand()%81); //random num between 10-90
        }
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<*(table[i]+j)<<"  "; //another way of accessing(dereferencing) the value of cells. simpler one table[i][j]
        }
        cout<<endl;
    }

/*
    As we learned previously that we should deallocate the
    memory we used once we are done using them. But in the case
    of multi-dimensional array we can't just delete the table
    array. if we do so we will lose the address of the table and
    the address of array the table had. So, the way we created multi
    dimensional array(table>array), we have to deallocate the reverse
    way. First we have to deallocated the elements inside the arrays
    inside the table and all the elements of the array will be deleted
    then we can delete address of the array. Finally as the arrays
    inside the table has been deleted we no longer should keep the
    address of the arrays. So we will set the table NULL
*/
    for(int i=0; i<rows; i++){
        delete[] table[i];
    }
    delete[] table;
    table = NULL;

    return 0;
}
