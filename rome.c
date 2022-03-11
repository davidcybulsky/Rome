//program by cybulsky
#include "rome.h"
#include <stdio.h>
#include <stdlib.h>

int ToDecimal(char *x) {
    int n = 0;
    int a;
    int checker = 0;
    while(*x) {
        switch(*x) {
        case 'M':
            if(checker == 0)
                a = 1000;
            else
                a = 800;
            break;
        case 'D':
            if(checker <= 1) {        
                a = 500;
                checker = 1;
            }
            else
                a = 300;
            break;
        case 'C':
            if(checker <= 2) {    
                a = 100;
                checker = 2;
            }
            else
                a = 80;
            break;
        case 'L':
            if(checker <= 3) {
                a = 50;
                checker = 3;
            }
            else
                a = 30;
            break;
        case 'X':
            if(checker <= 4) {         
                a = 10;
                checker = 4;
            }
            else
                a = 8;
            break;
        case 'V':
            if(checker <= 5) {
                a = 5;
                checker = 5;
            }
            else
                a = 3;
            break;
        case 'I':
            a = 1;
            checker = 6;
            break;
        }
        n += a;
        x++;
    }
    return n;
}
char *ToRome(int x) {
    char *n = malloc(sizeof(n));
    char *m = n;
    while(x>=0) {
        if((x-1000)>=0) {
            *n++ = 'M';
            x-=1000;
            continue;
        }
        else if ((x-900)>=0){
            *n++ = 'C';
            *n++ = 'M';
            x-=900;
            continue;
        }
        else if ((x-500)>=0){
            *n++ = 'D';
            x-=500;
            continue;
        }
        else if ((x-400)>=0){
            *n++ = 'C';
            *n++ = 'D';
            x-=400;
            continue;
        }
        else if((x-100)>=0) {
            *n++ = 'C';
            x-=100;
            continue;
        }
        else if ((x-90)>=0){
            *n++ = 'X';
            *n++ = 'C';
            x-=90;
            continue;
        }
        else if ((x-50)>=0) {
            *n++ = 'L';
            x-=50;
            continue;
        }
        else if ((x-40)>=0){
            *n++ = 'X';
            *n++ = 'L';
            x-=40;
            continue;
        }
        else if((x-10)>=0)  {
            *n++ = 'X';
            x-=10;
            continue;
        }        
        else if ((x-9)>=0){
            *n++ = 'I';
            *n++ = 'X';
            x-=9;
            continue;
        }
        else if ((x-5)>=0)  {
            *n++ = 'V';
            x-=5;
            continue;
        }
        else if ((x-4)>=0){
            *n++ = 'I';
            *n++ = 'V';
            x-=4;
            continue;
        }
        else if((x-1)>=0)   {
            *n++ = 'I';
            x-=1;
            continue;
        } else {
            *n = '\0';
            return m;
        }
    }
}