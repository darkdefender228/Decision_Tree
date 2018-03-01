#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 81
#define LEN 30
#define COUUNT_CLASES 2
#define COUNT_CASES 10
#define COUNT_FEATURE 3

void read_csv(char* , char (*)[LEN]);
double gini(double (*)[COUNT_CASES][COUNT_FEATURE], int, int);
int make_data(double (*)[3], char (*)[LEN]);
double num_cases(int, int);
int count(double*, double, int);
void test_split(double (*)[COUNT_FEATURE], double (*)[COUNT_FEATURE], int, double, double (*)[COUNT_FEATURE], int* , int*);

int main(int argc, const char * argv[]) {
    char data[COUNT_CASES][LEN], path[] = "banknote.csv";
    double converted_data[COUNT_CASES][COUNT_FEATURE], splited[COUUNT_CLASES][COUNT_CASES][COUNT_FEATURE], gini_value;
    int len, len1, len2;
    

    len = make_data(converted_data, data);
    test_split(splited[0], splited[1], 0, converted_data[0][0], converted_data, &len1, &len2);
    gini_value = gini(splited, len1, len2);
    
    return 0;
}

void read_csv(char* path, char data[][LEN]){
    int n = 0;
    char buf[LEN];
    FILE *file = fopen(path, "rb");
    
    while(fgets(buf,MAX,file) != NULL)
        strcpy(data[n], buf);
}

int make_data(double (*data)[COUNT_FEATURE], char (*data_str)[LEN]){
     double info[] = {2.771244718,1.784783929,0, 1.728571309,1.169761413,0,
        3.678319846,2.81281357,0, 3.961043357,2.61995032,0, 2.999208922,2.209014212,0,
        7.497545867,3.162953546,1, 9.00220326,3.339047188,1, 7.444542326,0.476683375,1,
        10.12493903,3.234550982,1, 6.642287351,3.319983761,1};
    int len = sizeof(info) / sizeof(info[0]), n = 0;
    
    for(int i = 0; i < len; i++){
        data[n][i % 3] = info[i];
        i % 3 == 2 ? n++ : n;
    }
    return len;
}

double gini(double (*converted_data)[COUNT_CASES][COUNT_FEATURE], int len1, int len2){
    double gini_index = 0.0, cases;
    double arr[COUNT_CASES], p;
    int size[] = {len1, len2}, T;
    
    cases = num_cases(len2, len1);
    
    for(int i = 0;i < COUUNT_CLASES; i++){
        if(size[i] == 0)
            continue;
        double estimation = 0.0;
        
        if(i == 0)
            T = len1;
        else
            T = len2;
        for(int class = 0; class < COUUNT_CLASES; class++){
            for(int t = 0; t < T; t++)
                arr[t] = converted_data[i][t][COUNT_FEATURE - 1];
            p = count(arr, class, T) / (double)size[i];
            estimation += p * p;
        }
        gini_index += (1.0 - estimation) * (size[i] / cases);
    }
    
    return gini_index;
}


inline double num_cases(int len, int len2){
    return len + len2;
}

int count(double* arr, double numb, int len){
    int c = 0;
    for(int i = 0; i < len; i++)
        arr[i] == numb ? c++ : c;
    
    return c;
}

void test_split(double (*left)[COUNT_FEATURE], double (*right)[COUNT_FEATURE], int index, double value, double (*data)[COUNT_FEATURE], int* len1, int* len2){
    int l = 0, r = 0;
    for(int feature = 0; feature < COUNT_CASES; feature++){
        if (data[feature][index] < value){
            for(int f = 0; f < COUNT_FEATURE; f++)
                left[l][f] = data[feature][f];
            l++;
        }else{
            for(int f = 0; f < COUNT_FEATURE; f++)
                right[r][f] = data[feature][f];
            r++;
        }
    }
    *len1 = l;
    *len2 = r;
}

