// main.cpp, put your driver code here,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>
// atof and atoi
#include <iomanip>   // formatting
#include <limits>    //numeric limit
#include <algorithm> // for std::find
#include <iterator>  // for std::begin, std::end
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

double Get_Double() // checks validity of input
{
  string line;
  double user_input;
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
    (*root)->appendDom(root, arr[i]);
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
    (*root)->appendInt(root, arr[i]);
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
    (*root)->appendMerge(root, arr[i]);
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
  int numDomesticStudents = lineCounter(domesticFile);
  try
  {
    Domestic *DomesticStudents = new Domestic[numDomesticStudents];
    while (getline(domesticFile, line)) // creates first name, last name, province, gpa, and RS for each domestic student
    {
      istringstream ss(line);
      string firstName, lastName, province, s_cgpa, s_researchScore;
      float cgpa;
      int researchScore;
      string Provinces[] = {"NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU"};
      // takes data from txt file and sets object member variables
      try
      {
        getline(ss, firstName, ',');
        if (firstName == "")
          throw(firstName);
        DomesticStudents[i].setFirstName(firstName);
        getline(ss, lastName, ',');
        if (lastName == "")
          throw(lastName);
        DomesticStudents[i].setLastName(lastName);
        getline(ss, province, ',');
        if (find(begin(Provinces), end(Provinces), province) != end(Provinces))
        {
          DomesticStudents[i].setProvince(province);
        }
        else if (province == "")
        {
          throw(province);
        }
        else
        {
          cout << province << " is not a province in Canada. Exiting program." << endl;
          exit(1);
        }
        getline(ss, s_cgpa, ',');
        if (s_cgpa == "")
          throw(s_cgpa);
        cgpa = float(int(atof(s_cgpa.c_str()) * 10 + 0.5)) / 10;
        DomesticStudents[i].setCGPA(cgpa);
        getline(ss, s_researchScore, ',');
        if (s_researchScore == "")
          throw(s_researchScore);
        researchScore = int(atoi(s_researchScore.c_str()) + 0.5);
        DomesticStudents[i].setResearchScore(atoi(s_researchScore.c_str()));
        DomesticStudents[i].setType("Domestic");
        i++;
      }
      catch (string errorEmptyField)
      {
        cout << "There are field(s) missing in domestic file" << endl;
        exit(1);
      }
    }

    ifstream InternationalFile("international-stu.txt"); // connects file with international student info
    if (!InternationalFile.is_open())                    // error return in case of file not opening
    {
      cout << "Unable to open file international-stu.txt" << endl;
      return -1;
    }

    getline(InternationalFile, line);

    int j = 0;
    int numInternationalStudents = lineCounter(InternationalFile);
    try
    {
      International *InternationalStudents = new International[numInternationalStudents];
      while (getline(InternationalFile, line)) // creates first name, last name, province, gpa, and RS for each international student
      {
        istringstream ss(line);
        string firstNameInt, lastNameInt, country, s_cgpa2, s_researchScore2, s_reading, s_listening, s_speaking, s_writing;
        float cgpa2;
        int researchScore2, reading, listening, speaking, writing;
        try
        {
          // sets object member variables
          getline(ss, firstNameInt, ',');
          if (firstNameInt == "")
            throw(firstNameInt);
          InternationalStudents[j].setFirstName(firstNameInt);
          getline(ss, lastNameInt, ',');
          if (lastNameInt == "")
            throw(lastNameInt);
          InternationalStudents[j].setLastName(lastNameInt);
          getline(ss, country, ',');
          if ((country != "Canada") && (country != "China") && (country != "India") && (country != "Iran") && (country != "Korea"))
          {
            if (country == "Idian")
            {
              // output warning message
              cout << "Error: India was misspelled. Correcting error\n";
              country = "India";
              InternationalStudents[j].setCountry(country);
            }
            else
            {
              // output error because country isnt valid
              cout << "Error: An invalid country was entered: " << country;
              exit(1);
            }
          }
          else if (country == "")
          {
            throw(country);
          }
          else
          {
            InternationalStudents[j].setCountry(country);
          }

          getline(ss, s_cgpa2, ',');
          if (s_cgpa2 == "")
            throw(s_cgpa2);
          cgpa2 = float(int(atof(s_cgpa2.c_str()) * 10 + 0.5)) / 10;
          InternationalStudents[j].setCGPA(cgpa2);

          getline(ss, s_researchScore2, ',');
          if (s_researchScore2 == "")
            throw(s_researchScore2);
          researchScore2 = int(atoi(s_researchScore2.c_str()) + 0.5);
          InternationalStudents[j].setResearchScore(atoi(s_researchScore2.c_str()));

          getline(ss, s_reading, ',');
          if (s_reading == "")
            throw(s_reading);
          reading = atoi(s_reading.c_str());
          InternationalStudents[j].setReading(atoi(s_reading.c_str()));

          getline(ss, s_listening, ',');
          if (s_listening == "")
            throw(s_listening);
          listening = atoi(s_listening.c_str());
          InternationalStudents[j].setListening(atoi(s_listening.c_str()));

          getline(ss, s_speaking, ',');
          if (s_speaking == "")
            throw(s_speaking);
          speaking = atoi(s_speaking.c_str());
          InternationalStudents[j].setSpeaking(atoi(s_speaking.c_str()));

          getline(ss, s_writing, ',');
          if (s_writing == "")
            throw(s_writing);
          writing = atoi(s_writing.c_str());
          InternationalStudents[j].setWriting(atoi(s_writing.c_str()));
        }
        catch (string errorField)
        {
          cout << "There are field(s) missing in international file" << endl;
          exit(1);
        }

        InternationalStudents[j].setToeflScore(reading, listening, speaking, writing);
        InternationalStudents[j].setType("International");
        j++;
      }

      DomesticStudentList *DomHead = nullptr;
      arrayToListDom(DomesticStudents, numDomesticStudents, &DomHead);
      domesticFile.close();
      delete[] DomesticStudents;

      InternationalStudentList *IntHead = nullptr;
      arrayToListInt(InternationalStudents, numInternationalStudents, &IntHead);
      try
      {
        International *filteredInternational = new International[numInternationalStudents];
        try
        {
          International *rejectedInternational = new International[numInternationalStudents];
          int filteredIndex = 0;
          int rejectedIndex = 0;
          for (int j = 0; j < numInternationalStudents; j++) // removes international students not meeting requirements
          {
            if (InternationalStudents[j].getTotalScore() >= 93 && InternationalStudents[j].getReading() >= 20 && InternationalStudents[j].getListening() >= 20 && InternationalStudents[j].getSpeaking() >= 20 && InternationalStudents[j].getWriting() >= 20)
            {
              filteredInternational[filteredIndex++] = InternationalStudents[j];
            }
          }
          for (int j = 0; j < numInternationalStudents; j++) // removes international students not meeting requirements
          {
            if (InternationalStudents[j].getTotalScore() < 93 || InternationalStudents[j].getReading() < 20 || InternationalStudents[j].getListening() < 20 || InternationalStudents[j].getSpeaking() < 20 || InternationalStudents[j].getWriting() < 20)
            {
              rejectedInternational[rejectedIndex++] = InternationalStudents[j];
            }
          }

          InternationalStudentList *IntHeadFiltered = nullptr;
          InternationalStudentList *IntHeadRejected = nullptr;

          arrayToListInt(filteredInternational, filteredIndex, &IntHeadFiltered);
          arrayToListInt(rejectedInternational, rejectedIndex, &IntHeadRejected);
          InternationalFile.close();
          delete[] InternationalStudents;
          delete[] filteredInternational;
          delete[] rejectedInternational;

          StudentList *StuHead = nullptr;
          DomesticStudentList *currentDom = DomHead;
          InternationalStudentList *currentInt = IntHeadFiltered;
          while (currentDom != NULL)
          {
            StuHead->appendMerge(&StuHead, currentDom->domesticStudent);
            currentDom = currentDom->next;
          }
          while (currentInt != NULL)
          {
            StuHead->appendMerge(&StuHead, currentInt->internationalStudent);
            currentInt = currentInt->next;
          }
          StuHead->updateMergeHD(&StuHead);
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
                   << "Select 3: to sort All Students (Based on Research Score and CGPA only)\n"
                   << "Select 4: to insert new student\n"
                   << "Select 5: to delete a student\n"
                   << "Select 6: to delete head and tail nodes\n"
                   << "Select 7: to search for a student\n"
                   << "Select 8: to see All test cases\n"
                   << "Select 9: to display all rejected international students\n"
                   << "Select 10: to exit the program\n"
                   << ">> ";
              menu_selector = Get_Number(); // get user_input
              cout << "-----------------------------------------------------------------------------------------------------------------------\n";
            }
            if (menu_selector < 1 || menu_selector > 10)
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
                DomHead->updateDomHD(&DomHead);
                cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
                cout << "\nAll Sorted Domestic Students:\n\n";
                cout << setw(12) << left << "UID: ";
                cout << setw(14) << left << "First Name: "
                     << " " << setw(17) << left << "Last Name: ";
                cout << setw(10) << left << "Province: ";
                cout << setw(6) << left << "CGPA: ";
                cout << setw(4) << left << "RS: " << endl;
                DomHead->printDom(DomHead);
              }
              if (menu_selector == 2) // selects international students
              {
                MergeSortInt(&IntHeadFiltered, user_input);
                IntHeadFiltered->updateIntHD(&IntHeadFiltered);
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
                IntHeadFiltered->printInt(IntHeadFiltered);
              }
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (menu_selector == 3) // sorts all students
            {
              MergeSortDom(&DomHead);
              MergeSortInt(&IntHead);

              MergeSortAll(&StuHead);
              StuHead->updateMergeHD(&StuHead);
              cout << "\nAll Sorted Students: (Based on Research Score and CGPA only)\n\n";
              cout << setw(12) << left << "UID: ";
              cout << setw(14) << left << "First Name: "
                   << " " << setw(17) << left << "Last Name: ";
              cout << setw(10) << left << "CGPA: ";
              cout << setw(6) << left << "RS: " << endl;
              StuHead->printMerge(StuHead);
              cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
            }

            if (menu_selector == 4)
            {
            USER_CHOICE:
              int user_choice = 1;
              cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
              cout << "Please select one of the following:\n"
                   << "Select 1: Insert Domestic Student\n"
                   << "Select 2: Insert International Student\n"
                   << ">> ";
              user_choice = Get_Number();
              if (user_choice != 1 && user_choice != 2)
              {
                cout << "You have selected an invalid menu option. Returning to selection.\n"; // If user selects invalid menu slection, print error and return to menu
                goto USER_CHOICE;
              }
              if (user_choice == 1)
              {
                int tempNum = 0;
                bool check = false;
                string userString;
                string firstNameVal, lastNameVal, typeVal, provinceVal;
                float cgpaDom;
                int rsDom;
                string Provinces[] = {"NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU"};
                cout << "Please enter first name" << endl;
                cin >> userString;
                firstNameVal = userString;
                cout << "Please enter last name" << endl;
                cin >> userString;
                lastNameVal = userString;
                cout << "Please enter province" << endl;

                while (true)
                {
                  cin >> userString;
                  transform(userString.begin(), userString.end(), userString.begin(), ::toupper);
                  if (find(begin(Provinces), end(Provinces), userString) != end(Provinces))
                  {
                    provinceVal = userString;
                    break;
                  }
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  cout << "Please enter a valid 2 letter prefix for a Canadian province" << endl;
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter CGPA" << endl;
                while (true)
                {
                  double tempDouble;
                  tempDouble = Get_Double();
                  cgpaDom = float(int(tempDouble * 10 + 0.5)) / 10;
                  if (cgpaDom <= 4.31 && cgpaDom >= 0)
                  {
                    break;
                  }

                  cout << "Please enter a valid CGPA" << endl;
                }
                check = false;
                cout << "Please enter research score" << endl;
                while (check != true)
                {
                  tempNum = Get_Number();
                  if (tempNum <= 100 && tempNum >= 0)
                  {
                    rsDom = tempNum;
                    check = true;
                  }
                  else
                  {
                    cout << "Please enter a valid research score" << endl;
                  }
                }
                typeVal = "Domestic";
                Domestic NewStudentDom(firstNameVal, lastNameVal, typeVal, provinceVal, cgpaDom, rsDom);
                DomHead->appendDom(&DomHead, NewStudentDom);
                MergeSortDom(&DomHead);
                DomHead->updateDomHD(&DomHead);
                StuHead->appendMerge(&StuHead, NewStudentDom);
                StuHead->updateMergeHD(&StuHead);
              }
              if (user_choice == 2)
              {
                int tempNum = 0;
                int readInt, speakInt, writeInt, listInt, rsInt;
                bool check = false;
                // International NewStudentInt;
                string userString, firstInt, lastInt, typeVal, countryVal;
                float cgpaInt;
                string Countries[] = {"canada", "china", "india", "iran", "korea"};
                cout << "Please enter first name" << endl;
                cin >> userString;
                firstInt = userString;
                // NewStudentInt.setFirstName(userString);
                cout << "Please enter last name" << endl;
                cin >> userString;
                lastInt = userString;
                // NewStudentInt.setLastName(userString);
                cout << "Please enter country" << endl;
                while (true)
                {
                  cin >> userString;
                  transform(userString.begin(), userString.end(), userString.begin(), ::tolower);
                  if (userString == "idian")
                  {
                    cout << "Error: India was misspelled. Correcting error\n";
                    userString = "Indian";
                    // NewStudentInt.setCountry(userString);
                    countryVal = userString;
                    break;
                  }
                  if (find(begin(Countries), end(Countries), userString) != end(Countries))
                  {
                    userString[0] = toupper(userString[0]);
                    // NewStudentInt.setCountry(userString);
                    countryVal = userString;
                    break;
                  }
                  cout << "ERROR: These are the accepted countries: Canada, China, India, Iran, and Korea" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter CGPA" << endl;
                while (check != true)
                {
                  double tempDouble;
                  tempDouble = Get_Double();
                  cgpaInt = float(int(tempDouble * 10 + 0.5)) / 10;
                  if (cgpaInt < 4.31 && cgpaInt > 0)
                  {
                    // NewStudentInt.setCGPA(cgpaInt);
                    check = true;
                  }
                  else
                  {
                    cout << "Please enter a valid CGPA" << endl;
                  }
                }
                check = false;
                cout << "Please enter research score" << endl;
                while (check != true)
                {
                  tempNum = Get_Number();
                  if (tempNum <= 100 && tempNum >= 0)
                  {
                    // NewStudentInt.setResearchScore(tempNum);
                    rsInt = tempNum;
                    check = true;
                  }
                  else
                  {
                    cout << "Please enter a valid research score" << endl;
                  }
                }
                check = false;
                cout << "Please enter reading score" << endl;
                while (check != true)
                {
                  tempNum = Get_Number();
                  if (tempNum <= 30 && tempNum >= 0)
                  {
                    // NewStudentInt.setReading(tempNum);
                    readInt = tempNum;
                    check = true;
                  }
                  else
                  {
                    cout << "Please enter a valid reading score" << endl;
                  }
                }
                check = false;
                cout << "Please enter listening score" << endl;
                while (check != true)
                {
                  tempNum = Get_Number();
                  if (tempNum <= 30 && tempNum >= 0)
                  {
                    // NewStudentInt.setListening(tempNum);
                    listInt = tempNum;
                    check = true;
                  }
                  else
                  {
                    cout << "Please enter a valid listening score" << endl;
                  }
                }
                check = false;
                cout << "Please enter speaking score" << endl;
                while (check != true)
                {
                  tempNum = Get_Number();
                  if (tempNum <= 30 && tempNum >= 0)
                  {
                    // NewStudentInt.setSpeaking(tempNum);
                    speakInt = tempNum;
                    check = true;
                  }
                  else
                  {
                    cout << "Please enter a valid speaking score" << endl;
                  }
                }
                check = false;
                cout << "Please enter writing score" << endl;
                while (check != true)
                {
                  tempNum = Get_Number();
                  if (tempNum <= 30 && tempNum >= 0)
                  {
                    // NewStudentInt.setWriting(tempNum);
                    writeInt = tempNum;
                    check = true;
                  }
                  else
                  {
                    cout << "Please enter a valid writing score" << endl;
                  }
                }
                typeVal = "International";
                International NewStudentInt(firstInt, lastInt, typeVal, countryVal, cgpaInt, rsInt, readInt, listInt, speakInt, writeInt);
                // NewStudentInt.setType("International");
                if (NewStudentInt.getTotalScore() >= 93 && NewStudentInt.getReading() >= 20 && NewStudentInt.getListening() >= 20 && NewStudentInt.getSpeaking() >= 20 && NewStudentInt.getWriting() >= 20)
                {
                  IntHead->appendInt(&IntHead, NewStudentInt);
                  MergeSortInt(&IntHead);
                  IntHead->updateIntHD(&IntHead);
                  StuHead->appendMerge(&StuHead, NewStudentInt);
                  StuHead->updateMergeHD(&StuHead);
                }
                else
                {
                  IntHeadRejected->appendInt(&IntHeadRejected, NewStudentInt);
                  MergeSortInt(&IntHeadRejected);
                  IntHeadRejected->updateIntHD(&IntHeadRejected);
                  cout << "International student does not meet TOEFL requirements and can't be added to system. Returning to menu" << endl;
                }
              }
            }
            if (menu_selector == 5)
            {
            DEL_CHOICE:
              int delMenu;
              cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
              cout << "Please select one of the following:\n"
                   << "Select 1: Delete Domestic Student\n"
                   << "Select 2: Delete International Student\n"
                   << ">> ";
              delMenu = Get_Number();
              if (delMenu != 1 && delMenu != 2)
              {
                cout << "You have selected an invalid menu option. Returning to selection.\n"; // If user selects invalid menu slection, print error and return to menu
                goto DEL_CHOICE;
              }
              string first, last;
              cout << "Please enter first name of student you want to delete" << endl;
              cin >> first;
              cout << "Please enter last name" << endl;
              cin >> last;
              if (delMenu == 1)
              {
                DomHead->deleteDom(&DomHead, first, last);
                MergeSortDom(&DomHead);
                DomHead->updateDomHD(&DomHead);
                MergeSortAll(&StuHead);
              }
              else
              {
                IntHead->deleteInt(&IntHead, first, last);
                MergeSortInt(&IntHead);
                IntHead->updateIntHD(&IntHead);
                MergeSortAll(&StuHead);
              }
              cout << "Returning to main menu" << endl;
            }
            if (menu_selector == 6)
            {
            DH_CHOICE:
              int delMenu;
              cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
              cout << "Please select one of the following:\n"
                   << "Select 1: Delete head and tail of Domestic Student list\n"
                   << "Select 2: Delete head and tail of International Student list\n"
                   << ">> ";
              delMenu = Get_Number();
              if (delMenu != 1 && delMenu != 2)
              {
                cout << "You have selected an invalid menu option. Returning to selection.\n"; // If user selects invalid menu slection, print error and return to menu
                goto DH_CHOICE;
              }
              if (delMenu == 1)
              {
                DomHead->deleteDomHD(&DomHead);
                DomHead->updateDomHD(&DomHead);
              }
              else
              {
                IntHead->deleteIntHD(&IntHead);
                IntHead->updateIntHD(&IntHead);
              }
              cout << "Returning to main menu" << endl;
            }
            if (menu_selector == 7) // search
            {
            MENSEV_CHOICE:
              int delMenu;
              cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
              cout << "Please select one of the following:\n"
                   << "Select 1: to search Domestic Student\n"
                   << "Select 2: to seatch International Student\n"
                   << ">> ";
              delMenu = Get_Number();
              if (delMenu != 1 && delMenu != 2)
              {
                cout << "You have selected an invalid menu option. Returning to selection.\n"; // If user selects invalid menu slection, print error and return to menu
                goto MENSEV_CHOICE;
              }
            MENSUB_CHOICE:
              int subMenu;
              cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
              cout << "Please select one of the following:\n"
                   << "Select 1: to search name\n"
                   << "Select 2: to search CGPA\n"
                   << "Select 3: to search reasearch score\n"
                   << "Select 4: to search UID\n"
                   << ">> ";
              subMenu = Get_Number();
              if (subMenu < 1 || subMenu > 4)
              {
                cout << "You have selected an invalid menu option. Returning to selection.\n"; // If user selects invalid menu slection, print error and return to menu
                goto MENSUB_CHOICE;
              }
              if (subMenu == 1)
              {
                string userFirst, userLast;
                cout << "Please enter first name" << endl;
                cin >> userFirst;
                cout << "Please enter last name" << endl;
                cin >> userLast;
                cout << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (delMenu == 1)
                {
                  cout << setw(12) << left << "UID: ";
                  cout << setw(14) << left << "First Name: "
                       << " " << setw(17) << left << "Last Name: ";
                  cout << setw(10) << left << "Province: ";
                  cout << setw(6) << left << "CGPA: ";
                  cout << setw(4) << left << "RS: " << endl;
                  DomFindName(DomHead, userFirst, userLast);
                  cout << endl;
                }
                else
                {
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
                  IntFindName(IntHead, userFirst, userLast);
                }
              }
              if (subMenu == 2)
              {
                float cgpaSearch;
                cout << "Please enter CGPA" << endl;
                while (true)
                {
                  double tempDouble;
                  tempDouble = Get_Double();
                  cout << endl;
                  cgpaSearch = float(int(tempDouble * 10 + 0.5)) / 10;
                  if (cgpaSearch < 4.31 && cgpaSearch > 0)
                  {
                    if (delMenu == 1)
                    {
                      cout << setw(12) << left << "UID: ";
                      cout << setw(14) << left << "First Name: "
                           << " " << setw(17) << left << "Last Name: ";
                      cout << setw(10) << left << "Province: ";
                      cout << setw(6) << left << "CGPA: ";
                      cout << setw(4) << left << "RS: " << endl;
                      DomFindCGPA(DomHead, cgpaSearch);
                    }
                    else
                    {
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
                      IntFindCGPA(IntHead, cgpaSearch);
                    }
                    break;
                  }
                  else
                  {
                    cout << "Please enter a valid CGPA" << endl;
                  }
                }
              }
              if (subMenu == 3)
              {
                int tempNum;
                cout << "Please enter research score" << endl;
                while (true)
                {
                  tempNum = Get_Number();
                  cout << endl;
                  if (tempNum <= 100 && tempNum >= 0)
                  {
                    if (delMenu == 1)
                    {
                      cout << setw(12) << left << "UID: ";
                      cout << setw(14) << left << "First Name: "
                           << " " << setw(17) << left << "Last Name: ";
                      cout << setw(10) << left << "Province: ";
                      cout << setw(6) << left << "CGPA: ";
                      cout << setw(4) << left << "RS: " << endl;
                      DomFindResearchScore(DomHead, tempNum);
                    }
                    else
                    {
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
                      IntFindResearchScore(IntHead, tempNum);
                    }
                    break;
                  }
                  else
                  {
                    cout << "Please enter a valid reading score" << endl;
                  }
                }
              }
              if (subMenu == 4)
              {
                int tempNum;
                cout << "Please enter UID" << endl;
                tempNum = Get_Number();
                if (delMenu == 1)
                {
                  cout << setw(12) << left << "UID: ";
                  cout << setw(14) << left << "First Name: "
                       << " " << setw(17) << left << "Last Name: ";
                  cout << setw(10) << left << "Province: ";
                  cout << setw(6) << left << "CGPA: ";
                  cout << setw(4) << left << "RS: " << endl;
                  DomFindUID(DomHead, tempNum);
                }
                else
                {
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
                  IntFindUID(IntHead, tempNum);
                }
              }
            }
            if (menu_selector == 8)
            {
              cout << "Test 1: Append new student to domestic and international lists" << endl;
              Domestic NewStudentDom("Gabus", "Anus", "Domestic", "BC", 4.3, 100);
              DomHead->appendDom(&DomHead, NewStudentDom);
              MergeSortDom(&DomHead);
              DomHead->updateDomHD(&DomHead);
              DomHead->printDom(DomHead);
              cout << "\nHead is: " << DomHead->head->domesticStudent;
              cout << "Tail is: " << DomHead->tail->domesticStudent;
              cout << endl;

              International NewStudentInt("NotGabus", "Anus", "International", "India", 4.3, 100, 22, 22, 22, 22);
              IntHead->appendInt(&IntHead, NewStudentInt);
              if (NewStudentInt.getTotalScore() >= 93 && NewStudentInt.getReading() >= 20 && NewStudentInt.getListening() >= 20 && NewStudentInt.getSpeaking() >= 20 && NewStudentInt.getWriting() >= 20)
              {
                IntHeadFiltered->appendInt(&IntHeadFiltered, NewStudentInt);
              }
              else
              {
                IntHeadRejected->appendInt(&IntHeadRejected, NewStudentInt);
              }
              MergeSortInt(&IntHead);
              IntHead->updateIntHD(&IntHead);
              IntHead->printInt(IntHead);
              cout << "\nHead is: " << IntHead->head->internationalStudent;
              cout << "Tail is: " << IntHead->tail->internationalStudent;
              cout << endl;

              cout << "Test 2: Search for students in domestic and international lists" << endl;
              DomFindName(DomHead, "Jacob", "Rivera");
              cout << endl;
              DomFindCGPA(DomHead, 2.9);
              cout << endl;
              DomFindResearchScore(DomHead, 99);
              cout << endl;
              DomFindUID(DomHead, 20210069);
              cout << endl;
              DomFindName(DomHead, "Aurora", "Foster");
              cout << endl;
              DomHead->printDom(DomHead);
              cout << endl;

              IntFindName(IntHead, "Haeun", "Choi");
              cout << endl;
              IntFindCGPA(IntHead, 2.9);
              cout << endl;
              IntFindResearchScore(IntHead, 99);
              cout << endl;
              IntFindUID(IntHead, 20210169);
              cout << endl;
              IntHead->printInt(IntHead);
              cout << endl;

              cout << "Test 3: Delete students from domestic and international lists" << endl;
              DomHead->deleteDom(&DomHead, "Gabus", "Anus");
              MergeSortDom(&DomHead);
              DomHead->updateDomHD(&DomHead);
              DomHead->printDom(DomHead);
              cout << "\nHead is: " << DomHead->head->domesticStudent;
              cout << "Tail is: " << DomHead->tail->domesticStudent;
              cout << endl;

              IntHead->deleteInt(&IntHead, "NotGabus", "Anus");
              MergeSortInt(&IntHead);
              IntHead->updateIntHD(&IntHead);
              IntHead->printInt(IntHead);
              cout << "\nHead is: " << IntHead->head->internationalStudent;
              cout << "Tail is: " << IntHead->tail->internationalStudent;
              cout << endl;

              cout << "Test 4: Delete head and tail nodes from domestic and international lists" << endl;
              DomHead->deleteDomHD(&DomHead);
              DomHead->updateDomHD(&DomHead);
              DomHead->printDom(DomHead);
              cout << "\nHead is: " << DomHead->head->domesticStudent;
              cout << "Tail is: " << DomHead->tail->domesticStudent;
              cout << endl;

              IntHead->deleteIntHD(&IntHead);
              IntHead->updateIntHD(&IntHead);
              IntHead->printInt(IntHead);
              cout << "\nHead is: " << IntHead->head->internationalStudent;
              cout << "Tail is: " << IntHead->tail->internationalStudent;
              cout << endl;

              cout << "Test 5: Merged student lists" << endl;
              MergeSortAll(&StuHead);
              StuHead->printMerge(StuHead);
              StuHead->updateMergeHD(&StuHead);
              cout << "\nHead is: " << StuHead->head->Students;
              cout << "Tail is: " << StuHead->tail->Students;
              cout << endl;

              cout << "Test 6: Display students based on threshold" << endl;
              StuHead->threshold(StuHead, 3.9, 90);
              cout << endl;

              cout << "End of test cases";
              cout << endl;
            }

            if (menu_selector == 9)
            {
              MergeSortInt(&IntHeadRejected);
              IntHeadRejected->updateIntHD(&IntHeadRejected);
              cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
              cout << "\nAll rejected International Students:\n\n";
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
              IntHeadRejected->printInt(IntHeadRejected);
            }

            if (menu_selector == 10) // exit program prommpt
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
        catch (bad_alloc)
        {
          std::cout << "Warning: Bad memory allocation." << '\n';
        }
      }
      catch (bad_alloc)
      {
        std::cout << "Warning: Bad memory allocation." << '\n';
      }
    }
    catch (bad_alloc)
    {
      std::cout << "Warning: Bad memory allocation." << '\n';
    }
  }
  catch (bad_alloc)
  {
    std::cout << "Warning: Bad memory allocation." << '\n';
  }
}