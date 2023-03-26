#include <iostream>

using namespace std;

class Product {

    //using public fields (not recommended)
/*
public:
    int id;
    string name;
    double price;
    bool available;
*/

    //using private fields:
private:
    int id;
    string name;
    double price;
    bool available;

public:
    void printProductInfo() {
        cout << "id: " << id << " " << name << ", price: " << price << " available: ";
        if (available) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    /*
     * This method let's the user enter the info
     * for the Product from the console
     * */
    void enterProductInfo(){
        cout<<"enter id: ";
        cin>>id;
        cout<<"enter name: ";
        cin>>name;
        cout<<"enter price: ";
        cin>>price;
        cout<<"is available (y/n):";
        char availableChar;
        cin>>availableChar;
        if (availableChar == 'y'){
            available = true;
        } else if (availableChar == 'n'){
            available = false;
        }
    }

    /*
     * get method for id field
     * */
    int getId() {
        return id;
    }

    /*
     * set method for id field
     * */
    void setId(int newId) {
        id = newId;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        /*
         * using Product::name in order to access the class
         * field name
         * */
        Product::name = name;
        //another option is to use:
        this->name = name;
        //choose one of the two above.
    }

    double getPrice() {
        return price;
    }

    void setPrice(double price) {
        Product::price = price;
    }

    bool isAvailable() {
        return available;
    }

    void setAvailable(bool available) {
        Product::available = available;
    }

};

int main() {

    Product p1;
    Product p2;
    Product p3;

    /*
     * if the fields are public, then they could be accessed
     * outside the class definition:
     * */
    /*
    p1.name = "Name1";
    p1.id = 12;
    p1.price = 13.2;
    p1.available = true;

    //entering data from the console. Here the class fields are public:
    cout << "Enter product's id (numbers only):";
    cin >> p2.id;
    cout << "Enter product's name:";
    cin >> p2.name;
    cout << "Enter product's price:";
    cin >> p2.price;
    cout << "Is product available (y/n):";
    char available;
    cin >> available;
    if (available == 'y') {
        p2.available = true;
    } else if (available == 'n') {
        available = false;
    } else {
        cout << "Not correct input entered (must be 'y' or 'n')";
        p2.available = false;
    }
    */


    // entering data from console with set methods:
    cout << "Enter product's id (numbers only):";
    int id;
    cin >> id;
    p3.setId(id);

    cout << "Enter product's name:";
    string name;
    cin>>name;
    p3.setName(name);

    cout << "Enter product's price:";
    double price;
    cin >> price;
    p3.setPrice(price);

    cout << "Is product available (y/n):";
    char available;
    cin >> available;
    if (available == 'y') {
        p3.setAvailable(true);
    } else if (available == 'n') {
        p3.setAvailable(false);
    } else {
        cout << "Not correct input entered (must be 'y' or 'n')";
        p3.setAvailable(false);
    }

    p3.printProductInfo();

    /*
     * using an array of Products
     * */
    Product products[3];

    // using for loop to access the objects
    for (int i = 0; i < 3; ++i) {
        products[i].enterProductInfo();
    }

    //using the array and enhanced for to print the objects info:
    for (Product p : products){
        p.printProductInfo();
    }


    //calculating the sum of the products:
    double sum = 0;
    for (Product p : products){
        sum += p.getPrice();
    }
    cout<<"The sum of the products is: "<<sum<<endl;

    return 0;
}



