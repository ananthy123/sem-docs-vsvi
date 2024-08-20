#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <map>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

int main(){
    map<int,int>mp;

    mp[1] = 10;
    mp[2] = 20;
    mp[3] = 30;
    mp[4] = 40;
    printf("%d", mp[5]);
    map<int, int>::iterator itr;
    int s = mp.size();
    printf("SIze of map: %d\n", s);
    //mp.empty()

    for(itr = mp.begin(); itr!=mp.end(); itr++){
        int key = itr->first;
        int value = itr->second;

        printf("%d-->%d\n", key, value);
    }
    printf("%d\n", mp[4]);    
    if(mp.find(5)!=mp.end()){
        printf("FOund in map\n");
    }
    else{
        printf("Not in  map\n");
    }
}