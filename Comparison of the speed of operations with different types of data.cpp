#include <iostream>
#include <iomanip>
#include <chrono>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a = 3, b = 5, c = 7, d = 11, e = 13, f = 17, g = 19, h = 23, j = 29, k = 37;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) {
        a = b + c;
        b = c + d;
        c = d + e;
        d = e + f;
        e = f + g;
        f = g + h;
        g = h + j;
        h = j + k;
        j = k + a;
        k = a + b;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(t2 - t1).count();
    double intplus = 1000000 * 10 / (duration / 1000000.0);

    a = 3, b = 5, c = 7, d = 11, e = 13, f = 17, g = 19, h = 23, j = 29, k = 31;
    t1 = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) {
        a = b - c;
        b = c - d;
        c = d - e;
        d = e - f;
        e = f - g;
        f = g - h;
        g = h - j;
        h = j - k;
        j = k - a;
        k = a - b;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double intminus = 1000000 * 10 / (duration / 1000000.0);

    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a = 3, b = 5, c = 7, d = 11, e = 13, f = 17, g = 19, h = 23, j = 29, k = 31;
        a = c / b;
        b = d / c;
        c = e / d;
        d = f / e;
        e = g / f;
        f = h / g;
        g = j / h;
        h = k / j;
        j = k / a;
        k = b / a;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double intdivision = 1000000 * 10 / (duration / 1000000.0);

    a = 3, b = 5, c = 7, d = 11, e = 13, f = 17, g = 19, h = 23, j = 29, k = 31;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a = b * c;
        b = c * d;
        c = d * e;
        d = e * f;
        e = f * g;
        f = g * h;
        g = h * j;
        h = j * k;
        j = k * a;
        k = a * b;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double intmultiplication = 1000000 * 10 / (duration / 1000000.0);

    char a1 = 3, b1 = 5, c1 = 7, d1 = 11, e1 = 13, f1 = 17, g1 = 19, h1 = 23, j1 = 29, k1 = 31;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a1 = b1 + c1;
        b1 = c1 + d1;
        c1 = d1 + e1;
        d1 = e1 + f1;
        e1 = f1 + g1;
        f1 = g1 + h1;
        g1 = h1 + j1;
        h1 = j1 + k1;
        j1 = k1 + a1;
        k1 = a1 + b1;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double charplus = 1000000 * 10 / (duration / 1000000.0);

    a1 = 3, b1 = 5, c1 = 7, d1 = 11, e1 = 13, f1 = 17, g1 = 19, h1 = 23, j1 = 29, k1 = 31;
    t1 = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) {
        a1 = b1 - c1;
        b1 = c1 - d1;
        c1 = d1 - e1;
        d1 = e1 - f1;
        e1 = f1 - g1;
        f1 = g1 - h1;
        g1 = h1 - j1;
        h1 = j1 - k1;
        j1 = k1 - a1;
        k1 = a1 - b1;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double charminus = 1000000 * 10 / (duration / 1000000.0);

    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a1 = 3, b1 = 5, c1 = 7, d1 = 11, e1 = 13, f1 = 17, g1 = 19, h1 = 23, j1 = 29, k1 = 31;
        a1 = c1 / b1;
        b1 = d1 / c1;
        c1 = e1 / d1;
        d1 = f1 / e1;
        e1 = g1 / f1;
        f1 = h1 / g1;
        g1 = j1 / h1;
        h1 = k1 / j1;
        j1 = k1 / a1;
        k1 = b1 / a1;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double chardivision = 1000000 * 10 / (duration / 1000000.0);

    a1 = 3, b1 = 5, c1 = 7, d1 = 11, e1 = 13, f1 = 17, g1 = 19, h1 = 23, j1 = 29, k1 = 31;
    t1 = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) {
        a1 = b1 * c1;
        b1 = c1 * d1;
        c1 = d1 * e1;
        d1 = e1 * f1;
        e1 = f1 * g1;
        f1 = g1 * h1;
        g1 = h1 * j1;
        h1 = j1 * k1;
        j1 = k1 * a1;
        k1 = a1 * b1;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double charmultiplication = 1000000 * 10 / (duration / 1000000.0);

    float a2 = 3.12345f, b2 = 5.12345f, c2 = 7.12345f, d2 = 11.12345f, e2 = 13.12345f, f2 = 17.12345f, g2 = 19.12345f, h2 = 23.12345f, j2 = 29.12345f, k2 = 31.12345f;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a2 = b2 + c2;
        b2 = c2 + d2;
        c2 = d2 + e2;
        d2 = e2 + f2;
        e2 = f2 + g2;
        f2 = g2 + h2;
        g2 = h2 + j2;
        h2 = j2 + k2;
        j2 = k2 + a2;
        k2 = a2 + b2;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double floatplus = 1000000 * 10 / (duration / 1000000.0);

    a2 = 3.12345f, b2 = 5.12345f, c2 = 7.12345f, d2 = 11.12345f, e2 = 13.12345f, f2 = 17.12345f, g2 = 19.12345f, h2 = 23.12345f, j2 = 29.12345f, k2 = 31.12345f;
    t1 = high_resolution_clock::now();

    for (int i = 0; i < 1000000; i++) {
        a2 = b2 - c2;
        b2 = c2 - d2;
        c2 = d2 - e2;
        d2 = e2 - f2;
        e2 = f2 - g2;
        f2 = g2 - h2;
        g2 = h2 - j2;
        h2 = j2 - k2;
        j2 = k2 - a2;
        k2 = a2 - b2;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double floatminus = 1000000 * 10 / (duration / 1000000.0);
    
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a2 = 3.12345f, b2 = 5.12345f, c2 = 7.12345f, d2 = 11.12345f, e2 = 13.12345f, f2 = 17.12345f, g2 = 19.12345f, h2 = 23.12345f, j2 = 29.12345f, k2 = 31.12345f;
        a2 = c2 / b2;
        b2 = d2 / c2;
        c2 = e2 / d2;
        d2 = f2 / e2;
        e2 = g2 / f2;
        f2 = h2 / g2;
        g2 = j2 / h2;
        h2 = k2 / j2;
        j2 = k2 / a2;
        k2 = b2 / a2;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double floatdivision = 1000000 * 10 / (duration / 1000000.0);

    a2 = 3.12345f, b2 = 5.12345f, c2 = 7.12345f, d2 = 11.12345f, e2 = 13.12345f, f2 = 17.12345f, g2 = 19.12345f, h2 = 23.12345f, j2 = 29.12345f, k2 = 31.12345f;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a2 = b2 * c2;
        b2 = c2 * d2;
        c2 = d2 * e2;
        d2 = e2 * f2;
        e2 = f2 * g2;
        f2 = g2 * h2;
        g2 = h2 * j2;
        h2 = j2 * k2;
        j2 = k2 * a2;
        k2 = a2 * b2;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double floatmultiplication = 1000000 * 10 / (duration / 1000000.0);

    double a3 = 3.12345, b3 = 5.12345, c3 = 7.12345, d3 = 11.12345, e3 = 13.12345, f3 = 17.12345, g3 = 19.12345, h3 = 23.12345, j3 = 29.12345, k3 = 31.12345;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a3 = b3 + c3;
        b3 = c3 + d3;
        c3 = d3 + e3;
        d3 = e3 + f3;
        e3 = f3 + g3;
        f3 = g3 + h3;
        g3 = h3 + j3;
        h3 = j3 + k3;
        j3 = k3 + a3;
        k3 = a3 + b3;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double doubleplus = 1000000 * 10 / (duration / 1000000.0);

    a3 = 3.12345, b3 = 5.12345, c3 = 7.12345, d3 = 11.12345, e3 = 13.12345, f3 = 17.12345, g3 = 19.12345, h3 = 23.12345, j3 = 29.12345, k3 = 31.12345;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a3 = b3 - c3;
        b3 = c3 - d3;
        c3 = d3 - e3;
        d3 = e3 - f3;
        e3 = f3 - g3;
        f3 = g3 - h3;
        g3 = h3 - j3;
        h3 = j3 - k3;
        j3 = k3 - a3;
        k3 = a3 - b3;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double doubleminus = 1000000 * 10 / (duration / 1000000.0);
    
    
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a3 = 3.12345, b3 = 5.12345, c3 = 7.12345, d3 = 11.12345, e3 = 13.12345, f3 = 17.12345, g3 = 19.12345, h3 = 23.12345, j3 = 29.12345, k3 = 31.12345;
        a3 = c3 / b3;
        b3 = d3 / c3;
        c3 = e3 / d3;
        d3 = f3 / e3;
        e3 = g3 / f3;
        f3 = h3 / g3;
        g3 = j3 / h3;
        h3 = k3 / j3;
        j3 = k3 / a3;
        k3 = b3 / a3;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double doubledivision = 1000000 * 10 / (duration / 1000000.0);

    t1 = high_resolution_clock::now();
    a3 = 3.12345, b3 = 5.12345, c3 = 7.12345, d3 = 11.12345, e3 = 13.12345, f3 = 17.12345, g3 = 19.12345, h3 = 23.12345, j3 = 29.12345, k3 = 31.12345;
    for (int i = 0; i < 1000000; i++) {
        a3 = b3 * c3;
        b3 = c3 * d3;
        c3 = d3 * e3;
        d3 = e3 * f3;
        e3 = f3 * g3;
        f3 = g3 * h3;
        g3 = h3 * j3;
        h3 = j3 * k3;
        j3 = k3 * a3;
        k3 = a3 * b3;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double doublemultiplication = 1000000 * 10 / (duration / 1000000.0);

    long a4 = 3, b4 = 5, c4 = 7, d4 = 11, e4 = 13, f4 = 17, g4 = 19, h4 = 23, j4 = 29, k4 = 31;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a4 = b4 + c4;
        b4 = c4 + d4;
        c4 = d4 + e4;
        d4 = e4 + f4;
        e4 = f4 + g4;
        f4 = g4 + h4;
        g4 = h4 + j4;
        h4 = j4 + k4;
        j4 = k4 + a4;
        k4 = a4 + b4;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double longplus = 1000000 * 10 / (duration / 1000000.0);

    a4 = 3, b4 = 5, c4 = 7, d4 = 11, e4 = 13, f4 = 17, g4 = 19, h4 = 23, j4 = 29, k4 = 31;
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a4 = b4 - c4;
        b4 = c4 - d4;
        c4 = d4 - e4;
        d4 = e4 - f4;
        e4 = f4 - g4;
        f4 = g4 - h4;
        g4 = h4 - j4;
        h4 = j4 - k4;
        j4 = k4 - a4;
        k4 = a4 - b4;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double longminus = 1000000 * 10 / (duration / 1000000.0);
   
    t1 = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        a4 = 3, b4 = 5, c4 = 7, d4 = 11, e4 = 13, f4 = 17, g4 = 19, h4 = 23, j4 = 29, k4 = 31;
        a4 = c4 / b4;
        b4 = d4 / c4;
        c4 = e4 / d4;
        d4 = f4 / e4;
        e4 = g4 / f4;
        f4 = h4 / g4;
        g4 = j4 / h4;
        h4 = k4 / j4;
        j4 = k4 / a4;
        k4 = b4 / a4;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double longdivision = 1000000 * 10 / (duration / 1000000.0);
   
    t1 = high_resolution_clock::now();
    a4 = 3, b4 = 5, c4 = 7, d4 = 11, e4 = 13, f4 = 17, g4 = 19, h4 = 23, j4 = 29, k4 = 31;
    for (int i = 0; i < 1000000; i++) {
        a4 = b4 * c4;
        b4 = c4 * d4;
        c4 = d4 * e4;
        d4 = e4 * f4;
        e4 = f4 * g4;
        f4 = g4 * h4;
        g4 = h4 * j4;
        h4 = j4 * k4;
        j4 = k4 * a4;
        k4 = a4 * b4;
    }
    t2 = high_resolution_clock::now();
    duration = duration_cast<microseconds>(t2 - t1).count();
    double longmultiplication = 1000000 * 10 / (duration / 1000000.0);

    double operations[16] = { intplus, intminus,intmultiplication, intdivision, charplus, charminus, charmultiplication, chardivision, doubleplus, doubleminus, doubledivision, doublemultiplication, longplus, longminus, longmultiplication, longdivision };
    double max_operation = operations[0];
    for (int m = 1; m < 16; m++) {
        if (operations[m] > max_operation) {
            max_operation = operations[m];
        }
    }
    cout << fixed << setprecision(2);
    cout << "The number of addition operations for int per second:" << intplus << "\t" << (intplus/max_operation)*100 << " % " << "\t";
    int x = (int)((intplus / max_operation) * 10);
    for (int n = 0;  n < x; n++) {
            cout << "X";
    }
    cout << endl;
        
    cout << "The number of subtraction operations for int per second: " << intminus << "\t" << (intminus/max_operation)*100 << "%" << "\t";
    x = (int)((intminus / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of multiplication operations for int per second: " << intmultiplication << "\t" << (intmultiplication/max_operation)*100 << "%" << "\t";
    x = (int)((intmultiplication / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of division operations for int per second: " << intdivision << "\t" << (intdivision / max_operation) * 100 << "%" << "\t";
    x = (int)((intdivision / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "Number of addition operations for char per second: " << charplus << "\t" << (charplus / max_operation) * 100 << "%" << "\t";
    x = (int)((charplus / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of subtraction operations for char per second: " << charminus << "\t" << (charminus / max_operation) * 100 << "%" << "\t";
    x = (int)((charminus / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of multiplication operations for char per second: " << charmultiplication << "\t" << (charmultiplication / max_operation) * 100 << "%" << "\t";
    x = (int)((charmultiplication / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of division operations for char per second: " << chardivision << "\t" << (chardivision / max_operation) * 100 << "%" << "\t";
    x = (int)(( chardivision/ max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of addition operations for double per second: " << doubleplus << "\t" << (doubleplus / max_operation) * 100 << "%" << "\t";
    x = (int)((doubleplus / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of subtraction operations for double per second: " << doubleminus << "\t" << (doubleminus / max_operation) * 100 << "%" << "\t";
    x = (int)((doubleminus / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of multiplication operations for double per second: " << doublemultiplication << "\t" << (doublemultiplication / max_operation) * 100 << "%" << "\t";
    x = (int)((doublemultiplication / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of division operations for double per second: " << doubledivision << "\t" << (doubledivision / max_operation) * 100 << "%" << "\t";
    x = (int)((doubledivision / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of addition operations for long per second: " << longplus << "\t" << (longplus / max_operation) * 100 << "%" << "\t";
    x = (int)((longplus / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of subtraction operations for long per second: " << longminus << "\t" << (longminus / max_operation) * 100 << "%" << "\t";
    x = (int)((longminus / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of multiplication operations for long per second: " << longmultiplication << "\t" << (longmultiplication / max_operation) * 100 << "%" << "\t";
    x = (int)((longmultiplication / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

    cout << "The number of division operations for long per second: " << longdivision << "\t" << (longdivision / max_operation) * 100 << "%" << "\t";
    x = (int)((longdivision / max_operation) * 10);
    for (int n = 0; n < x; n++) {
        cout << "X";
    }
    cout << endl;

}
