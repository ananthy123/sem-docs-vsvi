    #include <stdio.h>
    #include <stdlib.h>

    typedef struct chamber {
        int oxygen;
        int change;
    }chamber;

    int compare(const void* a, const void* b) {
        chamber* chamberA = (chamber*)a;
        chamber* chamberB = (chamber*)b;
        return (chamberA->oxygen - chamberB->oxygen);
    }

    int revcompare(const void* a, const void* b) {
        chamber* chamberA = (chamber*)a;
        chamber* chamberB = (chamber*)b;
        return (chamberB->oxygen - chamberA->oxygen);
    }

    int possiblevisit(chamber* posChamber, chamber* negChamber, int itr1, int itr2, int k) {
        int curr = k;
        for (int i = 0; i < itr1; i++) {
            if (curr < posChamber[i].oxygen) {
                return 0;
            }
            curr += posChamber[i].change;
            //printf("%d\n", curr);
        }

        for (int i = 0; i < itr2; i++) {
            if (curr < negChamber[i].oxygen) {
                return 0;
            }
            curr += negChamber[i].change;
            //printf("%d\n", curr);
        }
        if (curr < 0) return 0;
        else return 1;  
    }

    int main () {
        int n;
        int k;
        scanf("%d %d", &n, &k);
        chamber* mainChamber = (chamber*) malloc (sizeof(chamber) * n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &(mainChamber[i].oxygen));
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &(mainChamber[i].change));
        }
        chamber* posChamber = (chamber*) malloc (sizeof(chamber) * n);  
        chamber* negChamber = (chamber*) malloc (sizeof(chamber) * n);
        int itr1 = 0;
        int itr2 = 0;
        for (int i = 0; i < n; i++) {
            if (mainChamber[i].change > 0) { //being greedy and sending all the positive stuff to 1 chamber array
                posChamber[itr1].oxygen = mainChamber[i].oxygen;
                posChamber[itr1].change = mainChamber[i].change;
                itr1++;
            }
            else {
                negChamber[itr2].oxygen = mainChamber[i].oxygen;
                negChamber[itr2].change = mainChamber[i].change;
                itr2++;
            }
        }

        qsort(posChamber, itr1, sizeof(chamber), compare);
        qsort(negChamber, itr2, sizeof(chamber), revcompare);
        // for (int i = 0; i < itr1; i++) {
        //     printf("%d, %d\n", posChamber[i].oxygen, posChamber[i].change);
        // }
        // printf("Negative Chamber\n");
        // for (int i = 0; i < itr2; i++) {
        //     printf("%d, %d\n", negChamber[i].oxygen, negChamber[i].change);
        // }
        // printf("\n");
        int pos = possiblevisit(posChamber, negChamber, itr1, itr2, k);
        if (pos) printf("YES"); 
        else printf("NO");
        return 0;
    }