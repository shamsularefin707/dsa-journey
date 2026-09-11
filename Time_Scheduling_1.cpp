#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity{
    char id;
    int start;
    int finish;
};

int main(){
    vector<Activity> activities = {
        {'A', 1, 3},
        {'B', 2, 5},
        {'C', 4, 6},
        {'D', 5, 7},
        {'E', 8, 9},
        {'F', 5, 9}
    };
    vector<Activity> selectedActivities;
    int n = activities.size();
    //Sort the activities based on their finish time
    for(int i = 0; i < n-1; i++){
        int minIndex = i;

        for(int j = i+1; j < n; j++){
            if(activities[j].finish < activities[minIndex].finish){
                minIndex = j;
            }
        }
        swap(activities[i], activities[minIndex]);
    }

    int count = 0; 

    int lastFinishTime = INT_MIN;

    for(auto activity:activities){
        if(activity.start >= lastFinishTime){
            count++;
            lastFinishTime = activity.finish;
            selectedActivities.push_back(activity);
        }
    }

    cout << "Selected activities: \n";
    for(auto activity: selectedActivities){
        cout << activity.id << " "; 
        cout << "(" << activity.start << ", " << activity.finish << ") ";
        cout << endl;
    }

    cout << "Maximum number of non-overlapping activities: " << count << endl;
    return 0;

}