#include <iostream>
#include <vector>
using namespace std;

void conslog(string log) {
    cout << "[LOG] " << log << endl;
}

void consprint(string log) {
    cout << "[INFO] " << log << endl;
}

class Person {
    public:
        string name;
        int age;

        string phone_number;

        string daily_pass_pn;
        string tag;
        string pass;

        Person(string n, string pn, int a, string t, string p) {
            name=n;
            phone_number=pn;
            age=a;
            tag=t;
            pass=p;
        }
};

vector<Person> people = {};

void addPerson(string name, string phonen, int age, string tag, string pass) {
    people.push_back(Person(name, phonen, age, tag, pass));
    conslog("Added person: " + name + ". ");
    
    return;
}

void registerPerson(string name, string phonen, string pass) {
    consprint("Hi " + name + ". \n      Please enter password.");
    string entp;
    cin>>entp;
    if (entp==pass) {
        consprint("Send at number " + phonen + ". Your code is 123\n    Please enter your code.");
        int code;
        cin>>code;
        if (code == 123) conslog("Logged!");
        else conslog("You dont have permission!");
    } else conslog("You dont have permission!");
}

int main() {
    addPerson("Jan Kowalski", "0048 123 456 789", 23, "132", "132");
    registerPerson(people[0].name, people[0].phone_number, people[0].pass);

    return 0;
}
