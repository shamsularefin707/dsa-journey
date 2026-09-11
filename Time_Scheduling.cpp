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

    sort(activities.begin(), activities.end(), 
        [](Activity a, Activity b){
            return a.finish<b.finish;   
    });

    int count = 0;
    int lastFinishTime = INT_MIN;

    for(auto activity: activities){
        if(activity.start >= lastFinishTime){
            count++;
            lastFinishTime = activity.finish;
            selectedActivities.push_back(activity);
        }


    }

    cout << "Selected activities: ";
    for(auto activity: selectedActivities){
        cout << activity.id << " ";
    }
    cout << endl;

    cout << "Maximum number of non-overlapping activities: " << count << endl;
    return 0;
}