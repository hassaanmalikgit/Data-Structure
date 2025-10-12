#include <iostream>
using namespace std;

struct Weather {
    float rainfall;
};

int main() {
    int MONTHS = 6;
    Weather w[6];
    float totalRain = 0;

    cout << "=== Weather Data Program ===\n\n";

    
    for (int i = 0; i < MONTHS; i++) {
        cout << "Enter rainfall for month " << i+1 << ": ";
        cin >> w[i].rainfall;
        totalRain += w[i].rainfall;
    }

    
    cout << "\n=== Rainfall Report ===\n";
    for (int i = 0; i < MONTHS; i++) {
        cout << "Month " << i+1 << " rainfall = " << w[i].rainfall << endl;
    }

    cout << "\nTotal rainfall for " << MONTHS << " months = " << totalRain;
    cout << "\nAverage rainfall = " << totalRain / MONTHS << endl;

    return 0;
}

