#include"shared_ptr.h"

#include<iostream>
#include<string>
#include<vector>

class Employee
{
public:
	std::string uin;
	std::string name;
	int age;
	double salary;

	Employee(std::string uin, std::string name)
		:uin(uin), name(name)
	{
		std::cout << __FUNCTION__ << "\t" << "A new employee join the job\n";
	}

	~Employee()
	{
		std::cout << __FUNCTION__ << "\t" << "An old employee left the job\n";
	}
};

void shared_ptr_test1()
{
	shared_ptr<Employee> frontend_engineer;
	{
		shared_ptr<Employee> backend_engineer(new Employee("2020XXXX", "Xiao Cai"));

		std::cout << "use_count" << "\t" << backend_engineer.use_count() << "\n";
		std::cout << backend_engineer->uin << "\t" << backend_engineer->name << "\t" << "backend_engineer" << "\n";

		frontend_engineer = backend_engineer;
	}

	std::cout << "use_count" << "\t" << frontend_engineer.use_count() << "\n";
	std::cout << frontend_engineer->uin << "\t" << frontend_engineer->name <<"\t"<< "frontend_engineer" << "\n";

	shared_ptr<Employee> algorithm_engineer(frontend_engineer);
	std::cout << "use_count" << "\t" << algorithm_engineer.use_count() << "\n";

	std::cout << algorithm_engineer->uin << "\t" << algorithm_engineer->name << "\t" << "frontend_engineer and algorithm_engineer" << "\n";
}


void shared_ptr_test2()
{
	std::vector<shared_ptr<Employee> >backend_group;
	for (int i = 0; i < 5; i++)
	{
		backend_group.push_back(shared_ptr<Employee>(new Employee("2020", "Temporary Worker")));
	}

	std::vector<shared_ptr<Employee> >frontend_group;
	frontend_group.swap(backend_group);

	frontend_group.clear();
}

int main()
{
	shared_ptr_test1();
	std::cout << "\n";
	shared_ptr_test2();
	getchar();
}