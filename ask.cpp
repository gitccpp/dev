#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    string surname;

public:
    Person(string name, string surname) {
        this->name = name;
        this->surname = surname;
    }

    virtual void display() {
        cout << "Name : " << name << " Surname : " << surname << endl;
    }
};


class Lecturer : virtual public Person {
protected:
    string Course_name1;
    string Course_name2;
    string grade;

public:
    Lecturer(string name, string surname, string cname1, string cname2, string grade) : Person(name, surname) {
        Course_name1 = cname1;
        Course_name2 = cname2;
        this->grade = grade;
    }

    void display() {
        cout << "Teaching : " << Course_name1 << " " << Course_name2 << endl;
    }
};


class Researcher : virtual public Person {
protected:
    string field;
    int number_of_publications;

public:
    Researcher(string name, string surname, string field, int pnumber) : Person(name, surname) {
        this->field = field;
        number_of_publications = pnumber;
    }

    void display() {
        cout << "Field of research : " << field << " Number of Publications :" << number_of_publications << endl;
    }
};


class University_Lecturer : public Lecturer, public Researcher {
private:
    string department;

public:
    University_Lecturer(string name, string surname, string cname1, string cname2, string grade, string field, int pnumber, string dep)
        : Lecturer(name, surname, cname1, cname2, grade),
          Researcher(name, surname, field, pnumber),
          Person(name, surname) {
        department = dep;
    }

    void display() {
        Person::display();
        Lecturer::display();
        Researcher::display();
        cout << "Department : " << department << endl;
    }
};

int main() {
    Person *p1 = new University_Lecturer("Nikos", "Pappas", "C++", "Java", "Lecturer", "Programming and Algorithms", 56, "University of Aegean");
    p1->display();
}