#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Record {
    char name[16];
    int age;
    enum {female, male} sex;
};

void record_print(Record *arr, int data_size)
{
    cout << "name=" << (arr+data_size)->name << ", "
         << "age=" << (arr+data_size)->age << ", "
         << "sex=" << (((arr+data_size)->sex)? "male" : "female") << '\n';
    // if ((arr+data_size)->sex == Record::female)
    //     cout << "female\n";
    // else
    //     cout << "male\n";
}

int main()
{
    freopen("data.in", "r", stdin);

    Record *arr = (Record*)malloc(2 * sizeof(Record));
    int capacity = 2;
    int data_size = 0;

    char line[101];
    while (fgets(line, 101, stdin)) {

        if ((data_size + 1) > capacity) {
            cout << "queue/stack full, allocate double size "
                 << capacity * 2 << endl;
            Record *tmp = (Record*)malloc(2 * sizeof(arr));
            for (int i = 0; i < capacity; ++i) {
                strcpy((tmp+i)->name, (arr+i)->name);
                (tmp+i)->age = (arr+i)->age;
                (tmp+i)->sex = (arr+i)->sex;
            }
            free(arr);
            arr = tmp;
            tmp = NULL;
            capacity *= 2;
        }

        // printf("%s\n", line);

        char *token = strtok(line, "\"");
        strcpy((arr+data_size)->name, token);
        // printf("%s\n", token);
        // printf("%s\n", (arr+data_size)->name);

        token = strtok(NULL, " ,");
        sscanf(token, "%d", &(arr+data_size)->age);
        // printf("%s\n", token);
        // printf("%d\n", (arr+data_size)->age);

        token = strtok(NULL, " ,\n");
        if (strncmp(token, "female", 6) == 0)
            (arr+data_size)->sex = Record::female;
        else
            (arr+data_size)->sex = Record::male;
        // printf("%s\n", token);
        // cout << (arr+data_size)->sex << endl;
        
        record_print(arr, data_size);
    
        // for (int i = 0; i < data_size + 1; ++i) {
        //     cout << i << endl;
        //     record_print(arr, i);
        // }

        data_size++;
    }
    return 0;
}
