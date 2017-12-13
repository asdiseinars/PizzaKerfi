#include "OrderData.h"

OrderData::OrderData() {

}

void OrderData::addOrderToOrders(Order& order) {
    ofstream fout;
    fout.open("orders.txt", ios::app);
    fout << order;
    fout.close();
}

void OrderData::addOrderToLegacy(Order& order) {

    ofstream fout;
    fout.open("legacy.txt", ios::app);
    fout << order;
    fout.close();
}

vector<Order> OrderData::retrieveAllOrders() {

    vector <Order> orders;

    ifstream fin;
    fin.open("orders.txt");
    while(!fin.eof()) {
        Order order;
        fin >> order;
        orders.push_back(order);
    }
    orders.pop_back();

    return orders;
}

vector<Order> OrderData::retrieveAllOrdersFromLegacy() {

    vector <Order> orders;

    ifstream fin;
    fin.open("legacy.txt");
    while(!fin.eof()) {
        Order order;
        fin >> order;
        orders.push_back(order);
    }
    orders.pop_back();

    return orders;
}

void OrderData::storeAllOrdersToLegacy(vector<Order> orders) {

    ofstream fout;
    fout.open ("legacy.txt", ios::app);
    for(unsigned int i = 0; i < orders.size(); i++) {
        fout << orders[i];
    }
    fout.close();
}

void OrderData::storeAllOrders(vector<Order> orders)
{
    ofstream fout;
    fout.open("orders.txt");
    for(unsigned int i = 0; i < orders.size(); i++) {
        fout << orders[i];
    }
    fout.close();
}

vector<Order> OrderData::getOrderForLocation(string location) {
    vector <Order> orders;

    ifstream fin;
    fin.open("orders.txt");


    while(!fin.eof()) {
        Order order;
        fin >> order;
        orders.push_back(order);
    }

    vector<Order> orderForLocation;

    for(unsigned int i = 0; i < orders.size(); i++) {
        if (location == orders[i].getLocation()) {
            orderForLocation.push_back(orders[i]);

        }

    }

    orders.pop_back();

    return orderForLocation;
}

vector<Order> OrderData::getOrderForLocationAndOrderStatus(string location, int orderStatus) {
    vector <Order> orders;

    ifstream fin;
    fin.open("orders.txt");


    while(!fin.eof()) {
        Order order;
        fin >> order;
        orders.push_back(order);
    }

    vector<Order> orderForLocationAndOrderStatus;

    for(unsigned int i = 0; i < orders.size(); i++) {
        if (location == orders[i].getLocation() && orderStatus == orders[i].getOrderStatus()) {
            orderForLocationAndOrderStatus.push_back(orders[i]);
        }
    }

    orders.pop_back();

    return orderForLocationAndOrderStatus;
}

vector<Order> OrderData::getOrderForLocationAndOrderStatusAndPhoneNumber(string location, int orderStatus, string phoneNumber) {
    vector <Order> orders;

    ifstream fin;
    fin.open("orders.txt");


    while(!fin.eof()) {
        Order order;
        fin >> order;
        orders.push_back(order);
    }

    vector<Order> orderForLocationAndOrderStatusAndPhoneNumber;

    for(unsigned int i = 0; i < orders.size(); i++) {
        if (location == orders[i].getLocation() && orderStatus == orders[i].getOrderStatus() && phoneNumber == orders[i].getPhoneNumber()) {
            orderForLocationAndOrderStatusAndPhoneNumber.push_back(orders[i]);
        }
    }

    orders.pop_back();

    return orderForLocationAndOrderStatusAndPhoneNumber;
}

/*
void OrderData::removeFromOrder(string yourLocation) {
    vector<Order> thisOrder = getOrderForLocation(yourLocation);
    vector<Order> newOrders;

    for (unsigned int i = 0; i < thisOrder.size(); i++) {
        if (thisOrder[i].getOrderStatus() != 4) {
            newOrders.push_back(thisOrder[i]);
        }
        else{
            ofstream fout;
                fout.open("legacy.txt", ios::app);
                fout << newOrders.at(i);
                fout.close();

        }
        storeAllOrders(newOrders);
    }


}

void OrderData::moveOrderToLegacy(string yourLocation) {
    vector<Order> thisOrder = getOrderForLocation(yourLocation);
    vector<Order> legacyOrders;
    for (unsigned int i = 0; i < thisOrder.size(); i++) {
        if (thisOrder[i].getOrderStatus() == 4) {
            legacyOrders.push_back(thisOrder[i]);
        }
        storeAllOrdersToLegacy(legacyOrders);
    }
}


void OrderData::moveAllOrdersFromOrderstoLegacyAtLocation(string location)
{
    vector<Order> allOrders = getOrderForLocation(location);
    for(int i = 0; i < allOrders.size(); i++)
    {
        if(allOrders.at(i).getOrderStatus() == 4)
        {
            Order order = allOrders.at(i);
            allOrders.erase(allOrders.begin() + i);
            i -= 1;

                ofstream fout;
                fout.open("legacy.txt", ios::app);
                fout << order;
                fout.close();
        }

    }
    storeAllOrders(allOrders);

}*/



