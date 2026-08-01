class Person {
private:
    string lastName;
    int age;
    bool married;

public:
    Person(string lastName, int age, bool married) 
        : lastName(lastName), age(age), married(married) {}

    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    bool isMarried() {
        return married;
    }
};

class PersonFilter {
public:
    virtual ~PersonFilter() {}
    virtual bool apply(Person& person) = 0;
};

class AdultFilter : public PersonFilter {
public:
    // Implement Adult filter
    // 18 or older
    bool apply(Person& person) override {
        return person.getAge() >= 18;
    }
};

class SeniorFilter : public PersonFilter {
public:
    // Implement Senior filter
    // 65 and older
    bool apply(Person& person) override {
        return person.getAge() >= 65;

    }
};

class MarriedFilter : public PersonFilter {
public:
    // Implement Married filter
    // married
    bool apply(Person& person) override {
        return person.isMarried();
    }

};

class PeopleCounter {
private:
    PersonFilter* filter;

public:
    void setFilter(PersonFilter& filter) {
        this->filter = &filter;
    }

    int count(vector<Person>& people) {
        // Implement method here
        // loop through the people vector
        // and apply the filter each time
        // increment count when apply() is true
        int count = 0;
        for (Person& p: people) {
            if (filter->apply(p)) {
                ++count;
            }
        }
        return count;
    }
};
