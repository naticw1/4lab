/*Створити файл з інформацією про наявність лікарських ампул :назва ,термін дії після відкривання (за шаблоном ),
 * термін зберігання (роки)нерозпакованої.Створити новий файл який містисть інформацію про розкриті ампули :назва
 * ліків ,час відкриття(вводиться користувачем) та термін,до якого ампула має бути використана (розраховується
 * згідно даними з першого файлу).Видалити з нового файлу інформацію про ампули термін зберігання вийшов.*/
#include "header.h"
void getLines(string filename1) {//інформація для записування у файл(потрібно перевірити данф на правельність введення )
    string name , timeAfter ;
    int expirationDate;
    int i = 0;
    //Ampoule b;
    ofstream file(filename1 , ios::binary);
    char flag = 'y';
    while (flag == 'y') {
        Ampoule b ;
        cout << "enter ampoule name :"<<endl;
        cin >> name;
        name = verName(name);
        strcpy(b.name , name.c_str());
        cout << "expiration date after opening :"<<endl;
        cin >> timeAfter;
        timeAfter = verTimeAfter(timeAfter);
        strcpy(b.timeAfter , timeAfter.c_str());
        cout << "expiration date :"<<endl;
        cin >> expirationDate;
        expirationDate = verExpirationDate(expirationDate);
        b.expirationDate = expirationDate;
        //line = a.name + "," + a.timeAfter + "," + a.expirationDate;//append;
        file.write((char*)&b, sizeof(Ampoule));
        cout << "continue ? y/n"<<endl;
        cin >> flag;
        cin.ignore();

    }
    file.close();
}
string verName(string name){//перевірка на коректність назви препарату
    while (name.size() > 20 || name.size() < 1){
        cout <<"Please , enter ampoule name again :"<<endl;
        cin >> name;
    }
    cin.ignore();
    return name;
}
string verTimeAfter(string time){//перевірка на дотримання часу
    //bool hour = false;
    //bool min = false;
    bool hour = verHour(time.substr(0,2));
    bool min = verMin(time.substr(3,5));
    while(time.size() != 5 || time[2] != ':' || min || hour){
        cout <<"Enter correct time in format HH:MM:"<<endl;
        cin >> time;
        hour = verHour(time.substr(0,2));
        min = verMin(time.substr(3,5));
    }
    return time;

}
bool verHour(string hours){
    bool flag = false;
    int h = stoi(hours);
    if (h < 0 || h > 24 ){
        flag = true;
    }
    return flag;
}
bool verMin(string minutes){
    bool flag = false;
    int m = stoi(minutes);
    if (m < 0 || m > 59 ){
        flag = true;
    }
    return flag;
}
int verExpirationDate(int date){//перевірка терміну зберігання
    while(date < 0 || date > 100 ){
        cout <<"enter Expiration Date again:"<<endl;
        cin >> date;
    }
    cin.ignore();
    return date;
}
void outFIle(string filename1) {
    Ampoule b{};
    ifstream file(filename1 , ios::binary);
    while(file.read((char *)&b,sizeof (Ampoule))){
        string name(b.name) , timeAfter(b.timeAfter) ,expirationDate = to_string(b.expirationDate);
        cout << b.name << ", " <<b.timeAfter << ", "<<b.expirationDate<<";"<<endl;
    }
    file.close();
}
string getTime(){
    string time;
    cout <<"enter time of opening :"<<endl;
    cin >> time;
    cin.ignore();
    return time;
}
vector<Ampoule> file_text(string filename1){ // отримуємо текст з файлу 1
    vector<Ampoule> fileText;
    Ampoule b{};
    ifstream file(filename1 , ios::binary);
    while (file.read((char *)&b, sizeof (Ampoule))){
        fileText.push_back(b);
    }
    file.close();
    return fileText;
}
void secondFileLines(string filename2, vector<Ampoule> info ){

     int number = 0;
     string line;
     char flag = 'y';
     cout <<"File 2\n";
     ofstream file(filename2 , ios::binary);
     while (flag == 'y') {
         UsAmpule a;
         string name, timeOpening;
         cout <<"enter ampoule name : \n";
         cin >> name;
         name = checkInlist(info, name , number);
         strcpy(a.name , name.c_str());
         timeOpening = getTime();
         timeOpening = verTimeAfter(timeOpening);
         strcpy(a.timeOpening , timeOpening.c_str());
         string timeToFile2 = getTimeToFile2(info[number].timeAfter ,timeOpening);
         strcpy(a.timeToUse , timeToFile2.c_str());
         file.write((char*)&a, sizeof(UsAmpule));
         cout << "continue ? y/n"<<endl;
         cin >> flag;
    }
     file.close();
}
string checkInlist(vector<Ampoule> info, string name , int & number){
    bool flag = false;
    while (flag == false){
        for (int i = 0; i < info.size();i++){
            if(info[i].name == name){
                flag = true;
                number = i;
            }
        }
        if (flag == false){
            cout <<"This ampule is not on the file 1 , pleace enter again : "<<endl;
            cin >> name;
        }
    }
    cin.ignore();
    return name;
}
string getTimeToFile2(string timeFromFile1 , string timeOpening){
    int h ,m1, m2 , m;
    string timeToFile2 ;
    string newH = "+1d ";
    string zero = "0";
    m1 =  stoi(timeFromFile1.substr(3,5));
    m2 = stoi(timeOpening.substr(3,5));
    h = stoi(timeFromFile1.substr(0,2)) + stoi(timeOpening.substr(0,2));
    m = m1 + m2;
    if (m > 60){
        h = h + m / 60;
        m = m % 60;
    }
    if (h > 24){
        h -= 24;
        timeToFile2 = newH + to_string(h) + ":" + to_string(m);
    }else if (m == 0) {
        timeToFile2 = to_string(h) +":"+  to_string(m) + zero;
    }else{
        timeToFile2 = to_string(h) +":"+  to_string(m);
    }
    return timeToFile2;
}
void outFIle2(string filename2) {
    UsAmpule a{};
    ifstream file(filename2 , ios::binary);
    while(file.read((char *)&a,sizeof (UsAmpule))){
        string name(a.name) , timeOpening(a.timeOpening) ,timeToUse(a.timeToUse);
        cout << name<< ", " <<a.timeOpening << ", "<<a.timeToUse<<";"<<endl;
    }
    file.close();
}
//отримати час зараз
string getTimeNow(){
    string time;
    cout <<"Enter current time :";
    cin >> time ;
    cin.ignore();
    return time;
}
void deleteAmpule(string filename2 , string filename3){
    int h1 , h2 , m1 , m2;
    string time;
    string timeNow = getTimeNow();
    timeNow = verTimeAfter(timeNow);
    ifstream fil(filename2 , ios::binary);
    ofstream file(filename3 , ios::binary);
    UsAmpule c{};
    while(fil.read((char *)&c , sizeof(UsAmpule))){
        time = c.timeToUse;
        if (stoi(time.substr(0,2)) > stoi(timeNow.substr(0,2)) || time[0] != '+'){
            file.write((char*)&c, sizeof(UsAmpule));
        }else if(stoi(time.substr(0,2)) == stoi(timeNow.substr(0,2))) {
            if (stoi(time.substr(3,5)) > stoi(timeNow.substr(3,5))){
                file.write((char*)&c, sizeof(UsAmpule));
            }
        }

    }
    fil.close();
    file.close();
    remove(filename2.c_str());
    rename(filename3.c_str() , filename2.c_str());
}