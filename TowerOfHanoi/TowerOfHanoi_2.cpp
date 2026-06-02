#include <iostream>
using namespace std;
//not using the auxiliary stack to store the disks temporarily
int MoveCount = 0;
void printMove(int n, char src, char dest){
    cout << "Move disk " << n << " from " << src << " to " << dest << endl; 
}

void towerOfHanoi(int n, char src, char dest){
    if(n == 1){
        MoveCount++;
        printMove(n, src, dest);
        return;
    }
    char aux = 'A' + 'B' + 'C' - src - dest; 
    towerOfHanoi(n-1, src, aux);
    MoveCount++;
    printMove(n, src, dest);
    towerOfHanoi(n-1, aux, dest);
}

int main(){
    int n; 
    cout << "Enter the number of disks: ";
    cin >> n; 
    cout << "The sequence of moves to solve the Tower of Hanoi is:\n";
    towerOfHanoi(n, 'A', 'C'); // A is source, C is destination
    cout << "Total moves: " << MoveCount << endl;
    return 0;
}
