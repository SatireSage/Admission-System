#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, and stu_sort.o to executable main
main: main.o student.o stu_sort.o domestic.o domesticstudentlist.o international.o internationalstudentlist.o studentlist.o toeflscore.o
	g++ -g -o main main.o student.o stu_sort.o domestic.o domesticstudentlist.o international.o internationalstudentlist.o studentlist.o toeflscore.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp
	g++ -g -c student.cpp

#compile the stu_sort.cpp to stu_sort.o
stu_sort.o: stu_sort.cpp
	g++ -g -c stu_sort.cpp

#compile the domestic.cpp to domestic.o
domestic.o: domestic.cpp	
	g++ -g -c domestic.cpp

#compile the toeflscore.cpp to toeflscore.o
toeflscore.o: toeflscore.cpp	
	g++ -g -c toeflscore.cpp

#compile the domesticstudentlist.cpp to domesticstudentlist.o
domesticstudentlist.o: domesticstudentlist.cpp
	g++ -g -c domesticstudentlist.cpp

#compile the international.cpp to international.o
international.o: international.cpp
	g++ -g -c international.cpp

#compile the internationalstudentlist.cpp to internationalstudentlist.o
internationalstudentlist.o: internationalstudentlist.cpp
	g++ -g -c internationalstudentlist.cpp

#compile the studentlist.cpp to studentlist.o
studentlist.o: studentlist.cpp
	g++ -g -c studentlist.cpp

#remove built files
clean:
	rm -rf main main.o student.o stu_sort.o domestic.o domesticstudentlist.o international.o internationalstudentlist.o studentlist.o toeflscore.o *~
