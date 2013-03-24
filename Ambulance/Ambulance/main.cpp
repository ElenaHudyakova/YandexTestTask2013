//
//  main.cpp
//  Ambulance
//
//  Created by Elena Hudyakova on 20.03.13.
//  Copyright (c) 2013 Elena Hudyakova. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int get_min_apart_qty_per_floor(int K, int P, int N, int M){
    return (int)ceil(1.0 * K / ((P - 1) * M + N));
}

int get_max_apart_qty_per_floor(int K, int P, int N, int M){
    if ((P - 1) * M + (N - 1) == 0)
        return 1000;
    else
        return (int)floor(1.0 * (K - 1) / ((P - 1) * M + (N - 1)));
}

int get_entrance_num(int K, int apart_qty, int M){
    return (int)ceil(1.0 * K / (M * apart_qty));
}

int get_floor_num(int K, int apart_qty, int M){
    int floor_num = (int)ceil(1.0 * K / apart_qty) % M ;
    if (floor_num == 0)
        floor_num = M;
    
    return floor_num;
}

int main(int argc, const char * argv[])
{
    int M, K1, N1, P1, K2, N2, P2;
    
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    
    cin >> K1 >> M >> K2 >> P2 >> N2;
    
    int min_apart_per_floor = get_min_apart_qty_per_floor(K2, P2, N2, M);
    int max_apart_per_floor = get_max_apart_qty_per_floor(K2, P2, N2, M);
    N1 = -1;
    P1 = -1;

    for (int i = min_apart_per_floor; i <= max_apart_per_floor; i++){
        int P1i = get_entrance_num(K1, i, M);
        int N1i = get_floor_num(K1, i, M);
    
        if (N1i <= M && N2 <= M){
            if (P1 == -1 )  P1 = P1i;
            if (P1i != P1)  P1 = 0;
            if (N1 == -1 )  N1 = N1i;
            if (N1i != N1)  N1 = 0;
        }
    }
    
    cout << P1 << " " << N1;
    return 0;
}

