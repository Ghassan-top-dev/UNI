#include "../include/givenA3.h"

bool addNewSong(A3Song **headLL, int beginOrEnd){

    if (*headLL == NULL) {
        printf("\n\nLIST IS EMPTY\n\n");
        return false;  // List is empty
    }
    
    char addedSongName[MAX_LENGTH];       // name of the new song to be added

    // initiate a new node
    A3Song *currentWorkingNode = (A3Song *)malloc(sizeof(A3Song));
    
    if (currentWorkingNode == NULL) {
        printf("allocation failed\n");
        return false;
    }

    printf("Song Name: ");
  
    getchar();  // This will consume the newline character from the input buffer
    
    // Now read the full song name
    fgets(addedSongName, sizeof(addedSongName), stdin);
    
    // Remove the newline character if it exists
    addedSongName[strcspn(addedSongName, "\n")] = '\0';

    
    if (beginOrEnd == 1)
    {
        currentWorkingNode->nextSong = *headLL;
        *headLL = currentWorkingNode;

    }
    else if (beginOrEnd == 2)
    {
        currentWorkingNode->nextSong = NULL;

        if (*headLL == NULL) {
            *headLL = currentWorkingNode;
            return true;
        }

        // Traverse to the last node
        A3Song *current = *headLL;
        while (current->nextSong != NULL) {
            current = current->nextSong;
        }
        
        // Attach the new node to the last node
        current->nextSong = currentWorkingNode;

    }
    else{
        printf("Invalid beginOrEnd value passed!");
        return false; 
    }
    
    // attatch name
    strcpy(currentWorkingNode->songName, addedSongName);

    // attatch Id
    int songNameLength = strlen(currentWorkingNode->songName);
    currentWorkingNode->songId = songNameLength + (rand() % 1000 + 1); 


    const char *availableNotes[7] = {"do", "re", "mi", "fa", "sol", "la", "ti"};
    

    // Generate 21 random notes
    for (int i = 0; i < 21; i++) {
        // Pick a random index from 0 to 6
        int randomIndex = rand() % 7;
        
        // Copy the random note to the song's notes array
        snprintf(currentWorkingNode->songNotes[i], NOTE_LENGTH, "%s", availableNotes[randomIndex]);
    }

    printf("Song ID: %d\n", currentWorkingNode->songId);

    printf("Song Name: %s\n", currentWorkingNode->songName);

    printf("Song Notes: ");
        for (int i = 0; i < 21; i++) {
            printf("%s", currentWorkingNode->songNotes[i]);
            if (i < 20) {  // Print a period after every note 
                printf(".");
            }
        }
    printf("\n");  

    if (beginOrEnd == 1)
    {
        printf("Song added at the beginning\n");
    }else if(beginOrEnd == 2){
        printf("Song added at the end\n");
    }
    




    return true;

}