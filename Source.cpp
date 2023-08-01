#include <iostream>
#include <vector>
using namespace std;

class Contact
{
	string name = "";
	string surname = "";
	string number = "";
public:
	Contact() = default;
	Contact(const string _name, const string _surname, const string _number) :name(_name), surname(_surname), number(_number) {};
	void setName(const string _name) {
		if (_name.size() > 2)
		{
			name = _name;
		}
		else throw invalid_argument("ad minimum 3 simvol olmalidir");
	}
	const string getName() {
		return name;
	}
	void setSurname(const string _surname) {
		if (_surname.size() > 4)
		{
			surname = _surname;
		}
		else throw invalid_argument("soyad minimum 5 simvol olmalidir");
	}
	const string getSurname() {
		return surname;
	}
	void setNumber(const string _number) {
		if (_number.size() > 9)
		{
			number = _number;
		}
		else throw invalid_argument("nomre minimum 10 simvol olmalidir");
	}
	const string getNumber() {
		return number;
	}
	void showContact()
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
		cout << "Number: " << number << endl;

	}

};

class DataBase {
    Contact** arr = nullptr;
    int count = 0;

public:
    DataBase() = default;
    DataBase(Contact** _arr, int _count) : arr(_arr), count(_count) {}

    ~DataBase() {
        delete[] arr;
    }

    void AddContact(Contact* ct) {
        for (size_t i = 0; i < count; i++) {
            if (arr[i]->getNumber().compare(ct->getNumber()) == 0) {
                throw std::runtime_error("Bu nomrede contact movcuddur.");
            }
        }

        Contact** newarr = new Contact * [count + 1];
        for (size_t i = 0; i < count; i++) {
            newarr[i] = arr[i];
        }
        newarr[count] = ct;
        delete[] arr;
        arr = newarr;
        count++;
    }

    void DeleteByName(const string _name) {
        int index = -1;
        Contact** newarr = new Contact * [count - 1];

        for (size_t i = 0; i < count; i++) {
            if (arr[i]->getName().compare(_name) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            throw std::runtime_error("Bu adda biri tapilmadi.");
        }

        for (size_t i = 0; i < index; i++) {
            newarr[i] = arr[i];
        }
        for (size_t i = index + 1; i < count; i++) {
            newarr[i - 1] = arr[i];
        }

        delete[] arr;
        arr = newarr;
        count--;
    }

    Contact* SearchByName(const string _name) {
        for (size_t i = 0; i < count; i++) {
            if (arr[i]->getName().compare(_name) == 0) {
                return arr[i];
            }
        }

        return nullptr;
    }
    void show()
    {
        for (size_t i = 0; i < count; i++)
        {
            arr[i]->showContact();
        }
    }
};

int main() {
   int count = 3;
   Contact** contacts = new Contact * [count]
   {
           new Contact("Rasul", "Aslanov", "0556136155"),
           new Contact("Ali", "Aliyev", "0123456789"),
           new Contact("Veli", "Veliyev", "9876543210")

   };
   DataBase Data(contacts,count);
  // Data.show();
   Data.AddContact(new Contact("Filankes", "Filankesov", "0556666666"));
  // Data.show();
   //Data.DeleteByName("Rasul");
   //Data.show();
  //Contact* a =Data.SearchByName("Rasul");
   //a->showContact();
   
}