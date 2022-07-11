#include "Task5.h"
#include <iostream>

int main() {
    std::string description = "Найдите все тупиковые и минимальные ДНФ для данной функции.\
    В виде ответа предоставьте все тупиковые ДНФ в формате '-xz v -x-y v y-z'";
    Task5 task("11011110");

    task.generateTask(3);
    task.solveTask();

    
}