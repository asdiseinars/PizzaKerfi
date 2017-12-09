#include "OrderData.h"

OrderData::OrderData() {

}

void OrderData::addOrderToOrders(Order& order) {
    ofstream fout;
    fout.open("orders.txt", ios::app);
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

void OrderData::storeAllOrders(vector<Order> orders) {

    ofstream fout;
    fout.open("orders.txt");
    for(unsigned int i = 0; i < orders.size(); i++) {
        fout << orders[i];
    }
    fout.close();
}

