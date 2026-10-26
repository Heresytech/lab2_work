#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    //добавка кириллической локали
	setlocale(LC_ALL, "Russian");
    //вывод имен переменных при вводе, чтобы пользователь понимал, что он вводит
    const string var_names[4] = {"день недели:", "час дня:", "минута в часу:", "длительность желаемого окна:"};

    int d = 0,   //день недели
    h = 0, //час дня
    m = 0,  //минута в часу
    w = 0, //длительность окна
    t = 0, // текущее время в минутах
    start_w, //начало свободного окна(в минутах)
    current_w; //длительность данного свободного окна 
	
    int *var; // указатель на переменную  
    bool is_good; //флажок, показывающий, есть ли хоть один день со свободным окном 
    bool busy; //флажок, показывающий, занята ли конкретная минута
	std::string line;//строка, из которой передается значение

    //последовательный ввод четырех переменных(d, h, m, w) с проверкой типов
    for(int i = 0; i < 4; i++){
    std::cout << var_names[i];
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line); //символьный поток
        
        switch (i)
        {
        case 0: var = &d; break;
        case 1: var = &h; break;
        case 2: var = &m; break;
        case 3: var = &w; break;
        default:
            break;
        }
		if (ss >> *var)
		{

			if (ss.eof())
			{ 
			
				break;
			}
		}
       
		cout << "Ошибка!Введите целое число:" << endl;
	}
    }
    
	cout << "Ваш ввод:"<< " день недели:" << d << " час дня:" << h << " минута в часу:" << m << " длительность окна:" << w << endl;
    t = 60 * h + m; //вычисление текущего времени в минутах
    is_good = false; //по умолчанию свободных окон нет

    for(d; d <= 7; d++){
     start_w = 0; // начало окна равно нулю

    for(t; t <= 1440; t++){
    busy = false;
   
    //выбор дня с заданными занятыми минутами
    switch (d)
    {
    case 1: if((0 < t && t < 975) || (t > 1380)){
    busy = true;} 
    break;
    case 2: if((0 < t && t < 975) || (1140 < t && t < 1260) || (t > 1380)){
    busy = true;} 
    break;
    case 3: if((0 < t && t < 945) || (1080 < t && t < 1200) || (t > 1200)){
    busy = true;} 
    break;
    case 4: if((0 < t && t < 630) || (1080 < t && t < 1140) || (t > 1320)){
    busy = true;} 
    break;
    case 5: if((0 < t && t < 795) || (915 < t && t < 990) || (t > 1320)){
    busy = true;} 
    break;
    case 6: if((0 < t && t < 600) || (660 < t && t < 780) || (t > 1320)){
    busy = true;} 
    break;
    case 7: if((0 < t && t < 615) || (795 < t && t < 915) || (t > 1320)){
    busy = true;} 
    break;
    default:
        cout << "Номер дня недели неверный" << endl;
        break;
    }
    //если минута занята, то начинаем считать продолжительность окна
    if(busy == true){ 
   
    if(start_w != 0){ //если начало окна не равно нулю, то вычитаем из текущего времени время начало окна - получаем прод-сть окна
    current_w = t - start_w;
    
    if(w < current_w){//
    cout << "В день " << d << " есть свободное время с " << start_w << " до " << t << endl;
    is_good = true;
    }
    start_w = 0;
    }

    }
    else if(start_w == 0){//иначе фиксируем начало окна при start_w = 0
    start_w = t;    
    }

    }

    //проверка, "заползает" ли окно на следующий день
    //если да, то окно считается СТРОГО до полуночи
    if(start_w != 0){
    current_w = t - start_w;
    if(w < current_w){
    current_w = t - start_w;
    if(w < current_w){
    cout << "В день " << d << " есть свободное время с " << start_w << " до " << t << endl;
    is_good = true;
    }
    }
    }
    //|||||||||||||||||||||||||||||||||||||||||

    t = 0; //в след. день проверяются все минуты
    }
    
    //t = 0;
    if(is_good == false){
    cout << "Свободного времени нет" << endl;
    }
    return 0;
}
 
