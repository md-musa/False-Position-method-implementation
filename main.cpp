#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x) {
    return x*x*x-2*x-5; //2 * pow(x, 3) - 11.7 * pow(x, 2) + 17.7 * x - 5;
}

float falsiMid(float a, float b) {
    return (a * f(b) - b * f(a)) / (f(b) - f(a));
}

int main() {
    float a, b, tolerance;

up:
    cout << "Enter first guess: ";
    cin >> a;
    cout << "Enter second guess: ";
    cin >> b;
    cout << "Enter tolerable error: "; //Ex: 0.001
    cin >> tolerance;

    if (f(a) * f(b) > 0) {
        cout << "Incorrect Initial Guesses.\n\n";
        goto up;
    }

    cout << fixed << setprecision(4);
    cout << "+-------+-----------+-----------+-----------+-----------+-----------+-----------+\n";
    cout << "|  Step |     a     |     b     |     c     |   f(a)    |   f(b)    |   f(c)    |\n";
    cout << "+-------+-----------+-----------+-----------+-----------+-----------+-----------+\n";

    int step = 1; float c; 

    while (true) {
        c = falsiMid(a, b);
        float fa = f(a);
        float fb = f(b);
        float fc = f(c);

        cout << "| " << setw(5) << step++
             << " | " << setw(9) << a
             << " | " << setw(9) << b
             << " | " << setw(9) << c
             << " | " << setw(9) << fa
             << " | " << setw(9) << fb
             << " | " << setw(9) << fc
             << " |\n";

        if (fa * fc < 0) b = c;
        else a = c;
        
        if(fabs(fc) < tolerance ) break; 
    }
    
    cout << "+-------+-----------+-----------+-----------+-----------+-----------+-----------+\n\n";

    cout<< "+--------------------------+\n";
    cout<< "|  ROOT IS  ~ " << c << "     |\n";
    cout<< "+--------------------------+\n";


    return 0;
}
