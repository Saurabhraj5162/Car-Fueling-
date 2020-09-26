#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    stops.insert(stops.begin(),0);
    stops.push_back(dist);
    int n = stops.size();
    int last_fill=0;
    int i =0;
    int current =0;
    int num_fill = 0;
    int capacity = tank;


    while (current != n-1){
    if ((capacity >= (stops[i+1] - stops[i]))) {
        while ((current != n-1) && (capacity >= (stops[i+1] - stops[i]))){
            current = i+1;
            capacity = tank - (stops[current]-last_fill);
            i++;
        }

        num_fill++;
        last_fill = stops[current];
        capacity = tank;

    }
    else {
        break;
    }

    if (current==n-1){
        return (num_fill-1);
    }
    }

    return -1;

}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
