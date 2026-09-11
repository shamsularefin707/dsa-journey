#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Item{
    char id;
    int value;
    int weight;
};

int main(){
    vector<Item> items = {
        {'A', 60, 10},
        {'B', 100, 20},
        {'C', 120, 30},
        {'D', 80, 40},
        {'E', 30, 50},
        {'F', 50, 60},
        {'G', 70, 70},
        {'H', 90, 80},
        {'I', 40, 90},
        {'J', 20, 100}
    };

    int capacity = 50;

    //Sort items by value-to-weight ratio in descending order
    for(int i = 0; i < items.size(); i++){
        for(int j = i+1; j < items.size(); j++){
            double ratio1 = (double)items[i].value/items[i].weight;
            double ratio2 = (double)items[j].value/items[j].weight;

            if(ratio1 < ratio2){
                swap(items[i], items[j]);
            }
        }
    }

    double totalValue = 0.0;
    vector<pair<char, double>> selectedItems;

    for(int i = 0; i < items.size(); i++){
        if(capacity == 0){
            break;
        }

        if(items[i].weight <= capacity){
            capacity -= items[i].weight;
            totalValue += items[i].value;
            selectedItems.push_back({items[i].id, 1.0});
        }else{
            double fraction = (double)capacity/items[i].weight;
            capacity = 0;
            totalValue += items[i].value*fraction;
            selectedItems.push_back({items[i].id, fraction});
        }
    }

    cout << "Selected items: " << endl;
    for(auto item : selectedItems){
        cout << "Item ID: " << item.first << ", Fraction: " << item.second << endl;
    }
    cout << "Total value: " << totalValue << endl;

    return 0;
}