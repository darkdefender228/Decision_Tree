//
//  read_file.c
//  Decision tree
//
//  Created by Roman Ilechko on 02.03.18.
//  Copyright © 2018 Roman Ilechko. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "setting.h"

void read_csv(char* path, char data[][LEN]){
    int n = 0;
    char buf[LEN];
    FILE *file = fopen(path, "rb");
    
    while(fgets(buf, MAX, file) != NULL)
        strcpy(data[n], buf);
}
