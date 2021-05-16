#include<bits/stdc++.h>
using namespace std;
struct Day{
    int date,month,year;
};
class hostel{
    int room_no;
    char name[20];
    char address[100];
    char phone_no[11];
    char gender;
    int fees;
    Day Time;
    public:
    void main_menu();
    void clr(){system("cls");}
    void add();
    bool check_room(int );
    void display_all_rec();
    void display_single_data();
    void display_room();
    void modify_data();
    void delete_rec();
    void pay_fees();
    void display_by_gender();
};
void hostel::main_menu(){
    int choose;
    do{
        cout<<"\n\n";
        cout<<" \n\t\t\t\t\t************* ";
		cout<<" \n\t\t\t\t\t* MAIN MENU *";
		cout<<" \n\t\t\t\t\t*************"; 
        cout<<"\n\n\t\t\tEnter what you want!!!!!!!!!!";
		cout<<"\n\n\n\t\t\tl.Allot A Room"; 
		cout<<"\n\t\t\t2.student Record"; 
		cout<<"\n\t\t\t3.Search Record"; 
		cout<<"\n\t\t\t4.Modify Record";
		cout<<"\n\t\t\t5.Delete Record"; 
        cout<<"\n\t\t\t6.Pay fees";
        cout<<"\n\t\t\t7.Display (MALE/FEMALE)";
        cout<<"\n\t\t\t8.EXit";
		cout<<"\n\n\t\t\tEnter Your Choice: "; 
		cin>>choose;
        clr();
        switch (choose)
        {
            case 1:add();break;
            case 2:display_all_rec();break;
            case 3:display_room();break;
            case 4:modify_data();break;
            case 5:delete_rec();break;
            case 6:pay_fees();break;
            case 7:display_by_gender();break;
            case 8:cout<<"EXIT........";exit(0);break;
            default:
            cout<<"Wrong input............"<<endl;
            break;
        }
    }while(choose);
}
bool hostel::check_room(int r){
    int flag=0;
    fstream file("Hostel.dat",ios::binary|ios::in);
    if(!file.is_open()){cout<<"File doesnt open Error in add fun()\n";}
    while (file.read((char*)this,sizeof(*this)))
    {
        if(r==room_no){
            flag=1;
            break;
        }
    }
    file.close();
    if(flag){
        return true;
    }else{
        return false;
    }
}
void hostel::display_single_data(){
    cout<<"Name : "<<name<<endl;
    cout<<"Gender : "<<gender<<endl;
    cout<<"Room number : "<<room_no<<endl;
    cout<<"Phone number : "<<phone_no<<endl;
    cout<<"Fees pending : "<<fees<<endl;
    cout<<"Date of birth : "<<Time.date<<"/"<<Time.month<<"/"<<Time.year<<endl;
    cout<<"Address : "<<address<<endl;
}
void hostel::add(){
    int r;
    fstream file("Hostel.dat",ios::app|ios::binary);
    if(!file.is_open()){cout<<"File doesnt open Error in add fun()\n";return;}
    cout<<"\n\t\t\t*************************";
    cout<<"\n\t\t\t* Enter Student details * ";
    cout<<"\n\t\t\t*************************"; 
    cout<<"\n\nEnter room_no : ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while(!(cin>>r)){
        cout<<"\n\nERROR:: Wrong data type Please Enter Int data type........."<<endl;
        cout<<" Enter room_no : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    if(check_room(r)){cout<<"Sorry  !!!  Room is already book!!!!!\n";}
    else{
        room_no=r;
        cin.ignore(1);
        cout<<"Enter name : ";
        cin.getline(name,20);
      
        cout<<"Enter phone no : ";
        cin.getline(phone_no,11);

        cout<<"Enter gender (M/F) : ";cin>>gender;

        cin.clear();
        cin.ignore();
        cout<<"Enter Date of birth \n";
        cout<<"Date : ";cin>>Time.date;
        cout<<"Month : ";cin>>Time.month;
        cout<<"Year : ";cin>>Time.year;

        cin.clear();
        cin.ignore();
        cout<<"Enter address : ";
        cin.getline(address,100);

        cout<<"Do you want to payfees (Y,N) ? ";
        char c;cin>>c;
        if(c=='Y'||c=='y'){
            cout<<"Depost money (Total fees = 50,000) : ";
            int temp;cin>>temp;
            temp=(50000-temp);
            if(temp<0){
                cout<<"You have gave extra money : "<<abs(temp)<<endl;
                fees=0;
            }else{
                fees=temp;
            }
            cout<<fees<<" balance is pending !!!!!"<<endl;
        }else{
            fees=50000;
        }
        file.write((char*)this,sizeof(*this));
        cout<<"Room is Booked now...........\n";
    }
    file.close();
    system("pause");
    clr();
}

void hostel::display_all_rec(){
    ifstream file("Hostel.dat",ios::binary|ios::in);
    if(!file.is_open()){cout<<"File doesnt open Error in display_all_fun()\n";return;}
    cout<<"\n\t\t\t********************";
    cout<<"\n\t\t\t*  Student detail  *";
    cout<<"\n\t\t\t********************\n";
    int i=0;
    while(file.read((char*)this,sizeof(hostel))){
        cout<<(++i)<<".\n";
        display_single_data();
        cout<<"\n";
    }
    file.close();
    system("pause");
    clr();
}
void hostel::display_room(){
    int r;
    cout<<"Enter room to be searched : ";cin>>r;
    ifstream file("Hostel.dat",ios::binary|ios::in);
    if(!file.is_open()){cout<<"File doesnt open Error in display_room_fun()\n";return;}
    cout<<"\n\t\t\t********************";
    cout<<"\n\t\t\t*  Student  detail *";
    cout<<"\n\t\t\t********************\n";
    int flag=0;
    while(file.read((char*)this,sizeof(hostel))){
        if(r==room_no){
            display_single_data();
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Room is empty......."<<endl;
    }
    file.close();
    system("pause");
    clr();
}
void hostel::modify_data(){
    int r,flag=0;
    long pos;
    cout<<"\n\t\t\t\t\t**********************";
    cout<<"\n\t\t\t\t\t*  EDIT DATA MENU    *";
    cout<<"\n\t\t\t\t\t**********************\n";
    cout<<"Enter room number to be modified : ";cin>>r;
    if(!check_room(r)){"Room is empty .......";return;}
    fstream file("Hostel.dat",ios::binary|ios::in|ios::out);
    if(!file.is_open()){cout<<"Error in modify data fun()"<<endl;return;}
    while(!file.eof()){
        pos=file.tellg();
        file.read((char*)this,sizeof(*this));
        if(r==room_no){
            cout<<"\n\nEnter new data   "<<endl;
            cout<<"Enter name : ";cin.ignore(1);
            cin.getline(name,20);

            cout<<"Enter Gender (M/F) ";cin>>gender;
            cin.clear();
            cin.ignore();
            cout<<"Enter phone number : ";
            cin.getline(phone_no,11);
            
            cout<<"Enter address : ";
            cin.getline(address,100);

            cout<<"Enter Date of birth \n";
            cout<<"Date : ";cin>>Time.date;
            cout<<"Month : ";cin>>Time.month;
            cout<<"Year : ";cin>>Time.year;

            file.seekg(pos);
            file.write((char*)this,sizeof(*this));
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"\nModify successfully ........";
    }else{
        cout<<"\nModify unsuccessfully........";
    }

    file.close();
    system("pause");
    clr();
}
void hostel::pay_fees(){
    int r,flag=0;
    int pos;
    cout<<"\n\t\t\t\t******************";
    cout<<"\n\t\t\t\t*  FEES COUNTER  *";
    cout<<"\n\t\t\t\t******************";
    cout<<"\nEnter room number : ";cin>>r;
    fstream file("Hostel.dat",ios::binary|ios::in|ios::out);
    if(!file.is_open()){cout<<"Error in pay_fees()"<<endl;return;}
    while(!file.eof()){
        pos=file.tellg();
        file.read((char*)this,sizeof(*this));
        if(r==room_no){
            if(fees==0){
                cout<<"Your fees is already submitted...."<<endl;
            }else{
                cout<<"Name : "<<name<<endl;
                cout<<"Your pending Fees is "<<fees<<endl;
                int temp;
                cout<<"Enter money to deposit ";cin>>temp;
                temp=fees-temp;
                if(temp<0){
                    cout<<"Return change : "<<abs(temp);
                    fees=0;
                }else{
                    fees=temp;
                }
                file.seekg(pos);
                file.write((char*)this,sizeof(*this));
            }
            flag=1;
            break;
        }
    }
    if(flag==1){
        cout<<"Fees deposit........"<<endl;
    }else{
        cout<<"Fees doest not deposit........"<<endl;
    }
    file.close();
    system("pause");
    clr();
}
void hostel::delete_rec(){
    int r;char c;
    cout<<"Enter room number to be deleted : ";cin>>r;
    if(!check_room(r)){cout<<"Room is already empty!!!!"<<endl;return;}
    ifstream file("Hostel.dat",ios::binary|ios::in);
    ofstream ofile("NEWFILE.dat",ios::binary|ios::out);
    while(file.read((char*)this,sizeof(*this))){
        if(r==room_no){
            display_single_data();
            cout<<"\n\nDo you want to Delete data (y/n) : ";cin>>c;
            if(c=='n'){
                cout<<"Data is not deleted ..........\n";
            }else{
                cout<<"Data is deleted ..........\n";
                continue;
            }
        }
        ofile.write((char*)this,sizeof(*this));
    }
    file.close();
    ofile.close();
    remove("Hostel.dat");
    rename("NEWFILE.dat","Hostel.dat");
    clr();
}
void hostel::display_by_gender(){
    char c;
    ifstream file("Hostel.dat",ios::binary|ios::in);
    if(!file.is_open()){cout<<"File doesnt open Error in display_all_fun()\n";return;}
    cout<<"\n\t\t\t********************";
    cout<<"\n\t\t\t*  Student detail  *";
    cout<<"\n\t\t\t********************\n";
    cout<<"\tTo Display MALE(M) and for Female(F) : ";cin>>c;
    if(c=='M'||c=='m'){
        c='M';
    }else{
        c='F';
    }
    int i=0;
    while(file.read((char*)this,sizeof(hostel))){
        if(gender=='m'||gender=='M'){
            gender='M';
        }else{
            gender='F';
        }
        if(gender==c){
            cout<<(++i)<<".\n";
            display_single_data();
        }
    }
    file.close();
    system("pause");
    clr();
}
int main(){
    hostel h;
    cout<<"\n\t\t\t\t***************************** "; 
	cout<<"\n\t\t\t\t* HOSTEL MANAGEMENT PROJECT *"; 
	cout<<"\n\t\t\t\t*****************************";
    h.main_menu();
    return 0;
}