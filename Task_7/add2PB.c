#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[256];
    char phone[64];

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // remove newline (\n)

    printf("Enter phone number: ");
    fgets(phone, sizeof(phone), stdin);
    phone[strcspn(phone, "\n")] = 0;

    FILE *file = fopen("phonebook.txt", "a");
    if (!file) {
        perror("fopen");
        return 1;
    }

    fprintf(file, "%s,%s\n", name, phone);
    fclose(file);
    printf("Added to phonebook.\n");
    return 0;
}