#include <iostream>
using namespace std;

union Student {
    int age;
    int grupa;
};

int main() {
    int n = 5;
    Student* studenti = new Student[n];
    for (int i = 0; i < n; i++) {
        studenti[i].age=i*i*i*i*i;
        studenti[i].grupa=69*i;
    }

    for (int i=0;i<n;i++) {
        cout<<studenti[i].age<<" "<<studenti[i].grupa<<endl;
    }
    delete studenti;
}
