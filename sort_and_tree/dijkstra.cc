#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;
using vertex_t = int;
using weight_t = double;

const weight_t max_weight = numeric_limits<double>::infinity();

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
            : target(arg_target), weight(arg_weight) {}
};

struct Comp {
    bool operator()(const pair<weight_t, vertex_t> &p1, const pair<weight_t, vertex_t> &p2) const {
        return p1.first < p2.first;
    }
};

using adjacency_list_t = vector<vector<neighbor> >;

void DijkComputePaths(vertex_t source,
                      const adjacency_list_t &adjacency_list,
                      vector<weight_t> &min_distance,
                      vector<vertex_t> &previous) {
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    // by default, ordered set is implemented with binary search tree
    // set is in increasing order based on pair which is ordered by first element

    auto comparator = [](const pair<weight_t, vertex_t> &v1, const pair<weight_t, vertex_t> &v2){return v1.first < v2.first;};

    set<pair<weight_t, vertex_t>, decltype(comparator)> vertex_queue(comparator);
    /** set<pair<weight_t, vertex_t>,Comp> vertex_queue; **/ // old-fashion style to set a comparator
    vertex_queue.insert(make_pair(min_distance[source], source));

    while (!vertex_queue.empty()) {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        const vector<neighbor> &neighbors = adjacency_list[u];
        for (vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
             neighbor_iter != neighbors.end();
             neighbor_iter++) {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u < min_distance[v]) {
                vertex_queue.erase(make_pair(min_distance[v], v));
                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.insert(make_pair(min_distance[v], v));
            }
        }
    }
}

list<vertex_t> DijkGetShortestPathTo(vertex_t vertex,
                                     const vector<vertex_t> &previous) {
    list<vertex_t> path;
    for (; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}

int main() {
    adjacency_list_t adjacency_list(6);
    // 0
    adjacency_list[0].push_back(neighbor(1, 7));
    adjacency_list[0].push_back(neighbor(2, 9));
    adjacency_list[0].push_back(neighbor(5, 14));
    // 1
    adjacency_list[1].push_back(neighbor(0, 7));
    adjacency_list[1].push_back(neighbor(2, 10));
    adjacency_list[1].push_back(neighbor(3, 15));
    // 2
    adjacency_list[2].push_back(neighbor(0, 9));
    adjacency_list[2].push_back(neighbor(1, 10));
    adjacency_list[2].push_back(neighbor(3, 11));
    adjacency_list[2].push_back(neighbor(5, 2));
    // 3
    adjacency_list[3].push_back(neighbor(1, 15));
    adjacency_list[3].push_back(neighbor(2, 11));
    adjacency_list[3].push_back(neighbor(4, 6));
    // 4
    adjacency_list[4].push_back(neighbor(3, 6));
    adjacency_list[4].push_back(neighbor(5, 9));
    // 5
    adjacency_list[5].push_back(neighbor(0, 14));
    adjacency_list[5].push_back(neighbor(2, 2));
    adjacency_list[5].push_back(neighbor(4, 19));

    vector<weight_t> min_distance;
    vector<vertex_t> previous;
    DijkComputePaths(0, adjacency_list, min_distance, previous);
    cout << "Distance from 0 to 4:" << min_distance[4] << endl;
    list<vertex_t> path = DijkGetShortestPathTo(4, previous);
    cout << "Path : ";
    for_each(path.begin(), path.end(), [](vertex_t val){cout << val << ' ';});
    cout << endl;
    return 0;
}
