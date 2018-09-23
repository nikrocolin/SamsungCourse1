#include <iostream>
#include <queue>
#include <vector>
#include <conio.h>
using namespace std;

void inwide (int n,vector < vector <int> > matrix) {// передаем матрицу и количество вершин
  bool used[n];// задаем массив использованных вершин
  for (int i = 0; i < n; i++) {
  	used[i] = false;
  }
  queue<int> q;// для поочередного добавления
  q.push(0);
  used[0] = true; 
  while (!q.empty()) {
    int var = q.front();//берем 1 элемент из очереди
    cout << var << " ";// присваиваем его  значение переменной
	q.pop();// выбрасываем его
    for (auto a : matrix[var]) { // идем по его связям с другими вершинами
      int v = a;
      if (!used[v]) {// если попался неиспользованный эелемент добавляем его в очередь
        used[v] = true; // он становится использованным
        q.push(v);
        
      }
    }
  }
}

int main () {

	int number, f, kf=1;
	char ch;
	cout << "\nEnter the number of vertexes: ";
	cin >> number;
	vector < vector <int> > mas(number);
	cout <<"\n After each number press space (even after the last in a string) ";
	for (int i = 0; i < number; i++) {
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
	/*for(vector<vector<int> >::iterator it = mas.begin(); it != mas.end(); ++it){
    	cout << "\n" ;
		for(vector<int>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2){
        	cout << *it2;
    	}
    }*/
    cout << endl;
	inwide(number, mas);
	system ("pause");
	return 0;
}
