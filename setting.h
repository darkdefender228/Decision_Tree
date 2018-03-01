//
//  setting.h
//  Decision tree
//
//  Created by Roman Ilechko on 02.03.18.
//  Copyright © 2018 Roman Ilechko. All rights reserved.
//

#ifndef setting_h
#define setting_h

#define MAX 81                  // <-   settings for
#define LEN 30                  // <-   file reading

#define COUNT_CLASES 2         // <-   setings for
#define COUNT_CASES 10          // <-   your dataset
#define COUNT_FEATURE 3         // <-

#define INDEX 0                 // <-  don't
#define VALUE 1                 // <-  touch this

void read_csv(char* , char (*)[LEN]);
double gini(double (*)[COUNT_CASES][COUNT_FEATURE], int, int);
int make_data(double (*)[3], char (*)[LEN]);
double num_cases(int, int);
int count(double*, double, int);
void test_split(double (*)[COUNT_FEATURE], double (*)[COUNT_FEATURE], int, double, double (*)[COUNT_FEATURE], int* , int*);
void make_split(double (*)[COUNT_FEATURE], double (*)[COUNT_CASES][COUNT_FEATURE], double*);

#endif /* setting_h */
