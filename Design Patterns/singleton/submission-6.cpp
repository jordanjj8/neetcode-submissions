class Singleton {
private:
    // each singleton object has its own string member
    string value;
 
    // Private constructor: code outside this class cannot call `new Singleton`
    // or `Singleton s;`. 
    // main gate that prevents multiple instances.
    Singleton() {}
 
public:
    // Static member function: belongs to the class, not to an object.
    // Call it as `Singleton* s = Singleton::getInstance();`
    static Singleton* getInstance() {
        // `static` local variable: created only the first time this function runs,
        // destroyed automatically at program exit, and the same object is
        // returned on every later call.
        static Singleton instance;
 
        // Return the address of that single shared object.
        return &instance;
    }
 
    // Returns the current value. Note: this returns by copy, so a new string
    // is allocated and returned every time.
    string getValue() {
        return value;
    }
 
    // Takes a non-const reference to a string from the caller.
    // `this->value` is the member; `value` is the parameter.
    void setValue(string& value) {
        this->value = value;   // copy the caller's string into the member
    }
};