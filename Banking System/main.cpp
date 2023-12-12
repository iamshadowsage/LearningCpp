#include<iostream>
#include<string>
#include<limits>
#include<vector>




class Customer{
	std::string c_name,c_address;
	int c_age;
	long int c_mobile;

	long int c_balance,c_id;
	std::string c_password;
	static std::vector<Customer> CustomerList;
public:
	void getinfo(std::string name,int age,long int mobile_number,std::string address);
	static void custInfo(Customer c1);
	static void addcustomer(Customer customer);

	
};

std::vector<Customer> Customer::CustomerList;

void Customer::getinfo(std::string name,int age,long int mobile_number,std::string address)
{
	c_name = name;
	c_age = age;
	c_mobile = mobile_number;
	c_address = address;
}

void Customer::custInfo(Customer c1)
{
	std::cout<<"Name          : "<<c1.c_name<<std::endl;
	std::cout<<"Age           : "<<c1.c_age<<std::endl;
	std::cout<<"Mobile Number : "<<c1.c_mobile<<std::endl;
	std::cout<<"Address       : "<<c1.c_address<<std::endl;
}

void Customer::addcustomer(Customer customer)
{
	for(int i = 0 ; i < Customer::CustomerList.size();i++)
	{
		if(Customer::CustomerList[i].c_name == customer.c_name)
		{
			std::cout<<"Customer Already Exists"<<std::endl;
			return;
		}
	}
	Customer::CustomerList.push_back(customer);
}


int main()
{
	std::string name ,address;
	int age;
	long int mobileNumber;
	std::cout<<"Enter Your Name : ";
	getline(std::cin,name);
	
	std::cout<<"Enter age : ";
	std::cin>>age;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	std::cout<<"Enter Address : ";
	getline(std::cin,address);
	
	std::cout<<"Enter Mobile Number : ";
	std::cin>>mobileNumber;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

	Customer customer1;
	customer1.getinfo(name,age,mobileNumber,address);

	Customer::custInfo(customer1);
	Customer::addcustomer(customer1);

	Customer customer2;
	customer2.getinfo(name,age,mobileNumber,address);
	Customer::addcustomer(customer2);
	return 0;
}