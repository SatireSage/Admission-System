// main.cpp, put your driver code here,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>  //atof and atoi
#include <iomanip>
#include <limits> //numeric limit
#include "student.hpp"
#include "stu_sort.hpp"

using namespace std;

int Get_Number()
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
}

int lineCounter(ifstream &fileName)
{
  int i = 0;
  string line;
  while (getline(fileName, line))
    i++;
  fileName.clear();
  fileName.seekg(0, ios::beg);
  getline(fileName, line);
  return i;
}

int main()
{
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if (!domesticFile.is_open())
  {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);

  int i = 0;
  int stu_count = 1;
  int numDomesticStudents = lineCounter(domesticFile);
  Domestic *DomesticStudents = new Domestic[numDomesticStudents];
  while (getline(domesticFile, line))
  {
    istringstream ss(line);
    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

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

  ifstream InternationalFile("international-stu.txt");
  if (!InternationalFile.is_open())
  {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }

  getline(InternationalFile, line);

  int stu_inter_count = 1;
  int j = 0;
  int numInternationalStudents = lineCounter(InternationalFile);
  International *InternationalStudents = new International[numInternationalStudents];
  International *filteredInternational = new International[numInternationalStudents];
  while (getline(InternationalFile, line))
  {
    istringstream ss(line);
    string firstNameInt, lastNameInt, country, s_cgpa2, s_researchScore2, s_reading, s_listening, s_speaking, s_writing;
    float cgpa2;
    int researchScore2, reading, listening, speaking, writing;

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

  string exitCheck;
  while (true)
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

    if (menu_selector == 1 || menu_selector == 2)
    {
      bool check = true;
      char user_input;
      while (check)
      {
        char user_selector = '0';
        cout << "Please enter what you would like to sort by:\n"
             << "Please select one of the folowing:\n"
             << "First Name: F, Last Name: L, CGPA: G, Research Score: R, ";
        if (menu_selector == 1)
        {
          cout << "Province: P";
        }
        if (menu_selector == 2)
        {
          cout << "Country: C";
        }
        cout << "\n>> ";
        cin >> user_selector;
        if (menu_selector == 1)
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
        if (menu_selector == 2)
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
      if (menu_selector == 1)
      {
        SingleSort(DomesticStudents, 0, numDomesticStudents - 1, user_input);
        cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
        cout << "\nAll Sorted Domestic Students:\n";
        for (int i = 0; i < numDomesticStudents; i++)
        {
          cout << setw(5) << left << DomesticStudents[i];
        }
      }
      if (menu_selector == 2)
      {
        SingleSort(InternationalStudents, 0, numInternationalStudents - 1, user_input);
        cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
        cout << "\nAll Sorted International Students:\n";
        for (int i = 0; i < numInternationalStudents; i++)
        {
          cout << setw(5) << left << InternationalStudents[i];
        }
      }
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (menu_selector == 3)
    {
      MultiSort(DomesticStudents, numDomesticStudents);
      MultiSort(InternationalStudents, numInternationalStudents);
      int filteredIndex = 0;
      for (int j = 0; j < numInternationalStudents; j++)
      {
        if (InternationalStudents[j].getTotalScore() >= 93 && InternationalStudents[j].getReading() >= 20 && InternationalStudents[j].getListening() >= 20 && InternationalStudents[j].getSpeaking() >= 20 && InternationalStudents[j].getWriting() >= 20)
        {
          filteredInternational[filteredIndex++] = InternationalStudents[j];
        }
      }
      int totalIndex = 0;
      Student *AllStudents = new Student[numDomesticStudents + filteredIndex];
      for (int k = 0; k < numDomesticStudents; k++)
      {
        AllStudents[totalIndex++] = DomesticStudents[k];
      }
      for (int k = 0; k < filteredIndex; k++)
      {
        AllStudents[totalIndex++] = filteredInternational[k];
      }
      MultiSort(AllStudents, totalIndex - 1);
    CHOICE:
      int choice = 0;
      cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
      cout << "Please select one of the folowing:\n"
           << "Select 1: to view Domestic and International Students Spearately\n"
           << "Select 2: to view all sorted students (Based on Research Score and CGPA only)\n"
           << ">> ";
      choice = Get_Number();
      if (choice < 1 || choice > 2)
      {
        cout << "You have selected an invalid menu option. Returning to selection.\n"; // If user selects invalid menu slection, print error and return to menu
        goto CHOICE;
      }
      if (choice == 1)
      {
        cout << "\nAll Sorted Domestic Students:\n";
        for (int i = 0; i < numDomesticStudents; i++)
        {
          cout << setw(5) << left << DomesticStudents[i];
        }
        cout << "\nAll Sorted International Students:\n";
        for (int i = 0; i < filteredIndex; i++)
        {
          cout << setw(5) << left << filteredInternational[i];
        }
        cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
      }
      if (choice == 2)
      {
        cout << "\nAll Sorted Students: (Based on Research Score and CGPA only)\n";
        for (int i = 0; i < totalIndex; i++)
        {
          cout << setw(5) << left << AllStudents[i];
        }
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
        domesticFile.close();
        delete[] DomesticStudents;
        InternationalFile.close();
        delete[] InternationalStudents;
        delete[] filteredInternational;
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