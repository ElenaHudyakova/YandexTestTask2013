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

int get_min_apart_qty_per_floor(int K, int P, int N, int M){
    return (int)ceil(1.0 * K / ((P - 1) * M + N));
}

int get_max_apart_qty_per_floor(int K, int P, int N, int M){
    if ((P - 1) * M + (N - 1) == 0)
        return 1001;
    else
        return (int)floor(1.0 * (K - 1) / ((P - 1) * M + (N - 1)));
}

int get_entrance_num(int K, int apart_qty, int M){
    int entrance_num = ceil(1.0 * K / (M * apart_qty));
    return entrance_num;
}

int get_floor_num(int K, int apart_qty, int M){
    int floor_num = (int)ceil(1.0 * K / apart_qty) % M;
    if (floor_num == 0)
        floor_num = M;
    return floor_num;
}

int main(int argc, const char * argv[])
{
    int M;
    int K1, N1, P1;
    int K2, N2, P2;
    
    cin >> K1 >> M >> K2 >> P2 >> N2;
    
    int min_apart_per_floor = get_min_apart_qty_per_floor(K2, P2, N2, M);
    int max_apart_per_floor = get_max_apart_qty_per_floor(K2, P2, N2, M);
    
    if (min_apart_per_floor == max_apart_per_floor){//only one solution
        int apart_qty = min_apart_per_floor;
        P1 = get_entrance_num(K1, apart_qty, M);
        N1 = get_floor_num(K1, apart_qty, M);
        cout << P1 << " " << N1;
    }
    else
        if (min_apart_per_floor < max_apart_per_floor){//several solutions
            cout << 0;
        }
        else{ // no solution
            cout << -1 << " " << -1;
        }

    return 0;
}

