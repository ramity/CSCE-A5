#include <iostream>
#include <string>//for strings
#include <math.h>
#include <iomanip>//for setw
#include <fstream>//for files
#include <cstdlib>//for exit

using namespace std;

int const COURSE_MAX = 10;

bool reading(const char filename[], string name[], string time[], string number[], char grade[], int hours[], int& n, int capacity)
{
  // filename is course file on disk to be read
  // name is an array of course names
  // time is an array of semester and year a course was taken
  // number is an array of course numbers
  // grade is an array of letter grades
  // hours is an array of credit hours
  // n is the number of courses read upon return
  // capacity indicates the max elements the arrays may hold
  // the function returns true if file open and reading
  // are successful, otherwise it returns false
  // the function reads course information from the file
  // and stores the information to the arrays

  fstream file;
  file.open(filename);

  if(file.fail())
  {
    cout << "Failed to open file named: " << filename << endl;
    cout << "Error in reading the deafult file. Terminating..." << endl;
    exit(EXIT_FAILURE);
  }

  if(file.is_open())
  {
    //gets first line
    file >> n;

    if(n > capacity)
    {
      for(int z = 0;z < n;z++)
      {
        cout << "Reading class " << z + 1 << endl;
        getline(file,name[z]);
        //getline(file,name[z]);
        getline(file,time[z]);
        getline(file,number[z]);
        file >> grade[z];
        file >> hours[z];
      }
    }
    else
    {
      cout << "specified size on text file: " << filename << " is too large" << endl;
    }
  }

  file.close();

  return 1;
}

bool writing(const char filename[], const string name[], const string time[], const string number[], const char grade[], const int hours[], int n)
{
  // filename is course file on disk to be written
  // name is an array of course names
  // time is an array of semester and year a course was taken
  // number is an array of course numbers
  // grade is an array of letter grades
  // hours is an array of credit hours
  // n is the number of courses in the arrays
  // the function returns true if file open and writing
  // are successful, otherwise it returns false
  // the function stores course information of the arrays
  // to the file, similar to listing function of project 4
}

double gpa(int n, const char grades[], const int hours[])
{
  double tempGradePointsSum = 0;
  double tempCreditHoursSum = 0;
  double tempGradePointRep = -1;

  for(int courseNumber = 0; courseNumber < n; courseNumber++)
  {
    if(grades[courseNumber] == 'A')
    {
      tempGradePointRep = 4;
    }
    else if(grades[courseNumber] == 'B')
    {
      tempGradePointRep = 3;
    }
    else if(grades[courseNumber] == 'C')
    {
      tempGradePointRep = 2;
    }
    else if(grades[courseNumber] == 'D')
    {
      tempGradePointRep = 1;
    }
    else if(grades[courseNumber] == 'F')
    {
      tempGradePointRep = 0;
    }
    else
    {
      tempGradePointRep = -1;
    }

    if(tempGradePointRep >= 0)
    {
      tempGradePointsSum += (hours[courseNumber] * tempGradePointRep);
      tempCreditHoursSum += hours[courseNumber];
    }
  }

  if(tempCreditHoursSum > 0)
    return (tempGradePointsSum / tempCreditHoursSum);
  else
    cout << "An error occured" << endl;
}

double semesterGpa(int n, const string times[], const char grades[], const int hours[], string semester)
{
  double tempGradePointsSum = 0;
  double tempCreditHoursSum = 0;
  double tempGradePointRep = -1;

  for(int courseNumber = 0; courseNumber < n; courseNumber++)
  {
    if(times[courseNumber] == semester)
    {
      if(grades[courseNumber] == 'A')
      {
        tempGradePointRep = 4;
      }
      else if(grades[courseNumber] == 'B')
      {
        tempGradePointRep = 3;
      }
      else if(grades[courseNumber] == 'C')
      {
        tempGradePointRep = 2;
      }
      else if(grades[courseNumber] == 'D')
      {
        tempGradePointRep = 1;
      }
      else if(grades[courseNumber] == 'F')
      {
        tempGradePointRep = 0;
      }
      else
      {
        tempGradePointRep = -1;
      }

      if(tempGradePointRep >= 0)
      {
        tempGradePointsSum += (hours[courseNumber] * tempGradePointRep);
        tempCreditHoursSum += hours[courseNumber];
      }
    }
  }

  if(tempCreditHoursSum > 0)
    return (tempGradePointsSum / tempCreditHoursSum);
  else
    cout << "An error occured" << endl;
}

int DRule(int n, char grades[], int hours[])
{
  int calculation = 0;

  for(int z = 0;z < n;z++)
  {
    if(grades[z] == 1)
    {
      calculation += hours[z];
    }
  }

  return calculation;
}

void print(int n, string names[], string times[], string numbers[], char grades[], int hours[])
{
  cout << "Displaying (" << n << " of " << n << ") courses." << endl;
  cout << endl;
  cout << "Course Name" << setw(20) << "Semester" << setw(20) << "Course Number" << setw(20) << "Grade" << setw(20) << "Hour" << endl;
  //lists all courses
  for(int z = 0;z<n;z++)
  {
    cout << names[z] << setw(20) << times[z] << setw(20) << numbers[z] << setw(20) << grades[z] << setw(20) << hours[z] << endl;
  }
}

void getCourse(string& name, string& time, string& number, char& grade, int& hours, int n)
{
  //name
  cout << "Enter the course name (e.g. Programming Foundations I) for class number " << n << endl;
  getline(cin,name);

  while(name == "")
  {
    cout << "Invalid input. Please try again." << endl;
    getline(cin,name);
  }
  //time
  cout << "Enter the semester (e.g. Spring 2016) for class number " << n << endl;
  getline(cin,time);

  while(time == "")
  {
    cout << "Invalid input. Please try again." << endl;
    getline(cin,time);
  }
  //number
  cout << "Enter the course number (e.g. CSCE 2004) for class number " << n << endl;
  getline(cin,number);

  while(number == "")
  {
    cout << "Invalid input. Please try again." << endl;
    getline(cin,number);
  }
  //grade
  string tempString = "";
  while(tempString == "")
  {
    cout << "Enter the grade (A,B,C,D,F,W,I) for class number " << n << endl;
    getline(cin,tempString);

    if(tempString == "A" || tempString == "a")
    {
      grade = 'A';
    }
    else if(tempString == "B" || tempString == "b")
    {
      grade = 'B';
    }
    else if(tempString == "C" || tempString == "c")
    {
      grade = 'C';
    }
    else if(tempString == "D" || tempString == "d")
    {
      grade = 'D';
    }
    else if(tempString == "F" || tempString == "f")
    {
      grade = 'F';
    }
    else if(tempString == "W" || tempString == "w")
    {
      grade = 'W';
    }
    else if(tempString == "I" || tempString == "i")
    {
      grade = 'I';
    }
    else
    {
      tempString = "";
      cout << "Invalid user input, please try again" << endl;
    }
  }
  //number
  cout << "Enter the course hours (1 ... 5) for class number " << n << endl;
  cin >> hours;

  while(hours < 1 && hours > 5)
  {
    cout << "Invalid user input, please try again." << endl;
    cout << "Enter the course hours (1 ... 5) for class number " << n << endl;
    cin >> hours;
  }
}

char menu()
{
  string tempString;

  //return overrides while loop
  while(true)
  {
    cout << "Please enter the character next to the choice you wish to pick." << endl;
    cout << "Here are your options:" << endl;
    cout << "A(a) . Compute the GPA of all courses" << endl;
    cout << "B(b) . List all courses" << endl;
    cout << "C(c) . Compute the total credit hours of the courses with grade D" << endl;
    cout << "D(d) . Compute the GPA for a particular semester" << endl;
    cout << "E(e) . Add another course to the course list" << endl;
    cout << "F(f) . Delete a course from the course list" << endl;
    cout << "Q(q) . Quit the program" << endl;
    cout << "Please choose one of the above" << endl;

    getline(cin,tempString);

    if(tempString == "A" || tempString == "a")
    {
      return 'A';
    }
    else if(tempString == "B" || tempString == "b")
    {
      return 'B';
    }
    else if(tempString == "C" || tempString == "c")
    {
      return 'C';
    }
    else if(tempString == "D" || tempString == "d")
    {
      return 'D';
    }
    else if(tempString == "E" || tempString == "e")
    {
      return 'E';
    }
    else if(tempString == "F" || tempString == "f")
    {
      return 'F';
    }
    else if(tempString == "Q" || tempString == "q")
    {
      return 'Q';
    }
    else
    {
      cout << "Invalid selection. Please try again." << endl;
    }
  }
}

int main ()
{
  int courses = 0;
  string mode = "";
  string tempString = "";

  //init all vars
  //initalizes all array vars based on defined validated input above
  string courseNames[COURSE_MAX];
  string semesters[COURSE_MAX];
  string courseNumbers[COURSE_MAX];
  //stores as numerical equiv of letter grade for easier calculation
  char courseGrades[COURSE_MAX] = {0};
  int courseHours[COURSE_MAX] = {0};

  cout << "Welcome to PFI course management system v1" << endl;
  cout << "Would ou like to read the courses taken from a file?" << endl;
  cout << "Please enter y for yes and n for no" << endl;
  getline(cin, mode);

  while(mode != "y" && mode != "n")
  {
    cout << "The character entered is " << mode << ". That is not y or n";
    cout << "Would ou like to read the courses taken from a file?" << endl;
    cout << "Please enter y for yes and n for no" << endl;
    getline(cin, mode);
  }

  if(mode == "y")
  {
    string stock = "";

    cout << "Would you like to use the default file?" << endl;
    cout << "Please enter y for yes and n for no" << endl;
    getline(cin, stock);

    while(stock != "y" && stock != "n")
    {
      cout << "The character entered is " << stock << ". That is not y or n";
      cout << "Would you like to use the default file?" << endl;
      cout << "Please enter y for yes and n for no" << endl;
      getline(cin, stock);
    }

    if(mode == "y")
    {
      reading("courses.txt", courseNames, semesters, courseNumbers, courseGrades, courseHours, courses, COURSE_MAX);
    }
    else
    {
      string selectedFilename;
      cout << "Enter your file name" << endl;
      getline(cin, selectedFilename);

      while(selectedFilename == "")
      {
        cout << "Invalid filename. Please try again." << endl;
        getline(cin, selectedFilename);
      }

      cout << "Welcome to the interactive menu-driven part of the GPA and Course storage program." << endl;

      while(true)
      {
        char menuSelector = menu();

        if(menuSelector == 'A' || menuSelector == 'a')
        {
          cout << "Congratulations, your GPA was " << gpa(courses, courseGrades, courseHours) << endl;
        }
        else if(menuSelector == 'B' || menuSelector == 'b')
        {
          print(courses, courseNames, semesters, courseNumbers, courseGrades, courseHours);
        }
        else if(menuSelector == 'C' || menuSelector == 'c')
        {
          cout << "Total hours with D grades are " << DRule(courses, courseGrades, courseHours) << endl;
        }
        else if(menuSelector == 'D' || menuSelector == 'd')
        {
          double tempGPA = 0;
          string selectedSemester = "";
          int semesterIndex;

          cout << "Please input desired semester for calculation" << endl;
          getline(cin,selectedSemester);

          double tempClasses = 0;
          while(tempClasses == 0)
          {
            for(int z = 0; z<courses;z++)
            {
              if(semesters[z] == selectedSemester)
              {
                tempClasses++;
              }
            }
            if(tempClasses == 0)
            {
              cout << "Desired semester: " << selectedSemester << " was not found. Please try again." << endl;
              cout << "Please input desired semester for calculation" << endl;
              getline(cin,selectedSemester);
            }
          }

          cout << "Congratulations, your GPA was " << semesterGpa(courses, semesters, courseGrades, courseHours, selectedSemester) << " in " << selectedSemester << endl;
        }
        else if(menuSelector == 'E' || menuSelector == 'e')
        {
          if(courses + 1 < COURSE_MAX)
          {
            courses++;

            getCourse(courseNames[courses - 1], semesters[courses - 1], courseNumbers[courses - 1], courseGrades[courses - 1], courseHours[courses - 1], courses);
          }
          else
          {
            cout << "Unable to add more than 10 classes" << endl;
          }
        }
        else if(menuSelector == 'Q' || menuSelector == 'q')
        {
          //"escapes all logic"
          return 0;
        }
      }
    }
  }
  else
  {
    cout << "Interactive mode was selected." << endl;
    cout << "Enter the number of classes for the system [1," << COURSE_MAX << "]" << endl;
    cin >> courses;

    while(courses <= 0 && courses >= COURSE_MAX)
    {
      cout << "The supplied input was not within specified bounds. Please try again." << endl;
      cin >> courses;
    }

    for(int step = 0;step < courses;step++)
    {
      //comeback
      getCourse(courseNames[step], semesters[step], courseNumbers[step], courseGrades[step], courseHours[step], courses);
    }

    cout << "Welcome to the interactive menu-driven part of the GPA and Course storage program." << endl;

    while(true)
    {
      char menuSelector = menu();

      if(menuSelector == 'A' || menuSelector == 'a')
      {
        cout << "Congratulations, your GPA was " << gpa(courses, courseGrades, courseHours) << endl;
      }
      else if(menuSelector == 'B' || menuSelector == 'b')
      {
        print(courses, courseNames, semesters, courseNumbers, courseGrades, courseHours);
      }
      else if(menuSelector == 'C' || menuSelector == 'c')
      {
        cout << "Total hours with D grades are " << DRule(courses, courseGrades, courseHours) << endl;
      }
      else if(menuSelector == 'D' || menuSelector == 'd')
      {
        double tempGPA = 0;
        string selectedSemester = "";
        int semesterIndex;

        cout << "Please input desired semester for calculation" << endl;
        getline(cin,selectedSemester);

        double tempClasses = 0;
        while(tempClasses == 0)
        {
          for(int z = 0; z<courses;z++)
          {
            if(semesters[z] == selectedSemester)
            {
              tempClasses++;
            }
          }
          if(tempClasses == 0)
          {
            cout << "Desired semester: " << selectedSemester << " was not found. Please try again." << endl;
            cout << "Please input desired semester for calculation" << endl;
            getline(cin,selectedSemester);
          }
        }

        cout << "Congratulations, your GPA was " << semesterGpa(courses, semesters, courseGrades, courseHours, selectedSemester) << " in " << selectedSemester << endl;
      }
      else if(menuSelector == 'E' || menuSelector == 'e')
      {
        if(courses + 1 < COURSE_MAX)
        {
          courses++;

          getCourse(courseNames[courses - 1], semesters[courses - 1], courseNumbers[courses - 1], courseGrades[courses - 1], courseHours[courses - 1], courses);
        }
        else
        {
          cout << "Unable to add more than 10 classes" << endl;
        }
      }
      else if(menuSelector == 'Q' || menuSelector == 'q')
      {
        //"escapes all logic"
        return 0;
      }
    }
  }
}
