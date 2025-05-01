/*There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight take
to reach city B from A, or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by airport name or name of the city. Use adjacency
list representation of the graph or use adjacency matrix representation of the graph.
Check whether the graph is connected or not. Justify the storage representation used.*/

#include <iostream>
#include <string>
using namespace std;

class flight {
    public:
        int a[50][50], citycount;
        string cities[50];
        string source, destination;
        int dist;

        flight() {
            citycount = 0;
            for (int i = 0; i < 50; i++) {
                for (int j = 0; j < 50; j++) {
                    a[i][j] = 0;
                }
            }
        }

        void addcity() {
            int sourceindex = -1, dest_index = -1;

            cout << "Enter the source city : ";
            getline(cin >> ws, source);
            cout << "Enter the destination city : ";
            getline(cin >> ws, destination);

           
            for (int i = 0; i < citycount; i++) {
                if (cities[i] == source) {
                    sourceindex = i;
                    break;
                }
            }
            if (sourceindex == -1) {
                cities[citycount] = source;
                sourceindex = citycount;
                citycount++;
            }

            
            for (int i = 0; i < citycount; i++) {
                if (cities[i] == destination) {
                    dest_index = i;
                    break;
                }
            }
            if (dest_index == -1) {
                cities[citycount] = destination;
                dest_index = citycount;
                citycount++;
            }

            cout << "Enter distance between " << source << " & " << destination << " : ";
            cin >> dist;
            a[sourceindex][dest_index] = dist;
            a[dest_index][sourceindex] = dist;
        }

        void display() {
            cout << "\nDistance Matrix:\n\t";
            for (int i = 0; i < citycount; i++) {
                cout << cities[i] << "\t";
            }
            cout << endl;
            for (int i = 0; i < citycount; i++) {
                cout << cities[i] << "\t";
                for (int j = 0; j < citycount; j++) {
                    cout << a[i][j] << "\t";
                }
                cout << endl;
            }
        }
};

int main() {
    flight f;
    char ch;
    do {
        f.addcity();
        cout << "Do you want to add another city? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    f.display();
    return 0;
}


