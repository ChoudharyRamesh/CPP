#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#pragma pack(1)
using namespace std;
// name collision update remaining
// stream pos problem ,comparing with integer
class student
{
private:
    char name[20] = { 0 };
    int roll=0;
    int marks=0;

    void table() {
        cout << "------------------------------------------" << endl;
        cout << "| " << left << setw(8) << "ROLL NO." << "| " << left << setw(22) << "STUDENT-NAME" << "| " << left << setw(5) << "MARKS" << "|" << endl;
        cout << "------------------------------------------" << endl;
    }

    void showonedata()
    {
        cout << "| " << left << setw(8) << roll << "| " << left << setw(22) << name << "| " << left << setw(5) << marks << "|" << endl;
        cout << "------------------------------------------" << endl;
    }


    int PositiveDigitTake()
    {
        string DIGIT_STRING;
        int temp = 0;
    DIGIT_TAKE:
        cin >> ws;    getline(cin, DIGIT_STRING);
        for (auto i : DIGIT_STRING)
            if (!isdigit(i))
            {
                cout << "Input can't be alphabetic or negative ,try again !" << endl;
                goto DIGIT_TAKE;
            }
        try { temp = stoi(DIGIT_STRING); }
        catch (exception e) { cout << "Out of Range [0-999999999] ,try again !" << endl;  goto DIGIT_TAKE; }
        return temp;
    }

    string  AlphabetTake() {
        string AlphaStr;
    AlphaTake:
        if (AlphaStr.size() > 0) AlphaStr.clear();
        cin >> ws; getline(cin, AlphaStr);
        for (auto i : AlphaStr)
        {
            if (i == ' ') { continue; }
            if (!isalpha(i)) {
                cout << "Alphabet can't be numeric !,try again." << endl;
                goto AlphaTake;
            }
        }
        return AlphaStr;
    }

    inline   void rolltake()
    {
    back:
        cout << "enter roll no. ";
        roll = PositiveDigitTake();
        if (roll <= 0) { cout << "Roll No. cannot be ZERO ,try again !" << endl; goto back; }
    }

    inline  void markstake()
    {
        cout << "Enter marks. ";
        marks = PositiveDigitTake();
    }

    inline  void nametake()
    {
        cout << "Enter name.  ";
        for (int k =0;k<20;k++)
                  name[k]='\0';
        string temp = AlphabetTake();
        int i; int j=temp.size();
        for (i = 0; i < 20 && i<j; i++)
        {
            name[i] = temp[i];
        }
        if (name[19] != '\0')name[19] = '\0';
    }

    inline  void Umarkstake()
    {
        cout << "Enter marks for update. ";
        marks = PositiveDigitTake();
    }

    inline  void   Unametake()
    {    for (int k =0;k<20;k++)
           name[k]='\0';
        cout << "Enter name for update. ";
        string temp = AlphabetTake();
        int i; int j = temp.size();
        for (i = 0; i < 20 && i < j; i++)
        {
            name[i] = temp[i];
        }
        if (name[19] != '\0')name[19] = '\0';
    }

    int searchtemp()
    {
        int temproll = 0;
        rolltake();
        temproll = this->roll; this->roll =0 ;
        ifstream fdata("student.dat", ios::in | ios::binary);
        fdata.read(reinterpret_cast<char*>(this), sizeof(*this));
        while (!fdata.eof())
        {
            if (this->roll == temproll)
            {
                this->roll = temproll;
                int a1 = fdata.tellg(); // this is the problem if streampos value is greater than capacity of a1
                int a2 = sizeof(*this);
                 temproll = a1 - a2;
                fdata.close();
                return temproll; // sending location if found
            }
            else
                fdata.read(reinterpret_cast<char*>(this), sizeof(*this));
        }
        this->roll = temproll;
        fdata.close();
        return -1;
    }


    void updatetemp(int location)
    {
        fstream fdata("student.dat", ios::in | ios::out | ios::ate | ios::binary);
        fdata.seekp(location, ios::beg);
        Unametake(); Umarkstake();
        if(this->roll<=0){ cout<<"error 415"; exit(0); }
        fdata.write(reinterpret_cast<const char*>(this), sizeof(*this));
        fdata.close();
        cout << "Data updated successfully" << endl;
        return;
    }

    bool nodata()
    {
        ifstream fdata("student.dat", ios::in | ios::binary);
        fdata.read((char*)this, sizeof(*this));
        if (fdata.eof())
        {
            fdata.close(); return false;
        }
        else
        {
            fdata.close(); return true;
        }
    }

public:

    student()
    {
        ifstream fdata("student.dat", ios::in | ios::binary);
        if (fdata.is_open()) fdata.close();
        else
        {
            ofstream fdata("student.dat", ios::app | ios::binary);
            fdata.close();
        }
    }

    void  deleteallData()
    {
        remove("student.dat");
        cout << "All data deleted sucessfully " << endl << endl;
        ofstream fdata("student.dat", ios::app | ios::binary);
        fdata.close();
    }

    void showalldata()
    {
        table();
        ifstream fdata("student.dat", ios::in | ios::binary);
        fdata.read((char*)this, sizeof(*this));
        while (!fdata.eof())
        {
            showonedata();
            fdata.read((char*)this, sizeof(*this));
        }
        fdata.close();
    }



    void write()
    {
        int loc = searchtemp();
        if (loc == -1)
        {
            ofstream fdata("student.dat", ios::app | ios::binary);
            nametake(); markstake();
            if(this->roll<=0){ cout<<"error 414"; exit(0); }
            fdata.write(reinterpret_cast<const char*>(this), sizeof(*this));
            fdata.close();
            cout << "Data written successfully" << endl;
            return;
        }
        else
        {
            cout << "Data already exist,do you want to rewrite ?" << endl;
            int flag = 0;
        back:
            cout << "   1. YES" << endl; cout << "   2. NO. ";
            cin >> ws;  cin >> flag;
            switch (flag)
            {
            case 1:  updatetemp(loc);
                return;
            case 2:  return;
            default: cout << "   Invalid Entry ! ,try again " << endl; goto back;
            }

        }
    }

    void update()
    {
        int loc = searchtemp();
        if (loc >= 0)
        {
            updatetemp(loc);
            return;
        }
        else {
            cout << "Data not found !" << endl;
            return;
        }
    }

    void search()
    {
        int loc = searchtemp();
        if (loc >= 0)
        {
            cout << endl << "Data found" << endl; table();
            showonedata();
            return;
        }
        else
        {
            cout << "Data not found !" << endl;
            return;
        }
    }

    void deletedata()
    {
        int loc = searchtemp();
        if (loc >= 0)
        {
            ofstream fp("temp.dat", ios::app | ios::binary);
            ifstream fdata("student.dat", ios::in | ios::binary);
            fdata.read(reinterpret_cast<char*>(this), sizeof(*this));
            while (!fdata.eof())
            {
                if (fdata.tellg() == loc + sizeof(*this))
                {
                    fdata.read(reinterpret_cast<char*>(this), sizeof(*this));
                    continue;
                }

                fp.write(reinterpret_cast<const char*>(this), sizeof(*this));
                fdata.read(reinterpret_cast<char*>(this), sizeof(*this));
            }
            fp.close(); fdata.close();
            remove("student.dat"); rename("temp.dat", "student.dat");
            cout << "Deleted successfully" << endl;
            return;
        }
        else
        {
            cout << "Data not found !" << endl;
            return;
        }
    }

    void start()
    {
        int choice = 8;
        cout << " WELCOME TO DEMO PROGRAM FOR STUDENT DATA MANAGEMENT" << endl;
        cout << " VERSION ::-  1.0" << endl;
        cout << " DEVELOPED BY  ::-  RAMESH CHOUDHARY" << endl;
        cout << " FEATURE :: \n\t1. Search\n\t2. Upate\n\t3. Delete" << endl;
        cout << " "; system("pause");
        system("cls");
    bck:
        cout << "1. Add Data" << endl;
        cout << "2. Delete Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Search Data" << endl;
        cout << "5. Show All Data" << endl;
        cout << "6. clear screen." << endl;
        cout << "7. delete all data " << endl;
        cout << "8. exit. ";
        choice = PositiveDigitTake();
        switch (choice)
        {
        case 1:
            system("cls");
            write();
            cout << endl;
            showalldata();
            cout << endl << endl; goto bck;
        case 2:  if (nodata())
        {
            system("cls");
            showalldata(); cout << endl;
            deletedata();
            cout << endl;
            showalldata();
            cout << endl << endl; goto bck;
        }
              else
        {
            system("cls");
            cout << "No data found for delete !" << endl;
            cout << endl; goto bck;
        }
        case 3:  if (nodata())
        {
            system("cls");
            showalldata(); cout << endl;
            update();
            cout << endl;
            showalldata();
            cout << endl << endl; goto bck;
        }
              else
        {
            system("cls");
            cout << "No data found for update !" << endl;
            cout << endl; goto bck;
        }
        case 4:  if (nodata())
        {
            system("cls");
            search();
            cout << endl;
            showalldata();
            cout << endl << endl; goto bck;
        }
              else
        {
            system("cls");
            cout << "No data found for searching !" << endl;
            cout << endl; goto bck;
        }
        case 5:  if (nodata())
        {
            system("cls");
            showalldata();
            cout << endl << endl; goto bck;
        }
              else
        {
            system("cls");
            cout << "No data found for display !" << endl;
            cout << endl; goto bck;
        }
        case 6: system("cls");
            goto bck;
        case 7:  if (nodata())
        {
            system("cls");
            deleteallData();
            goto bck;
        }
              else
        {
            system("cls");
            cout << "No data found for delete !" << endl;
            cout << endl; goto bck;
        }

        case 8: exit(0);
        default:
            system("cls");
            cout << "Invalid Entry ! ,try again " << endl;
            goto bck;
        }
    }


};
int main()
{
    student obj;
    obj.start();
}




















