class Observer {
public:
    virtual ~Observer() = default;
    virtual void notify(const string& itemName) = 0;
};

class Customer : public Observer {
private:
    string name_;
    int notifications_;

public:
    explicit Customer(string name) : name_(move(name)), notifications_(0) {}

    void notify(const string& itemName) override {
        notifications_ += 1;
    }

    int countNotifications() {
        return notifications_;
    }
};

class OnlineStoreItem {
private:
    string itemName_;
    int stock_;
    unordered_set<Observer*> subscribers_;

public:
    OnlineStoreItem(string itemName, int stock) : itemName_(move(itemName)), stock_(stock) {}

    void subscribe(Observer* observer) {
        subscribers_.insert(observer);
    }

    void unsubscribe(Observer* observer) {
        subscribers_.erase(observer);
    }

    void updateStock(int newStock) {
        if (stock_ <= 0 && newStock > 0) {
            // notify subscribers!
            for (Observer* observer: subscribers_) {
                observer->notify(itemName_);
            }
        }
        // update stock memeber
        stock_ = newStock;
    }
};
