#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


struct Person
{
    char age[25];
    char first[25];
    char last[25];
    char phone[25];
};

class BinaryWorker
{
private:
    char age[25];
    char first[25];
    char last[25];
    char phone[25];

public:
    BinaryWorker() {}

    ~BinaryWorker() {}

    void SetData(int age, string fname, string lname, string phone)
    {
        sprintf(this->age, "%d", age);
        sprintf(this->first, "%s", fname.c_str());
        sprintf(this->last, "%s", lname.c_str());
        sprintf(this->phone, "%s", phone.c_str());
    }

    void Save(ofstream &fs)
    {
        fs.write((char *) &age, sizeof(age));
        fs.write((char *) &first, sizeof(first));
        fs.write((char *) &last, sizeof(last));
        fs.write((char *) &phone, sizeof(phone));
    }

    void WriteBinaryFile(string filename)
    {
        ofstream fs;
        fs.open(filename, ios::out | ios::binary | ios::app);
        if (!fs.is_open())
        {
            printf("Cannot open file %s \n", filename);
        }
        else
        {
            this->Save(fs);
        }
        fs.close();
    }

    void ReadBinaryFile(string filename)
    {
        Person person;
        ifstream binaryFile;
        int size = 0;
        binaryFile.open(filename, ios::in | ios::binary);
        binaryFile.seekg(0, ios::end);
        size = (int)binaryFile.tellg();
        binaryFile.seekg(0, ios::beg);

        while(binaryFile.tellg() < size)
        {
            binaryFile.read((char *) person.age, sizeof(person.age));
            binaryFile.read((char *) person.first, sizeof(person.first));
            binaryFile.read((char *) person.last, sizeof(person.last));
            binaryFile.read((char *) person.phone, sizeof(person.phone));

            std::cout << person.age << "\t" << person.first << "\t" << person.last << "\t" << person.phone << endl;
        }

        binaryFile.close();
    }
};

int main()
{
    string filename = "records.dat";
    string fname, lname, phone;
    int age;

    //unique_ptr<BinaryWorker> bWorker (new BinaryWorker() );
    BinaryWorker* bWorker  =  new BinaryWorker() ;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter firstname: ";
    cin >> fname;
    cout << "Enter lastname: ";
    cin >> lname;
    cout << "Enter cellphone number: ";
    cin >> phone;

    bWorker->SetData(age, fname, lname, phone);
    bWorker->WriteBinaryFile(filename);
    bWorker->ReadBinaryFile(filename);
}
