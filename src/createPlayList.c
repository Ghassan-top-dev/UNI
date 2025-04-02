#include "../include/givenA3.h"

int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]) {
    int numberOfSongs = 0; 
    char row[1000];
    char *token;
    
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return -1;  // Exit with an error code
    }
    
    // skip header row
    if (fgets(row, sizeof(row), file) == NULL) {
        fclose(file);
        return numberOfSongs;
    }
    
    while (fgets(row, sizeof(row), file) != NULL) {
        
        // replace newline at the end if present with null terminator
        row[strcspn(row, "\n")] = '\0';

        // Create a new node
        A3Song *currentWorkingNode = (A3Song *)malloc(sizeof(A3Song));
        
        
        if (currentWorkingNode == NULL) {
            printf("allocation failed\n");
            fclose(file);
            return -1;
        }
        
        // Initialize nextSong pointer to NULL
        currentWorkingNode->nextSong = NULL;
        
        // Parse the song name
        token = strtok(row, ",");
        if (token == NULL) continue; // Skip if row is empty
        
        strncpy(currentWorkingNode->songName, token, MAX_LENGTH);
        currentWorkingNode->songName[MAX_LENGTH-1] = '\0';  // place null character at the end
        
        // Generate songId 
        int songNameLength = strlen(currentWorkingNode->songName);
        currentWorkingNode->songId = songNameLength + (rand() % 1000 + 1);  // rand() % 1000 returns 0 to 999, so add 1
        
        // Parse 21 notes
        for (int i = 0; i < 21; i++) {
            token = strtok(NULL, ",");
            if (token == NULL) {
                printf("Not enough notes provided for song: %s\n", currentWorkingNode->songName);
                break;
            }
            // Copy token into the i-th note slot and null terminate
            strncpy(currentWorkingNode->songNotes[i], token, NOTE_LENGTH);
            currentWorkingNode->songNotes[i][NOTE_LENGTH-1] = '\0';
        }
        
        // Insert the new node to the linked list
        currentWorkingNode->nextSong = *headLL;
        *headLL = currentWorkingNode;
        
        numberOfSongs++;
    }
    
    fclose(file);
    return numberOfSongs;
}
