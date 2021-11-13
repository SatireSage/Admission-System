// main.cpp, put your driver code here,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>  //atof and atoi
#include <iomanip>  // formatting
#include <limits>   //numeric limit
#include "student.hpp"
#include "stu_sort.hpp"

using namespace std;

int Get_Number() // checks validity of input
{
  string line;
  int user_input;
  while (getline(cin, line))
  {
    stringstream ss(line);
    if (ss >> user_input)
    {
      if (ss.eof())
      {
        break;
      }
    }
    cout << "Please enter a number as input only for the previous input: " << '\n'
         << ">> ";
  }
  return user_input;
};

int lineCounter(ifstream &fileName) // counts number of lines (students) in a file
{
  int i = 0;
  string line;
  while (getline(fileName, line))
    i++;
  fileName.clear();
  fileName.seekg(0, ios::beg);
  getline(fileName, line);
  return i;
};

DomesticStudentList **arrayToListDom(Domestic arr[], int n, DomesticStudentList **root)
{
  if (root != NULL)
  {
    DomesticStudentList *current = *root;
    DomesticStudentList *next = NULL;
    while (current != NULL)
    {
      next = current->next;
      free(current);
      current = next;
    }
    *root = NULL;
  }
  // DomesticStudentList *root = NULL;
  for (int i = 0; i < n; i++)
  {
    appendDom(root, arr[i]);
  }
  return root;
};

InternationalStudentList **arrayToListInt(International arr[], int n, InternationalStudentList **root)
{
  if (root != NULL)
  {
    InternationalStudentList *current = *root;
    InternationalStudentList *next = NULL;
    while (current != NULL)
    {
      next = current->next;
      free(current);
      current = next;
    }
    *root = NULL;
  }
  // DomesticStudentList *root = NULL;
  for (int i = 0; i < n; i++)
  {
    appendInt(root, arr[i]);
  }
  return root;
};

StudentList **arrayToListStu(Student arr[], int n, StudentList **root)
{
  if (root != NULL)
  {
    StudentList *current = *root;
    StudentList *next = NULL;
    while (current != NULL)
    {
      next = current->next;
      free(current);
      current = next;
    }
    *root = NULL;
  }
  // DomesticStudentList *root = NULL;
  for (int i = 0; i < n; i++)
  {
    appendMerge(root, arr[i]);
  }
  return root;
};

int main() // main function
{
  string line;
  ifstream domesticFile("domestic-stu.txt"); // connects files with domestic student information
  if (!domesticFile.is_open())               // error return in case of file not opening
  {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);

  int i = 0;
  int stu_count = 1;
  int numDomesticStudents = lineCounter(domesticFile);
  Domestic *DomesticStudents = new Domestic[numDomesticStudents];
  while (getline(domesticFile, line)) // creates first name, last name, province, gpa, and RS for each domestic student
  {
    istringstream ss(line);
    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    // takes data from txt file and sets object member variables
    getline(ss, firstName, ',');
    DomesticStudents[i].setFirstName(firstName);
    getline(ss, lastName, ',');
    DomesticStudents[i].setLastName(lastName);
    getline(ss, province, ',');
    DomesticStudents[i].setProvince(province);
    getline(ss, s_cgpa, ',');
    cgpa = float(int(atof(s_cgpa.c_str()) * 10 + 0.5)) / 10;
    DomesticStudents[i].setCGPA(cgpa);
    getline(ss, s_researchScore, ',');
    researchScore = int(atoi(s_researchScore.c_str()) + 0.5);
    DomesticStudents[i].setResearchScore(atoi(s_researchScore.c_str()));
    DomesticStudents[i].setUID(stu_count);
    stu_count++;
    i++;
  }

  DomesticStudentList *DomHead = nullptr;
  arrayToListDom(DomesticStudents, numDomesticStudents, &DomHead);
  domesticFile.close();
  delete[] DomesticStudents;

  ifstream InternationalFile("international-stu.txt"); // connects file with international student info
  if (!InternationalFile.is_open())                    // error return in case of file not opening
  {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }

  getline(InternationalFile, line);

  int stu_inter_count = 1;
  int j = 0;
  int numInternationalStudents = lineCounter(InternationalFile);
  International *InternationalStudents = new International[numInternationalStudents];
  while (getline(InternationalFile, line)) // creates first name, last name, province, gpa, and RS for each international student
  {
    istringstream ss(line);
    string firstNameInt, lastNameInt, country, s_cgpa2, s_researchScore2, s_reading, s_listening, s_speaking, s_writing;
    float cgpa2;
    int researchScore2, reading, listening, speaking, writing;

    // sets object member variables
    getline(ss, firstNameInt, ',');
    InternationalStudents[j].setFirstName(firstNameInt);
    getline(ss, lastNameInt, ',');
    InternationalStudents[j].setLastName(lastNameInt);
    getline(ss, country, ',');
    InternationalStudents[j].setCountry(country);

    getline(ss, s_cgpa2, ',');
    cgpa2 = float(int(atof(s_cgpa2.c_str()) * 10 + 0.5)) / 10;
    InternationalStudents[j].setCGPA(cgpa2);

    getline(ss, s_researchScore2, ',');
    researchScore2 = int(atoi(s_researchScore2.c_str()) + 0.5);
    InternationalStudents[j].setResearchScore(atoi(s_researchScore2.c_str()));

    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());
    InternationalStudents[j].setReading(atoi(s_reading.c_str()));

    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());
    InternationalStudents[j].setListening(atoi(s_listening.c_str()));

    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());
    InternationalStudents[j].setSpeaking(atoi(s_speaking.c_str()));

    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());
    InternationalStudents[j].setWriting(atoi(s_writing.c_str()));

    InternationalStudents[j].setToeflScore(reading, listening, speaking, writing);
    InternationalStudents[j].setUID(numDomesticStudents + stu_inter_count);

    j++;
    stu_inter_count++;
  }

  InternationalStudentList *IntHead = nullptr;
  arrayToListInt(InternationalStudents, numInternationalStudents, &IntHead);
  InternationalFile.close();
  delete[] InternationalStudents;

  string exitCheck;
  while (true) // menu system
  {
    int menu_selector = 0; // resets menu selection value to 0 when loop begins

    if (menu_selector == 0) // main menu
    {
      cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
      cout << "Welcome to 251 Interim Project! Please select one of the following menu options:\n"
           << "Please select one of the folowing:\n"
           << "Select 1: to sort Domestic Students\n"
           << "Select 2: to sort International Students\n"
           << "Select 3: to sort All Students\n"
           << "Select 4: to exit the program\n"
           << ">> ";
      menu_selector = Get_Number(); // get user_input
      cout << "-----------------------------------------------------------------------------------------------------------------------\n";
    }
    if (menu_selector < 1 || menu_selector > 4)
    {
      cout << "You have selected an invalid menu option. Returning to main menu.\n"; // If user selects invalid menu slection, print error and return to menu
    }

    if (menu_selector == 1 || menu_selector == 2) // allows user to select which sorting method to sort students by
    {
      bool check = true;
      char user_input;
      while (check)
      {
        char user_selector = '0';
        cout << "Please enter what you would like to sort by:\n"
             << "Please select one of the folowing:\n"
             << "First Name: F, Last Name: L, CGPA: G, Research Score: R, ";
        if (menu_selector == 1) // uses province in the case of domestic students
        {
          cout << "Province: P";
        }
        if (menu_selector == 2) // uses country in the case of international students
        {
          cout << "Country: C";
        }
        cout << "\n>> ";
        cin >> user_selector;
        if (menu_selector == 1) // user input to select which option, case insensitive
        {
          if (user_selector == 'F' || user_selector == 'f' || user_selector == 'L' || user_selector == 'l' || user_selector == 'G' || user_selector == 'g' || user_selector == 'R' || user_selector == 'r' || user_selector == 'P' || user_selector == 'p')
          {
            check = false;
            user_input = user_selector;
            break;
          }
          else
          {
            cout << "\nPlease select the appropriate character only:\n";
            check = true;
          }
        }
        if (menu_selector == 2) // user input to select which option, case insensitive
        {
          if (user_selector == 'F' || user_selector == 'f' || user_selector == 'L' || user_selector == 'l' || user_selector == 'G' || user_selector == 'g' || user_selector == 'R' || user_selector == 'r' || user_selector == 'C' || user_selector == 'c')
          {
            check = false;
            user_input = user_selector;
            break;
          }
          else
          {
            cout << "\nPlease select the appropriate character only:\n";
            check = true;
          }
        }
      }
      if (menu_selector == 1) // selects domestic students
      {
        MergeSortDom(&DomHead, user_input);
        cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
        cout << "\nAll Sorted Domestic Students:\n\n";
        cout << setw(12) << left << "UID: ";
        cout << setw(14) << left << "First Name: "
             << " " << setw(17) << left << "Last Name: ";
        cout << setw(10) << left << "Province: ";
        cout << setw(6) << left << "CGPA: ";
        cout << setw(4) << left << "RS: " << endl;
        printDom(DomHead);
      }
      if (menu_selector == 2) // selects international students
      {
        MergeSortInt(&IntHead, user_input);
        cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
        cout << "\nAll Sorted International Students:\n\n";
        cout << setw(12) << left << "UID: ";
        cout << setw(14) << left << "First Name: "
             << " " << setw(17) << left << "Last Name: ";
        cout << setw(10) << left << "Country: ";
        cout << setw(6) << left << "CGPA: ";
        cout << setw(4) << left << "RS: ";
        cout << setw(4) << left << "R: ";
        cout << setw(4) << left << "L: ";
        cout << setw(4) << left << "S: ";
        cout << setw(4) << left << "W: ";
        cout << "Total Score: " << endl;
        printInt(IntHead);
      }
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (menu_selector == 3) // sorts all students
    {
      // MultiSort(&DomHead);
      // MultiSort(&IntHead);
      cout << "\nHead is: " << DomHead->head->domesticStudent;
      cout << "Tail is: " << DomHead->tail->domesticStudent;
      cout << "\nHead is: " << IntHead->head->internationalStudent;
      cout << "Tail is: " << IntHead->tail->internationalStudent;
      cout << endl;

      printDom(DomHead);
      cout << endl;
      printInt(IntHead);
      cout << endl;

      DomFindName(DomHead, "Jacob", "Rivera");
      cout << endl;
      DomFindCGPA(DomHead, 2.9);
      cout << endl;
      DomFindResearchScore(DomHead, 101);
      cout << endl;
      DomFindUID(DomHead, 20210069);
      cout << endl;
      DomFindName(DomHead, "Aurora", "Foster");
      cout << endl;
      printDom(DomHead);
      cout << endl;

      DomFindUID(DomHead, 20210099);
      cout << endl;

      Domestic NewStudent;
      NewStudent.setCGPA(4.3);
      NewStudent.setResearchScore(100);
      NewStudent.setFirstName("Gabus");
      NewStudent.setLastName("Anus");
      NewStudent.setUID(stu_count++);
      NewStudent.setProvince("BC");

      appendDom(&DomHead, NewStudent);
      // MergeSortDom(&DomHead, 'r');
      printDom(DomHead);

      cout << endl;
      DomFindUID(DomHead, 20210099);
      DomFindUID(DomHead, 20210100);
      cout << "\nHead is: " << DomHead->head->domesticStudent;
      cout << "Tail is: " << DomHead->tail->domesticStudent;
      cout << endl;

      deleteDom(&DomHead, "Gabus", "Anus");
      // MergeSortDom(&DomHead, 'r');
      printDom(DomHead);

      cout << endl;
      DomFindUID(DomHead, 20210099);
      DomFindUID(DomHead, 20210100);
      cout << "\nHead is: " << DomHead->head->domesticStudent;
      cout << "Tail is: " << DomHead->tail->domesticStudent;
      cout << endl;

      deleteDomHD(&DomHead);
      printDom(DomHead);

      cout << "\nHead is: " << DomHead->head->domesticStudent;
      cout << "Tail is: " << DomHead->tail->domesticStudent;
      cout << endl;
    CHOICE:
      int choice = 0;
      cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
      cout << "Please select one of the folowing:\n" // presents users with two options
           << "Select 1: to view Domestic and International Students Spearately\n"
           << "Select 2: to view all sorted students (Based on Research Score and CGPA only)\n"
           << ">> ";
      choice = Get_Number();
      if (choice < 1 || choice > 2) // error checking
      {
        cout << "You have selected an invalid menu option. Returning to selection.\n"; // If user selects invalid menu slection, print error and return to menu
        goto CHOICE;
      }
      if (choice == 1) // choice 1: view separately
      {
        cout << "\nAll Sorted Domestic Students:\n\n";
        cout << setw(12) << left << "UID: ";
        cout << setw(14) << left << "First Name: "
             << " " << setw(17) << left << "Last Name: ";
        cout << setw(10) << left << "Province: ";
        cout << setw(6) << left << "CGPA: ";
        cout << setw(4) << left << "RS: " << endl;
        printDom(DomHead);
        cout << "\nAll Sorted International Students:\n\n";
        cout << setw(12) << left << "UID: ";
        cout << setw(14) << left << "First Name: "
             << " " << setw(17) << left << "Last Name: ";
        cout << setw(10) << left << "Country: ";
        cout << setw(6) << left << "CGPA: ";
        cout << setw(4) << left << "RS: ";
        cout << setw(4) << left << "R: ";
        cout << setw(4) << left << "L: ";
        cout << setw(4) << left << "S: ";
        cout << setw(4) << left << "W: ";
        cout << "Total Score: " << endl;
        printInt(IntHead);
        cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
      }
      if (choice == 2) // choice 2: sort all students
      {
        cout << "\nAll Sorted Students: (Based on Research Score and CGPA only)\n\n";
        cout << setw(12) << left << "UID: ";
        cout << setw(14) << left << "First Name: "
             << " " << setw(17) << left << "Last Name: ";
        cout << setw(10) << left << "CGPA: ";
        cout << setw(6) << left << "RS: " << endl;
        // printMerge(/**/);
        cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
      }
    }

    else if (menu_selector == 4) // exit program prommpt
    {
      cout << "Are you sure you wish to completely exit the program? Use Y/N (yes or no) to proceed.\n" // Ensures that the user wishes to exit the program
           << ">> ";
      cin >> exitCheck;
      if (exitCheck == "Y" || exitCheck == "y" || exitCheck == "YES" || exitCheck == "yes" || exitCheck == "Yes") // Various forms of the so called term "yes" to agree to the terms of exiting the program
      {
        cout << "Exiting Script after cleaning up files!";
        cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
        break;
      }
      else if (exitCheck == "N" || exitCheck == "n" || exitCheck == "NO" || exitCheck == "no" || exitCheck == "No") // various forms of the so called term "no" to return to go through the main menu cycle from the beginiinng
      {
        cout << "\nReturning to main menu!\n";
        // clear input stream since last input was a string
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      else // If the Various forms of the so called term "yes" and "no" are not entered then we resort to force the person to go through the main menu cycle from the beginiinng
      {
        cout << "\nInput unrecognized: You are being returned to the main menu.\n";
        // clear input stream since last input was a string
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
    }
  }
  return 0;
}