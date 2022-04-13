/*Створити файл з інформацією про наявність лікарських ампул :назва ,термін дії після відкривання (за шаблоном ),
 * термін зберігання (роки)нерозпакованої.Створити новий файл який містисть інформацію про розкриті ампули :назва
 * ліків ,час відкриття(вводиться користувачем) та термін,до якого ампула має бути використана (розраховується
 * згідно даними з першого файлу).Видалити з нового файлу інформацію про ампули термін зберігання вийшов.*/
#include "header.h"
 vector<string> getLines(vector<string> & names){//інформація для записування у файл(потрібно перевірити данф на правельність введення )
    string name ,timeAfter , expirationDate , line;
    vector<string> lines;
    //vector<string> names ;
    vector<string> timeAfters ;
    vector<string> expirationDates ;
    char flag = 'y';
    while (flag == 'y'){
        cout <<"enter ampoule name :\n";
        cin >> name;
        name = verName(name);
        names.push_back(name);
        cout <<"expiration date after opening :\n";
        cin >> timeAfter;
        timeAfter = verTimeAfter(timeAfter);
        timeAfters.push_back(timeAfter);
        cout <<"expiration date :\n";
        cin >> expirationDate;
        expirationDate = verExpirationDate(expirationDate);
        expirationDates.push_back(expirationDate);
        line = name + "," + timeAfter + "," + expirationDate;//append;
        lines.push_back(line);
        cout << "continue ? y/n\n";
        cin >> flag;
    }
    return lines;
}
string verName(string name){//перевірка на коректність назви препарату
    while (name.size() > 20 || name.size() < 1){
        cout <<"Please , enter ampoule name again : \n";
        cin >> name;
    }
    return name;
}
string verTimeAfter(string time){//перевірка на дотримання часу
    //bool hour = false;
    //bool min = false;
    bool hour = verHour(time.substr(0,2));
    bool min = verMin(time.substr(3,5));
    while(time.size() != 5 || time[2] != ':' || min || hour){
        cout <<"Enter correct time in format HH:MM:\n";
        cin >> time;
        hour = verHour(time.substr(0,2));
        min = verMin(time.substr(3,5));


        /*cout <<"Enter correct time in format HH:MM :\n ";
        cin >> time;
        hour = verHour(time.substr(0,2));
        min = verMin(time.substr(3,5));
         */
        /*cout <<"Enter correct time in format HH:MM :\n ";
        cin >> time;*/
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
string verExpirationDate(string date){//перевірка терміну зберігання
    while(stoi(date) < 0 || stoi(date) > 100 ){
        cout <<"enter Expiration Date again:\n";
        cin >> date;
    }
    return date;
}
void writeFile(string fileName , vector<string> lines){//запис у початковий файл
    ofstream file(fileName, ios::binary);
    for (int i = 0; i < lines.size(); i ++){
        file << lines[i];
        if (i != lines.size() - 1){
            file <<"\n";
        }
    }
    file.close();
}
string getTime(){
    string time;
    cout <<"enter time of opening :\n";
    cin >> time;
    return time;
}

vector<string>secondFileLines(vector<string > names , vector<string> text1){
     vector<string> lines2;
     int number = 0;
     string line;
     char flag = 'y';
     cout <<"File 2\n";
     while (flag == 'y') {
         string name, timeOpening;
         cout <<"enter ampoule name : \n";
         cin >> name;
         name = checkInlist(names, name , number);
         timeOpening = getTime();
         timeOpening = verTimeAfter(timeOpening);
         //cout <<"time oppening :\n"<<timeOpening;
         //cout <<"names[number]"<< names[number]<<"\n";
         string timeFromFile1 = getTimeFile1(text1[number]);
         //cout << "\nTime :" << timeFromFile1<<"\n";
         string timeToFile2 = getTimeToFile2(timeFromFile1 ,timeOpening);
         line = name + ";" + timeOpening + ";" + timeToFile2;
         lines2.push_back(line);
         cout << "continue ? y/n"<<endl;
         cin >> flag;
    }
    return lines2;
}

string checkInlist(vector<string> names, string name , int & number){
     bool flag = false;
     /*for (int i = 0; i < names.size();i++){
         if(names[i] == name){
             flag = true;
             number = i;
         }
     }*/
     /*int it = find(names.begin(),name.end(),name);
     if (it != names.end()){
         number = it - names.begin();
     }*/
     while (flag == false){
         for (int i = 0; i < names.size();i++){
             if(names[i] == name){
                 flag = true;
                 number = i;
             }
         }
         if (flag == false){
             cout <<"This ampule is not on the file 1 , pleace enter again : \n";
             cin >> name;
         }
     }
     return name;
 }

string getTimeFile1(string lineWithTime ){

    string time;
    vector <string > times;
    for(int i = 0; i < lineWithTime.size(); i++){
        if (lineWithTime[i] == ','){
            time = lineWithTime.substr(i+1,i+6);
            break;
        }
    }
    return time;
}
string getTimeToFile2(string timeFromFile1 , string timeOpening){
     int h ,m ;
     string timeToFile2;
     string newH = "1d ";
     h = stoi(timeFromFile1.substr(0,2)) + stoi(timeOpening.substr(0,2));
     m = stoi(timeFromFile1.substr(3,5)) + stoi(timeOpening.substr(3,5));
     if (m > 60){
         h = h + m / 60;
         m = m % 60;
         if (h > 24){
             h -= 24;
             timeToFile2 = "+1d " + to_string(h) + ":" + to_string(m);
         }
         else{
             timeToFile2 = to_string(h) +":"+  to_string(m);
         }
     }
     return timeToFile2;

 }
string getTimeNow(){
     string time;
     cout << "To complete the last task, enter the current time:";
     cin >> time ;
     return time;
 }
void outFIle(string fileName){
     ifstream file(fileName, ios::binary);
     string i;
     while(getline(file, i)){
         cout <<i <<endl;
     }
     file.close();

 }