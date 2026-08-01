class Observer {
public:
    virtual void notify(string& itemName) = 0;
};

class Customer : public Observer {
private:
    string name;
    int notifications;

public:
    Customer(string& name) : name(name), notifications(0) {}

    void notify(string& itemName) override {
        notifications += 1;
    }

    int countNotifications() {
        return notifications;
    }
};

class OnlineStoreItem {
private:
    string itemName;
    int stock;
    unordered_set<Observer*> subscribers;

public:
    OnlineStoreItem(string& itemName, int stock) : itemName(itemName), stock(stock) {}

    void subscribe(Observer* observer) {
        subscribers.insert(observer);
    }

    void unsubscribe(Observer* observer) {
        subscribers.erase(observer);
    }

    void updateStock(int newStock) {
        if (stock <= 0 && newStock > 0) {
            // notify subscribers!
            for (Observer* observer: subscribers) {
                observer->notify(itemName);
            }
        }
        // update stock memeber
        stock = newStock;
    }
};
