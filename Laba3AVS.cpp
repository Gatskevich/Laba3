﻿#include <iostream>
#include <omp.h>
#include <time.h>
#include <thread>
using namespace std;

void  main() {

    int i,j;
    const int n = 5, m = 5;
    int** matrix = new int* [n];;
    int* vect = new int[n];
    int* new_vect = new int[m];;
    for (i = 0; i < n; i++) {
        vect[i] = rand() % 10;
        matrix[i] = new int[m];
    }
    for (i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
   // clock_t start = clock();
    #pragma omp parallel 
    {
        #pragma omp for schedule (dynamic)
        for (i = 0; i < n; i++) {
            new_vect[i] = 0;
            for (j = 0; j < m; j++)
            {
                new_vect[i] += matrix[i][j] * vect[j];
            }
        }
        //this_thread::sleep_for(chrono::milliseconds(10));
    }
   // clock_t end = clock();
   // double seconds = (double)(end - start) / CLK_TCK;
    //cout << seconds << std::endl;
    for (i = 0; i < n; i++) {
        cout << new_vect[i] << " ";
    }
    cout << endl;
    /*start = clock();
#pragma omp parallel 
    {
#pragma omp for schedule (guided)
        for (i = 0; i < n; i++) {
            new_vect[i] = 0;
            for (j = 0; j < m; j++)
            {
                new_vect[i] += matrix[i][j] * vect[j];
            }
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
    end = clock();
    seconds = (double)(end - start) / CLK_TCK;
    cout << seconds << std::endl;
    start = clock();
#pragma omp parallel
    {
#pragma omp for schedule (static)
        for (i = 0; i < n; i++) {
            new_vect[i] = 0;
            for (j = 0; j < m; j++)
            {
                new_vect[i] += matrix[i][j] * vect[j];
            }
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }    end = clock();
    seconds = (double)(end - start) / CLK_TCK;
    cout << seconds << endl;*/
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vect;
    delete[] new_vect;
}