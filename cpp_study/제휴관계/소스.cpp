#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Doctor; //forward declaration

class Patient
{
private:
	string _name;
	vector<Doctor*> _doctors;
public:
	Patient(string name) : _name(name)
	{}

	void addDoctor(Doctor* new_doctor)
	{
		_doctors.push_back(new_doctor);
	}

	void meetDoctors();

	friend class Doctor;
};

class Doctor
{
private:
	string _name;
	vector<Patient*> _patients;
public:
	Doctor(string name) : _name(name)
	{}

	void addPatient(Patient* new_patient)
	{
		_patients.push_back(new_patient);
	}
	friend class Patient;

	void meetPatients()
	{
		for (auto& ele : _patients)
		{
			cout << "Meet Patient : " << ele->_name << endl;
		}
	}
};

void Patient::meetDoctors()
{
	for (auto& ele : _doctors)
	{
		cout << "Meet Doctor : " << ele->_name << endl;
	}
}

int main()
{
	Patient* p1 = new Patient("Jan");
	Patient* p2 = new Patient("Swan");
	Patient* p3 = new Patient("Yee");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor G");
	
	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	p1->meetDoctors();
	d1->meetPatients();

	delete p1;
	delete p2;
	delete d1;
	delete d2;
	return 0;
}