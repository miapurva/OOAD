#include <iostream>
#include <ctime>

using namespace std;
int size, dfn = 1, rootNodeDegree = 0;
int graph[100][100];
int visited[100] = {0};
int tree[100][100] = {0};
int Lvalue[100] = {0};
int articulation_points[100] = {0};
int root;


int minimum(int first, int second, int third) {
    if (first <= second && first <= third)
        return (first);

    else if (second <= first && second <= third)
        return (second);

    return (third);

}

void getLvalue(int node) {
    int minimumLvalueofChildren = size, minimumDFNofBackedges = size;
    int termsinsecond = 0, termsinthird = 0;

    int first = visited[node];
    //dfn of w
    int second = 10000, third = 10000;
    for (int i = 1; i < size + 1; i++) {
        if (tree[node][i] == 1) {
            second = Lvalue[i];
            termsinsecond++;
        }
        if (second < minimumLvalueofChildren)
            minimumLvalueofChildren = second;
    }
    if (termsinsecond == 0)
        second = 10000;
    else
        second = minimumLvalueofChildren;//minimum of l values of children of w
    for (int i = 1; i < size + 1; i++) {
        if (tree[node][i] == 2) {
            third = visited[i];
            termsinthird++;
        }
        if (third < minimumDFNofBackedges)
            minimumDFNofBackedges = third;
    }
    if (termsinthird == 0)
        third = 10000;
    else
        third = minimumDFNofBackedges;       //minimum of dfn of back edges from w

    Lvalue[node] = minimum(first, second, third);

}


void dfs(int node) {
    visited[node] = dfn++;
    for (int i = 1; i < size + 1; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
            tree[node][i] = 1;
            for (int j = 1; j < size + 1; j++) {
                if (tree[i][j] != 1 && tree[j][i] != 1 && graph[j][i] == 1 && visited[j] < visited[i])
                    tree[i][j] = 2;
            }
            getLvalue(i);
        }
    }
}


void APs() {

    //for the articulation points

    cout << "\n\nThe APs are: {";

    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            if (Lvalue[j] >= visited[i] && graph[i][j] == 1 && i != root) {
                articulation_points[i] = 1;
                cout << i << ",";
                break;
            }
            if (i == root) {
                rootNodeDegree = rootNodeDegree + tree[i][j];
                if (rootNodeDegree > 1) {
                    articulation_points[root] = 1;
                    cout << i;
                }
            }
        }
    }

    cout << "}";

}

void Bridges() {
    //for the bridges
    cout << "\nThe bridges are: " << endl;
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            if (graph[i][j] == 1 && visited[i] < visited[j] && Lvalue[j] > visited[i]) {
                cout << "(" << i << "," << j << ")" << endl;
            }
        }
    }
}


void displayDFSTree() {
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            cout << "  " << tree[i][j];
        }
        cout << endl;
    }
}

void takeinput() {
    cout << "enter the size of the graph: " << endl;
    cin >> size;

    cout << "enter the Adjacency matrix : " << endl;

    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            cin >> graph[i][j];
        }
    }
}

int main() {

    takeinput();

    srand((unsigned int) time(NULL));
    root = 1 + rand() % size;

    cout << "\nthe root of the dfs tree is : " << root << endl;

    dfs(root);

    cout << "\nthe DFS tree is (unidirectional when it comes to backedges) : " << endl;

    displayDFSTree();

    getLvalue(root);

    APs();

    Bridges();


}
