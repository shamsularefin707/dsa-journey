#include <iostream> 
using namespace std;
int MoveCount = 0;
//using the auxiliary stack to store the disks temporarily
void towerOfHanoi(int n, char src, char dest, char aux){
    if(n == 0) return; 

    towerOfHanoi(n-1, src, aux, dest); // Move n-1 disks from source to auxiliary
    MoveCount++;
    cout << "Move disk " << n << " from " << src << " to " << dest << endl; 
    towerOfHanoi(n-1, aux, dest, src); // Move n-1 disks from auxiliary to destination
}

int main(){
    int n; 
    cout << "Enter the number of disks: ";
    cin >> n; 
    cout << "The sequence of moves to solve the Tower of Hanoi is:\n";
    towerOfHanoi(n, 'A', 'C', 'B'); // A is source, C is destination, B is auxiliary
    cout << "Total moves: " << MoveCount << endl;
    return 0;
}
