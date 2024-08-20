#include <stdio.h>
#include <stdlib.h>

typedef long long int lint;

typedef struct station {
    lint time;
    lint depth;
}station;

int compare(const void *a, const void *b) {
    const station *stationA = (const station *)a;
    const station *stationB = (const station *)b;
    if (stationA->depth < stationB->depth) return -1;
    if (stationA->depth > stationB->depth) return 1;
    return 0; 
}


void minHeapify(station arr[], lint n, lint i) {
    lint smallest = i;
    lint l = 2*i + 1;
    lint r = 2*i + 2;

    if (l < n && arr[l].time < arr[smallest].time)
        smallest = l;

    if (r < n && arr[r].time < arr[smallest].time)
        smallest = r;

    if (smallest != i) {
        station temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

station deleteHeap(station arr[], lint* n) {
    station smallestElem = arr[0];
    arr[0] = arr[--(*n)];
    minHeapify(arr, *n, 0);
    return smallestElem;
}

void minInsertHeap (station arr[], lint *n, station key) {
    lint i = (*n);
    arr[*n] = key;
    (*n)++;

    while (i > 0 && arr[(i-1) / 2].time > arr[i].time) {
        lint k = (i-1) / 2;
        station temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
        i = k;
    }
}

void buildMinHeap(station arr[], lint n) {
    for (lint i = (n-1)/2; i >= 0; i--) {
        minHeapify(arr, n, i);
    }
}

int isHeapEmpty (station* heap, lint n) {
    if (n == 0) {
        return 1;
    }
    return 0;
}

void finResult(station* stations, lint n, lint k, lint d, lint p) {
    lint station_itr = 0;
    lint heap_size = 0;
    lint currentOxygen = k;
    lint currentTime = 0;
    lint possible = 1;
    // n (the number of stations), k (initial oxygen supply)
    // d (the final depth that has to be reached), and p (the amount of oxygen thatis refilled at each station).
    station* heap = (station*) malloc (sizeof(station) * n);

    for (lint i = 0; i <= d; i++) {
       if (currentOxygen < 0) {
            if (isHeapEmpty(heap, heap_size)) { //cant even go any further cause you cant refill from any previous stations.
                printf("-1 %lld\n", i - 1);
                possible = 0;
                return;
            }
            else { //extract from the least time taking station and refill
                station top = deleteHeap(heap, &heap_size);
                currentOxygen += p;
                currentTime += top.time;
            }
       }

        // printf("Current time at %lld is %lld\n", i, currentTime);
        if (i == stations[station_itr].depth) // basically when we encounter a station, we add it to the minimum heap
        {
            // printf("Station at %lld is %lld and time is %lld\n", i, stations[station_itr].depth, stations[station_itr].time);
            minInsertHeap(heap, &heap_size, stations[station_itr]);
            station_itr++;
        }
        // if (heap_size > 0) {
        //     printf("Heap size at %lld is %lld\n", i, heap_size);
        //     printf("Top of heap at %lld is %lld\n", i, heap[0].time);
        // }
       // to check: can you reach the bottom and be at 0 oxygen?
       currentOxygen--; // cause you keep losing oxygen the more you go down
    }
    //printf("Could he reach? %lld\n", possible);
    printf("%lld\n", currentTime);
    return;
}


// main logic would be like this    


int main () {
    lint n, k, d, p;
    scanf("%lld %lld %lld %lld", &n, &k, &d, &p);
    // n (the number of stations), k (initial oxygen supply)
    // d (the final depth that has to be reached), and p (the amount of oxygen thatis refilled at each station).
    station* stations = (station*) malloc (sizeof(station) * n);
    for (lint i = 0; i < n; i++) {
        scanf("%lld", &(stations[i].depth));
    }
    for (lint i = 0; i < n; i++) {
        scanf("%lld", &(stations[i].time));
    }
    qsort(stations, n, sizeof(station), compare);
    // for (lint i = 0; i < n; i++) {
    //     printf("Depth: %lld Time: %lld\n", stations[i].depth, stations[i].time);
    // }
    finResult(stations, n, k, d, p);
}