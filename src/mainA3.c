#include "../include/givenA3.h"

int main(int argc, char* argv[]){
    
    int userChoiceForFunction; 
    // this is used to validate input for the menu
    int scanResult;

    // initialize time
    srand(time(NULL));



    // task 1
    char *fileName;

    if (argc > 1) {
        fileName = argv[1];  // Use the provided argument
    } else {
        fileName = "MusicalTunes.csv";  // Default filename
    }    int numberOfSongs; 


    A3Song *head = NULL;  // Initialize the head of the linked list to NULL
    


    // task 2
    bool success; 
    int beginOrEnd; 



    while (1)
    {
        // print the menu
        printf("======================================================\n");
        printf("1. Create a new playlist\n");
        printf("2. Add a new song to an existing playlist\n");
        printf("3. Play all songs in the given playlist\n");
        printf("4. Play a song from the playlist, given its id\n");
        printf("5. Play a song from the playlist, given its name\n");
        printf("6. Count the number of occurrences of a note in a given song\n");
        printf("7. Delete a song from the playlist, given its id\n");
        printf("8. Delete the entire playlist\n");
        printf("9. Exit\n");
        printf("======================================================\n");

        printf("Enter your choice: ");
        
        // Check if scanf successfully reads an integer
        if ((scanResult = scanf("%d", &userChoiceForFunction)) != 1)
        {
            // Clear input buffer
            while (getchar() != '\n');
            
            printf("Invalid input. Please enter a number between 1 and 9.\n");
            continue;
        }

        // Additional validation for the range of input
        if (userChoiceForFunction < 1 || userChoiceForFunction > 9)
        {
            printf("Invalid choice. Please enter a number between 1 and 9.\n");
            continue;
        }


        if (userChoiceForFunction == 1)
        {
            numberOfSongs = createPlayList(&head, fileName);
            printf("\nNumber of songs in the playlist: %d\n", numberOfSongs); 
        }

        if (userChoiceForFunction == 2)
        {
            printf("Enter the value for beginOrEnd: ");
            scanf("%d", &beginOrEnd);
            success = addNewSong(&head, beginOrEnd);

            if (success == false)
            {
                printf("\n\nSong Addition Failed\n\n");
            }
            
        }


        if (userChoiceForFunction == 3)
        {
            playPlayList(head);
        }

        if (userChoiceForFunction == 4)
        {
            int songIdToSearch;

            printf("Enter the id of the song you want to play: ");
            scanf("%d", &songIdToSearch);
            
            
            int searchSuccess = playSongGivenId(head, songIdToSearch);

            if (searchSuccess == -1)
            {
                printf("No song found!\n\n");
            }
            
        }

        if (userChoiceForFunction == 5)
        {
            char givenSongNameToSearch[MAX_LENGTH];

            printf("Enter the name of the song you want to play: ");
            getchar();  // This will consume the newline character from the input buffer
    
            fgets(givenSongNameToSearch, sizeof(givenSongNameToSearch), stdin);
            
            // Remove the newline character if it exists
            givenSongNameToSearch[strcspn(givenSongNameToSearch, "\n")] = '\0';
            
            
            int searchSuccess = playSongGivenName(head, givenSongNameToSearch);

            if (searchSuccess == -1)
            {
                printf("No song found!\n\n");
            }
            
        }

        if (userChoiceForFunction == 6)
        {
            int songIdToSearch;
            char givenNoteToCount[NOTE_LENGTH]; 

            printf("Enter the id of the song you want to count the notes in: ");
            scanf("%d", &songIdToSearch);


            printf("Enter the note you want to count: ");
            getchar();  // This will consume the newline character from the input buffer
    
        
            fgets(givenNoteToCount, sizeof(givenNoteToCount), stdin);
            
            // Remove the newline character if it exists
            givenNoteToCount[strcspn(givenNoteToCount, "\n")] = '\0';

            int noteOccuranceCount = countNotesInASong(head, songIdToSearch, givenNoteToCount);

            if (noteOccuranceCount == -1)
            {
                printf("Song not found!\n");
            }else{

                printf("Number of times the note appears: %d\n", noteOccuranceCount); 
            }
            
        }

        if (userChoiceForFunction == 7)
        {
            int idOfSongToDelete;
            printf("Enter the id of the song you want to delete: ");
            scanf("%d", &idOfSongToDelete);

            int success = deleteASongGivenId(&head, idOfSongToDelete);
            
            if (success == 1)
            {
                printf("Song Deleted!\n");
            }else if(success == -1){
                printf("Song Not Found!\n");

            }
            
        }

        if (userChoiceForFunction == 8)
        {
            deletePlayList(&head);

            if (head == NULL)
            {
                printf("\nPlaylist successfully deleted!\n");
            }
            
        }
        
        
        // Exit condition
        else if (userChoiceForFunction == 9)
        {
            printf("\nExiting The Program\n");

            // delete before exiting
            deletePlayList(&head);

            return 0; 
        }

    }

    return 0; 
}