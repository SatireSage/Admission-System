// main.cpp, put your driver code here,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>  //atof and atoi
#include "student.hpp"
#include "stu_sort.hpp"

int lineCounter(ifstream &file)
{
  int i = 0;
  string line;
  while (getline(file, line))
    i++;
  // reset the position in the file for the user
  file.clear();
  file.seekg(0, ios::beg);
  getline(file, line);
  return i;
}

/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */
int main()
{
  // Read the domestic-stu.txt file and exit if failed
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if (!domesticFile.is_open())
  {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);
  cout << "File format: " << line << endl;
  int i = 0;
  int stu_count = 1;
  int numDomesticStudents = lineCounter(domesticFile) - 1;
  while (getline(domesticFile, line))
  {
    istringstream ss(line);
    Domestic *DomesticStudents = new Domestic[numDomesticStudents];
    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    // get firstName separated by comma
    getline(ss, firstName, ',');
    DomesticStudents[i].setFirstName(firstName);
    // get lastName separated by comma
    getline(ss, lastName, ',');
    DomesticStudents[i].setLastName(lastName);
    // get province separated by comma
    getline(ss, province, ',');
    DomesticStudents[i].setProvince(province);
    // get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    DomesticStudents[i].setCGPA(atof(s_cgpa.c_str()));
    // get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    DomesticStudents[i].setResearchScore(atoi(s_researchScore.c_str()));

    // print the student info to the screen
    cout << "Domestic student " << stu_count << " " << firstName << " "
         << lastName << " from " << province << " province has cgpa of "
         << cgpa << ", and research score of " << researchScore << endl;

    DomesticStudents[i++].setUID(stu_count++);
  }

  ifstream InternationalFile("international-stu.txt");
  if (!InternationalFile.is_open())
  {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }

  getline(InternationalFile, line);
  cout << endl
       << "File format: " << line << endl;

  int stu_inter_count = 1;
  int j = 0;
  int numInternationalStudents = lineCounter(InternationalFile) - 1;
  while (getline(InternationalFile, line))
  {
    istringstream ss(line);
    International *InternationalStudents = new International[numInternationalStudents];
    // FirstName,LastName,Country,CGPA,ResearchScore,Reading,Listening,Speaking,Writing
    string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore, reading, listening, speaking, writing;

    getline(ss, firstName, ',');
    InternationalStudents[j].setFirstName(firstName);
    getline(ss, lastName, ',');
    InternationalStudents[j].setLastName(lastName);
    getline(ss, country, ',');
    InternationalStudents[j].setCountry(country);

    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    InternationalStudents[j].setCGPA(atof(s_cgpa.c_str()));

    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    InternationalStudents[j].setResearchScore(atoi(s_researchScore.c_str()));

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

    cout << "International student " << stu_inter_count << " " << firstName << " "
         << lastName << " from " << country << " has cgpa of "
         << cgpa << ", and research score of " << researchScore
         << " Reading Score: " << reading << " "
         << " Listening Score: " << listening << " "
         << " Speaking Score: " << speaking << " "
         << " Writing Score: " << writing << endl;

    InternationalStudents[j++].setUID(stu_inter_count++);
  }
  // close your file
  domesticFile.close();
  InternationalFile.close();

  return 0;
}