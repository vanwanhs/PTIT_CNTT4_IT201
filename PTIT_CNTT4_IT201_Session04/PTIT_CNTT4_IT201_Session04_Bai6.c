#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // để dùng strcspn

typedef struct {
    int id;
    char name[50];
    int age;
} sinhVien;

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    sinhVien sinhViens[n];
    getchar();

    for (int i = 0; i < n; i++) {
        sinhViens[i].id = i + 1;
        printf("Name of student %d: ", sinhViens[i].id);
        fgets(sinhViens[i].name, sizeof(sinhViens[i].name), stdin);
        sinhViens[i].name[strcspn(sinhViens[i].name, "\n")] = 0;

        printf("Age of student %d: ", sinhViens[i].id);
        scanf("%d", &sinhViens[i].age);
        getchar();
    }

    printf("\nList of students:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", sinhViens[i].id, sinhViens[i].name, sinhViens[i].age);
    }
    int start = 0, end = n - 1;
    int key;
    printf("Please enter the student to search for(id): ");
    scanf ("%d", &key);
    while (start <= end) {
        int mid = (start + end) /2;
        if (sinhViens[mid].id == key) {
            printf("ID: %d, Name: %s, Age: %d",sinhViens[mid].id,sinhViens[mid].name,sinhViens[mid].age);
            return 0;
        } else if (sinhViens[mid].id > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    printf("No solo: ");
    return 0;
}
