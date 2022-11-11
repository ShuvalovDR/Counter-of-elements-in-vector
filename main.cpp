#include <iostream>
#include <vector>

void print_vector(std :: vector <int> v){
    for (int i = 0; i < v.size(); i++){
        std::cout << v.at(i) << ' ';
    }
    std :: cout << std::endl;
}

std :: vector<int> bubble_sort(std :: vector <int> v){ //функция сортирует массив по возрастанию
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size() - 1; j++){
            if (v.at(j) > v.at(j + 1)){
                int temp1 = v.at(j);
                int temp2 = v.at(j + 1);
                v.at(j) = temp2;
                v.at(j + 1) = temp1;
            }
        }
    }
    return v;
}

std :: vector<int> counter_of_elements(std :: vector <int> v_sort){ //функция считает количство каждого элемента в векторе и записывает в новый вектор
    std :: vector<int> kolvo = {};
    int counter = 1;
    for(int i = 0; i < v_sort.size() - 1; i++) {
        if(v_sort.at(i) == v_sort.at(i + 1)){
            counter++;
            if(i == v_sort.size() - 2){
                kolvo.push_back(counter);
            }
        }
        else if (v_sort.at(i) != v_sort.at(i + 1)){
            kolvo.push_back(counter);
            counter = 1;
        }
    }
    int n = v_sort.size();
    if (v_sort.at(n - 1) != v_sort.at(n - 2)){
        kolvo.push_back(1);
    }
    return kolvo;
}

int main() {
    int n;  //Длина вектора
    int number;  //Переменная для записи числа в вектор
    std :: vector <int> v = {};  //пустой вектор
    std :: cout <<"Input the length of vector:" << std :: endl;
    std :: cin >> n;
    for (int i = 0; i < n; i++){ //заполнение вектора числами с клавиатуры
        std::cout <<"Input the " << i + 1 << " element of vector:"<< std::endl;
        std::cin >> number;
        v.push_back(number);
    }
    std::cout << "Vector" << std::endl;
    print_vector(v);
    std::vector <int> v_sort = bubble_sort(v);
    std::cout << "Sort Vector" << std::endl;
    print_vector(v_sort);
    std :: vector <int> kolvo = counter_of_elements(v_sort);
    std::cout << "The number of equal elements in vector" << std::endl;
    print_vector(kolvo);
}
