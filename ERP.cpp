#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class secure                                   //for login and password
{
    public:
    char user[50];                              //username
    char pass[50];                              //password
    void get_data()                              //to get username and password
    {
        cout<<"\nEnter username - ";
        cin.ignore();
        cin.getline(user,50);
        cout<<"\nEnter password - ";
        cin.ignore();
        cin.getline(pass,50);
    }
};
class info                        //information class
{
protected:
	char name[20];
	int gr_no;
	int roll_no;
	char department[50];
	char div;
	char gender;
	int MinMark10;
	int MaxMark10;
	int MinMark12;
	int MaxMark12;
	int percentage10;
	int percentage12;
	char address[50];

public:
	void get_info();                           //to get data
	void put_info();                           //to put data
	int check() { return gr_no; }
};

void info::get_info()
{
	cout << "\nEnter your information" << endl;

	cout << "\nGr number			  :\t";   cin >> gr_no; cout << endl;
	cout << "\nName					  :\t";   cin.ignore(); cin.getline(name, 20); cout << endl;
	cout << "\nDepartment			  :\t";   cin.getline(department, 50); cout << endl;
	cout << "\nDivision				  :\t";   cin >> div; cout << endl;
	cout << "\nRoll number			  :\t";   cin >> roll_no; cout << endl;
	cout << "\nGender (m/f)           :\t";   cin.ignore(); cin >> gender; cout << endl;
	cout << "\n 10th marks obtained   :\t";   cin >> MinMark10; cout << endl;
	cout << "\nMax marks			  :\t";   cin >> MaxMark10; cout << endl;
	cout << "\n12th mark obtained	  :\t";   cin >> MinMark12; cout << endl;
	cout << "\nMax marks              :\t";   cin >> MaxMark12; cout << endl;
	cout << "\nAddress                :\t";   cin.ignore(); cin.getline(address, 50); cout << endl;
	cout << endl;
	percentage10 = ((MinMark10 * 100) / MaxMark10);
	percentage12 = ((MinMark12 * 100) / MaxMark12);
}

void info::put_info()
{
	cout << "INFORMATION" << endl;
	cout << "Gr number             :\t" << gr_no << endl;
	cout << "Name                  :\t" << name << endl;
	cout << "Department		       :\t" << department;
	cout << "\tDivision		       :\t" << div << endl;
	cout << "Roll number           :\t" << roll_no << endl;
	cout << "Gender                :\t" << gender << endl;
	cout << "10th marks obtained   :\t" << MinMark10;
	cout << "\tMax marks           :\t" << MaxMark10 << endl;
	cout << "Percentage            :\t" << percentage10 << endl;
	cout << "12th mark obtained    :\t" << MinMark12;
	cout << "\tMax marks           :\t" << MaxMark12 << endl;
	cout << "Percentage            :\t" << percentage12 << endl;
	cout << "Address               :\t" << address << endl;
}


class entc:public info
{
   protected:fstream file4;
	     fstream ftemp4;
	     fstream ftrash4;
         fstream login4;
   public:void create()
          {
            info dtl4;
	    file4.open("entc.txt", ios::app);
	    dtl4.get_info();
	    file4.write((char*)&dtl4, sizeof(dtl4));
	    file4.close();
          }
	  void display()
	  {
	    info dtl4;
	    file4.open("entc.txt", ios::in);
	    while (file4.read((char*)&dtl4, sizeof(dtl4)))
	    {
		dtl4.put_info();
	    }
	    file4.close();
	  }
	  	  	  void displayuser(int key)                           //To display student info by user
{
    info dtl4;
    int k=1;
    file4.open("entc.txt",ios::in);
    while(file4.read((char*)&dtl4,sizeof(dtl4)))
    {
        if(k==key)
        {
            dtl4.put_info();
        }
        k++;
    }

    file4.close();
}

	  void searchdata()
	  {
	    info dtl4;
	    int check;
	    int flag = 0;
	    file4.open("entc.txt", ios::in);
	    cout << "\nEnter Gr number you want to search - ";
            cin >> check;
            while (file4.read((char*)&dtl4, sizeof(dtl4)))
	    {
		if (dtl4.check() == check)
		{
			cout << "Details of students - " << endl;
			dtl4.put_info();
			flag = 1;
			break;
		}
	    }
	file4.close();
	if(flag==0)
		cout << "The Gr No. " << check << " not found....\n\n";
	  }
	  void deletedata()
	  {
	        info dtl4;
		int check;
		int flag = 0;
		file4.open("entc.txt", ios::in);
		ftemp4.open("temp4.txt", ios::out);
		ftrash4.open("trash4.txt", ios::app);
                cout << "\nEnter Gr number you want to search - ";
	        cin >> check;
                while (file4.read((char*)&dtl4, sizeof(dtl4)))
		{
			if (dtl4.check() == check)
			{
				cout << "The Following Gr No. " << check << " has been moved to Trash:\n";
				dtl4.put_info();
				ftrash4.write((char*)&dtl4, sizeof(dtl4));
				flag = 1;
			}
			else
			{
				ftemp4.write((char*)&dtl4, sizeof(dtl4));
			}
		}
		ftrash4.close();
		ftemp4.close();
		file4.close();
		if(flag==0)
			cout << "The Gr No. " << check << " not found....\n\n";
		remove("entc.txt");
		rename("temp4.txt", "entc.txt");

	  }
	  void showdelete()
	  {
	        fstream ftrash4;
		info dtl4;
		ftrash4.open("trash4.txt", ios::in);

		while (ftrash4.read((char*)&dtl4, sizeof(dtl4)))
		{
			dtl4.put_info();
		}
		ftrash4.close();
		cout << "\nTrash completed";

	  }
	  void putdelete()
	  {
	    	info dtl4;
		int check;
		file4.open("entc.txt", ios::app);
		ftrash4.open("trash4.txt", ios::in);

		cout << "\nEnter Gr number you want to search - ";
		cin >> check;

		while (ftrash4.read((char*)&dtl4, sizeof(dtl4)))
		{
			if (dtl4.check() == check)
			{
				cout << "Details of students - " << endl;
				dtl4.put_info();
				file4.write((char*)&dtl4, sizeof(dtl4));
				break;
			}
		}

		file4.close();
		ftrash4.close();
	  }
	  void modifyadmin()
	  {
	     	info dtl4;
		int check;
		file4.open("entc.txt", ios::in | ios::out);

		cout << "\nEnter Gr number you want to search - ";
		cin >> check;

		while (file4.read((char*)&dtl4, sizeof(dtl4)))
		{
			if (dtl4.check() == check)
			{
				cout << "Details of students - " << endl;
				dtl4.put_info();
				cout << "Modified record - " << endl;
				dtl4.get_info();
				file4.seekg(sizeof(dtl4), ios::cur);
				file4.write((char*)&dtl4, sizeof(dtl4));
				break;
			}
		}
		file4.close();
		cout << "The Gr No. " << check << " not found....\n\n";
	  }

	  	  void modifyuser(int key)                            //Use by user to modify its data
      {
        info dtl4;
        int k=1;
        file4.open("entc.txt",ios::in|ios::out);
        while(file4.read((char*)&dtl4,sizeof(dtl4)))
        {
            if(key==k)
            {
                cout<<"Details of students - "<<endl;
                dtl4.put_info();
                cout<<"Modified record - "<<endl;
                dtl4.get_info();
                file4.seekg(-sizeof(dtl4),ios::cur);
                file4.write((char*)&dtl4,sizeof(dtl4));
                break;
            }
            k++;
       }
       file4.close();
      }
      void put_file()
      {
            secure s;
            s.get_data();
            login4.open("login4.txt",ios::app);
            login4.write((char*)&s,sizeof(s));
            login4.close();
      }

      int get_file()
      {
            int i,j,k=1;
            char username[20];
            char password[20];
            secure s;
            login4.open("login4.txt",ios::in);
            cout<<"\nUser name -- ";
            cin.ignore();
            cin.getline(username,20);
            cout<<"\npassword -- ";
            cin.ignore();
            cin.getline(password,20);
            while(login4.read((char*)&s,sizeof(s)))
            {
                i=strcmp(s.user,username);
                j=strcmp(s.pass,password);
                if(i==0&&j==0)
                {
                    return k;
                }
                k++;
            }
            login4.close();
            return 0;
      }
};

int main()
{
    int ch,n;
    cout<<"\nWHO ARE YOU\n -(PRESS 1 -ADMIN PRESS 2-USER)"<<endl;
    cin>>ch;
    switch(ch)
    {
        case 1: {
                    cout<<"\n................ADMINISTRATION LOGIN......................\n";
                    int choice, choice1,key;
                    int dept;
                    entc obj1;
                    int flag;
                    do
                    {
                        system("cls");
                        do
                        {
                        cout << ".......................ERP SYSTEM.....................\n";
                        cout << "======================================================\n";
                        cout<<"\1. Entc(PRESS 1)\n";
                        cout<<"\nWhich department do you belong	:\t";
                        cin>>dept;
                        switch(dept)
                        {
                          case 1:
                              while(1)
                            {
	                            cout<<"\n1. Sign Up\n2. login\n3. Exit";
	                            cin>>choice1;
	                            switch(choice1)
	                            {
	                                case 1: {cout<<"Sign up\n";
	                                        obj1.put_file();
	                                        break;}
	
	                                case 2: {cout<<"Login\n";
	                                        flag=obj1.get_file();
	                                        if(flag!=0)
	                                        {
	                                            while(1)
	                                            {
	                                                cout << "1. Add Data \n";
	                                                cout << "2. Display Data\n";
	                                                cout << "3. Search Data\n";
	                                                cout << "4. Delete Data\n";
	                                                cout << "5. Show delete Data\n";
	                                                cout << "6. retrieve Delete Data\n";
	                                                cout << "7. Modify data\n";
	                                                cout << "Enter your choice  : ";
	                                                cin >> choice;
	                                                system("cls");
	                                                switch (choice)
	                                                {
	                                                    case 1: obj1.create(); break;
	                                                    case 2: obj1.display(); break;
	                                                    case 3: obj1.searchdata(); break;
	                                                    case 4: obj1.deletedata(); break;
	                                                    case 5: obj1.showdelete(); break;
	                                                    case 6: obj1.putdelete(); break;
	                                                    case 7: obj1.modifyadmin(); break;
	                                                    case 8: return 0;
	                                                }
	                                            }
	                                        }
	                                        else if(flag==0)
	                                        {
	                                            cout<<"\nInvalid user name or password\n";
	                                        }
	                                        break;}

                            }}

                      default: cout<<"press proper department";
                    }
                    system("pause");
                } while (dept);
                cout<<"WANT TO LOGIN AGAIN(press 1)"<<endl;
                cin>>n;
            }
            while(n==1);
            break;}
        case 2:{
                cout<<"\n................USER LOGIN......................\n";
                int choice, choice1,key;
                int dept;
                entc obj1;
                do
                {
                system("cls");
                cout << ".......................ERP SYSTEM.....................\n";
                cout << "======================================================\n";
                cout<<"1. Entc(PRESS 1)\n";
                cout<<"\nWhich department do you belong	:\t";
                cin>>dept;
                int flag;
                switch(dept)
                {
                  case 1:{
                            while(1)
                            {
                            cout<<"\n1. Sign Up\n2. login\n3. Exit";
                            cin>>choice1;
                            switch(choice1)
                            {
                                case 1: {cout<<"Sign up\n";
                                        obj1.put_file();
                                        break;}

                                case 2: {cout<<"Login\n";
                                        flag=obj1.get_file();
                                        if(flag!=0)
                                        {
                                            while(1)
                                            {
                                                cout << "1. Add Data \n";
                                                cout << "2. Display Data\n";
                                                cout << "3. Modify data\n";
                                                cout << "Enter your choice  : ";
                                                cin >> choice;
                                                system("cls");
                                                switch (choice)
                                                {
                                                    case 1: obj1.create(); break;
                                                    case 2: obj1.displayuser(flag); break;
                                                    case 3: obj1.modifyuser(flag); break;
                                                    case 4: return 0;
                                                }
                                            }
                                        }
                                        else if(flag==0)
                                        {
                                            cout<<"\nInvalid user name or password\n";
                                        }
                                        break;}

                               case 3:{
                                    return 0;
                                    break;}}}

                  break;}
                      default: cout<<"press proper department";
                    }
                    system("pause");
                    } while (dept);

                  break; }
        }
   }




