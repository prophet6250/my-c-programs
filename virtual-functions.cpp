#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person {
public:
	string name;
	int age;

	virtual void getdata()
	{
		cin >> name >> age;
	}

	virtual void putdata()
	{
		cout << name << " " << age << "\n";
	}
};

class Professor : public Person {
	int publications, cur_id;
public:
	Professor() 
	{
		static int counter = 0;
		cur_id = counter + 1;
		counter += 1;

		publications = 0;
	}

	void getdata()
	{
		cin >> name >> age >> publications;
		return;
	}
	
	void putdata()
	{
		cout << name << " " << age << " " << publications << " " << cur_id 
			 << "\n";
	}
};

class Student : public Person {
	int marks[6], cur_id;
public:
	Student()
	{
		static int counter = 0;
		counter += 1;
		cur_id = counter;
	}
	
	void getdata()
	{
		cin >> name >> age;
		for (int i = 0; i < 6; i += 1) {
			cin >> marks[i];
		}
	}

	void putdata() 
	{
		int sum = 0, i = 6;
		
		while (i--) {
			sum += marks[i];
		}

		cout << name << " " << age << " " << sum << " " << cur_id << "\n";

	}
};

int main()
{

	int n, val;
    cin >> n; 
    Person *per[n];

    for(int i = 0;i < n; i++){

    	cin >> val;
    	if(val == 1){
    		per[i] = new Professor;

    	}
        else per[i] = new Student; /

        per[i]->getdata(); 

    }

    for(int i = 0; i < n; i++)
        per[i]->putdata(); 

    return 0;

}
