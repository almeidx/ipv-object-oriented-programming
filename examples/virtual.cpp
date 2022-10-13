#include <iostream>

using namespace std;

class Vehicle {
    int year;
    string brand;

    public:
        Vehicle() {
            cout << "Vehicle created" << endl;

            year = 0;
            brand = "???";
        }

        Vehicle(string _brand, int year = 2022) {
            cout << "Vehicle created with arguments" << endl;

            year = year;
            brand = _brand;
        }

        virtual ~Vehicle() {
            cout << "Vehicle destroyed" << endl;
        }

        virtual void show() {
            cout << "Vehicle: " << brand << " " << year << endl;
        }

        int get_year() {
            return year;
        }

        string get_brand() {
            return brand;
        }

        virtual string get_type() {
            return "Vehicle";
        }
};

class LargeVehicle : public Vehicle {
    int weight;

    public:
        LargeVehicle() : Vehicle() {
            weight = 0;
        }

        LargeVehicle(string _brand, int _year, int _weight) : Vehicle(_brand, _year) {
            weight = _weight;

            cout << "LargeVehicle " << _brand << " created with arguments" << endl;
        }

        void show() {
            cout << "LargeVehicle: " << get_brand() << " " << get_year() << " " << weight << endl;
        }

        string get_type() {
            return "LargeVehicle";
        }
};

class LightVehicle : public Vehicle {
    int passengers;

    public:
        LightVehicle() : Vehicle() {
            passengers = 0;
        }

        LightVehicle(string _brand, int _year, int _passengers) : Vehicle(_brand, _year) {
            passengers = _passengers;
        }

        void show() {
            cout << "LightVehicle: " << get_brand() << " " << get_year() << " " << passengers << endl;
        }
};

int main() {
    // Vehicle vehicle("Audi", 2021);
    // LightVehicle light("Fiat", 2019, 5);
    // LargeVehicle large("Mercedes", 2020, 1000);
    Vehicle *light2 = new LightVehicle("Small", 2019, 5);
    // Vehicle *large2 = new LargeVehicle("Fat", 2019, 5);

    // vehicle.show();
    // light.show();
    // large.show();
    light2->show();
    // large2->show();

    cout << "Type: " << light2->get_type() << endl;

    return 0;
}
