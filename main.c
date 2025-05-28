#include <stdio.h>
#include <string.h>

#define MAX_PARTICIPANTS 100

typedef struct {
    char name[50];
    char genre[50];
    int age;
    char gender[10];
    char city[50];
} Participant;

int main() {
    Participant participants[MAX_PARTICIPANTS] = {
        {"Anna Petrenko", "vocal singing", 12, "female", "Kyiv"},
        {"Ivan Shevchenko", "dance", 10, "male", "Lviv"},
        {"Oksana Dmytruk", "vocal singing", 11, "female", "Odesa"},
        {"Serhiy Moroz", "playing instrument", 13, "male", "Dnipro"}
    };

    int count = 4;  

    FILE *outputFile = fopen("vocal_output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Participants in 'vocal singing' genre:\n\n");

    for (int i = 0; i < count; i++) {
        if (strcmp(participants[i].genre, "vocal singing") == 0) {
            printf("Name: %s\nGenre: %s\nAge: %d\nGender: %s\nCity: %s\n\n",
                   participants[i].name, participants[i].genre,
                   participants[i].age, participants[i].gender,
                   participants[i].city);

            fprintf(outputFile, "Name: %s\nGenre: %s\nAge: %d\nGender: %s\nCity: %s\n\n",
                    participants[i].name, participants[i].genre,
                    participants[i].age, participants[i].gender,
                    participants[i].city);
        }
    }

    fclose(outputFile);

    return 0;
}
