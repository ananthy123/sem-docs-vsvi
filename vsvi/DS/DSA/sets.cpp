#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <set>
#include <iostream>
#include <iterator>
using namespace std;

void printSet(set<int>s){
    set<int >::iterator itr;
    int si = s.size();

    printf("%d\n", si);
    for (itr = s.begin(); itr != s.end(); itr++) {
        printf("%d ", *itr);
        // cout << *itr << " ";
    }
    printf("\n");
}


int main(){

    set<int>s;
    // multiset<int>ms;
    if(s.empty()){
        printf("Set is an empty set\n");
    }
    s.insert(5);
    s.insert(4);
    s.insert(6);
    s.insert(1);
    s.insert(2);
    s.insert(10);
    s.insert(10);
    s.insert(19);

    if(!s.empty()){
        printf("Set is not an empty set\n");
    }

    printSet(s);

    s.erase(6);
    
    printSet(s);
    
    set<int >::iterator itr;
    
    // // itr = s.begin();
    // // itr ++;
    // // s.erase(itr);
    
    // // printSet(s);

    // itr = s.find(10);
    // // itr++;
    // // printf("%d\n",*itr);

    // // int c = s.count(5);
    // // printf("Is 5 present: %d\n", c);    

    itr  = s.lower_bound(20);
    // --itr;
    if(itr == s.end())
        printf("Out Of range\n");
    else
        printf("%d\n", *itr);


    itr = s.upper_bound(20);

    if(itr == s.end())
        printf("Out Of range\n");
    else
        printf("%d\n", *itr);


    // //user upper_bound to find the nearest smaller element
}