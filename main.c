//
//  main.c
//  Decision tree
//
//  Created by Roman Ilechko on 26.02.18.
//  Copyright © 2018 Roman Ilechko. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 81
#define LEN 30
#define COUNT_ROWS 30

void read_csv(char* path, char data[][LEN]);

int main(int argc, const char * argv[]) {
    char data[COUNT_ROWS][LEN];
    char path[] = "banknote.csv";
    
    read_csv(path, data);
    return 0;
}

void read_csv(char* path, char data[][LEN]){
    int n = 0;
    char buf[LEN];
    FILE *file = fopen(path, "r");
    
    while(fgets(buf,MAX,file) != NULL)
        strcpy(data[n], buf);
}


