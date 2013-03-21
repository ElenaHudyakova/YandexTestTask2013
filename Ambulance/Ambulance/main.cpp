//
//  main.cpp
//  Ambulance
//
//  Created by Elena Hudyakova on 20.03.13.
//  Copyright (c) 2013 Elena Hudyakova. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

void input(int& K1, int& K2, int& N2, int& P2, int& M){
    cout << "Hello, please enter an apartment number (K1)\n";
    cin >> K1;
    
    cout << "Now please enter data for ANOTHER apartment (apartment number K2, entrance number P2 and floor N2)\n";
    cin >> K2 >> P2 >> N2;
    
    cout << "And finally enter number of floors in this building (M)\n";
    cin >> M;
}

int get_min_apart_qty_per_floor(int K, int P, int N, int M){
    return (int)ceil(1.0 * K / ((P - 1) * M + N));
}

int get_max_apart_qty_per_floor(int K, int P, int N, int M){
    return (int)floor(1.0 * (K - 1) / ((P - 1) * M + (N - 1)));
}

int get_entrance_num(int K, int apart_qty, int M){
    int entrance_num = K / (M * apart_qty) + 1;
    return entrance_num;
}

int get_floor_num(int K, int apart_qty, int M){
    int floor_num = (int)ceil(K / apart_qty) % M + 1;
    return floor_num;
}

int main(int argc, const char * argv[])
{
    int M;
    int K1, N1, P1;
    int K2, N2, P2;
    
    input(K1, K2, N2, P2, M);
    
    int min_apart_per_floor = get_min_apart_qty_per_floor(K2, P2, N2, M);
    int max_apart_per_floor = get_max_apart_qty_per_floor(K2, P2, N2, M);
    
    if (min_apart_per_floor == max_apart_per_floor){//only one root
        int apart_qty = min_apart_per_floor;
        P1 = get_entrance_num(K1, apart_qty, M);
        N1 = get_floor_num(K1, apart_qty, M);
        cout << "P1 = " << P1 << ", N1 = " << N1;
    }
    else
        if (min_apart_per_floor < max_apart_per_floor){//several roots
            cout << 0;
        }
        else{ // no roots
            cout << -1 << " " << -1;
        }

    return 0;
}

