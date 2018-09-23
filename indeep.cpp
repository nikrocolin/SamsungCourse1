#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

void indeep(int n, vector < vector <int> > graph, 
			bool *used, int vertex) {
  int i = 0;
  used[vertex] = true;
  cout << endl <<vertex;
  for (auto i : graph[vertex]) {
    if (!used[i]) {
	  indeep(n, graph, used, i);
  	}
  	i++;
  }
}


int main() 
{	int number, f, kf=1;
	char ch;
	cout << "\nEnter the number of vertexes: ";
	cin >> number;
	vector < vector <int> > mas(number);
	bool *visited = new bool [number];
	cout <<"\n After each number press space (even after the last in a string) ";
	for (int i = 0; i < number; i++) {
		visited[i] = false;
		cout << "\nfor "<< i << " vertex :";
		while ((ch = getche()) != '\r') {
			if (ch >= '0' && ch <='9') {
				f = f + kf * (ch-'0');
				kf++;
			} else if (ch == ' ') {
				mas[i].push_back(f);
				kf = 1;
				f = 0;
			}
		}
	}
	indeep(number, mas, visited, 0);
	return 0;
}
