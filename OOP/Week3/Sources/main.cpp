#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#include "Course.h"
#include "Fraction.h"
#include "Stack.h"
#include "Student.h"

Student getRandomStudent() {
  std::string studentId = std::to_string(std::rand() % 1000);
  double grade = (std::rand() % 1001) / 100.0;
  std::string fullname = "Student " + studentId;
  return Student(studentId, grade, fullname);
}

Fraction getRandomFraction() {
  return Fraction(std::rand() % 1000, std::rand() % 1000);
}

template <typename T>
void test(std::vector<T> vt) {
  std::cout << "The randomized vector: ";
  for (int i = 0; i < vt.size(); ++i) std::cout << vt[i] << ' ';
  Stack<T> S;
  std::stack<T> s;
  for (T i : vt) {
    S.push(i);
    s.push(i);
  }
  std::cout << "\nstd stack: ";
  while (!s.empty()) {
    std::cout << s.top() << ' ';
    s.pop();
  }
  std::cout << "\nUser-defined Stack: ";
  while (!S.isEmpty()) std::cout << S.pop() << ' ';
  for (T i : vt) S.push(i);
  S.clear();
  std::cout << '\n'
            << (S.isEmpty() ? "The stack is empty!" : "The stack is not empty!")
            << '\n';
}

int main() {
  // Bai 1
  std::srand(std::time(nullptr));
  int n = 10;  // 3 + (rand() % 18);
  std::vector<int> int_vt;
  std::vector<Fraction> fraction_vt;
  for (int i = 0; i < n; ++i) {
    int_vt.push_back(std::rand() % 1000);
    fraction_vt.push_back(getRandomFraction());
  }
  std::cout << "Stack of integer demo:\n";
  test(int_vt);

  // Bai 2 vs 3
  std::cout << "\n\n";
  std::vector<Student> student_vt;
  for (int i = 0; i < n; ++i) student_vt.push_back(getRandomStudent());

  Course course("CS101", "Computer Science", student_vt);
  std::cout << "Number of passed students: " << course.getPassedStudent()
            << '\n';
  std::cout << "Number of failed students: " << course.getFailedStudent()
            << '\n';

  std::cout << "Randomized students: \n";
  for (Student s : course)
    std::cout << '\t' << s.getFullname() << " - " << s.getGrade() << '\n';

  std::cout << "Excellent students: \n";
  for (Student s : course.getExcellentStudents())
    std::cout << '\t' << s.getFullname() << '\n';

  std::cout << "Good students: \n";
  for (Student s : course.getGoodStudents())
    std::cout << '\t' << s.getFullname() << '\n';

  std::cout << "Average students: \n";
  for (Student s : course.getAverageStudents())
    std::cout << '\t' << s.getFullname() << '\n';

  std::cout << "Weak students: \n";
  for (Student s : course.getWeakStudents())
    std::cout << '\t' << s.getFullname() << '\n';

  course.sortByName_Asc();
  std::cout << "Students sorted by name in ascending order: \n";
  for (Course::Iterator it = course.begin(); it != course.end(); ++it)
    std::cout << '\t' << (*it).getFullname() << '\n';

  course.sortByName_Desc();
  std::cout << "Students sorted by name in descending order: \n";
  for (Course::Iterator it = course.begin(); it != course.end(); ++it)
    std::cout << '\t' << (*it).getFullname() << '\n';

  course.sortByScore_Asc();
  std::cout << "Students sorted by score in ascending order: \n";
  for (Course::Iterator it = course.begin(); it != course.end(); ++it)
    std::cout << '\t' << (*it).getFullname() << " - " << (*it).getGrade()
              << '\n';

  course.sortByScore_Desc();
  std::cout << "Students sorted by score in descending order: \n";
  for (Course::Iterator it = course.begin(); it != course.end(); ++it)
    std::cout << '\t' << (*it).getFullname() << " - " << (*it).getGrade()
              << '\n';

  std::cout << "Saving the course to file...\n";
  course.save("Other/course.txt");
  Course course2;
  std::cout << "Loading the course from file...\n";
  course2.load("Other/course.txt");

  std::vector<std::string> ids;
  for (Student s : course.getWeakStudents()) ids.push_back(s.getId());
  course.removeByIds(ids);
  std::cout << "Removed weak students! from course 1\n";
  for (Student s : course) std::cout << '\t' << s << '\n';

  std::cout << "Add 1.0 points to all students in course 2\n";
  for (Student& s : course2) {
    if (s.getGrade() + 1.0 < 10)
      s.setGrade(s.getGrade() + 1);
    else
      s.setGrade(10);
  }
  std::cout << "Students in course 2 after adding 1.0 points: \n";
  for (Course::Iterator it = course2.begin(); it != course2.end(); ++it)
    std::cout << '\t' << (*it).getFullname() << " - " << (*it).getGrade()
              << '\n';
  return 0;
}