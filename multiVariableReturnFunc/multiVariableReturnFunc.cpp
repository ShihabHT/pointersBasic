#include <iostream>
#include <math.h>

using namespace std;

void root(int a, int b, int c, double& r1, double& r2){ //this way we can take the reference of a variable directly without creating a pointer variable(ex. int& a)
    double discriminant;
    discriminant = b*b-4*a*c;
    if(discriminant<0){
        cout<<"Imaginary solution";
        return;
    }
    r1 = (-b + sqrt(discriminant))/(2.0*a);
    r2 = (-b - sqrt(discriminant))/(2.0*a);

}

int main(){
    double r1, r2;
    root(1, -5, 6, r1, r2); //passing the variable r1, r2 directly to create its reference in the function
    cout << r1<<" "<<r2 << endl;
    return 0;
}
