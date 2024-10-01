//
// Created by Rainy-Heights on 2024/9/2.
//
#include "../cunion.h"
class Person{
private:
    string name;
    int age;
    int score;

    Person(string name, int age, int score) : name(name), age(age), score(score) {};

    string toString() {
        return "[name=" + this->name + ",age=" + to_string(this->age) + ",score=" + to_string(this->score) + "]";
    }
};