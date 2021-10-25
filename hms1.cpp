//HMSS hospital management system this c++ program implement different kind of services which is given in the Birhanu hospital .........
/*The program will help the patient to register with out the help of third party and see doctors tip and full information this is in
For doctor it is possible to enter tip and other patient requirement and to keep patient confidentiality doctor uses password.


#include <iostream>//input output stream.
#include <string.h>//string library.
#include <iomanip>// used to construct table with proper width.
#include <fstream>//help to use file streams
#include <cstring>//to compare strings
#include <cmath>//to use different math functions

using namespace std;


//structures

struct dateofadd
{
    int dd,mm,yy;
};

//store data of appointment
struct appoint
{
    string dd,mm,yy;
    string day;
};
//used to store data of doctors in the hospital

struct Address
{
string city;
string kfleketema;
int kebele,wereda;

};
//used to store data of hospital

//used to store personal information of patient
struct patient_info
{
string name;
string city;
string kfleketema;

char blood[50];
string  contact;
char sex[50];
int date,month,year,age,kebele,wereda;

int dd,mm,yy;

string health_condition;
string medicine_taken;
int no_medicine,id;
string passcode,passcode2;
string illnesses;
string surgeries;
int no_surgeries;

string vacsination;
string allergies;
string symptoms;
int days;
float cost;
dateofadd dateadd;
Address patiadd;

double weight, height, heightt,bmi;
string tipFromDoc,recommend,checkup,prescription;
};

struct doctors_form
{
string prescription;
string medicine;
string tip;
string recommendation;
string str1;
int passcode;
}d;
//templates
template<typename T1,typename U1,typename V1>
struct Hospitals
{
T1 name_hos;
T1 service;
T1 name_doc;
V1 sex;
T1 specialst;
T1 schedule_doc;
T1 city_hos;
T1 kfleketema_hos;
U1 kebele_hos,wereda_hos;
T1 email_hos;;
T1 phone_hos;;
};

//function declaration

void Administrator();
void menu();
void patient();
void newPatient();
void oldPatient();
void inpatient();
void edit();
void doctor();
void hospital_information();
void medicalTip();

//global variables

int c = 0;//count patients being registered by using increment to count number of patients
int id = 1;//to give unique id for patients and it help to search a patient

struct patient_info p[1000];//patient_info structure global definition
//main function
int main()
{
    //system("color 3E");//used to coloring the output screen
    menu();//here we call the menu function

return 0;
}
//menu function definition it used to give different options for users that help him to fulfill his target
//to call different function
void menu(){
char menu_option;

    cout<<"\n\n\t\tHospital Management System\n"<<endl;
    cout<<" \t\t\tOption [1]-For Administrator\n"<<endl;
    cout<<" \t\t\tOption [2]-For patient \n"<<endl;
    cout<<" \t\t\tOption [3]-For Doctor\n"<<endl;
    cout<<" \t\t\tOption [4]-About the Hospital Management System\n"<<endl;
    cout<<" \t\t\tOption [5]-exit"<<endl;

cout<<"\nEnter your choice from the option listed above: ";
menu:
cin>>menu_option;


switch(menu_option){
case '1':
    system("cls");
    Administrator();
    break;
case '2':
    system("cls");
    patient();
    break;
case '3':
    system("cls");
    doctor();
    break;
case '4':
    system("cls");
   hospital_information();
    break;
case '5':
    system("cls");
    exit(0);
    break;

  default :
   cout<<"\nwrong input try again: ";
goto menu;

}
}
//patient function definition
//patient options
void patient(){
char choice;
cout<<"\nWelcome";

cout<<"\n\tOption[1]For new patient registration"<<endl;
cout<<"\n\tOption[2]for existing patient login"<<endl;
cout<<"\n\tOption[3]for inpatient "<<endl;
cout<<"\n\tOption[4]For editing information"<<endl;
cout<<"\n\tOption[5]Back main menu"<<endl;

cout<<"\n\nEnter your option from listed above: ";
enter:
cin>>choice;//patient_menu;


switch(choice/*patient_menu*/){
case '1':
    system("cls");
    newPatient();//calling newpatient function
    break;

case '2':
    system("cls");
    oldPatient();//oldpatient function is being called
    break;

 case '3':
     system("cls");
     inpatient();
    break;

 case '4':
     system("cls");
     edit();
    break;
case '5':
     system("cls");
     menu();//the system return back to menu part
    break;
default:
cout<<"\nwrong input try again: ";
goto enter;
}
}

//newpatient definition
//registration will be occured....information of patients will be stored
void newPatient(){

int response,inpsex=0,inblood=0;
appoint ap;
Hospitals<string,int,char> Hos;
  ofstream ofile("patient.txt",ios::app);
if (!ofile.is_open())
    {
    cout<<"could not open file";
    }
else
    {
  for (int i = 0; i<1; i++){


        cout<<"\nEnter the day, month and year of registration respectively on different line: "<<endl;
        cin>>p[i].dateadd.dd>>p[i].dateadd.mm>>p[i].dateadd.yy;


  cout<<"\n\Personal Information : "<<endl;

     cout<<"\nEnter full  name : ";
     cin>>p[i].name;

     cout<<"\nAddress : ";
     cout<<"\nEnter city name: ";

    cin>>p[i].city;//used to string with spaces

     cout<<"\nEnter kfleketema : ";
     cin>>p[i].kfleketema;

     cout<<"\nEnter kebele  : ";
     cin>>p[i].kebele;

     cout<<"\nEnter wereda: ";
     cin>>p[i].wereda;

     cout<<"\nContact Number : ";
     cin>>p[i].contact;

     cout<<"\nDate Of Birth : ";
     cin>>p[i].date;

     cout<<"\nMonth Of Birth : ";
     cin>>p[i].month;
      if (p[i].month<=0 && p[i].month>=32)
        {
     cout <<"\n wrong input try again";
   //  goto enter;
        }
       // again:

     cout<<"\nYear Of Birth : ";
     cin>>p[i].year;

     cout<<"\nAge : ";
     cin>>p[i].age;

     enter:
     cout<<"\nSex(F/M) : ";
     cin>>p[i].sex;

      if ((strcmp (p[i].sex , "m" )==0)||(strcmp (p[i].sex , "f") == 0))
//     (strcmp (p[i].sex , "M" )==0)||(strcmp (p[i].sex , "F") == 0))
     inpsex=1;

     if(inpsex == 0)
        {

     cout <<"\n wrong input try again";
     goto enter;

        }
        again:
     cout<<"\nBlood Group : ";
     cin>>p[i+c].blood;

     if((strcmp(p[i+c].blood,"A+")==0)||(strcmp(p[i+c].blood,"a+")==0)||(strcmp(p[i+c].blood,"A-")==0)||(strcmp(p[i+c].blood,"a-")==0)||
      (strcmp(p[i+c].blood,"B+")==0)||(strcmp(p[i+c].blood,"b+")==0)||(strcmp(p[i+c].blood,"B-")==0)||(strcmp(p[i+c].blood,"b-")==0)||
      (strcmp(p[i+c].blood,"O+")==0)||(strcmp(p[i+c].blood,"o+")==0)||(strcmp(p[i+c].blood,"O-")==0)||(strcmp(p[i+c].blood,"o-")==0)||
      (strcmp(p[i+c].blood,"AB+")==0)||(strcmp(p[i+c].blood,"ab+")==0)||(strcmp(p[i+c].blood,"AB-")==0)||(strcmp(p[i+c].blood,"ab-")==0))
       inblood=1;

       if (inblood == 0)
        {
     cout <<"\n wrong input try again";
     goto again;
        }

     system("cls");

    cout<<"\nBMI Calculator: \n";

cout<<"Enter Weight in Kilograms : ";
cin>>p[i].weight;

cout<<"\nEnter Height in Meters : ";
cin>>p[i].height;

p[i].heightt=p[i].height*p[i].height;
p[i].bmi= p[i].weight/p[i].heightt;

cout<< "BMI : "<<p[i].bmi<<endl;
if(p[i].bmi<18.5)
    cout<< "Under Weight";

else if(p[i].bmi>=18.5 &&p[i].bmi<=24.9)
    cout<< "Normal Range";

else if(p[i].bmi>=25 && p[i].bmi<=29.9)
    cout<< "Over Weight";

else if(p[i+c].bmi>=30 && p[i].bmi<=39.9)
    cout<< "Obese";

    else
    cout<< " ";


system("cls");
cout<<"\nMedical history : \n";

cout<<"\nEnter types of medicine taken(if any): "<<endl;
cin.ignore();
getline(cin,p[i].medicine_taken);


cout<<"\nEnter types of illness: "<<endl;
getline(cin,p[i].illnesses);


cout<<"\nEnter the types of surgery that you have been in (if any): "<<endl;
getline(cin,p[i].surgeries);


cout<<"\nEnter the symptoms of the disease that you are experiencing: "<<endl;
getline(cin,p[i].symptoms);

system("cls");

cout<<"\n\Appointment : "<<endl;
cout<<"\nHere is the doctors schedule "<<endl;
   ifstream file("hospital.txt");

cout<<"\nDoctor's name: "<<Hos.name_doc<<"\nSex: "<<Hos.sex<<"\nSpeciality name: "<<Hos.specialst<<"\nSchedule: "<<Hos.schedule_doc;
    cout<<" \n\nNow you can see when the doctor is available and choose your appointment."<<endl;

    cout<<"\n The appointment date day: ";
    cin>>ap.dd;

    cout<<"\n The month: ";
    cin>>ap.mm;

    cout<<"\n The year: ";
    cin>>ap.yy;

    cout<<"\n\nYou have successfully book an appointment : "<<endl;
    cout<<"***Don't forget your appointment and be punctual!!!**"<<endl;


system("cls");
cout<<"\n---------------------------------------------------------"<<endl;
cout<<"\nThank you the information have been registered\n";

    tryagain:
        cout<<"\ncreate password: ";
    cin>>p[i].passcode;

    cout<<"\nRe-enter your password";
    cin>>p[i].passcode2;

    if(p[i].passcode == p[i].passcode2)
        cout<<"\npassword successfully created";
    else
    {
        cout<<"passwords doesn't match please try again : ";
        goto tryagain;
    }


    ofile<<"\n\Personal Information : "<<endl;

     ofile<<"Full  name : "<<p[i].name;

     ofile<<"\nAddress : ";
     ofile<<"\nCity: "<<p[i].city;
    ofile<<"\nEnter Kefleketema : "<<p[i].kfleketema;

     ofile<<"\nKebele  : "<<p[i].kebele;

    ofile<<"\nWoreda: "<<p[i].wereda;

    ofile<<"\nContact Number : "<<p[i].contact;

     ofile<<"\nBirthdate : "<<p[i].date<<"/"<<p[i].month<<"/"<<p[i].year;

     ofile<<"\nAge : "<<p[i].age;
     ofile<<"\nSex"<<p[i].sex;
     ofile<<"\nBlood Group : "<<p[i+c].blood;

     ofile<<"\nWeight"<<p[i].weight;

ofile<<"\nHeight"<<p[i].height;
ofile<< "BMI : "<<p[i].bmi;
ofile<< "BMI range : ";
if(p[i].bmi<18.5)
    ofile<< "Under Weight";

else if(p[i].bmi>=18.5 &&p[i].bmi<=24.9)
    ofile<< "Normal Range";

else if(p[i].bmi>=25 && p[i].bmi<=29.9)
    ofile<< "Over Weight";

else if(p[i+c].bmi>=30 && p[i].bmi<=39.9)
    ofile<< "Obese";

    else
    ofile<< " ";
ofile<<"\nMedical history : \n";

ofile<<"\nTypes of medicine taken(if any): "<<p[i].medicine_taken;


ofile<<"\nIllness: "<<p[i].illnesses;


ofile<<"\nSurgery: "<<p[i].surgeries;


ofile<<"\nSymptoms : "<<p[i].symptoms;

ofile<<"\n\Appointment : ";
ofile<<"\nDoctor's name: "<<Hos.name_doc<<"\nSex: "<<Hos.sex<<"\nSpeciality name: "<<Hos.specialst<<"\nSchedule: "<<Hos.schedule_doc;
    ofile<<"\n Appointment date: "<<ap.dd<<"/"<<ap.mm<<"/"<<ap.yy;

    p[i+c].id=id;
    c++;
    id++;
  }
  ofile.close();

    }
   do{
    cout<<"\npress 1 to go back: ";
    cin>>response;//entering value for choosing the option which is listed above
    }while(response!=1);
     system("cls");
     patient();//if the user press 1 it return back to patient function

}

//display registered patients information
void display(){
string ename;
int response;
    ifstream ifile("patient.txt");
    if (!ifile.is_open())
    {
    cout<<"could not open file";
    }
else
    {
 cout<<"..................Well come doctor firdews please fill the following information according to patients information............. "<<endl;
    cout<<"\n\n===============patient information stored in table================="<<endl;

    while(!ifile.eof()){

cout<<"====================================================================================================================================================="<<endl;
cout<<"dd"<<"\t"<<"mm"<<"\t"<<"yy"<<"\t"<<"na"<<"\t"<<"cy"<<"\t"<<"k/k"<<"\t"<<"keb"<<"\t"<<"wer"<<"\t";
cout<<"cont"<<"\t"<<"brdy"<<"\t"<<"brmon"<<"\t"<<"btyr"<<"\t"<<"age"<<"\t"<<"sex"<<"\t"<<"bld"<<"\t";
cout<<"bmi"<<"\t"<<"medt"<<"\t"<<"ill"<<"\t"<<"surg"<<"\t"<<"syp"<<"\t"<<"pass1"<<"\t"<<"pass2"<<endl;
cout<<"======================================================================================================================================================"<<endl;
    while(getline(ifile,ename)){
        cout<<ename;cout<<endl;}

    ifile.close();
    }

     do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     doctor();//if the user presses 1 it return back to doctor function

}}
//login if already registered
void oldPatient(){

int response;
string pass;
    cout<<"\nEnter passcode";
    cin>>pass;//asks the password that the patient have entered when he/she was registering

    for(int i = 0; i<c; i++){
    if( pass==p[i].passcode && pass==p[i].passcode2 ){

        cout<<"patient ID: ";
        cout<<p[i].id;
cout<<"================================================================"<<endl;
cout<<"\nPatient name :            "<<setw (32)<< left<<p[i].name;

cout<<"\nCity name:              "<<setw (32)<< left<<p[i].city;

cout<<"\nKfleketema :            "<<setw (32)<< left<<p[i].kfleketema;
cout<<"\nKebele  :               "<<setw (32)<< left<<p[i].kebele;

cout<<"\nWereda:                 "<<setw (32)<< left<<p[i].wereda;
cout<<"\nContact Number :        "<<setw (32)<< left<<p[i].contact;

cout<<"\nDate Of Birth :         "<<setw (32)<< left<<p[i].date;
cout<<"\nMonth Of Birth :        "<<setw (32)<< left<<p[i].month;

cout<<"\nYear Of Birth :         "<<setw (32)<< left<<p[i].year;
cout<<"\nAge :                   "<<setw (32)<< left<<p[i].age;

cout<<"\nSex :                   "<<setw (32)<< left<<p[i].sex;
cout<<"\nBlood Group :           "<<setw (32)<< left<<p[i].blood;
cout<<"\nBMI :                  "<<setw (30)<<left<<p[i].bmi;

cout<<"\nMedicine taken:         "<<setw (30)<< left<<p[i].medicine_taken<<endl;

cout<<"\nNumber of medicine:     "<<setw (30)<< left<<p[i].no_medicine<<endl;
cout<<"Name of illnesses:      "<<setw (30)<< left<<p[i].illnesses<<endl;

cout<<"Type of surgeries:      "<<setw (30)<< left<<p[i].surgeries<<endl;
cout<<"Number of surgeries:    "<<setw (30)<< left<<p[i].no_surgeries<<endl;

cout<<"Type of allergic:       "<<setw (30)<< left<<p[i].allergies<<endl;
cout<<"symptoms experienced:   "<<setw (30)<< left<<p[i].symptoms<<endl;

cout<<"\n\n\n================================================================"<<endl;

        cout<<"doctor recommendation for you: ";
        cout<<p[i].recommend<<endl;

        cout<<"doctor tip: ";
        cout<<p[i].tipFromDoc<<endl;

        cout<<"doctor check up order for you: ";
        cout<<p[i].checkup<<endl;


        cout<<"doctor prescription for you: ";
        cout<<p[i].prescription<<endl;
        cout<<"\n";
    }
    else cout<<"password not found ";
    }

    do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     patient();//if the user press 1 it returns back to patient function

}
void inpatient()
{
    int response;
    string pass;
     int days[100],cost[100];
     cout<<"\nEnter passcode";
    cin>>pass;//asks the password that the patient have entered when he/she was registering


for(int i = 0; i<c; i++){
    if( pass==p[i].passcode&&pass==p[i].passcode2 ){


    cout<< "Enter the number of days you have Stayed in the hospital : ";

cin>>p[i].days;
cout<<"The severity of illness is : " ;

if(p[i].days<=1)
    cout<<" Minor"<< endl;

    else if(p[i].days<=3)
    cout<<" Moderate"<< endl;

        else if(p[i].days<=6)
        cout<<" Major"<< endl;

        else
        cout<<" Extreme"<< endl;
        p[i].cost= 200*p[i].days;

   cout<<"The total cost for "<<p[i].days<<" days is : "<<p[i].cost;
 }}
    do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     patient();
}
//function to edit information
void edit()
{
    struct edit{
string a,b,c,d,e,f,g,h;
int j,k,l,n,o,p,q,r;
char s,t,m;


    }e;
        int response,i;
        char choose;
        string pass;




cout<<"\nenter passcode";
    cin>>pass;//asks the password that the patient have entered when he/she was registering



for(int i = 0; i<c; i++){
    if( pass==p[i].passcode&&pass==p[i].passcode2 ){
cout<<"================================================================"<<endl;
cout<<"\nPatient name :            "<<setw (32)<< left<<p[i].name;

cout<<"\nCity name:              "<<setw (32)<< left<<p[i].city;

cout<<"\nKfleketema :            "<<setw (32)<< left<<p[i].kfleketema;
cout<<"\nKebele  :               "<<setw (32)<< left<<p[i].kebele;

cout<<"\nWereda:                 "<<setw (32)<< left<<p[i].wereda;
cout<<"\nContact Number :        "<<setw (32)<< left<<p[i].contact;

cout<<"\nDate Of Birth :         "<<setw (32)<< left<<p[i].date;
cout<<"\nMonth Of Birth :        "<<setw (32)<< left<<p[i].month;

cout<<"\nYear Of Birth :         "<<setw (32)<< left<<p[i].year;
cout<<"\nAge :                   "<<setw (32)<< left<<p[i].age;

cout<<"\nSex :                   "<<setw (32)<< left<<p[i].sex;
cout<<"\nBlood Group :           "<<setw (32)<< left<<p[i].blood;
cout<<"\nMedicine taken:         "<<setw (30)<< left<<p[i].medicine_taken<<endl;

cout<<"Name of illnesses:      "<<setw (30)<< left<<p[i].illnesses<<endl;

cout<<"Type of surgeries:      "<<setw (30)<< left<<p[i].surgeries<<endl;
cout<<"Type of allergic:       "<<setw (30)<< left<<p[i].allergies<<endl;
cout<<"symptoms experienced:   "<<setw (30)<< left<<p[i].symptoms<<endl;

cout<<"\n\n\n================================================================"<<endl;
cout<<"\n\n\n================================================================"<<endl;
cout<<"\n\n\n================================================================"<<endl;

cout<< "which statement do u want to edit"<<endl;
cout<< "choose 1 if you want to edit name"<<endl;
cout<< "choose 2 if you want to edit City name"<<endl;
cout<< "choose 3 if you want to edit Kfleketema"<<endl;
cout<< "choose 4 if you want to edit Kebele"<<endl;
cout<< "choose 5 if you want to edit Wereda"<<endl;
cout<< "choose 6 if you want to edit Contact Number"<<endl;
cout<< "choose 7 if you want to edit Date Of Birth"<<endl;
cout<< "choose 8 if you want to edit month Of Birth"<<endl;
cout<< "choose 9 if you want to edit year Of Birth"<<endl;
cout<< "choose 11 if you want to edit age"<<endl;
cout<< "choose 12 if you want to edit Sex "<<endl;
cout<< "choose 13 if you want to edit Blood Group"<<endl;
cout<< "choose 14 if you want to edit Medicine taken"<<endl;
cout<< "choose 15 if you want to edit Number of medicine"<<endl;
cout<< "choose 16 if you want to edit Name of illnesses"<<endl;
cout<< "choose 17 if you want to edit Type of surgeries"<<endl;
cout<< "choose 18 if you want to edit Number of surgeries"<<endl;
cout<< "choose 19 if you want to edit Type of allergic "<<endl;
cout<< "choose 20 if you want to edit symptoms experienced"<<endl;
enter:
cin>>choose;
    switch(choose)
    {
    case '1':
        cout<< "enter your full name"<<endl;
            cin.ignore();
    getline(cin,e.a);
    p[i].name=e.a;
    break;

    case '2':
        cout<<"enter your city"<<endl;
        cin.ignore();
        getline(cin,e.b);
        p[i].city=e.b;
        break;
    case '3':
       cout<< "enter your kfleketema"<<endl;
        cin.ignore();
        getline(cin,e.c);
        p[i].kfleketema=e.c;
        break;
    case '4':
        cout<< "enter your kebele"<<endl;
        cin>>e.k;
        p[i].kebele=e.k;
                break;
    case '5':
        cout<<"enter your wereda"<<endl;
        cin>>e.l;
        p[i].wereda=e.l;
        break;
    case '6':
        cout<<"enter your contact number here"<<endl;
        cin>>e.m;
        //p[i+c].contact=e.m;
        break;
    case '7':
         cout<<"enter your date of birth here"<<endl;
        cin>>e.n;
        p[i].date=e.n;
        break;
    case '8':
    cout<<"enter your month of birth here"<<endl;
        cin>>e.o;
        p[i].month=e.o;
        break;
    case '9':
       cout<<"enter your year of birth here"<<endl;
        cin>>e.p;
        p[i].year=e.p;
        break;
     case '10':
        cout<<"enter your age"<<endl;
        cin>>e.j;
        p[i].age=e.j;
        break;
    case '12':
          cout<<"enter your sex"<<endl;
        cin>>e.s;
      //  p[i+c].sex=e.s;
        break;
    case '13':
        cout<<"enter your blood group"<<endl;
        cin>>e.t;
       // p[i+c].blood=e.t;
        break;
    case '14':
        cout<< "enter medicine taken"<<endl;
        cin.ignore();
        getline(cin,e.d);
          p[i].medicine_taken=e.d;
        break;
    case '15':
        cout<<"enter number of medicine taken"<<endl;
        cin>>e.q;
        p[i].no_medicine=e.q;
        break;
    case '16':
        cout<< "enter name of illness"<<endl;
        cin.ignore();
        getline(cin,e.e);
        p[i].illnesses=e.e;
        break;
    case '17':
        cout<< "enter type of surgeries"<<endl;
        cin.ignore();
        getline(cin,e.f);
        p[i].surgeries=e.f;
        break;
    case '18':
        cout<<"enter number of surgeries"<<endl;
        cin>>e.r;
        p[i+c].no_surgeries=e.r;
        break;
    case '19':
      cout<< "enter allergies"<<endl;
        cin.ignore();
        getline(cin,e.g);
        p[i].allergies=e.g;
   case '20':
      cout<< "enter symptoms"<<endl;
        cin.ignore();
        getline(cin,e.h);
        p[i].symptoms=e.h;
        break;

    default:
        cout<< "you have entered a wrong number please try again"<<endl;
        goto enter;
    }
    }}
    do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     patient();

}
//function to delete information
void Administrator()
{
       int response,x=1234;
int pass;
    cout<<"\nenter passcode";
    cin>>pass;
 if(pass==x){
int pidd;
bool deletes=false;
char cho;
cout<<"For administrator side please enter the id of patient you want to clear(delete) information : ";
cin>>pidd;
fstream fp1;
  fp1.open("patient.txt",ios::in|ios::out);
  fstream fp2;
  fp2.open("Temp.txt",ios::out);
  fp1.seekg(0,ios::beg);
  int i;
  while(fp1.read((char*)&p,sizeof(patient_info)))
  {
    if(pidd!=p[i].id)
    {
      fp2.write((char*)&p,sizeof(patient_info));
    }
  }
  fp2.close();
  fp1.close();
  remove("patient.txt");
  rename("Temp.txt","patient.txt");
  cout<<endl<<endl<<"\tRecord Deleted...";
  do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     menu();
 }


}

//function definition
//only applicable for doctors
void doctor(){
    int c,x,code,response;
    x=1565;
cout<<"Enter password:";
cin>>code;
if(code==x){
cout<<"=================Choose your option from listed below==============";
 cout<<"\n\n1.display patients information\n";
 cout<<"2.doctors note for patient\n";
 cout<<"3.back\n";

 cout<<"enter your option: ";
 cin>>c;
 cout<<endl;

 switch(c){
 case 1:
     system("cls");
     display();//calling display funtion

     break;
 case 2:
     system("cls");
     medicalTip();//calling medical tip function
    break;

case 3:
     system("cls");
     menu();//if the user press 3 it return to menu function

    break;
 }}
 else
{cout<<"\nIncorrect password!!!Please try again\n "<<endl;}
 do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     doctor();
 }
//stored medical tip from doctors
void medicalTip(){

    int response;
    string rec,tip,pres,check;
    int pid;

    cout<<"enter patient ID: ";
    cin>>pid;//entering patients id that he/she uses when they register in order to display their information according to their id number

     for(int i=0; i<c; i++){
        if(pid==p[i].id){

        cout<<"patient ID: ";
        cout<<p[i].id;

cout<<"\nname of patient:    "<<setw (8)<<p[i].name;
cout<<"\npatient age:        "<<setw (8)<<p[i].age;
cout<<"\nSex :               "<<setw (8)<<p[i].sex;
cout<<"\nBlood Group :       "<<setw (8)<<p[i].blood;
cout<<"\nPatient ID Number : "<<setw (8)<<p[i].id;
cout<<"\nBMI :                      "<<setw (30)<<left<<p[i].bmi;
cout<<"\n\nMedicine taken:          "<<setw (30)<<p[i].medicine_taken<<endl;

cout<<"\nName of illnesses:        "<<setw (30)<<p[i].illnesses<<endl;

cout<<"\nType of surgeries:        "<<setw (30)<<p[i].surgeries<<endl;

cout<<"\nsymptoms experienced:     "<<setw (30)<<p[i].symptoms<<endl;
cout<<"\n";
        }
     }

     cout<<"enter tip\n";
     cin.ignore();
     getline(cin,tip);

   cout<<"enter recommendation\n";
     cin.ignore();
     getline(cin,rec);

     cout<<"enter check up\n";
     cin.ignore();
     getline(cin,check);

     cout<<"enter prescription\n";
    cin.ignore();
     getline(cin,pres);

      for(int i=0; i<c; i++){
        if(pid==p[i].id){
             fflush(stdin);//used to copying information to display it in another function
             p[i].tipFromDoc = tip;

             p[i].recommend = rec;

             p[i].checkup = check;

             p[i].prescription = pres;

        }
        }

    do{
    cout<<"\npress 1 to go back: ";
    cin>>response;
    }while(response!=1);
     system("cls");
     doctor();//if the user press 1 it will return back to doctor functions

}
//hospital
//hospitals information is stored
void hospital_information()
{
 ofstream file("hospital.txt");

Hospitals<string,int,char> Hos;
Hos.name_hos={"Birhanu centralized hospital"};
Hos.service={"\n - short-term hospitalization\n - emergency room services\n - general and specialty surgical services\n - x-ray radiology services \n - laboratory services\n - blood services."};
Hos.name_doc={"DR.Firdews Abrar"};
Hos.sex='f';
Hos.specialst={"General Doctor"};
Hos.schedule_doc={"(Monday-Thursday)=4:00am-11:30pm,(Friday and Saturday)=2:30am-6:00am"};
Hos.city_hos={"Addiss Ababa"};
Hos.kfleketema_hos={"Kolfe Keranyo"};
Hos.wereda_hos=05;
Hos.kebele_hos=01;
Hos.email_hos={"birhanu_centrhos@gmail.com"};
Hos.phone_hos={"011-345-654"};
file<<Hos.name_hos<<Hos.service<<Hos.name_doc<<Hos.sex<<Hos.specialst<<Hos.schedule_doc<<Hos.city_hos<<Hos.kfleketema_hos<<Hos.wereda_hos<<Hos.kebele_hos<<Hos.email_hos<<Hos.phone_hos;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
file.close();
cout<<"Name of Hospital: "<<Hos.name_hos<<endl;
cout<<"\n->Service that "<<Hos.name_hos<<" provide: "<<endl<<Hos.service<<endl;
cout<<"\n General information:"<<"\n ->President  Peter L. Slavin,\n-> Total certified beds  907\n-> Total employees (part- and full-time)  23,302\n-> Total operating revenue  $612 million"<<endl;
cout<<"\nPatient and surgical statistics: "<<"\n #Total inpatients  47,250\n #Average length of stay  5.82 days\n #Admissions to observe  7,978\n #Total surgical cases  36,701\n #Inpatient surgical cases  19,233\n #Ambulatory surgical cases  17,468"<<endl;
cout<<"\n General information:"<<"\n ->President  Peter L. Slavin,\n-> Total certified beds  907\n-> Total employees (part- and full-time)  23,302\n-> Total operating revenue  $612 million"<<endl;
cout<<"\nPatient and surgical statistics: "<<"\n #Total inpatients  47,250\n #Average length of stay  5.82 days\n #Admissions to observe  7,978\n #Total surgical cases  36,701\n #Inpatient surgical cases  19,233\n #Ambulatory surgical cases  17,468"<<endl;
cout<<"\nDoctors information in "<<Hos.name_hos<<endl;
cout<<"______________________________________________________"<<endl;

cout<<"\nDoctor's name: "<<Hos.name_doc<<"\nSex: "<<Hos.sex<<"\nSpeciality name: "<<Hos.specialst<<"\nSchedule: "<<Hos.schedule_doc;
cout<<"\n\n________Hospitals Address_____________"<<endl;
cout<<"\nHispitals city: "<<Hos.city_hos<<"\n"<<" KfleKetema: "<<Hos.kfleketema_hos<<endl;
cout<<"kebele: "<<Hos.kebele_hos<<"\n"<<" wereda: "<<Hos.wereda_hos<<endl;
cout<<"Hispitals  emailaddress: "<<Hos.email_hos<<"\n"<<" phone number: "<<Hos.phone_hos<<endl;
cout<<"......................................................"<<endl;
system("pause");
system("cls");
menu();

}
