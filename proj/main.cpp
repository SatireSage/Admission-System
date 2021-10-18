// main.cpp, put your driver code here,
// you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream>  //file processing
#include <sstream>  //formatted string processing
#include <cstdlib>  //atof and atoi
#include <iomanip>
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

    cout << "Domestic student " << stu_count << " " << firstName << " "
         << lastName << " from " << province << " province has cgpa of "
         << cgpa << ", and research score of " << researchScore << endl;

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
  cout << endl
       << "File format: " << line << endl;

  int stu_inter_count = 1;
  int j = 0;
  int numInternationalStudents = lineCounter(InternationalFile);
  International *InternationalStudents = new International[numInternationalStudents];
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

    cout << "International student " << stu_inter_count << " " << firstNameInt << " "
         << lastNameInt << " from " << country << " has cgpa of "
         << cgpa2 << ", and research score of " << researchScore2
         << " Reading Score: " << reading << " "
         << " Listening Score: " << listening << " "
         << " Speaking Score: " << speaking << " "
         << " Writing Score: " << writing << endl;

    InternationalStudents[j].setUID(numDomesticStudents + stu_inter_count);
    j++;
    stu_inter_count++;
  }

  // close your file
  domesticFile.close();
  delete[] DomesticStudents;
  InternationalFile.close();
  delete[] InternationalStudents;

  return 0;
}