/*k nearest neighbors*/

#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

// helper func to print
void print_knn(int k, multimap<double, tuple<int, int>> distances){
    int i=0;
    auto it=distances.begin();
    while(i<k && it!=distances.end()){
        cout << get<0>(it->second) << ", " << get<1>(it->second) << endl;
        it++;
        i++;
    }
}

// distance between 2 points
double distance(tuple<int,int> p1, tuple<int,int> p2){
    return sqrt(pow(get<0>(p1) - get<0>(p2), 2) + pow(get<1>(p1) - get<1>(p2), 2));
}

// find k nearest neighbors to origin
void find_knn(vector<tuple<int, int>> points, tuple<int,int> origin, int k){
    multimap<double, tuple<int, int>> distances;
    for (auto p : points){
        distances.emplace(distance(p, origin), p);
    }
    print_knn(k, distances);
}

int main(){
    vector<tuple<int, int>> points = {make_tuple(0,1), 
    make_tuple(10,5), 
    make_tuple(-3,4), 
    make_tuple(0,-1), 
    make_tuple(50,51)};
    
    find_knn(points, make_tuple(0,0), 2);
}
