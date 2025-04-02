# Copyright 2025 daman
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     https://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


# There are two makefiles in this one
# One is for test cases and the other is for the main code
# The test cases makefile is active (line #23-#41)
# The main code makefile is commented out (line #44-#68)



# CC= gcc
# CFLAGS = -Wall -std=c99 -w


# bin/test: TestCode.o unity.o TestCodeRunner.o harness/unity.h harness/CodeUnderTest.h
# 	$(CC)  $(CFLAGS) -o bin/test TestCode.o unity.o TestCodeRunner.o -lm

# TestCode.o: harness/TestCode.c unity.o harness/unity.h
# 	$(CC)  $(CFLAGS) -c harness/TestCode.c

# unity.o: harness/unity.c harness/unity.h
# 	$(CC)  $(CFLAGS) -c harness/unity.c
	
# TestCodeRunner.o: harness/TestCodeRunner.c harness/unity.h
# 	$(CC)  $(CFLAGS) -c harness/TestCodeRunner.c

# clean test:
# 	rm *.o bin/test



bin/musicalLL: mainA3.o createPlayList.o playPlayList.o addNewSong.o playSongGivenId.o playSongGivenName.o countNotesInASong.o deleteASongGivenId.o deletePlayList.o
	gcc mainA3.o createPlayList.o playPlayList.o addNewSong.o playSongGivenId.o playSongGivenName.o countNotesInASong.o deleteASongGivenId.o deletePlayList.o -o bin/musicalLL -lm

mainA3.o: src/mainA3.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/mainA3.c 

createPlayList.o: src/createPlayList.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/createPlayList.c 

playPlayList.o: src/playPlayList.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/playPlayList.c 

addNewSong.o: src/addNewSong.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/addNewSong.c 

playSongGivenId.o: src/playSongGivenId.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/playSongGivenId.c 

playSongGivenName.o: src/playSongGivenName.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/playSongGivenName.c 

countNotesInASong.o: src/countNotesInASong.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/countNotesInASong.c 

deleteASongGivenId.o: src/deleteASongGivenId.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/deleteASongGivenId.c 

deletePlayList.o: src/deletePlayList.c include/givenA3.h
	$(CC)  $(CFLAGS) -c src/deletePlayList.c

clean:
	rm *.o bin/musicalLL