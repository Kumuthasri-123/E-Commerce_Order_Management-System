#include <iostream>
#include <fstream>
using namespace std;
class Payment {
public:
    virtual void pay(float amt) = 0;  
};
class UPI : public Payment {
public:
    void pay(float amt) {
        cout << "Payment of Rs." << amt << " made via UPI" << endl;
    }
};
class Order {
    float total;
public:
    Order(float t = 0) {
        total = t;
    }
    float operator-(float discount) {
        return total - (total * discount / 100);
    }
};
void generateInvoice(float amount) {
    ofstream file("invoice.txt");
    if (file) {
        file << "Invoice Total: Rs." << amount;
        file.close();
        cout << "Invoice generated!" << endl;
    }
}
int main() {
    Order order(1000);       
    float finalAmount = order - 10;  

    UPI payment;
    payment.pay(finalAmount);

    generateInvoice(finalAmount);

    return 0;
}

